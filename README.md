taller de damas internacionales c++
en el proyecto fue conplenplementado al juego damas internacionales con un tablero 10x10 en c++.
relacion entre los archivos son:



1 main.cpp  →  usa la clase Tablero.
2 Tablero.h →  declara la clase y sus métodos
3 Tablero.cpp → implementa la lógica del juego






🎯 que se hizo en tablero.h, en esta parte del codigo estan las fuenciones y los valores logicos como el bool que se van a utilizar en todo el codigo.
tablero 10x10 y las funciones del tablero.h son:
int turno; → controla de quién es el turno. 
iniciar() → coloca las piezas al inicio del juego.
mostrar() → imprime el tablero en pantalla.
mover() → ejecuta movimientos o capturas.
cambiarTurno() → alterna entre jugadores. 
hayGanador() → determina si alguien ganó.




🟦que se hizo en tablero.cpp
la estructura que se utilizo se incluyo tablero.h, en esta parte esta impelmentada la loquica real del juego.
🧮funciones mas descatadas son:
Tablero::iniciar() → llena el tablero con las piezas iniciales. 
Tablero::mostrar() → muestra el tablero con las posiciones actuales.  
Tablero::mover() → valida y ejecuta los movimientos. 
Tablero::esCaptura() → comprueba si un movimiento implica una captura.
Tablero::hayGanador() → verifica si un jugador ya no tiene piezas.





🟥en el main.cpp en esta parte se incluye todo lo que hicimos en tablero.h y tablero.cpp,
en esta partde del codigo el main es donde se incluye la logica.
caracteristicas:Contiene el menú de interacción con el usuario y controla el flujo del juego.
las funciones que tiene el main:
muestra las menu con opciones:
1. Iniciar partida`, `2. Ver reglas`, `3. Salir
Permite ingresar coordenadas para mover piezas.
Muestra mensajes de error o victoria.
Llama a los métodos del objeto Tablero para realizar los movimientos.

en el tablero.h se hizo:
#ifndef TABLERO_H
#define TABLERO_H

1) #include <iostream>
using namespace std;
Evita incluir el archivo dos veces (directiva de preprocesador).
🔹 Incluye iostream para usar cout y cin.


class Tablero {
private: "cono es esta parte del codigo como es clase privado solo puede adcerder ella misma"
    char tablero[10][10];
    int turno; // 1 = jugador 1, 2 = jugador 2

Aquí se definen los atributos privados:

2) tablero[10][10]: matriz de 10x10 con las casillas.

turno: indica qué jugador mueve (1 o 2).
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
🔹 Métodos públicos de la clase: "como es publico en esta parte del codigo cualquiera puede adceder a ella"

Tablero(): constructor → prepara el tablero al inicio.

iniciar(): coloca las piezas en su posición inicial.

mostrar(): imprime el tablero en pantalla.

mover(): intenta mover una pieza de una casilla a otra.

dentroDelTablero(): valida que las coordenadas estén dentro del tablero.

cambiarTurno(): cambia de jugador tras cada movimiento válido.

esMovimientoValido(): verifica si un movimiento normal es correcto.

esCaptura(): comprueba si el movimiento es una captura (salto sobre oponente).

hayGanador(): determina si un jugador ya ganó.


en el tablero.cpp la funcion del codigo funciona de esta manera y aqui se implementa la logica de cada funcion que se hizo en el tablero.h:


1) Tablero::Tablero() {
    turno = 1;
    iniciar();
}

en esta parte del codigo se hizo: Cada vez que creas un objeto Tablero, comienza el turno 1
y se inicializa el tablero con iniciar().

este es el de iniciar().
2) void Tablero::iniciar() {
    for (int f = 0; f < 10; f++) {
        for (int c = 0; c < 10; c++) {
            if ((f + c) % 2 == 1) {
                if (f < 4) tablero[f][c] = '2';      // Jugador 2 arriba
                else if (f > 5) tablero[f][c] = '1'; // Jugador 1 abajo
                else tablero[f][c] = '.';            // Casilla vacía
            } else {
                tablero[f][c] = ' '; // Casilla clara
            }
        }
    }
}
en esta parte del codigo se hizo: Se recorre el tablero con dos bucles.
🔹 (f + c) % 2 == 1 indica las casillas oscuras (donde se colocan las piezas).
🔹 Jugador 2 ocupa las 4 primeras filas ('2').
🔹 Jugador 1 ocupa las 4 últimas filas ('1').
🔹 Las demás casillas oscuras quedan vacías ('.').
en esta parte se hizo la funcion de mostrar tablero:


3) void Tablero::mostrar() {
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
en esta funcion hace:
Muestra la numeración de filas y columnas.
🔹 Imprime la matriz tablero para mostrar piezas, vacíos y casillas claras.
🔹 Al final muestra de quién es el turno actual.


4)bool Tablero::dentroDelTablero(int f, int c) {
    return (f >= 0 && f < 10 && c >= 0 && c < 10);
    en esta partde se Comprueba que las coordenadas estén dentro de los límites (0–9).


   " bool Tablero::esMovimientoValido(int f1, int c1, int f2, int c2) {
    int df = f2 - f1;
    int dc = c2 - c1;
    char pieza = tablero[f1][c1];

   " if (pieza == '1' && df == -1 && abs(dc) == 1) return true;
    if (pieza == '2' && df == 1 && abs(dc) == 1) return true; 

   " return false; "
}
en esta parte del codigo se hizo:se Calcula la diferencia de filas (df) y columnas (dc).
🔹 Jugador 1 ('1') solo se mueve hacia arriba (fila menor).
🔹 Jugador 2 ('2') solo hacia abajo (fila mayor).
🔹 Solo permite moverse una casilla en diagonal.

la siguente funcion es de captura:

5) bool Tablero::esCaptura(int f1, int c1, int f2, int c2) {
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
donde: Detecta si hay un salto de 2 casillas (posible captura).
🔹 Calcula la casilla “del medio” (mf, mc).
🔹 Si en el medio hay una pieza del oponente, la jugada es una captura válida.

el siguente es mover() donde: Este método une todas las validaciones anteriores.

6) bool Tablero::mover(int f1, int c1, int f2, int c2) {
    // Validar límites
    if (!dentroDelTablero(f1, c1) || !dentroDelTablero(f2, c2)) {
        cout << "Movimiento fuera del tablero.\n";
        return false;
    }

   " char pieza = tablero[f1][c1];
    if (pieza != '1' && pieza != '2') {
        cout << "No hay pieza válida ahí.\n";
        return false;
    }

   " // Validar turno
    if (turno == 1 && pieza != '1') {
        cout << "Esa pieza no te pertenece.\n";
        return false;
    }
    if (turno == 2 && pieza != '2') {
        cout << "Esa pieza no te pertenece.\n";
        return false;
    }

   " // Verificar destino vacío
    if (tablero[f2][c2] != '.') {
        cout << "La casilla de destino no está vacía.\n";
        return false;
    }

   " // Captura
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

  "  // Movimiento normal
    if (esMovimientoValido(f1, c1, f2, c2)) {
        tablero[f2][c2] = pieza;
        tablero[f1][c1] = '.';
        cambiarTurno();
        return true;
    }
"
    cout << "Movimiento inválido.\n";
    return false;
}


donde esta funcion hace:
1)Valida que las coordenadas estén dentro del tablero.

2) Comprueba que haya una pieza válida y que sea del jugador correcto.

3) Verifica que la casilla destino esté vacía.

4) Si el movimiento es una captura, elimina la pieza enemiga.

5) Si es un movimiento normal, mueve la pieza una casilla.

6) Si nada de esto se cumple → muestra error.

la siguente funcion es la de cambiar turno donde:


7) oid Tablero::cambiarTurno() {
    turno = (turno == 1) ? 2 : 1;
}

en esta parte se hizo: Alterna entre jugador 1 y jugador 2.


la siguente funcion es hay ganador():

8) bool Tablero::hayGanador() {
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
en esta funcion se hizo: Cuenta las piezas restantes de cada jugador.
🔹 Si uno se queda sin piezas, el otro gana.
