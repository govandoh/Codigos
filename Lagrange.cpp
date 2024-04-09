#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;
/*  Gerardo Antonio Ovando Hernandez 9490-21-7 Sección: A 
    Metodos Numéricos - TAREA 07 - METODO LAGRANGE 
    Fecha: 09-04-2024
*/

int i, j, n;
float v, valor, z; 
float *filaX; 
float *filaY; 

void solicitar_datos(){
    cout<<"Ingrese n: "; 
    cin>> n;
    filaX = new  float[n];
    filaY = new   float [n];
    for(i=0; i<n; i++){
        printf("Ingrese x(%3d), y(%3d): ", i,i); 
        scanf("%f,%f", &filaX[i],&filaY[i]); 
    }
    cout<<"Ingrese el valor z (valor de x  para evaluar la función): "; 
    cin >> z; 
    cout<<" "; 
}


void ejecutar_lagrange(){
    valor = 0; 
    for(i = 0; i < n; i++){
        v = filaY[i]; 
        for(j = 0; j < n; j++){
            if(i != j){
                v = v * (z - filaX[j]) / (filaX[i] - filaX[j]);  
            }
        }
        valor = valor + v;
        //printf("\n valor = %4.10f \n", valor);
        cout<<" ";
    }
    printf("Resultado a la interpolación del polinomio z=%f es: %4.15f \n", z, valor);
}

int main(){
    solicitar_datos();
    ejecutar_lagrange(); 
    return 0; 
}