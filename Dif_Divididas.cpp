#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int n, i, j, m;
    float x[100], f[100], xint, fxint, p;

    cout << "Ingrese la cantidad de datos: ";
    cin >> n;

    cout << "Ingrese los datos (xi, f(xi)):" << endl;
    for (i = 0; i < n; i++) {
        cin >> x[i] >> f[i];
    }

    cout << "Ingrese el valor a interpolar xint: ";
    cin >> xint;

    // Inicializar matriz T
    float T[100][100];

    // Cargar la primera columna de la tabla de diferencias divididas
    m = n - 1;
    for (i = 0; i <= m; i++) {
        T[i][0] = f[i];
    }

    // Calcular las diferencias divididas restantes
    for (j = 1; j <= m; j++) {
        for (i = 0; i <= m - j; i++) {
            T[i][j] = (T[i + 1][j - 1] - T[i][j - 1]) / (x[i + j] - x[i]);
        }

        cout << "a" << j << " = " << T[0][j]<< endl;
    }

    // Calcular f(xint) usando el polinomio interpolante de Newton
    fxint = T[0][0];
    p = 1;
    for (i = 1; i <= m; i++) {
        p *= (xint - x[i - 1]);
        fxint += T[0][i] * p;
    }

    cout << fixed << setprecision(15);
    cout << "f(xint) = " << fxint << endl;

    return 0;
}
