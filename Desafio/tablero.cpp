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
    if (estado)
        tablero[x][bytePos] |= (1 << bitPos);
    else
        tablero[x][bytePos] &= ~(1 << bitPos);
}

bool leerCelda(unsigned char** tablero, int x, int y, int f, int c) {
    if (x < 0 || x >= f || y < 0 || y >= c) return true;
    int bytePos = y / 8;
    int bitPos = 7 - (y % 8);
    return (tablero[x][bytePos] >> bitPos) & 1;
}

Pieza generarPieza(int ancho) {
    Pieza p;
    p.tipo = rand() % 7;
    int s = ancho / 2 - 1;
    switch(p.tipo) {
    case 0: p.x[0]=0;p.y[0]=s; p.x[1]=1;p.y[1]=s; p.x[2]=2;p.y[2]=s; p.x[3]=3;p.y[3]=s; break; // I
    case 1: p.x[0]=0;p.y[0]=s; p.x[1]=0;p.y[1]=s+1; p.x[2]=1;p.y[2]=s; p.x[3]=1;p.y[3]=s+1; break; // O
    case 2: p.x[0]=0;p.y[0]=s+1; p.x[1]=1;p.y[1]=s; p.x[2]=1;p.y[2]=s+1; p.x[3]=1;p.y[3]=s+2; break; // T
    case 3: p.x[0]=0;p.y[0]=s+1; p.x[1]=0;p.y[1]=s+2; p.x[2]=1;p.y[2]=s; p.x[3]=1;p.y[3]=s+1; break; // S
    case 4: p.x[0]=0;p.y[0]=s; p.x[1]=0;p.y[1]=s+1; p.x[2]=1;p.y[2]=s+1; p.x[3]=1;p.y[3]=s+2; break; // Z
    case 5: p.x[0]=0;p.y[0]=s; p.x[1]=1;p.y[1]=s; p.x[2]=1;p.y[2]=s+1; p.x[3]=1;p.y[3]=s+2; break; // J
    case 6: p.x[0]=0;p.y[0]=s+2; p.x[1]=1;p.y[1]=s; p.x[2]=1;p.y[2]=s+1; p.x[3]=1;p.y[3]=s+2; break; // L
    }
    return p;
}

void rotarPieza(Pieza &p) {
    if (p.tipo == 1) return;
    int ox = p.x[1], oy = p.y[1];
    for (int i = 0; i < 4; i++) {
        int tx = p.x[i];
        p.x[i] = ox + (p.y[i] - oy);
        p.y[i] = oy - (tx - ox);
    }
}

bool validarMovimiento(unsigned char** tablero, Pieza p, int f, int c) {
    for (int i = 0; i < 4; i++) {
        if (p.x[i] < 0 || p.x[i] >= f || p.y[i] < 0 || p.y[i] >= c) return false;
        if (leerCelda(tablero, p.x[i], p.y[i], f, c)) return false;
    }
    return true;
}

void verificarYLimpiarFilas(unsigned char** tablero, int f, int c) {
    int bytesPorFila = c / 8;
    for (int i = 0; i < f; i++) {
        bool llena = true;
        for (int j = 0; j < bytesPorFila; j++) {
            if (tablero[i][j] != 0xFF) {
                llena = false; break;
            }
        }
        if (llena) {
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < bytesPorFila; j++) tablero[k][j] = tablero[k-1][j];
            }
            for (int j = 0; j < bytesPorFila; j++) tablero[0][j] = 0;
        }
    }
}

void imprimirEstado(unsigned char** tablero, int filas, int columnas) {
    cout << "\nTABLERO ACTUAL:\n";
    for (int i = 0; i < filas; ++i) {
        cout << "|";
        for (int j = 0; j < columnas; ++j) {
            if (leerCelda(tablero, i, j, filas, columnas)) cout << "#";
            else cout << ".";
        }
        cout << "|\n";
    }
}

void liberarTablero(unsigned char** &tablero, int filas) {
    for (int i = 0; i < filas; ++i) delete[] tablero[i];
    delete[] tablero;
}