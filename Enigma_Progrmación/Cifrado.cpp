#include <iostream>
#include <cctype>
#include <fstream>
#include <limits>
#include "Cifrado.h"
#include "Rotores.h"
#include "processarTxt.h"

void introducirMensaje() {
    std::string mensaje;
    std::cout << "Introduce un mensaje para cifrar" << std::endl;
    std::getline(std::cin, mensaje);

    std::ofstream fitxer("Missatge.txt");
    if (fitxer.is_open()) {
        fitxer << mensaje;
        fitxer.close();
        std::cout << "[INFO] Mensaje guardado en Missatge.txt" << std::endl;
    }
    else {
        std::cerr << "[ERROR] No se ha podido abrir Missatge.txt" << std::endl;
    }
}

// Funciï¿½n para cifrar un carï¿½cter usando los 3 rotores y cifrado Cï¿½sar con desplazamiento 2
char cifrarCaracter(char c, std::string& rotor1, std::string& rotor2, std::string& rotor3) {
    c = toupper(c);

<<<<<<< HEAD
    // Verificar que el carácter esté en el rango A-Z
    if (c < 'A' || c > 'Z') {
        return c;
    }
=======
    // Aplicar cifrado Cï¿½sar con desplazamiento 2
    c = 'A' + ((c - 'A' + 2) % 26);
>>>>>>> 28d8cadcd656791bd0fd793b0f5f9cedf856f017

    // Paso 1: Rotor 1 (directo)
    if (c - 'A' < rotor1.length()) {
        c = rotor1[c - 'A'];
    }

    // Paso 2: Rotor 2 (directo)
    if (c - 'A' < rotor2.length()) {
        c = rotor2[c - 'A'];
    }

    // Paso 3: Rotor 3 (directo)
    if (c - 'A' < rotor3.length()) {
        c = rotor3[c - 'A'];
    }

    // Aplicar cifrado César con desplazamiento 2
    c = 'A' + ((c - 'A' + 2) % 26);

    return c;
}

// Funciï¿½n principal para cifrar un mensaje
void procesoCifrado() {
    std::string mensaje;
    char posR1, posR2, posR3;

    std::cout << "\n=== CIFRADO DE MENSAJE ===\n";

    // Pedir posiciones iniciales de los rotores
    std::cout << "Introduce la posiciï¿½n inicial de los rotores (ejemplo: A B C): "<< std::endl;

    std::cin >> posR1 >> posR2 >> posR3;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Pedir el mensaje a cifrar
    std::cout << "Introduce el mensaje a cifrar: ";
    std::getline(std::cin, mensaje);

    // Procesar el mensaje (quitar sï¿½mbolos, acentos, convertir a mayï¿½sculas)
    quitarSimbolosEspeciales(mensaje);
    std::cout << "[INFO] Quitamos los simbolos especiales: " << mensaje << std::endl;

    mensaje = quitarAcentos(mensaje);
    std::cout << "[INFO] Quitamos los acentos: " << mensaje << std::endl;

    convertirMayusculas(mensaje);
    std::cout << "[INFO] Convertimos en mayuscula: " << mensaje << std::endl;

    // Quitar espacios para procesar correctamente
    soloLetras(mensaje);

    // Copiar los rotores globales para no modificarlos
    std::string rotor1Copy = rotor1.mapeo;
    std::string rotor2Copy = rotor2.mapeo;
    std::string rotor3Copy = rotor3.mapeo;

    // Ajustar rotores a la posiciï¿½n inicial
    ajustarRotor(rotor1Copy, posR1);
    ajustarRotor(rotor2Copy, posR2);
    ajustarRotor(rotor3Copy, posR3);

    std::string resultado;

    // Procesar el mensaje
    for (char c : mensaje) {
        if (isalpha(c)) {
            char cifrado = cifrarCaracter(c, rotor1Copy, rotor2Copy, rotor3Copy);
            resultado += cifrado;
        }
    }

    // Agrupar en bloques de 5 letras
    std::string resultadoAgrupado = agruparLetras(resultado);
    std::cout << "[INFO] Agrupamos las letras en grupos de 5: " << resultadoAgrupado << std::endl;

    // Guardar el mensaje cifrado en un archivo
    std::ofstream fitxer("Missatge.txt");
    if (fitxer.is_open()) {
        fitxer << resultadoAgrupado;
        fitxer.close();
        std::cout << "[INFO] Mensaje cifrado guardado en Missatge.txt" << std::endl;
    }
    else {
        std::cerr << "[ERROR] No se ha podido abrir Missatge.txt" << std::endl;
    }
}
