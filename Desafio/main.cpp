#include <iostream>
#include "tablero.h"

using namespace std;

int main() {
    int filas, columnas;
    unsigned char** tableroPrincipal = nullptr;

    cout << "Ingrese filas (minimo 8): ";
    cin >> filas;
    cout << "Ingrese columnas (multiplo de 8): ";
    cin >> columnas;

    if (filas >= 8 && columnas % 8 == 0) {
        crearTablero(tableroPrincipal, filas, columnas);

        cout << "\nTablero Inicializado (Logica de Bits):\n" << endl;
        imprimirEstado(tableroPrincipal, filas, columnas);

        liberarTablero(tableroPrincipal, filas);
        cout << "\nMemoria liberada exitosamente." << endl;
    } else {
        cout << "Error: Dimensiones no validas." << endl;
    }

    return 0;
}