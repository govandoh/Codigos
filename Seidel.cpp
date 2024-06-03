#include <math.h> 
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

/*  Gerardo Antonio Ovando Hernandez 9490-21-7 Sección: A 
    Metodos Numéricos - TAREA 12 - METODO Gauss Seidel
    Fecha: 19-05-2024

    Algoritmo de Gauss Seidel, es un algortimo mejorado al algortimo de jacobi, ya que en este algoritmo, no se utilizan las aproximaciones anteriores, 
    en cambio el algoritmo, empieza a calcular sus nuevas aproxiamciones en base a las actuales. 
*/

#define MAX 100 // Define el número máximo de variables

// Función para implementar el método de Jacobi
void Seidel(float a[MAX][MAX], float b[MAX], float x[MAX], int n, float tol, int IT) {
    int i, j, k; // Variables para los bucles
    float sum, error; // Variables para calcular la suma y el error

    // Iteraciones de Gauss Seidel
    for (k = 0; k < IT; k++) {
        // Calcula la nueva solución
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum += a[i][j] * x[j];
                }
            }
            float x_new = (b[i] - sum) / a[i][i];
            error = 0;
            error += std::fabs(x_new - x[i]);
            x[i] = x_new;
        }

        // Imprime los valores de las variables en la iteración actual
        printf("Iteracion %d:\n", k+1);
        for (i = 0; i < n; i++) {
            printf("x[%d] = %4.15f\n", i, x[i]);
        }
        printf("\n");
        
        // Si el error es menor que la tolerancia, detener las iteraciones
        if (error < tol) {
            break;
        }
    }

    // Imprime si el método no convergió
    if (k == IT) {
        printf("El metodo no convergio despues de %d iteraciones.\n", IT);
    } else {
        // Imprime la solución aproximada
        printf("La solucion aproximada despues de %d iteraciones es:\n", k+1);
        for (i = 0; i < n; i++) {
            printf("x[%d] = %4.15f\n", i, x[i]);
        }
    }
}

//Funcion para hacer diagonalmente dominante la función
void hacerDiagonalDominante(float a[MAX][MAX], float b[MAX], int n) {
    int i, j, maxIndex;
    float maxVal, temp;

    for (i = 0; i < n; i++) {
        maxVal = a[i][i];
        maxIndex = i;

        // Encuentra el valor máximo en la fila i
        for (j = i+1; j < n; j++) {
            if (fabs(a[j][i]) > fabs(maxVal)) {
                maxVal = a[j][i];
                maxIndex = j;
            }
        }

        // Intercambia las filas i y maxIndex
        if (maxIndex != i) {
            for (j = 0; j < n; j++) {
                temp = a[i][j];
                a[i][j] = a[maxIndex][j];
                a[maxIndex][j] = temp;
            }

            temp = b[i];
            b[i] = b[maxIndex];
            b[maxIndex] = temp;
        }
    }
}

int main() {
    float a[MAX][MAX], b[MAX], x[MAX]; // La matriz de coeficientes, el vector de términos constantes y la solución aproximada
    int n; // Número de variables
    float tol, dd; // Tolerancia
    int IT, suma; // Número máximo de iteraciones
    int cont = 0;

    // Solicita al usuario que ingrese los datos
    printf("\n");
    printf("Ingrese el numero de ecuaciones: ");
    scanf("%d", &n);
    printf("Ingrese el numero de variables: ");
    scanf("%d", &n);
    printf("Ingrese los coeficientes de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("Ingrese los terminos constantes:\n");
    for (int i = 0; i < n; i++) {
        printf("b[%d] = ", i);
        scanf("%f", &b[i]);
    }
    printf("Ingrese los puntos iniciales:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
    }
    printf("Ingrese la tolerancia: ");
    scanf("%f", &tol);
    printf("Ingrese el numero maximo de iteraciones: ");
    scanf("%d", &IT);

    //valida si los numeros de la diagonal son mayores que su valor absoluto, y comprueba si el recorrido (cont) es > que suma, si es asi, no es diagonalmente dominante
    for(int i=0; i<n; i++){
        suma = 0;
        for(int j=0; j<n; j++){
            if(i == j){
                dd = a[i][j]; 
            }else{
                suma += abs(a[i][j]);
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
        cout<<"\n";
        // Reordena las filas de la matriz para que sea diagonalmente dominante
        hacerDiagonalDominante(a, b, n);
        cout<<"Matriz ajustada"<<endl;
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    

    // Llama a la función jacobi para resolver el sistema
    Seidel(a, b, x, n, tol, IT);

    return 0;
}