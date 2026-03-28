#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    // EJERCICIO DEL ABECEDARIO
    int n;
    cin >> n;
    cin.ignore(); // limpiar salto de linea

    for(int i = 0; i < n; i++) {
        string frase;
        getline(cin, frase);

        bool letras[26] = {false};

        for(char c : frase) {
            if(c >= 'a' && c <= 'z') {
                letras[c - 'a'] = true;
            }
        }

        int contador = 0;
        for(int j = 0; j < 26; j++) {
            if(letras[j]) contador++;
        }

        if(contador == 26)
            cout << "frase completa" << endl;
        else if(contador >= 13)
            cout << "frase casi completa" << endl;
        else
            cout << "frase mal elaborada" << endl;
    }
    
    // suma de equivalentes
    int n;
    cin >> n;

    int arr[100];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }


    for(int i = 0; i < n; i++){

        int suma = 0;

        for(int j = 0; j < n; j++){
            if(i != j){
                suma = suma + arr[j];
            }
        }

        if(arr[i] == suma){
            cout << "Salida: " << arr[i];
            return 0;
        }
    }
    
    /*
    Ejercicio de contar espacios en blanco, saltos de linea, etc.
    */
    
    string texto, linea;
    int espacios = 0, digitos = 0, letras = 0, saltoLinea = 0;

    while(getline(cin, linea)&&!linea.empty()){
        texto+=linea + '\n';
    }
    
    for(char c : texto){

        if(c == ' ')
            espacios++;

        if(isdigit(c))
            digitos++;

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            letras++;

        if(c== '\n')
            saltoLinea++;
    }

    cout << "Espacios: " << espacios << endl;
    cout << "Digitos: " << digitos << endl;
    cout << "Letras: " << letras << endl;
    cout << "salto de linea: " << saltoLinea << endl;

    return 0;
}
