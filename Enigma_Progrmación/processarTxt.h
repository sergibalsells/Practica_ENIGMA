#pragma once
#include <string>

//Funciones con strings para poder procesar todo el texto introducido. ( Con Ayuda de la IA por temas de Errores). 
void quitarSimbolosEspeciales(std::string& mensajeParaCifrar);
std::string quitarAcentos(std::string& mensajeParaCifrar);
std::string convertirMayusculas(std::string& mensajeParaCifrar);
std::string agruparLetras(std::string& mensajeParaCifrar);
void ajustarRotor(std::string& rotor, char letra);
void soloLetras(std::string& mensajeParaCifrar);