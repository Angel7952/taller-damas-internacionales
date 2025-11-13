#include "Tablero.h"

Tablero::Tablero() {
    turno = 1;
    iniciar();
}

void Tablero::iniciar() {
    for (int f = 0; f < 10; f++) {
        for (int c = 0; c < 10; c++) {
            if ((f + c) % 2 == 1) {
                if (f < 4) tablero[f][c] = '2';      // Jugador 2 (arriba)
                else if (f > 5) tablero[f][c] = '1'; // Jugador 1 (abajo)
                else tablero[f][c] = '.';            // Casilla vacía
            } else {
                tablero[f][c] = ' '; // Casilla clara
            }
        }
    }
}

void Tablero::mostrar() {
    cout << "\n   ";
    for (int c = 0; c < 10; c++) cout << c << " ";
    cout << "\n";
    for (int f = 0; f < 10; f++) {
        cout << " " << f << " ";
        for (int c = 0; c < 10; c++) {
            cout << tablero[f][c] << " ";
        }
        cout << "\n";
    }
    cout << "\nTurno del jugador: " << turno << "\n";
}

bool Tablero::dentroDelTablero(int f, int c) {
    return (f >= 0 && f < 10 && c >= 0 && c < 10);
}

bool Tablero::esMovimientoValido(int f1, int c1, int f2, int c2) {
    int df = f2 - f1;
    int dc = c2 - c1;
    char pieza = tablero[f1][c1];

    if (pieza == '1' && df == -1 && abs(dc) == 1) return true;
    if (pieza == '2' && df == 1 && abs(dc) == 1) return true;

    return false;
}

bool Tablero::esCaptura(int f1, int c1, int f2, int c2) {
    int df = f2 - f1;
    int dc = c2 - c1;
    if (abs(df) == 2 && abs(dc) == 2) {
        int mf = (f1 + f2) / 2;
        int mc = (c1 + c2) / 2;
        char pieza = tablero[f1][c1];
        char medio = tablero[mf][mc];
        if (pieza == '1' && medio == '2') return true;
        if (pieza == '2' && medio == '1') return true;
    }
    return false;
}

bool Tablero::mover(int f1, int c1, int f2, int c2) {
    if (!dentroDelTablero(f1, c1) || !dentroDelTablero(f2, c2)) {
        cout << "Movimiento fuera del tablero.\n";
        return false;
    }

    char pieza = tablero[f1][c1];
    if (pieza != '1' && pieza != '2') {
        cout << "No hay pieza válida ahí.\n";
        return false;
    }

    if (turno == 1 && pieza != '1') {
        cout << "Esa pieza no te pertenece.\n";
        return false;
    }
    if (turno == 2 && pieza != '2') {
        cout << "Esa pieza no te pertenece.\n";
        return false;
    }

    if (tablero[f2][c2] != '.') {
        cout << "La casilla de destino no está vacía.\n";
        return false;
    }

    // Captura
    if (esCaptura(f1, c1, f2, c2)) {
        int mf = (f1 + f2) / 2;
        int mc = (c1 + c2) / 2;
        tablero[mf][mc] = '.';
        tablero[f2][c2] = pieza;
        tablero[f1][c1] = '.';
        cout << "¡Captura realizada!\n";
        cambiarTurno();
        return true;
    }

    // Movimiento normal
    if (esMovimientoValido(f1, c1, f2, c2)) {
        tablero[f2][c2] = pieza;
        tablero[f1][c1] = '.';
        cambiarTurno();
        return true;
    }

    cout << "Movimiento inválido.\n";
    return false;
}

void Tablero::cambiarTurno() {
    turno = (turno == 1) ? 2 : 1;
}

bool Tablero::hayGanador() {
    int p1 = 0, p2 = 0;
    for (int f = 0; f < 10; f++) {
        for (int c = 0; c < 10; c++) {
            if (tablero[f][c] == '1') p1++;
            if (tablero[f][c] == '2') p2++;
        }
    }
    if (p1 == 0) {
        cout << "\n¡Jugador 2 gana!\n";
        return true;
    }
    if (p2 == 0) {
        cout << "\n¡Jugador 1 gana!\n";
        return true;
    }
    return false;
}