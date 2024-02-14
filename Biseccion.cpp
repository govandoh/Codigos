#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <cmath>
using namespace std; 
/* Gerardo Antonio Ovando Hernandez Carnet: 9490-21-7 
	Metodos Numericos 	Seccion: A 
	Codigo fuente del metodo: Biseccion */

int i, IT; 
double a, b, p, FA, FP, TOL; 


double f(double x){
	//return x-pow(2,-x); 	//Inciso 1
	//return exp(x) - pow(x,2) + (3)*(x) - 2; //Inciso 2
	//return (2*x) * (cos(x)) - pow((x+1),2);  //Inciso 3
	return (x) * cos(x) - pow(2*x,2) + (3)*(x) - 1;  //Inciso 4
}

//Metodo para mostrar en forma de tabla cada iteración
void datos_tabla(int i, double a, double b, double p, double FP) {
    // Muestra los datos de cada iteracion
    cout<< fixed << setprecision(15); // Hace que la precision decimal sea establecida 
	cout << i << "\t" << a << "\t" << b << "\t" << p << "\t" << FP << "\t" << abs((b - a) / 2) << endl;
}


void solicitar_datos_iniciales(){
	printf("Ingrese el intervalo [a,b]: \n"); 
	printf("Ingrese el limite inferior a:");						//Solicito el valor de a
	cin >> setprecision(15) >> a; 									//Leo el valor de a
	printf("Ingrese el limite superior b:");		
	cin >> setprecision(15) >> b; 									//Leo el valor de b
	printf("Ingrese la Tolerancia (TOL):");	
	cin >> setprecision(15) >> TOL; 								//Leo el valor de la tolerencia
	printf("Ingrese la cantidad maxima de iteraciones (IT):");
	cin >> setprecision(15) >> IT; 									//Leo la cantidad maxima de iteraciones
}

void ejecutar_biseccion(){ 
	FA = f(a);
	i = 1;
	cout << "Iteracion |     a     |    b    |     p   |     F(p)    |  Error \n";
    cout << "-------------------------------------------------------------------------- \n";
	do{
		p = (a+b)/2; 			// calculamos el valor de p_i (valor de p en cada iteracion i) 
		FP = f(p);				// calculamos el valor de la funciona en el punto p 
		 
		if( FP==0 || std::abs((b-a)/2) < TOL){
			datos_tabla(i,a,b,p,f(p)); //imprimo la ultima linea donde la iteracion de exito
			printf("\nExito, se aproximacion alcanzada \n"); 
			printf("Iteraciones necesarias: %i \n",i);  	// muestra el numero de iteraciones necesarias
			printf("Intervalo [%4.15f, %4.15f] \n", a, b); 	// muestra el intervalo final 
			printf("Valor de p = %4.15f \n", p); 			// muestra el valor del punto p, final 
			printf("f(%4.15f) = %4.15f \n" , p, f(p) ); 	// muestrs valor de f(p), final
			printf("Error: %4.15f \n", fabs((b-a)/2)); 	// muestra el Error en la ultima iteracion
			break;
		}
		
		datos_tabla(i,a,b,p,f(p)); 
		i = i + 1; 
		if(FA * FP > 0){
			a = p; 
			FA = FP; 
		}else{
			b = p;
		}
	}while((i <= IT) );

	if(i > IT){
		cout << "El metodo fracaso despues de " << IT << "iteraciones";
		printf("Iteraciones: %i \n",i);  	// muestra el numero de iteraciones necesarias
		printf("Intervalo [%4.15f, %4.15f] \n", a, b); 	// muestra el intervalo final 
		printf("Valor de p = %4.15f \n", p); 			// muestra el valor del punto p, final 
		printf("f(%4.15f) = %4.15f \n" , p, f(p) ); 	// muestrs valor de f(p), final
		printf("Error: %4.15f \n", fabs((b-a)/2)); 	// muestra el Error en la ultima iteracion
	}
}

int main(int argc, char** argv) {
	solicitar_datos_iniciales(); 
	ejecutar_biseccion();
}
