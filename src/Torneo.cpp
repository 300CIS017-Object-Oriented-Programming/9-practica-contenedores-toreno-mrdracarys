#include "Torneo.h"
#include <iostream>
#include <limits>

Torneo::~Torneo() {
    // Liberar memoria de videojuegos
    for (auto it : videojuegosDisponibles) {
        delete it.second;
    }
    // Liberar memoria de jugadores
    for (auto it : jugadoresRegistrados) {
        delete it.second;
    }
}

void Torneo::registrarVideojuego() {
    std::string codigo, nombre, genero;
    int dificultad;

    std::cout << "Ingrese codigo del videojuego: ";
    std::cin >> codigo;

    // Validar que el videojuego sea unico
    if (videojuegosDisponibles.find(codigo) != videojuegosDisponibles.end()) {
        std::cout << "El videojuego ya existe." << std::endl;
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese nombre del videojuego: ";
    std::getline(std::cin, nombre);

    std::cout << "Ingrese genero del videojuego: ";
    std::getline(std::cin, genero);

    std::cout << "Ingrese nivel de dificultad (1-10): ";
    std::cin >> dificultad;
    if (dificultad < 1 || dificultad > 10) {
        std::cout << "Nivel de dificultad invalido." << std::endl;
        return;
    }

    Videojuego* nuevoJuego = new Videojuego(codigo, nombre, genero, dificultad);
    videojuegosDisponibles[codigo] = nuevoJuego;
    std::cout << "Videojuego registrado exitosamente." << std::endl;
}

void Torneo::registrarJugador() {
    std::string nickname;
    int ranking;

    std::cout << "Ingrese nickname del jugador: ";
    std::cin >> nickname;

    // Validar que el jugador sea unico
    if (jugadoresRegistrados.find(nickname) != jugadoresRegistrados.end()) {
        std::cout << "El jugador ya existe." << std::endl;
        return;
    }

    std::cout << "Ingrese nivel de ranking: ";
    std::cin >> ranking;

    Jugador* nuevoJugador = new Jugador(nickname, ranking);
    jugadoresRegistrados[nickname] = nuevoJugador;
    std::cout << "Jugador registrado exitosamente." << std::endl;
}

void Torneo::inscribirJugadorEnVideojuego() {
    std::string nickname, codigo;

    std::cout << "Ingrese nickname del jugador: ";
    std::cin >> nickname;
    auto itJugador = jugadoresRegistrados.find(nickname);
    if (itJugador == jugadoresRegistrados.end()) {
        std::cout << "Jugador no encontrado." << std::endl;
        return;
    }

    std::cout << "Ingrese codigo del videojuego: ";
    std::cin >> codigo;
    auto itJuego = videojuegosDisponibles.find(codigo);
    if (itJuego == videojuegosDisponibles.end()) {
        std::cout << "Videojuego no encontrado." << std::endl;
        return;
    }

    // Inscribir y verificar duplicidad
    if (!itJugador->second->inscribirVideojuego(itJuego->second)) {
        std::cout << "Jugador ya inscrito en este videojuego." << std::endl;
    } else {
        std::cout << "Inscripcion realizada exitosamente." << std::endl;
    }
}

void Torneo::mostrarVideojuegosDeJugador() {
    std::string nickname;

    std::cout << "Ingrese nickname del jugador: ";
    std::cin >> nickname;
    auto itJugador = jugadoresRegistrados.find(nickname);
    if (itJugador == jugadoresRegistrados.end()) {
        std::cout << "Jugador no encontrado." << std::endl;
        return;
    }

    Jugador* jugador = itJugador->second;
    const auto& lista = jugador->getVideojuegosInscritos();

    if (lista.empty()) {
        std::cout << "El jugador no esta inscrito en ningun videojuego." << std::endl;
        return;
    }

    std::cout << "Videojuegos en los que participa " << nickname << ":" << std::endl;
    for (auto juego : lista) {
        juego->mostrar();
    }

    std::cout << "Promedio de dificultad: " << jugador->promedioDificultad() << std::endl;
}
