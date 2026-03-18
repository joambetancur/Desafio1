#include "tablero.h"
#include <iostream>

using namespace std;

void crearTablero(unsigned char** &tablero, int filas, int columnas) {
    tablero = new unsigned char*[filas];

    int bytesPorFila = columnas / 8;

    for (int i = 0; i < filas; ++i) {
        tablero[i] = new unsigned char[bytesPorFila];
        for (int j = 0; j < bytesPorFila; ++j) {
            tablero[i][j] = 0;
        }
    }
}

void imprimirEstado(unsigned char** tablero, int filas, int columnas) {
    int bytesPorFila = columnas / 8;

    for (int i = 0; i < filas; ++i) {
        cout << "|";
        for (int j = 0; j < bytesPorFila; ++j) {
            for (int bit = 7; bit >= 0; --bit) {
                if ((tablero[i][j] >> bit) & 1) {
                    cout << "#";
                } else {
                    cout << ".";
                }
            }
        }
        cout << "|" << endl;
    }
}

void liberarTablero(unsigned char** &tablero, int filas) {
    if (tablero != nullptr) {
        for (int i = 0; i < filas; ++i) {
            delete[] tablero[i];
        }
        delete[] tablero;
        tablero = nullptr;
    }
}