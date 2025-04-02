#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <string>
#include <iostream>

class Videojuego {
private:
    std::string codigo;
    std::string nombre;
    std::string genero;
    int nivelDificultad;
public:
    Videojuego(std::string codigo, std::string nombre, std::string genero, int nivelDificultad);
    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getGenero() const;
    int getNivelDificultad() const;
    void mostrar() const;
};

#endif
