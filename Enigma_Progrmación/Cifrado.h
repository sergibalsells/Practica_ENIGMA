#pragma once
#include <string>
#include "Rotores.h"
#include "processarTxt.h"

void introducirMensaje();
char cifrarCaracter(char c, std::string& rotor1, std::string& rotor2, std::string& rotor3);
void procesoCifrado();