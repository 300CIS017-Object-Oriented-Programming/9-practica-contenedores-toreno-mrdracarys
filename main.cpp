#include <iostream>
#include "src/Torneo.h"

int main() {
    Torneo torneo;
    int opcion;

    do {
        std::cout << "\n--- Menu del Torneo Battle Arena ---\n";
        std::cout << "1. Registrar Videojuego\n";
        std::cout << "2. Registrar Jugador\n";
        std::cout << "3. Inscribir Jugador en Videojuego\n";
        std::cout << "4. Mostrar Videojuegos de un Jugador\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1:
                torneo.registrarVideojuego();
                break;
            case 2:
                torneo.registrarJugador();
                break;
            case 3:
                torneo.inscribirJugadorEnVideojuego();
                break;
            case 4:
                torneo.mostrarVideojuegosDeJugador();
                break;
            case 5:
                std::cout << "Saliendo del sistema..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida." << std::endl;
        }
    } while(opcion != 5);

    return 0;
}
