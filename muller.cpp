#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <cassert>

using namespace std;
/*  Gerardo Antonio Ovando Hernandez 9490-21-7 Sección: A 
    Metodos Numéricos - TAREA 05 - METODO MULLER 
    Fecha: 18-03-2024
*/

int i, IT; 
float x0, x1, x2, TOL, h, h1, h2, S1, S2, d, D, b, E, p; 


void solicitar_datos(){
    cout<<"Ingrese x0: "; 
    cin>> setprecision(15) >> x0;
    cout<<"Ingrese x1: "; 
    cin>> setprecision(15) >> x1;
    cout<<"Ingrese x2: "; 
    cin>> setprecision(15) >> x2;
    cout<<"Ingrese TOL: "; 
    cin>> setprecision(15) >> TOL;
    cout<<"Ingrese Ingrese IT: "; 
    cin>> setprecision(15) >> IT;
    cout<<" "; 
}

float f(float x){
    //return (-3 * powf(x,4)) - (5*powf(x,2)) + 4;
    //return pow(x,5) + 11*pow(x,4) - 21*pow(x,3) - 10*pow(x,2) - 21*x - 5;         //Inciso a
    //return pow(x,4) + pow(x,3) + 3 * pow(x,2) + 2*x + 2;                          //Inciso b
    //return pow(x,3) - 9*pow(x,2) + 12; 
    return  pow(x,3) - 13*x - 12 - (3.5);                                 // Ejemplo 2 proyecto
    //return (1.222222222)*powf(x,3) - (5.5)*x - 2;                           //Ejemplo 1 proyecto
}

void datos_iteracion(int i, float p){
    cout<< fixed << setprecision(15);
    cout << i << "\t" << p << "\t" << f(p) << "\t" << abs((p-x2)/p) << endl; 
}

void ejecutar_muller(){
    h1 = x1 - x0; 
    h2 = x2 - x1; 
    S1 = (f(x1) - f(x0)) / (h1);            //Declaración necesaria para sustituir y despejar para encontrar a y b
    S2 = (f(x2) - f(x1)) / (h2);            //Declaración necesaria para sustituir y despejar para encontrar a y b
    d = (S2 - S1) / (h2 + h1);              //Expresión despejada que representa a 
    i = 3; 

    cout << fixed << setprecision(15); 
    cout << setw(1) << "i" << setw(15) << "p" << setw(25) << "f(p)" << setw(28) << "Error Abs." << endl;

    while(i <= IT){
        b = S2 + (h2 * d);                          //Expresión despejada que representa b
        D = sqrtf(powf(b, 2) - 4*f(x2)*d);          //Se calcula el discriminante de la formula general de una parábola
        
        if(isnan(D)){
            cout << " \n El calculo de la siguiente D, genera un numero complejo, resultados obtenidos" << endl;
            cout << " \n Con los puntos iniciales, se encontró convergencia: " << endl;
            printf("Iteraciones: %i \n", i-1); 
            printf("P = %4.15f \n", p); 
            printf("f(%4.15f) = %4.15f \n", p, f(p)); 
            printf("Error absoluto = %4.15f \n", abs((p-x2)/p)); 
            printf("\n");
            break;;
        }
        
        
        if(fabsf(b - D) < fabsf(b + D)){
            E = b + D;      //Significa que la raíz se encuentra más hacia la derecha, entonces se toman los nuevos puntos hacia la derecha.
        }else{
            E = b-D;        //En cambio acá significa que la raíz se encuentra más hacia la izquierda, entonces se toman los nuevos puntos hacia la izquierda.
        }
        
        //Calculo del error 
        h = (- 2 * f(x2)) / E; 
        p = x2 + h;

        //Evaluo si se encontró la raíz o si se debe seguir iterando
        if(fabsf(h) < TOL){
            datos_iteracion(i,p); 
            printf("\n");
            printf("El método fue exitoso, se encotró la raiz: \n");
            printf("Iteraciones: %i \n", i); 
            printf("P = %4.15f \n", p); 
            printf("f(%4.15f) = %4.15f \n", p, f(p)); 
            printf("Error absoluto = %4.15f \n", fabsf((p-x2)/p)); 
            printf("\n");
            break;
        }

        // Se preparan las variables para la siguiente iteración
        datos_iteracion(i,p);
        x0 = x1; 
        x1 = x2; 
        x2 = p; 
        h1 = x1 - x0; 
        h2 = x2 - x1; 
        S1 = (f(x1) - f(x0)) / (h1); 
        S2 = (f(x2) - f(x1)) / (h2);
        d = (S2 - S1) / (h2 + h1);
        i = i + 1;
        
    }

    if(i >= IT){
        printf("El método fracasó, no se encontró la raiz aproximada \n");
    }
}

int main(){
    solicitar_datos();
    ejecutar_muller(); 
    return 0; 
}