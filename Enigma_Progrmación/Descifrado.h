#pragma once
#include <string>
#include "Rotores.h"
#include "processarTxt.h"  // Incluimos processarTxt.h para tener acceso a ajustarRotor

char pasarPorRotorInverso(const std::string& rotor, char c);

char descifrarCaracter(char c,
                       std::string& rotor1,
                       std::string& rotor2,
                       std::string& rotor3);

void procesoDescifrado();