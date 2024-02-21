#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iomanip>
using namespace std; 

int i, IT; 
float TOL, p, po; 

//Metodo para evaluar f()
float f(float x){
    //return pow(x,4) - 3 * pow(x,2) - 3;
    return pow(x,3) + (4)*pow(x,2) - 10;
}

//Metodo para evaluar g(po)
float g(float x){
    //return sqrtf(6 + 2*sqrt(21))/(2);             //Inciso 1 -> Transformacion 1
    //return powf((3 * powf(x,2) + 3),(0.25));      //Inciso 1 -> Transformacion 2
    
    //return   (0.5) * sqrt(10 + powf(-x,3));        //Inciso 2 -> Transformacion 1 x (0.5) * (10 - x^3)^1/2
    return sqrtf((10)/(4+x));                     //Inciso 2 -> Transformacion 2 x = (10/4+x)^1/2
}

//Metodo para mostrar los datos por cada iteración de manera de tabla
void datos_iteracion(int i, float po, float p){
    cout<< fixed << setprecision(15);
    cout << i << "\t" << po << "\t" <<  p << "\t " << f(p) << "\t" << fabsf((p - po)/p) << "\t" << fabsf(p - po) << endl; 
}

//Metodo para solicita datos
void solicitar_datos(){
    cout<<"Ingrese Po: "; 
    cin>> setprecision(15) >> po;
    cout<<"Ingrese TOL: "; 
    cin>> setprecision(15) >> TOL;
    cout<<"Ingrese Ingrese IT: "; 
    cin>> setprecision(15) >> IT;
    cout<<" "; 
}

//Metodo que ejecuta el algotirmo de biseccion
void ejecutar_puntoF(){
    i = 1;
    cout << fixed << setprecision(15); 
    cout << "   Iteracion    |      Po      |       p -> g(po)      |       f(p)        |       Error Absoluto      |       Error relativo      |\n";
    cout << "--------------------------------------------------------------------------------------------------- \n";
    do{ 
        p = g(po); 
        if( abs(p - po) < TOL){
            datos_iteracion(i,po,p);
            printf("\n");
            printf("El método fue exitoso, se encotró la raiz: \n");
            printf("Iteraciones: %i \n", i); 
            printf("Po = %4.15f \n", po); 
            printf("P = %4.15f \n", p); 
            printf("f(%4.15f) = %4.15f \n", p, f(p)); 
            printf("Error absoluto = %4.15f \n", fabsf((p-po)/p)); 
            printf("Error relativo = %4.15f \n", fabsf((p - po)));
            printf("\n");
            break;
        }else{
            datos_iteracion(i, po, p); 
            i = i +1; 
            po = p; 
        }
    }while( (i <= IT)); 

    //Compruebo si hubo fracaso 
    if(i >= IT){
        printf("El método fracasó, no se encontró la raiz, con la transformación seleccionado \n");
        printf("Iteraciones: %i \n", i); 
        printf("Po = %4.15f \n", po); 
        printf("P = %4.15f \n", p); 
        printf("f(%4.15f) = %4.15f \n", p, f(p)); 
        printf("Error absoluto = %4.15f \n", fabsf((p-po)/p)); 
        printf("Error relativo = %4.15f \n", fabsf((p - po))); 
    }   
}

int main(){
    solicitar_datos(); 
    ejecutar_puntoF();
    return 0; 
}
