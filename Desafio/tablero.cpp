#include "tablero.h"
#include <iostream>

using namespace std;

void crearTablero(unsigned char** &tablero, int filas, int columnas) {
    tablero = new unsigned char*[filas];
    int bytesPorFila = columnas / 8;
    for (int i = 0; i < filas; ++i) {
        tablero[i] = new unsigned char[bytesPorFila];
        for (int j = 0; j < bytesPorFila; ++j) tablero[i][j] = 0;
    }
}

void modificarCelda(unsigned char** tablero, int x, int y, bool estado) {
    int bytePos = y / 8;
    int bitPos = 7 - (y % 8);

    if (estado) {
        tablero[x][bytePos] |= (1 << bitPos);
    } else {
        tablero[x][bytePos] &= ~(1 << bitPos);
    }
}

void imprimirEstado(unsigned char** tablero, int filas, int columnas) {
    int bytesFila = columnas / 8;
    for (int i = 0; i < filas; ++i) {
        cout << "|";
        for (int j = 0; j < bytesFila; ++j) {
            for (int bit = 7; bit >= 0; --bit) {
                if ((tablero[i][j] >> bit) & 1) cout << "#";
                else cout << ".";
            }
        }
        cout << "|" << endl;
    }
}

void liberarTablero(unsigned char** &tablero, int filas) {
    if (tablero == nullptr) return;
    for (int i = 0; i < filas; ++i) delete[] tablero[i];
    delete[] tablero;
    tablero = nullptr;
}

bool filaLlena(unsigned char** tablero, int fila, int columnas) {
    int bytesPorFila = columnas / 8;
    for (int j = 0; j < bytesPorFila; ++j) {
        if (tablero[fila][j] != 255) return false;
    }
    return true;
}

void eliminarFila(unsigned char** tablero, int fila, int columnas) {
    int bytesPorFila = columnas / 8;
    for (int i = fila; i > 0; --i) {
        for (int j = 0; j < bytesPorFila; ++j) {
            tablero[i][j] = tablero[i-1][j];
        }
    }
    for (int j = 0; j < bytesPorFila; ++j) tablero[0][j] = 0;
}

bool hayColision(unsigned char** tablero, int x, int y, int filas, int columnas) {
    if (x < 0 || x >= filas || y < 0 || y >= columnas) return true;

    int bytePos = y / 8;
    int bitPos = 7 - (y % 8);
    return (tablero[x][bytePos] >> bitPos) & 1;
}