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

// Funcion para cifrar un caracter usando los 3 rotores y ciframos con cesar con desplazamiento 2 
// Apoyo de la IA para pasar por los rotores debido a errores al poder esablecer las vueltas en ellos. 
char cifrarCaracter(char c, std::string& rotor1, std::string& rotor2, std::string& rotor3) {
    c = toupper(c);

    // Aplicamos cifrado Cesar con desplazamiento 2
    c = 'A' + ((c - 'A' + 2) % 26);

    // Paso 1: Aplicamos en el Rotor 1 de forma directa
    if (c - 'A' < rotor1.length()) {
        c = rotor1[c - 'A'];
    }

    // Paso 2: Aplicamos en el Rotor 2 de forma directa
    if (c - 'A' < rotor2.length()) {
        c = rotor2[c - 'A'];
    }

    // Paso 3: Aplicamos en el Rotor 3 de forma directa
    if (c - 'A' < rotor3.length()) {
        c = rotor3[c - 'A'];
    }

    // Aplicamos cifrado Cesar con desplazamiento 2
    c = 'A' + ((c - 'A' + 2) % 26);

    return c;
}

// Funcion principal para cifrar el mensaje que se ponga
void procesoCifrado() {
    std::string mensaje;
    char posR1, posR2, posR3;

    std::cout << "\n=== CIFRADO DE MENSAJE ===\n";

    // Pedimos posiciones iniciales de los rotores
    std::cout << "Introduce la posici�n inicial de los rotores (ejemplo: A B C): "<< std::endl;

    std::cin >> posR1 >> posR2 >> posR3;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Pedimos el mensaje a cifrar
    std::cout << "Introduce el mensaje a cifrar: ";
    std::getline(std::cin, mensaje);

    // Procesamos el mensaje (quitamos simbolos, acentos, convertimos todo a mayusculas)
    quitarSimbolosEspeciales(mensaje);
    std::cout << "[INFO] Quitamos los simbolos especiales: " << mensaje << std::endl;

    mensaje = quitarAcentos(mensaje);
    std::cout << "[INFO] Quitamos los acentos: " << mensaje << std::endl;

    convertirMayusculas(mensaje);
    std::cout << "[INFO] Convertimos en mayuscula: " << mensaje << std::endl;

    // Quitamos espacios para procesar correctamente el texto
    soloLetras(mensaje);

    // Copiamos los rotores globales para no modificarlos
    std::string rotor1Copy = rotor1.mapeo;
    std::string rotor2Copy = rotor2.mapeo;
    std::string rotor3Copy = rotor3.mapeo;

    // Ajustamos rotores a la posicion inicial
    ajustarRotor(rotor1Copy, posR1);
    ajustarRotor(rotor2Copy, posR2);
    ajustarRotor(rotor3Copy, posR3);

    std::string resultado;

    // Procesamos el mensaje introducido
    for (char c : mensaje) {
        if (isalpha(c)) {
            char cifrado = cifrarCaracter(c, rotor1Copy, rotor2Copy, rotor3Copy);
            resultado += cifrado;
        }
    }

    // Agrupamos en bloques de 5 letras
    std::string resultadoAgrupado = agruparLetras(resultado);
    std::cout << "[INFO] Agrupamos las letras en grupos de 5: " << resultadoAgrupado << std::endl;

    // Guardamos el mensaje cifrado en un archivo
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
