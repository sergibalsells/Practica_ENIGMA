#include <string>
#include <iostream>
#include <fstream>
#include <limits> // Para limpiar el buffer del cin

#ifndef ROTORES_H
#define ROTORES_H

struct Rotor {
    std::string mapeo;
    char notch;
};

extern Rotor rotor1;
extern Rotor rotor2;
extern Rotor rotor3;

// Declaracion de funciones
bool validarRotor(const std::string& mapeo, char notch);
void mostrarRotores();
void editarRotor(Rotor& rotor, const std::string& nombre);
void guardarRotorEnArchivo(const Rotor& rotor, const std::string& nombreArchivo);
void guardarRotoresEnArchivos();

#endif // ROTORES_H
