#include <iostream>
#include <conio.h>
#include <ctime>
#include "tablero.h"

using namespace std;

int main() {
    srand(time(0));
    int f, c;

    cout << "--- TETRIS BITWISE UdeA ---\n";
    cout << "Ingrese alto (min 8): "; cin >> f;
    cout << "Ingrese ancho (multiplo de 8): "; cin >> c;

    if (f < 8 || c % 8 != 0) {
        cout << "Dimensiones invalidas.\n";
        return 1;
    }

    unsigned char** juego = nullptr;
    crearTablero(juego, f, c);

    bool derrota = false;
    while (!derrota) {
        Pieza actual = generarPieza(c);

        if (!validarMovimiento(juego, actual, f, c)) {
            derrota = true;
            cout << "\n!!! GAME OVER !!!\n";
            break;
        }

        bool piezaActiva = true;
        while (piezaActiva) {
            for(int i=0; i<4; i++) modificarCelda(juego, actual.x[i], actual.y[i], true);
            imprimirEstado(juego, f, c);
            for(int i=0; i<4; i++) modificarCelda(juego, actual.x[i], actual.y[i], false);

            cout << "Accion [A]Izq [D]Der [S]Bajar [W]Rotar [Q]Salir: ";
            char accion = _getch();
            if (accion == 'q' || accion == 'Q') { derrota = true; break; }

            Pieza intento = actual;
            if (accion == 'a' || accion == 'A') for(int i=0; i<4; i++) intento.y[i]--;
            else if (accion == 'd' || accion == 'D') for(int i=0; i<4; i++) intento.y[i]++;
            else if (accion == 'w' || accion == 'W') rotarPieza(intento);

            if (validarMovimiento(juego, intento, f, c)) actual = intento;

            Pieza gravedad = actual;
            for(int i=0; i<4; i++) gravedad.x[i]++;

            if (validarMovimiento(juego, gravedad, f, c)) {
                actual = gravedad;
            } else {
                for(int i=0; i<4; i++) modificarCelda(juego, actual.x[i], actual.y[i], true);
                verificarYLimpiarFilas(juego, f, c);
                piezaActiva = false;
            }
        }
    }

    liberarTablero(juego, f);
    return 0;
}