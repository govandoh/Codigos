#include <iostream>
#include <iomanip> 
using namespace std;

/*  Gerardo Antonio Ovando Hernandez 9490-21-7 Sección: A 
    Metodos Numéricos - TAREA 07 - METODO LAGRANGE 
    Fecha: 09-04-2024
*/

int n;
float *colX, *colY, xint, fxint, valor; 

void solicitar_datos(){
    cout << "Ingrese la cantidad de datos: ";
    cin >> n;

    cout << "Ingrese el valor a interpolar xint: ";
    cin >> xint;

    colX = new  float[n];
    colY = new   float [n];
    for(int i=0; i<n; i++){
        printf("Ingrese x(%3d), y(%3d): ", i,i); 
        scanf("%f,%f", &colX[i],&colY[i]); 
    }
    
}

void ejecutarNeville(){
    float Q[100][100];
    valor = 0; 

    for (int i = 0; i < n; i++) {
        Q[i][i] = colY[i]; 
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j <= n - i; j++) { 
            Q[j][j + i] = ((xint - colX[j]) * Q[j + 1][j + i] - (xint - colX[j + i]) * Q[j][j + i - 1]) / (colX[j + i] - colX[j]);
        }
    }
    valor = Q[0][n-1];
    printf("Resultado a la interpolación del polinomio xint=%f es fxint: %4.15f \n", xint, valor);
}

int main(){
    solicitar_datos(); 
    ejecutarNeville();
    return 0;
}
