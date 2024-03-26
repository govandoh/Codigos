#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <cassert>

using namespace std;
/*  Gerardo Antonio Ovando Hernandez 9490-21-7 Sección: A 
    Metodos Numéricos - TAREA 07 - METODO REGULAR FALSI 
    Fecha: 26-03-2024
*/

int i, IT; 
float p0, p1, p, q0, q1, q, TOL; 

float f(float x){
    return powf(x,3) - 2*x - 5; 
}

void solicitar_datos(){
    cout<<"Ingrese p0: "; 
    cin>> setprecision(15) >> p0;
    cout<<"Ingrese p1: "; 
    cin>> setprecision(15) >> p1;
    cout<<"Ingrese TOL: "; 
    cin>> setprecision(15) >> TOL;
    cout<<"Ingrese Ingrese IT: "; 
    cin>> setprecision(15) >> IT;
    cout<<" "; 
}



void datos_iteracion(int i, float q0, float q1, float p0, float p1, float p){
    cout<< fixed << setprecision(15);
    cout << i << "\t" << q0 << "\t" << q1 << "\t" << p0 << "\t"  << p1 << "\t" << p << "\t" << f(p) << "\t" << fabsf(p - p1) << endl; 
}

void ejecutar_falsi(){
    i = 2; 
    q0 = f(p0);
    q1 =  f(p1);
    cout << fixed << setprecision(15); 
    cout << setw(2) << "i" << setw(15) << "q0" << setw(25) << "q1" << setw(23) << "Po" << setw(23) << "P1" << setw(23) << "p" << setw(30) << "q => f(p)" << setw(23) << "Error" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    while(i <= IT){
        p = (p1) -  (q1 * (p1 - p0)) / (q1 - q0);
        if(fabsf(p - p1) < TOL){
            datos_iteracion(i, q0, q1, p0, p1, p); 
            printf("\n");
            printf("El método fue exitoso, se encotró la raiz: \n");
            printf("Iteraciones: %i \n", i); 
            printf("q0 = %4.15f \n", q0);
            printf("q1 = %4.15f \n", q1);
            printf("p0 = %4.15f \n", p0);
            printf("p1 = %4.15f \n", p1);
            printf("P = %4.15f \n", p); 
            printf("f(%4.15f) o q = %4.15f \n", p, f(p)); 
            printf("Error = %4.15f \n", fabsf(p - p1)); 
            printf("\n");
            break;
        }else {
            datos_iteracion(i, q0, q1, p0, p1, p);
        }
        i = i + 1; 
        q = f(p);

        if((q * q1) < 0){
            p0 = p1; 
            q0 = q1; 
        }
        p1 = p; 
        q1 = q;
    }

    if(i >= IT){
        printf("El método fracasó, no se encontró la raiz aproximada \n");
    }
}

int main() {
    solicitar_datos();
    ejecutar_falsi();
    return 0;
}