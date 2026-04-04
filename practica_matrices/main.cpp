///////////////////////////////////////////
/// DALE UNA ESTRELLA AL REPO SI TE SIRIVIÓ
///////////////////////////////////////////

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#include <iostream>
using namespace std;


void cuboMagico() {
    int n;
    cout << "Ingrese el orden del cubo magico (numero impar): ";
    cin >> n;

    // Verificamos que n sea impar
    if (n % 2 == 0) {
        cout << "El orden debe ser impar." << endl;
        return;
    }

    // Creamos la matriz y la llenamos con ceros
    int mat[20][20] = {};

    // Empezamos colocando el 1 en la fila 0, columna del medio
    int fila = 0;
    int col = n / 2;

    // Colocamos los numeros del 1 al n*n
    for (int num = 1; num <= n * n; num++) {
        mat[fila][col] = num;

        // Calculamos la siguiente posicion: arriba y a la derecha
        int nuevaFila = (fila - 1 + n) % n;  // si nos salimos por arriba, volvemos abajo
        int nuevaCol  = (col + 1) % n;        // si nos salimos por la derecha, volvemos a la izquierda

        // Si esa posicion ya esta ocupada, bajamos una fila en vez de subir
        if (mat[nuevaFila][nuevaCol] != 0) {
            fila = (fila + 1) % n;
            // la columna no cambia en este caso
        } else {
            fila = nuevaFila;
            col  = nuevaCol;
        }
    }

    // Mostramos la matriz
    cout << "\nCubo magico de orden " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}


void matrizPotencias() {
    int n = 5;
    int mat[5][5];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // El valor depende del minimo entre la fila y la columna
            int menor = (i < j) ? i : j;

            // Calculamos 2^menor a mano con un bucle sencillo
            int valor = 1;
            for (int k = 0; k < menor; k++) {
                valor *= 2;
            }

            mat[i][j] = valor;
        }
    }

    cout << "\nMatriz de potencias de 2:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

// Esta matriz se llena en forma de serpiente:
// fila 0 va de izquierda a derecha: 1,2,3,4,5
// fila 1 va de derecha a izquierda: 10,9,8,7,6
// fila 2 va de izquierda a derecha: 11,12,13,14,15
// y asi sucesivamente
void matrizSerpentina() {
    int n = 5;
    int mat[5][5];
    int num = 1;  // numero que vamos colocando

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // Fila par: llenamos de izquierda a derecha
            for (int j = 0; j < n; j++) {
                mat[i][j] = num;
                num++;
            }
        } else {
            // Fila impar: llenamos de derecha a izquierda
            for (int j = n - 1; j >= 0; j--) {
                mat[i][j] = num;
                num++;
            }
        }
    }

    cout << "\nMatriz serpentina:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}


void produccionLeche() {
    int n;
    cout << "Cuantas vacas tiene el hato: ";
    cin >> n;

    // Declaramos la matriz con maximo 100 vacas
    int leche[7][100];

    // Pedimos los datos: 7 dias, n vacas
    for (int dia = 0; dia < 7; dia++) {
        cout << "Dia " << dia + 1 << ":\n";
        for (int vaca = 0; vaca < n; vaca++) {
            cout << "  Litros de la vaca " << vaca + 1 << ": ";
            cin >> leche[dia][vaca];
        }
    }

    // Calculamos total por dia y vaca con mayor produccion
    for (int dia = 0; dia < 7; dia++) {
        int total = 0;
        int maxLitros = leche[dia][0];
        int vacaMax = 0;

        for (int vaca = 0; vaca < n; vaca++) {
            total += leche[dia][vaca];  // acumulamos el total del dia

            // Actualizamos si encontramos una vaca que produjo mas
            if (leche[dia][vaca] > maxLitros) {
                maxLitros = leche[dia][vaca];
                vacaMax = vaca;
            }
        }

        cout << "Dia " << dia + 1 << ": total=" << total
             << " litros | vaca con mas produccion: vaca " << vacaMax + 1
             << " con " << maxLitros << " litros\n";
    }
}

// Cinco operaciones sobre una matriz NxN, solo es un ejemplo
// en una sola función, puedes hacer esta función más pequeña o con una
// solución mejor
void recorridosMatriz() {
    int n;
    cout << "Ingrese N para la matriz NxN: ";
    cin >> n;

    int mat[20][20] = {};

    // --- Operacion 1: poner cero en ambas diagonales ---
    for (int i = 0; i < n; i++) {
        mat[i][i] = 0;         // diagonal principal: fila y columna iguales
        mat[i][n - 1 - i] = 0; // diagonal secundaria: fila i, columna n-1-i
    }
    cout << "\nDiagonales en cero:\n";
    // (primero llenamos la matriz con valores para ver el efecto)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = i * n + j + 1;  // llenamos con 1..n*n
    for (int i = 0; i < n; i++) {
        mat[i][i] = 0;
        mat[i][n - 1 - i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << "\t";
        cout << endl;
    }

    // --- Operacion 2: poner cero en bordes (primera/ultima fila y columna) ---
    // Reiniciamos con valores
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = i * n + j + 1;

    for (int j = 0; j < n; j++) {
        mat[0][j] = 0;      // primera fila
        mat[n-1][j] = 0;    // ultima fila
    }
    for (int i = 0; i < n; i++) {
        mat[i][0] = 0;      // primera columna
        mat[i][n-1] = 0;    // ultima columna
    }
    cout << "\nBordes en cero:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << "\t";
        cout << endl;
    }

    // --- Operacion 3: mat[i][j] = i + j ---
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = i + j;
    cout << "\nmat[i][j] = i + j:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << "\t";
        cout << endl;
    }

    // --- Operacion 4: llenar diagonal principal con 1,2,3...N ---
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = 0;  // partimos de ceros

    for (int i = 0; i < n; i++)
        mat[i][i] = i + 1;  // en la diagonal: posicion i tiene el valor i+1
    cout << "\nDiagonal principal con 1..N:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << "\t";
        cout << endl;
    }

    // --- Operacion 5: filas pares con 1..N, filas impares con N..1 ---
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // fila par: va de 1 a N
            for (int j = 0; j < n; j++)
                mat[i][j] = j + 1;
        } else {
            // fila impar: va de N a 1
            for (int j = 0; j < n; j++)
                mat[i][j] = n - j;
        }
    }
    cout << "\nFilas pares 1..N, impares N..1:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << "\t";
        cout << endl;
    }
}

// La matriz se divide en 4 cuadrantes de n/2 x n/2
// cuadrante superior-izquierdo = 1
// cuadrante superior-derecho   = 2
// cuadrante inferior-izquierdo = 3
// cuadrante inferior-derecho   = 4
void matrizCuadrantes() {
    int n;
    cout << "Ingrese n (numero par): ";
    cin >> n;

    int mat[20][20];
    int mitad = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Determinamos en que cuadrante cae cada celda
            if (i < mitad && j < mitad)
                mat[i][j] = 1;  // arriba-izquierda
            else if (i < mitad && j >= mitad)
                mat[i][j] = 2;  // arriba-derecha
            else if (i >= mitad && j < mitad)
                mat[i][j] = 3;  // abajo-izquierda
            else
                mat[i][j] = 4;  // abajo-derecha
        }
    }

    cout << "\nMatriz de cuadrantes:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << "\t";
        cout << endl;
    }
}


// La matriz se llena columna por columna, de abajo hacia arriba
// Columna 0: 13,14,15,16 (de abajo a arriba)
// Columna 1:  9,10,11,12,etc
void matrizColumnas() {
    int n = 4;
    int mat[4][4];
    int num = 1;

    // Recorremos las columnas de derecha a izquierda
    // y dentro de cada columna de abajo a arriba
    for (int j = n - 1; j >= 0; j--) {
        for (int i = n - 1; i >= 0; i--) {
            mat[i][j] = num;
            num++;
        }
    }

    cout << "\nMatriz 5f (columnas de abajo a arriba):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << mat[i][j] << "\t";
        cout << endl;
    }
}

// Tenemos una matriz nxm y eliminamos la columna K
// Para eso, desplazamos todas las columnas que estan a la derecha de K hacia la izquierda

void eliminarColumna() {
    int n, m, k;
    cout << "Filas: "; cin >> n;
    cout << "Columnas: "; cin >> m;
    cout << "Columna a eliminar (0-indexado): "; cin >> k;

    int mat[10][10];

    cout << "Ingrese la matriz:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    // Desplazamos cada columna desde K+1 hasta el final, una posicion a la izquierda
    for (int i = 0; i < n; i++) {
        for (int j = k; j < m - 1; j++) {
            mat[i][j] = mat[i][j + 1];  // cada celda toma el valor de la celda a su derecha
        }
    }

    // Ahora la matriz tiene m-1 columnas utiles
    m = m - 1;

    cout << "\nMatriz sin la columna " << k << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << mat[i][j] << "\t";
        cout << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Cubo magico\n";
        cout << "2. Matriz de potencias de 2\n";
        cout << "3. Matriz serpentina (zigzag)\n";
        cout << "4. Produccion de leche de vacas\n";
        cout << "5. Recorridos especiales de matriz\n";
        cout << "6. Matriz de cuadrantes (5c)\n";
        cout << "7. Matriz por columnas de abajo a arriba (5f)\n";
        cout << "8. Eliminar columna\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: cuboMagico(); break;
            case 2: matrizPotencias(); break;
            case 3: matrizSerpentina(); break;
            case 4: produccionLeche(); break;
            case 5: recorridosMatriz(); break;
            case 6: matrizCuadrantes(); break;
            case 7: matrizColumnas(); break;
            case 8: eliminarColumna(); break;
        }
    } while (opcion != 0);

    return 0;
}

