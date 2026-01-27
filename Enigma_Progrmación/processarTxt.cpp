#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "processarTxt.h"
// 1. Quitar puntos, comas y simbolos y letras especiales. 

void quitarSimbolosEspeciales(std::string &mensajeParaCifrar) {
    std::string simboloEsp = "',.!??:;"; // keep your variable name
    size_t i = 0;
    while (i < mensajeParaCifrar.length()) {
        for (size_t j = 0; j < simboloEsp.length(); j++) {
            if (mensajeParaCifrar[i] == simboloEsp[j]) {
                mensajeParaCifrar.erase(i, 1);
                i--; // stay on same index after erase
                break; // stop checking other special chars for this index
            }
        }
        i++;
    }

    std::cout << "[INFO] Quitamos los simbolos especiales:" << mensajeParaCifrar << std::endl;
}

// 2. Quitar Acentos.
//CHATGPT
std::string quitarAcentos(std::string mensajeParaCifrar) {
    std::string sinAcentos = mensajeParaCifrar;

    std::string original  = "áàäâãéèëêíìïîóòöôõúùüûñÁÀÄÂÃÉÈËÊÍÌÏÎÓÒÖÔÕÚÙÜÛÑ";
    std::string reemplazo = "aaaaaeeeeiiiiooooouuuunAAAAAEEEEIIIIOOOOOUUUUN";

    for (size_t i = 0; i < sinAcentos.length(); i++) {
        size_t pos = original.find(sinAcentos[i]);
        if (pos != std::string::npos) {
            sinAcentos[i] = reemplazo[pos];
        }
    }

    std::cout << "[INFO] Quitamos los acentos:" << mensajeParaCifrar << std::endl;
    return sinAcentos;
}


// 3. Todo en mayusculas.
std::string convertirMayusculas(std::string &mensajeParaCifrar) {

    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {
        mensajeParaCifrar[i] = std::toupper(mensajeParaCifrar[i]); // coverrt each char in string to upper case
    }

    std::cout << "[INFO] Convertimos en mayuscula:" << mensajeParaCifrar << std::endl;
    return mensajeParaCifrar;
}


// 4. Separar en grupos de 5. 
std::string agruparLetras(std::string &mensajeParaCifrar) {

    std::string result = "";
    int count = 0;

    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {
        result += mensajeParaCifrar[i];
        count++;

        if (count == 5) {
            result += ' '; // add a space after every 5 letters
            count = 0;
        }
    }

    std::cout << "[INFO] Agrupamos las letras en grupos de 5:" << mensajeParaCifrar << std::endl;
    return result;
}
