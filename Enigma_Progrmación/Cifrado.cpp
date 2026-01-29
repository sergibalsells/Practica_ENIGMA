#include <iostream>
#include <cctype>
#include "Rotores.h"
#include "Cifrado.h"
#include <fstream>

void introducirMensaje(){

    std::string mensaje;
    std::cout << "Introduce un mensaje para cifrar"<<std::endl;

    std::getline(std::cin, mensaje); //leer toda la entrada de usuario

    std::ofstream fitxer("Missatge.txt");

    if (fitxer.is_open()) {

        fitxer << mensaje;

        fitxer.close();

        std::cout << "[INFO] Mensaje guardado en Missatge.txt" <<std::endl;
    } else {
        std::cerr << "[ERROR] No se ha podido abrir Missatge.txt" <<std::endl;
    }
}