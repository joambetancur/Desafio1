#include <iostream>
#include "tablero.h"

using namespace std;

int main() {
    int alto, ancho;

    cout << "--- UdeA: Informatica II ---" << endl;
    cout << "Ingrese alto (min 8): ";
    cin >> alto;
    cout << "Ingrese ancho (multiplo de 8): ";
    cin >> ancho;

    if (alto < 8 || ancho % 8 != 0) {
        cout << "Dimensiones invalidas." << endl;
        return 1;
    }

    unsigned char** tableroPrincipal = nullptr;
    crearTablero(tableroPrincipal, alto, ancho);

    cout << "\nVisualizacion Inicial:" << endl;
    imprimirEstado(tableroPrincipal, alto, ancho);

    return 0;
}
