#ifndef TABLERO_H
#define TABLERO_H

void crearTablero(unsigned char** &tablero, int filas, int columnas);
void imprimirEstado(unsigned char** tablero, int filas, int columnas);
void modificarCelda(unsigned char** tablero, int x, int y, bool estado);
void liberarTablero(unsigned char** &tablero, int filas);
bool filaLlena(unsigned char** tablero, int fila, int columnas);
void eliminarFila(unsigned char** tablero, int fila, int columnas);
bool hayColision(unsigned char** tablero, int x, int y, int filas, int columnas);

#endif