#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;

int i, IT; 
float TOL, p, po; 

float f(float x){
    //return -(pow(x,3)) - cos(x);
    //return pow(x,3) - 2*(x)-5; Ejercicio prueba corta
    //return pow(x,4) - 3*pow(x,2) - 3;                 //Inciso 1 tarea
    //return pow(x,3) - 2 * pow(x,2) -5;                  //Inciso 2 tarea
    //return pow(2,x) - 6 * cos(x);                       //Inciso 3 tarea
    //return 230*pow(x,4) + 18*pow(x,3)+ 9*pow(x,2) - 221*x - 9;

    return powf(2,x) - 6 * cosf(x);                    //Inciso 2 - Tarea 5
}

float derivada(float x){
    //return  -3 * powf(x,2) + sinf(x);
    //return (3) * powf(x,2)-2;  Ejercicio prueba corta
    //return 4 * powf(x,3) -6*x;                        //Inciso 1 tarea
    //return 3 * pow(x,2) - 4*x;                          //Iniciso 2 tarea
    //return (pow(2,x)*log(2)) + 6 * sin(x);              //Inciso 3 tarea
    //return 920*powf(x,3) + 54*powf(x,2) + 18*x - 221;

    return log(2) * powf(2,x) + 6 * sinf(x);        // Inciso 2 - Tarea 5 
}


void datos_iteracion(int i, float po, float p){
    cout<< fixed << setprecision(15);
    cout << i << "\t" << po << "\t" << f(po) << "\t"  << p << "\t " << f(p) << "\t"  << fabsf((p-po)/p) << endl; 
}

void solicitar_datos(){
    cout<<"Ingrese Po: "; 
    cin>> setprecision(15) >> po;
    cout<<"Ingrese TOL: "; 
    cin>> setprecision(15) >> TOL;
    cout<<"Ingrese Ingrese IT: "; 
    cin>> setprecision(15) >> IT;
    cout<<" "; 
}

void ejecutar_raphson(){
    i = 1; 
    cout << fixed << setprecision(15); 
    cout << "i|     po      |       f(po)       |       p       |       f(p)        |       Error       |\n";
    cout << "--------------------------------------------------------------------------------------------\n";
    do{
        p = po - (f(po)/derivada(po));
        if (abs((p-po)/p) < TOL){
            //mostrar salida 
            datos_iteracion(i,po, p);
            printf("\n");
            printf("El método fue exitoso, se encotró la raiz: \n");
            printf("Iteraciones: %i \n", i); 
            printf("Po = %4.15f \n", po); 
            printf("P = %4.15f \n", p); 
            printf("f(%4.15f) = %4.15f \n", p, f(p)); 
            printf("Error absoluto = %4.15f \n", fabsf((p-po)/p)); 
            printf("\n");
            break;
        }else{
            datos_iteracion(i,po, p);
            i = i + 1; 
            po = p;
        }
    }while(i <= IT);

    if(i >= IT){
        printf("El método fracasó, no se encontró la raiz aproximada \n");
    }
}

int main(){
    solicitar_datos();
    ejecutar_raphson();
    return 0; 
}