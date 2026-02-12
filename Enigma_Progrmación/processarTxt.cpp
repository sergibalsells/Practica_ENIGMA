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
// Función creada por IA CHATGPT
std::string quitarAcentos(std::string& mensajeParaCifrar) {
    std::string original = "áàäâãéèëêíìïîóòöôõúùüûñÁÀÄÂÃÉÈËÊÍÌÏÎÓÒÖÔÕÚÙÜÛÑ";//un string todas las possibilidades de letras con simbolos especiales

    std::string reemplazo = "aaaaaeeeeiiiiooooouuuunAAAAAEEEEIIIIOOOOOUUUUN";// un string de la misma cantidad de letras que el string original, son las mismas letra sin el simbolo

    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {// Recorremos el mensaje

        size_t pos = original.find(mensajeParaCifrar[i]);
        // se buscan concidencias de letras con simbolos especiales que coincidan con el string original

        if (pos != std::string::npos) { // si se encuentra una, se sustituye por la misma letra sin el simbolo

            mensajeParaCifrar[i] = reemplazo[pos];
        }
    }
    return mensajeParaCifrar; // la funcion devuelve el mismo mensaje sin simbolos especiales 
}

// 3. Convertir a mayúsculas
std::string convertirMayusculas(std::string& mensajeParaCifrar) {

    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {// Recorremos el mensaje

        mensajeParaCifrar[i] = std::toupper(mensajeParaCifrar[i]); // caracter a caracter se transforman las letras a mayúscula 
    }
    return mensajeParaCifrar; // la funcion devuelve el mismo mensaje en letras mayusculas
}

// 4. Agrupar en grupos de 5 letras
std::string agruparLetras(std::string& mensajeParaCifrar) {

    std::string result = "";// se declara una string vacia para ir añadiendo letras 

    int count = 0; //se declara una variable para controlar el numero de letras 

    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {// Recorremos el mensaje

        result += mensajeParaCifrar[i]; //la letra se añade a la string result

        count++;

        if (count == 5) {// Una vez se han agrupado 5 letras se separa con espacio

            result += ' ';

            count = 0; // Se iguala esta variable a 0 para poder repetir el bucle 
        }
    }
    return result; // la funcion devuelve el mismo mensaje con las letras agrupadas en grupos de 5  
}

// Función para ajustar rotor
void ajustarRotor(std::string& rotor, char letra) {
    size_t pos = rotor.find(toupper(letra)); // Ene ste caso lo que hacemos con el .find() es para realizar la busqueda inversa, 
    // Lo hacemos localizando la posicion del caracter cifrado en el rotor para recuperar su indice original. 
    if (pos != std::string::npos) {
        rotor = rotor.substr(pos) + rotor.substr(0, pos);
    }
}

// Función para dejar solo letras
void soloLetras(std::string& mensajeParaCifrar) {

    std::string soloLetras; se declara una string sin inicializacion para ir añadiendo letras 

    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {// Recorremos el mensaje

        char letra = mensajeParaCifrar[i]; //Se declara una variable por los caracteres

        if (isalpha(letra)) {//caracter a caracter se comprueba si es una letra

            soloLetras += letra; //si la funcion retorna 1 esa letra se añade a la string creada anteriormente soloLetras
        }
    }
    mensajeParaCifrar = soloLetras; // la funcion devuelve solo las letras que habia en el mensaje introduido por el usuaro
}