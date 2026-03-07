#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Busqueda binaria
    /*
    int numeros[] = {3,7,2,5,6,4,9};
    sort(numeros, numeros + 7);

    // 1 opcion: binary_search(numeros, numeros + 7, 4);

    int indiceInicial = 0;
    int indiceFinal = (sizeof(numeros)/ sizeof(numeros[0])) - 1;
    // Bytes => 28bytes; // 6 = 28
    // sizeof(numeros)/ sizeof(numeros[0]) => 28 / 4 => 7 -1 => 6;
    int numeroObjetivo = 23;
    while(indiceInicial <= indiceFinal) {
        int medio = (indiceFinal - indiceInicial)/ 2;

        if(numeros[medio] == numeroObjetivo){
            cout << "Tu numero es este "<< numeroObjetivo ;
            break;
        }

        if(numeroObjetivo < numeros[medio]) {
            indiceFinal = medio -1;
        }else{
            indiceInicial = medio +1;
        }
    }
    */

    // Two Pointers => 2 punteros
    int numeros[] = {3,7,2,5,6,4,9};
    int sumaTotal = 16;
    int indiceInicial = 0; // 3
    int indiceFinal = (sizeof(numeros) / sizeof(numeros[0]))-1; // 9

    while(indiceInicial < indiceFinal) {
        // sumarNumeros = 3 + 9 => 12
        int sumarNumeros = numeros[indiceInicial] + numeros[indiceFinal];

        if(sumarNumeros == sumaTotal) {
            cout << "Numeros que sumados dan " << sumarNumeros << " son "
            << numeros[indiceInicial] << " y " << numeros[indiceFinal];
            break;
        }

        if(sumarNumeros < sumaTotal) {
            indiceInicial++;
        }else {
            indiceFinal--;
        }
    }


    return 0;
}
