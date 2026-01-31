#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "processarTxt.h"

// 1. Quitar puntos, comas y símbolos especiales
void quitarSimbolosEspeciales(std::string& mensajeParaCifrar) {
    std::string simboloEsp = "',.!??:;";
    size_t i = 0;
    while (i < mensajeParaCifrar.length()) {
        for (size_t j = 0; j < simboloEsp.length(); j++) {
            if (mensajeParaCifrar[i] == simboloEsp[j]) {
                mensajeParaCifrar.erase(i, 1);
                i--;
                break;
            }
        }
        i++;
    }
}

// 2. Quitar acentos
std::string quitarAcentos(std::string& mensajeParaCifrar) {
    std::string original = "áàäâãéèëêíìïîóòöôõúùüûñÁÀÄÂÃÉÈËÊÍÌÏÎÓÒÖÔÕÚÙÜÛÑ";
    std::string reemplazo = "aaaaaeeeeiiiiooooouuuunAAAAAEEEEIIIIOOOOOUUUUN";

    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {
        size_t pos = original.find(mensajeParaCifrar[i]);
        if (pos != std::string::npos) {
            mensajeParaCifrar[i] = reemplazo[pos];
        }
    }
    return mensajeParaCifrar;
}

// 3. Convertir a mayúsculas
std::string convertirMayusculas(std::string& mensajeParaCifrar) {
    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {
        mensajeParaCifrar[i] = std::toupper(mensajeParaCifrar[i]);
    }
    return mensajeParaCifrar;
}

// 4. Agrupar en grupos de 5 letras
std::string agruparLetras(std::string& mensajeParaCifrar) {
    std::string result = "";
    int count = 0;

    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {
        result += mensajeParaCifrar[i];
        count++;

        if (count == 5) {
            result += ' ';
            count = 0;
        }
    }
    return result;
}

// Función para ajustar rotor
void ajustarRotor(std::string& rotor, char letra) {
    size_t pos = rotor.find(toupper(letra));
    if (pos != std::string::npos) {
        rotor = rotor.substr(pos) + rotor.substr(0, pos);
    }
}

// Función para dejar solo letras
void soloLetras(std::string& mensajeParaCifrar) {
    std::string soloLetras;
    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {
        char c = mensajeParaCifrar[i];
        if (isalpha(c)) {
            soloLetras += c;
        }
    }
    mensajeParaCifrar = soloLetras;
}