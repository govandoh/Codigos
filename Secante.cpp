#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

using namespace std;
/*  Gerardo Antonio Ovando Hernandez 9490-21-7 Sección: A 
    Metodos Numéricos - TAREA 05 - METODO SECANTE 
    Fecha: 11-03-2024
*/

int i, IT; 
float po, p1, p,  TOL; 
float qo, q1;  

void solicitar_datos(){
    cout<<"Ingrese Po: "; 
    cin>> setprecision(15) >> po;
    cout<<"Ingrese P1: "; 
    cin>> setprecision(15) >> p1;
    cout<<"Ingrese TOL: "; 
    cin>> setprecision(15) >> TOL;
    cout<<"Ingrese Ingrese IT: "; 
    cin>> setprecision(15) >> IT;
    cout<<" "; 
}

float f(float x){
    //return log(powf(x,2) + 1) - expf(0.4*x) * cosf(x * M_PI);
    return powf(2,x) - 6 * cosf(x); 
    //return powf(x,2) - 6; 
}

void datos_iteracion(int i, float po, float p1, float qo, float q1, float p){
    cout<< fixed << setprecision(15);
    cout << i << "\t" << po << "\t" << p1 << "\t"  << qo << "\t " << q1 << "\t" << p << "\t" << f(p) << "\t" << fabsf((p-p1)/p) << endl; 
}

void ejecutar_secante(){
    i = 2; 
    qo =  f(po); 
    q1 =  f(p1);
    cout << fixed << setprecision(15); 
    cout << setw(4) << "i" << setw(15) << "po" << setw(20) << "p1" << setw(20) << "qo" << setw(25) << "q1" << setw(25) << "p" << setw(30) << "f(p)" << setw(30) << "Error Abs."  << setw(5) << endl;
    //cout << "i" << "\t" << "po" << "\t" << "p1" << "\t"  << "qo" << "\t " << "q1" << "\t" << "p" << "\t" << "f(p)" << "\t" << "Error Abs." << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    do{
        float numerador = (q1 * (p1 - po)); 
        float denominador = (q1 -qo); 
        p = p1 - (numerador/denominador); 
        if(abs((p-p1)) < TOL){
            datos_iteracion(i,po,p1,qo,q1,p);
            printf("\n");
            printf("El método fue exitoso, se encotró la raiz: \n");
            printf("Iteraciones: %i \n", i); 
            printf("p0 = %4.15f \n", po);
            printf("p1 = %4.15f \n", p1);
            printf("q0 = %4.15f \n", qo);
            printf("q1 = %4.15f \n", q1);
            printf("P = %4.15f \n", p); 
            printf("f(%4.15f) = %4.15f \n", p, f(p)); 
            printf("Error absoluto = %4.15f \n", fabsf((p-p1)/p)); 
            printf("\n");
            break;
        }else{
            datos_iteracion(i,po,p1,qo,q1,p);
            i = i + 1; 
            po = p1; 
            qo = q1;
            p1 = p;
            q1  = f(p); 
        }

    } while(i <= IT);

    if(i >= IT){
        printf("El método fracasó, no se encontró la raiz aproximada \n");
    }
}

int main(){
    solicitar_datos();
    ejecutar_secante(); 
    return 0; 
}