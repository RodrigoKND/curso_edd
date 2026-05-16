#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//1 listas enlazadas simples
struct NodoEdad {
    int edad;
    NodoEdad* siguiente = nullptr;
};

void listaEnlazadaSimple() {
    //1. Pedir datos al usuario
    int edad1;
    cout << "Ingresa tu edad: ";
    cin >> edad1;

    NodoEdad* nodo1 = new NodoEdad();
    nodo1->edad = edad1;

    //cout << nodo1->edad << " " << nodo1->siguiente << '\n';

    int edad2;
    cout << "Ingresa tu edad: ";
    cin >> edad2;
    NodoEdad* nodo2 = new NodoEdad();
    nodo2->edad = edad2;
    nodo1->siguiente = nodo2;

    /*cout << nodo1->edad << " - " << nodo1->siguiente<<'\n';
    cout << nodo2->edad << " - " << nodo2->siguiente<<'\n';

    cout << nodo1->siguiente->edad << " - " << nodo1->siguiente->siguiente;*/

    /*
        nodo1: {
            edad: 23,
            siguiente: {
                edad: 34,
                siguiente: nullptr
            }
        }
    */

    NodoEdad* nodoActual = nodo1;
    /*
        {
            edad: 23,
            siguiente:
            nodoActual = {
                edad: 34,
                siguiente: nullptr
            }
            nodoActual = nullptr
        }
    */

    while(nodoActual!= nullptr){
        cout << nodoActual->edad << '\n'; // 23 34
        nodoActual = nodoActual->siguiente;
    }
}

//2 Crear una playlist de spotify con listas enlazadas
struct Playlist {
    int id;
    string nombrePlaylist = "Mi playlist #1";
    string cancion;
    string artista;
    Playlist* siguiente = nullptr;
};

//3 Completar el código de la anterior clase
int main()
{
    int cantidadCancionesAMostrar = 3;

    cout<< "El nombre de la Playlist por default es: Mi playlist #1"<<endl;
    char opcionUsuarioCrearPlaylist;
    cout << "Quieres mantener el nombre por defecto o crear uno nuevo? (s/n): " <<endl;
    cin >> opcionUsuarioCrearPlaylist;
    // S s
    cin.ignore();

    string nombrePlaylist = "Mi playlist #1";

    if(tolower(opcionUsuarioCrearPlaylist) == 'n') {
        cout << "Escribe tu propio nombre de la playlist: "<<endl;
        getline(cin, nombrePlaylist);
    }

    Playlist* cabeza = nullptr;
    Playlist* ultimo = nullptr;
    int IDPLAYLIST = 1;
    while(cantidadCancionesAMostrar--) {
        string cancion, artista;
        cout << "Escribe tu cancion: ";
        getline(cin, cancion);
        cout << endl;
        cout << "Escribe tu artista: ";
        getline(cin, artista);

        Playlist* nuevaCancionPorElUsuario = new Playlist();
        nuevaCancionPorElUsuario->id = IDPLAYLIST++;
        nuevaCancionPorElUsuario->nombrePlaylist = nombrePlaylist;
        nuevaCancionPorElUsuario->cancion = cancion;
        nuevaCancionPorElUsuario->artista = artista;

        if(cabeza == nullptr) {
            cabeza = nuevaCancionPorElUsuario;
            ultimo = cabeza;
        }else {
            ultimo->siguiente = nuevaCancionPorElUsuario;
            ultimo = nuevaCancionPorElUsuario;
        }
    }

    Playlist* cancionActual = cabeza;
    while(cancionActual!= nullptr) {
        cout << "ID: " << cancionActual->id
        << " | " << cancionActual ->cancion
        << " - " << cancionActual->artista << '\n';

        cancionActual = cancionActual->siguiente;
    }

    int IDCANCIONSELECCIONADA;
    cout << "Escribe el id de la canción que quieres mover arriba: ";
    cin >> IDCANCIONSELECCIONADA; // 3

    Playlist* buscarCancionActual = cabeza;
    /*
        {
            id: 1,
            cancion: Baile Inolvidable,
            artista: Bad Bunny,
            ...
            siguiente: {
                id: 2, // 2 == 3
                ...
                buscarCancionActual = siguiente: {
                    id: 3, // 3==3
                    cancion: "Chica Vacilona"
                    artista: Turromantikos
                    siguiente: {
                        id: 4,
                        siguiente: nullptr
                    }
                }
            }
        }

    */

    while(buscarCancionActual->siguiente->id != IDCANCIONSELECCIONADA) {
        buscarCancionActual = buscarCancionActual->siguiente;
    }

    /*
    buscarCancionActual =
                    artista: Turromantikos
                    siguiente: null
                }

    */

    Playlist* NodoSeleccionado = buscarCancionActual->siguiente;
    Playlist* NodoTemporal = buscarCancionActual->siguiente->siguiente;

    buscarCancionActual->siguiente = NodoTemporal;
    NodoSeleccionado->siguiente = cabeza;

    cabeza = NodoSeleccionado;

    Playlist* cancionActualX = cabeza;
    while(cancionActualX!= nullptr) {
        cout << "ID: " << cancionActualX->id
        << " | " << cancionActualX ->cancion
        << " - " << cancionActualX->artista << '\n';

        cancionActualX = cancionActualX->siguiente;
    }

    return 0;
}
