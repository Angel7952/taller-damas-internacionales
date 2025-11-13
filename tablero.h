#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
using namespace std;

class Tablero {
private:
    char tablero[10][10];
    int turno; // 1 = jugador 1, 2 = jugador 2

public:
    Tablero();
    void iniciar();
    void mostrar();
    bool mover(int f1, int c1, int f2, int c2);
    bool dentroDelTablero(int f, int c);
    void cambiarTurno();
    bool esMovimientoValido(int f1, int c1, int f2, int c2);
    bool esCaptura(int f1, int c1, int f2, int c2);
    bool hayGanador();
};

#endif