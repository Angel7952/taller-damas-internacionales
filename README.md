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



