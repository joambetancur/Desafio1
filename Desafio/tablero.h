#ifndef TABLERO_H
#define TABLERO_H

void crearTablero(unsigned char** &tablero, int filas, int columnas);
void imprimirEstado(unsigned char** tablero, int filas, int columnas);
void liberarTablero(unsigned char** &tablero, int filas);

#endif // TABLERO_H
