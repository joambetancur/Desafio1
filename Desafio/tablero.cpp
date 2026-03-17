#include "tablero.h"
#include <iostream>

using namespace std;

void crearTablero(unsigned char** &tablero, int filas, int columnas) {
    tablero = new unsigned char*[filas];

    for (int i = 0; i < filas; ++i) {
        tablero[i] = new unsigned char[columnas];

        for (int j = 0; j < columnas; ++j) {
            tablero[i][j] = 0;
        }
    }
}

void imprimirEstado(unsigned char** tablero, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        cout << "|";
        for (int j = 0; j < columnas; ++j) {
            if (tablero[i][j] == 0) cout << ".";
            else cout << "#";
        }
        cout << "|" << endl;
    }
}