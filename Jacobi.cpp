#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*  Gerardo Antonio Ovando Hernandez 9490-21-7 Sección: A 
    Metodos Numéricos - TAREA 12 - METODO Jacobi
    Fecha: 12-05-2024
*/

int n, IT, suma;
int cont = 0;  
float TOL, dd, error;
float A[100][100]; 
float *B;
float *aprox;
float *aprox_anterior;

#define MAX 100

void solicitar_datos(){
    cout << "Ingrese la cantidad de incognitas: ";
    cin >> n;
    cout<<"Ingrese TOL: "; 
    cin>> setprecision(15) >> TOL;
    cout<<"Ingrese Ingrese IT: "; 
    cin>> setprecision(15) >> IT;
    cout<<" "; 

    
}

void ajustar_matriz(float A[100][100], float B[MAX], int n) {
    int i, j, maxIndex;
    float maxVal, temp;

    for (i = 0; i < n; i++) {
        maxVal = A[i][i];
        maxIndex = i;

        // Encuentra el valor máximo en la fila i
        for (j = i+1; j < n; j++) {
            if (fabs(A[j][i]) > fabs(maxVal)) {
                maxVal = A[j][i];
                maxIndex = j;
            }
        }

        // Intercambia las filas i y maxIndex
        if (maxIndex != i) {
            for (j = 0; j < n; j++) {
                temp = A[i][j];
                A[i][j] = A[maxIndex][j];
                A[maxIndex][j] = temp;
            }

            temp = B[i];
            B[i] = B[maxIndex];
            B[maxIndex] = temp;
        }
    }
}

void solicitar_matriz(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"Ingrese los valores en la matriz de coeficientes (A) A["<<i<<"]["<<j<<"]: ";
            cin>> A[i][j];
            cout<<"\n";
        }
    }

    B = new float[n];

    for(int i=0; i<n; i++){
        cout<<"Ingrese el vector de resultados (B)["<<i<<"]: ";
        cin>> B[i];
        cout<<"\n";
    }

    aprox = new float [n]; 
    for(int i=0; i<n; i++){
        cout<<"Ingrese las aproximaciones iniciales: X0 (ingrese y presione enter):";
        cin>> aprox[i];
        cout<<"\n";
    }

    aprox_anterior = new float[n];

    for(int i=0; i<n; i++){
        suma = 0;
        for(int j=0; j<n; j++){
            if(i == j){
                dd = A[i][j]; 
            }else{
                suma += abs(A[i][j]);
            }
        }
        if(dd > suma){
            cont++;
        }
    }

    if(cont == n){
        cout<<"El sistema es diagonalmente dominante"<<endl;
    }else{
        cout<<"El sistema no es diagonalmente dominante, se ajustará la la matriz"<<endl;
        ajustar_matriz(A, B, n);
        cout<<"Matriz ajustada"<<endl;
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<A[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

}


void ejecutar_jacobi(){
    int k; 
    float xi[n];
    for(k = 1; k < IT; k++){
        for(int i = 0; i < n; i++){
            aprox_anterior[i] = xi[i];
        }

        for(int i=0; i<n; i++){
            suma = 0; 
            for(int j=0; j<n;j++){
                if(j != i){
                    suma += A[i][j] * aprox_anterior[j];
                }
            }
            xi[i] = (B[i] - suma) / A[i][i];
        }

        printf("Iteracion %d:\n", k);
        for (int i = 0; i < n; i++) {
            printf("x[%d] = %4.15f\n", i, xi[i]);
        }
        printf("\n");

        // Cálculo del error
        error = 0;
        for (int i = 0; i < n; i++) {
            error += fabsf(xi[i] - aprox_anterior[i]);
        }

        if(error < TOL){
            break;
        }
    }
    if(k == IT){
        printf("El metodo no convergio despues de %d iteraciones.\n", k);
    }else{
        printf("La solucion aproximada despues de %d iteraciones es:\n", k);
        for (int i = 0; i < n; i++) {
            printf("x[%d] = %f\n", i, xi[i]);
        }

    }
}

int main(){
    solicitar_datos();
    solicitar_matriz();
    ejecutar_jacobi();
    return 0;
}