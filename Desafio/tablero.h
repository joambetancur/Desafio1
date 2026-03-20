#ifndef TABLERO_H
#define TABLERO_H

struct Pieza {
    int x[4], y[4];
    int tipo;
};

void crearTablero(unsigned char** &tablero, int filas, int columnas);
void liberarTablero(unsigned char** &tablero, int filas);
void modificarCelda(unsigned char** tablero, int x, int y, bool estado);
bool leerCelda(unsigned char** tablero, int x, int y, int f, int c);
void imprimirEstado(unsigned char** tablero, int filas, int columnas);

Pieza generarPieza(int ancho);
void rotarPieza(Pieza &p);
bool validarMovimiento(unsigned char** tablero, Pieza p, int f, int c);
void verificarYLimpiarFilas(unsigned char** tablero, int f, int c);

#endif