#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Videojuego.h"

class Jugador {
private:
    std::string nickname;
    int nivelRanking;
    std::vector<Videojuego*> videojuegosInscritos;
public:
    Jugador(std::string nickname, int nivelRanking);
    std::string getNickname() const;
    int getNivelRanking() const;
    void mostrar() const;
    // Inscribe un videojuego; retorna false si ya estaba inscrito.
    bool inscribirVideojuego(Videojuego* juego);
    const std::vector<Videojuego*>& getVideojuegosInscritos() const;
    // Calcula el promedio de dificultad de los videojuegos inscritos.
    double promedioDificultad() const;
};

#endif
