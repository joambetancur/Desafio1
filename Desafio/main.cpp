#include <iostream>
#include "tablero.h"

using namespace std;

int main() {
    int f = 10, c = 8;
    unsigned char** juego = nullptr;
    crearTablero(juego, f, c);

    for(int i = 0; i < 8; i++) {
        modificarCelda(juego, 9, i, true);
    }

    cout << "TABLERO CON FILA COMPLETA:" << endl;
    imprimirEstado(juego, f, c);

    if (filaLlena(juego, 9, c)) {
        cout << "\nFILA COMPLETADA Eliminando..." << endl;
        eliminarFila(juego, 9, c);
    }

    cout << "\nTABLERO DESPUES DE ELIMINAR:" << endl;
    imprimirEstado(juego, f, c);

    liberarTablero(juego, f);
    return 0;
}