#include <iostream>
#include <cctype>
#include <fstream>
#include <limits>
#include "Descifrado.h"
#include "Rotores.h"
#include "processarTxt.h"

// Función para descifrar un carácter - CORREGIDA
char descifrarCaracter(char c, std::string& rotor1, std::string& rotor2, std::string& rotor3) {
    c = toupper(c);

    // Verificar que el carácter esté en el rango A-Z
    if (c < 'A' || c > 'Z') {
        return c;
    }

    // PASO 1: Primero deshacer César (-2)
    c = 'A' + ((c - 'A' - 2 + 26) % 26);

    // PASO 2: Rotor 3 inverso (último del cifrado)
    size_t pos = rotor3.find(c);
    if (pos != std::string::npos) {
        c = 'A' + static_cast<int>(pos);
    }

    // PASO 3: Rotor 2 inverso
    pos = rotor2.find(c);
    if (pos != std::string::npos) {
        c = 'A' + static_cast<int>(pos);
    }

    // PASO 4: Rotor 1 inverso (primero del cifrado)
    pos = rotor1.find(c);
    if (pos != std::string::npos) {
        c = 'A' + static_cast<int>(pos);
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

    // Quitar espacios para procesar correctamente
    soloLetras(mensaje);

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
    std::cout << "[INFO] Mensaje descifrado: " << resultadoAgrupado << std::endl;

    // Guardar el mensaje descifrado en un archivo llamado MensajeDescifrado.txt
    std::ofstream fitxer("MensajeDescifrado.txt");
    if (fitxer.is_open()) {
        fitxer << resultadoAgrupado;
        fitxer.close();
        std::cout << "[INFO] Mensaje descifrado guardado en MensajeDescifrado.txt" << std::endl;
    }
    else {
        std::cerr << "[ERROR] No se ha podido abrir MensajeDescifrado.txt" << std::endl;
    }
}
