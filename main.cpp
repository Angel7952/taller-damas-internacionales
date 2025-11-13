#include <iostream>
#include "Tablero.h"
using namespace std;

int main() {
    Tablero juego;
    int f1, c1, f2, c2;
    int opcion;

    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Iniciar partida\n";
        cout << "2. Ver reglas\n";
        cout << "3. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        if (opcion == 3) {
            cout << "Gracias por jugar.\n";
            break;
        } 
        else if (opcion == 2) {
            cout << "\nReglas de Damas Internacionales:\n";
            cout << "- Tablero de 10x10 con 20 piezas por jugador.\n";
            cout << "- Jugador 1 (abajo) usa '1'.\n";
            cout << "- Jugador 2 (arriba) usa '2'.\n";
            cout << "- Las piezas se mueven en diagonal.\n";
            cout << "- Capturar es obligatorio (simplificado en esta versión).\n";
            cout << "- Gana quien capture todas las piezas del rival.\n";
        } 
        else if (opcion == 1) {
            juego.iniciar();
            while (true) {
                juego.mostrar();
                if (juego.hayGanador()) break;

                cout << "\nIngrese su movimiento (fila1 col1 fila2 col2) o -1 para salir: ";
                cin >> f1;
                if (f1 == -1) break;
                cin >> c1 >> f2 >> c2;
                juego.mover(f1, c1, f2, c2);
            }
        } 
        else {
            cout << "Opción no válida.\n";
        }
    }

    return 0;
}