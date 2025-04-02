#include "Videojuego.h"
#include <iostream>

Videojuego::Videojuego(std::string codigo, std::string nombre, std::string genero, int nivelDificultad)
        : codigo(codigo), nombre(nombre), genero(genero), nivelDificultad(nivelDificultad) {}

std::string Videojuego::getCodigo() const {
    return codigo;
}

std::string Videojuego::getNombre() const {
    return nombre;
}

std::string Videojuego::getGenero() const {
    return genero;
}

int Videojuego::getNivelDificultad() const {
    return nivelDificultad;
}

void Videojuego::mostrar() const {
    std::cout << "Codigo: " << codigo
              << " | Nombre: " << nombre
              << " | Genero: " << genero
              << " | Dificultad: " << nivelDificultad << std::endl;
}
