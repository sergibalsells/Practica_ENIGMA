#include <iostream>
#include <cctype>
#include "Rotores.h"
#include "menu.h"

// Función para imprimir el menú principal
void imprimirMenuPrincipal() {

    //Mostrar opciones de menú
    std::cout << "       ENIGMA\n";
    std::cout << "-------------------\n";
    std::cout << "1. Cifrar mensaje\n";
    std::cout << "2. Descifrar mensaje\n";
    std::cout << "3. Editar rotores\n";
    std::cout << "4. Salir\n";
    
}
//CHATGPT
void ajustarRotor(std::string &rotor, char letra) {
    size_t pos = rotor.find(letra);
    if (pos != std::string::npos) {
        rotor = rotor.substr(pos) + rotor.substr(0, pos);
    }
}

void opcionDeCifrado (){ //configuración de la ventana.

    char ventana1, ventana2, ventana3;

    std::cout << "Introduce la ventana inicial ej: A C B):";
    std::cin >> ventana1 >> ventana2 >> ventana3;

    ventana1 = std::toupper(ventana1);
    ventana2 = std::toupper(ventana2);
    ventana3 = std::toupper(ventana3);

    ajustarRotor(rotor1.mapeo, ventana1);
    ajustarRotor(rotor2.mapeo, ventana2);
    ajustarRotor(rotor3.mapeo, ventana3);

}

// Función para redigir al usuario a la opcion introducida
void asignacionMenuPrincipal() {

    int opcionMenu;

    imprimirMenuPrincipal();
    std::cin >> opcionMenu;

    while (true){
        if (opcionMenu == 1) {

            std::cout << "Cifrado" << std::endl;
            opcionDeCifrado ();
            return;    //quan s'hagi gestionat el xifrat redirigir usuari allà per ara ha de sortir del menu

        }
        else if (opcionMenu == 2) {

            std::cout << "Descifrado " << std::endl;
            opcionDeCifrado ();
            return;   //quan s'hagi gestionat el desxifrat redirigir usuari allà per ara ha de sortir del menu
    

        }
        else if (opcionMenu == 3) {

            asignacionMenuRotores();

        }
        else if (opcionMenu == 4) {

            std::cout << "Saliendo del programa.." << std::endl;
            return;

        }
        else {

            std::cout << "Entrada inválida; Por favor introduzca 1, 2, 3 o 4" << std::endl;
            return;
        }
    }
}
