#ifndef TORNEO_H
#define TORNEO_H

#include <map>
#include <string>
#include "Videojuego.h"
#include "Jugador.h"

class Torneo {
private:
    // Catálogo global de videojuegos
    std::map<std::string, Videojuego*> videojuegosDisponibles;
    // Registro de jugadores
    std::map<std::string, Jugador*> jugadoresRegistrados;
public:
    // Destructor para liberar memoria dinámica
    ~Torneo();
    void registrarVideojuego();
    void registrarJugador();
    void inscribirJugadorEnVideojuego();
    void mostrarVideojuegosDeJugador();
};

#endif
