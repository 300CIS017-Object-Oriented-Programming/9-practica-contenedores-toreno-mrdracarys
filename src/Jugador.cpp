#include "Jugador.h"
#include <iostream>

Jugador::Jugador(std::string nickname, int nivelRanking)
        : nickname(nickname), nivelRanking(nivelRanking) {}

std::string Jugador::getNickname() const {
    return nickname;
}

int Jugador::getNivelRanking() const {
    return nivelRanking;
}

void Jugador::mostrar() const {
    std::cout << "Nickname: " << nickname
              << " | Ranking: " << nivelRanking << std::endl;
}

bool Jugador::inscribirVideojuego(Videojuego* juego) {
    // Validar que no se inscriba dos veces al mismo videojuego.
    for (auto j : videojuegosInscritos) {
        if (j->getCodigo() == juego->getCodigo()) {
            return false;
        }
    }
    videojuegosInscritos.push_back(juego);
    return true;
}

const std::vector<Videojuego*>& Jugador::getVideojuegosInscritos() const {
    return videojuegosInscritos;
}

double Jugador::promedioDificultad() const {
    if (videojuegosInscritos.empty())
        return 0.0;
    int suma = 0;
    for (auto juego : videojuegosInscritos) {
        suma += juego->getNivelDificultad();
    }
    return static_cast<double>(suma) / videojuegosInscritos.size();
}
