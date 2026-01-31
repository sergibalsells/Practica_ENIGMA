#include <iostream>
#include <cctype>
#include <fstream>
#include <limits>
#include "Descifrado.h"
#include "Rotores.h"
#include "processarTxt.h"  // Aquí está definida avanzarRotor

// Función para pasar un carácter a través de un rotor (en dirección inversa para descifrar)
char pasarPorRotorInverso(const std::string& rotor, char c) {
    size_t pos = rotor.find(toupper(c));
    if (pos != std::string::npos) {
        return static_cast<char>('A' + pos);
    }
    return c;
}

// Función para descifrar un carácter usando los 3 rotores
char descifrarCaracter(char c, std::string& rotor1, std::string& rotor2, std::string& rotor3) {
    c = toupper(c);

    // Paso 1: Rotor 1 (directo)
    c = rotor1[c - 'A'];

    // Paso 2: Rotor 2 (directo)
    c = rotor2[c - 'A'];

    // Paso 3: Rotor 3 (directo)
    c = rotor3[c - 'A'];

    // Paso 4: Reflector (simplificado)
    c = 'A' + ('Z' - (c - 'A'));

    // Paso 5: Rotor 3 (inverso)
    size_t pos = rotor3.find(c);
    if (pos != std::string::npos) {
        c = static_cast<char>('A' + pos);
    }

    // Paso 6: Rotor 2 (inverso)
    pos = rotor2.find(c);
    if (pos != std::string::npos) {
        c = static_cast<char>('A' + pos);
    }

    // Paso 7: Rotor 1 (inverso)
    pos = rotor1.find(c);
    if (pos != std::string::npos) {
        c = static_cast<char>('A' + pos);
    }

    return c;
}

// Función principal para descifrar un mensaje
void procesoDescifrado() {
    std::string mensaje;
    char posR1, posR2, posR3;

    std::cout << "\n=== DESCIFRADO DE MENSAJE ===\n";

    // Pedir posiciones iniciales de los rotores
    std::cout << "Introduce la posición inicial de los rotores (ejemplo: A B C): ";
    std::cin >> posR1 >> posR2 >> posR3;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Pedir el mensaje a descifrar
    std::cout << "Introduce el mensaje a descifrar: ";
    std::getline(std::cin, mensaje);

    // Procesar el mensaje (quitar símbolos, acentos, convertir a mayúsculas)
    quitarSimbolosEspeciales(mensaje);
    std::cout << "[INFO] Quitamos los simbolos especiales: " << mensaje << std::endl;

    mensaje = quitarAcentos(mensaje);
    std::cout << "[INFO] Quitamos los acentos: " << mensaje << std::endl;

    convertirMayusculas(mensaje);
    std::cout << "[INFO] Convertimos en mayuscula: " << mensaje << std::endl;

    // Copiar los rotores globales para no modificarlos
    std::string rotor1Copy = rotor1.mapeo;
    std::string rotor2Copy = rotor2.mapeo;
    std::string rotor3Copy = rotor3.mapeo;

    // Ajustar rotores a la posición inicial
    ajustarRotor(rotor1Copy, posR1);
    ajustarRotor(rotor2Copy, posR2);
    ajustarRotor(rotor3Copy, posR3);

    std::string resultado;

    // Procesar el mensaje
    for (char c : mensaje) {
        if (isalpha(c)) {
            char descifrado = descifrarCaracter(c, rotor1Copy, rotor2Copy, rotor3Copy);
            resultado += descifrado;
        }
    }

    // Agrupar en bloques de 5 letras
    std::string resultadoAgrupado = agruparLetras(resultado);
    std::cout << "[INFO] Agrupamos las letras en grupos de 5: " << resultadoAgrupado << std::endl;
    std::cout << "[INFO] Mensaje descifrado: " << resultadoAgrupado << std::endl;
}