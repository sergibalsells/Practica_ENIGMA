#include <iostream>
#include <fstream>
#include <string>
#include <cctype>


void quitarSimbolosEspeciales(std::string &mensajeParaCifrar);
	
std::string quitarAcentos(std::string &mensajeParaCifrar);

std::string convertirMayusculas(std::string &mensajeParaCifrar);
	
std::string agruparLetras(std::string &mensajeParaCifrar);

void ajustarRotor(std::string &rotor, char letra);

void soloLetras(std::string &mensajeParaCifrar);
