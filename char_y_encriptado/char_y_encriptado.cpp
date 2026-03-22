#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Primer ejercicio
    //HEY usando char;
    char h = 'H';
    char e = 'E';
    char y = 'Y';
    //cout << h << e << y;
    
    // Segundo ejercicio 
    // Convertir a ascii
    char v1='b';
    // 98 => en la computadora se está guardando el 98 
    // pero en binario => 00101
    
    /*cout << toascii(v1)<<endl;
    cout << int(v1);
    cout << v1 + 2;*/
    //Console.WriteLine();
    
    //Contar vocales con el uso de char
    // vocales = a, e, i, o, u;
    /* Pedir al usuario que ingrese una palabra y 
    tenemos que contar las vocales*/
    /*string palabra;
    cout << "Ingresa una palabra: ";
    cin >> palabra;
    int contador = 0;
    char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
    
    for(int i=0; i < palabra.size(); i++) {
        for(int j=0; j < 5; j++) {
            if(palabra[i] == vocales[j]){
                contador++;
            }
        }
    }
    
    cout <<"Cantidad de vocales: " << contador;
    */
    
    /*
        Contar mayúsculas, minúsculas y números
    */
    
    /*string palabra;
    cout << "Ingrese la palabra: ";
    cin >> palabra;
    int numeros = 0, mayusc = 0, minusc=0;
    for(int i=0; i < palabra.size(); i++){
        if(palabra[i] >= 'A' && palabra[i] <= 'Z'){
            mayusc++;
        }
        
        if(palabra[i] >= 'a' && palabra[i] <= 'z'){
            minusc++;
        }
        
        if(isdigit(palabra[i])){
            numeros++;
        }
    }
    
    //cout<< "Mayusculas " << mayusc << " Minusculas " << minusc << " Numeros " << numeros;
    */
    // Invertir mayúsculas/minúsculas
    /*string palabra = "TAZAB"; // taza
    string resultado;
    
    for(int i=0; i < palabra.size(); i++) {
        if(palabra[i] >= 'A' && palabra[i] <= 'Z'){
            // i = 0
            // resultado = 't'
            // i=1
            // resultado = 'ta'
            // i=2
            // resultado = 'taz'
            
            // resultado = tolower(palabra[i]);
            //i =0;
            // resultado = t;
            // i=1;
            // resultado = a;
           resultado += tolower(palabra[i]);
        }
        
        if(palabra[i] >= 'a' && palabra[i] <= 'z'){
             // detectando minusculas
             resultado += toupper(palabra[i]);
        }
    }
    
    cout << resultado; 
    */
    
    //CIFRADO CÉSAR
    // c => 2 espacios atras => a
    string palabra;
    cout << "palabra: ";
    cin >> palabra;
    
    int desplazamiento;
    cout << "Desplazamiento: ";
    cin >> desplazamiento;
    
    string encriptado;
    
    for(int i=0; i < palabra.size(); i++) {
        char caracterActual = palabra[i];
        if(caracterActual >= 'a' && caracterActual <= 'z'){
            encriptado += (caracterActual - 'a' + desplazamiento) % 26 + 'a';
        }
        
    }
    
    cout << encriptado;

    return 0;
}