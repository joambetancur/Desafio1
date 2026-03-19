#include <iostream>
#include "tablero.h"

using namespace std;

int main() {
    int f = 10, c = 16;
    unsigned char** juego = nullptr;

    crearTablero(juego, f, c);

    modificarCelda(juego, 5, 4, true);
    modificarCelda(juego, 6, 4, true);
    modificarCelda(juego, 7, 4, true);
    modificarCelda(juego, 7, 5, true);

    cout << "--- TETRIS BITWISE ---" << endl;
    imprimirEstado(juego, f, c);

    liberarTablero(juego, f);
    return 0;
}