#include <iostream>
#include <cctype>
#include <fstream>
#include <limits>
#include "Descifrado.h"
#include "Rotores.h"
#include "processarTxt.h"

// Funcion para pasar un caracter a tramos de un rotor lo hacemos en direccion inversa para descifrar
//Tambien lo hacemos con ayuda de la IA para poder corregir errores el pasar de forma inversa los rotores. 
char pasarPorRotorInverso(const std::string& rotor, char c) {
    size_t pos = rotor.find(toupper(c));
    if (pos != std::string::npos) {
        return static_cast<char>('A' + pos);
    }
    return c;
}

// Funcion para descifrar un caracter usando los 3 rotores
// Ayuda de la IA
char descifrarCaracter(char c,
                       std::string& rotor1,
                       std::string& rotor2,
                       std::string& rotor3) {
    c = toupper(c);

    //Aplicamos Rotor 3 de forma inversa
    size_t pos = rotor3.find(c);
    c = static_cast<char>('A' + pos);

    //Aplicamos Rotor 2 de forma inversa
    pos = rotor2.find(c);
    c = static_cast<char>('A' + pos);

    //Aplicamos Rotor 1 de forma inversa
    pos = rotor1.find(c);
    c = static_cast<char>('A' + pos);

    // Aplicamos Cesar de forma inversa (-2)
    c = 'A' + ((c - 'A' - 2 + 26) % 26);

    return c;
}


// Creamos Funcion principal para descifrar un mensaje pedido
void procesoDescifrado() {
    std::string mensaje;
    char posR1, posR2, posR3;

    std::cout << "\n=== DESCIFRADO DE MENSAJE ===\n";

    // Pedimos posiciones iniciales de los rotores ( Deberia de coincidir con el del cifrado 
    // siempre que se en caso que se haya cifrado antes. 
    std::cout << "Introduce la posici�n inicial de los rotores (ejemplo: A B C): ";
    std::cin >> posR1 >> posR2 >> posR3;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Pedimos el mensaje a descifrar
    std::cout << "Introduce el mensaje a descifrar: ";
    std::getline(std::cin, mensaje);

    // Procesamos el mensaje (quitamos simbolos, acentos, convertimos todo a mayusculas)
    quitarSimbolosEspeciales(mensaje);
    std::cout << "[INFO] Quitamos los simbolos especiales: " << mensaje << std::endl;

    mensaje = quitarAcentos(mensaje);
    std::cout << "[INFO] Quitamos los acentos: " << mensaje << std::endl;

    convertirMayusculas(mensaje);
    std::cout << "[INFO] Convertimos en mayuscula: " << mensaje << std::endl;

    // Quitamos los espacios para procesar correctamente
    soloLetras(mensaje);

    // Copiamos los rotores globales para no modificarlos
    std::string rotor1Copy = rotor1.mapeo;
    std::string rotor2Copy = rotor2.mapeo;
    std::string rotor3Copy = rotor3.mapeo;

    // Ajustamos los rotores a la posicion inicial
    ajustarRotor(rotor1Copy, posR1);
    ajustarRotor(rotor2Copy, posR2);
    ajustarRotor(rotor3Copy, posR3);

    std::string resultado;

    // Procesamos el mensaje
    for (char c : mensaje) {
        if (isalpha(c)) {
            char descifrado = descifrarCaracter(c, rotor1Copy, rotor2Copy, rotor3Copy);
            resultado += descifrado;
        }
    }

    // Agrupamos en bloques de 5 letras
    std::string resultadoAgrupado = agruparLetras(resultado);
    std::cout << "[INFO] Mensaje descifrado: " << resultadoAgrupado << std::endl;

    // Guardamos el mensaje descifrado en un archivo llamado MensajeDescifrado.txt
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
