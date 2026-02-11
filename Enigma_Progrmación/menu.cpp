#include <iostream>
#include <cctype>
#include "Rotores.h"
#include "menu.h"
#include "Cifrado.h"
#include "Descifrado.h"
#include "processarTxt.h"

// Función para imprimir el menú principal
void imprimirMenuPrincipal() {
    //Mostramos las opciones del menú
    std::cout << "       ENIGMA\n";
    std::cout << "-------------------\n";
    std::cout << "1. Cifrar mensaje\n";
    std::cout << "2. Descifrar mensaje\n";
    std::cout << "3. Editar rotores\n";
    std::cout << "4. Salir\n";
}

// Función para configurar la posición inicial de los rotores
void opcionDeCifrado() {
    char ventana1, ventana2, ventana3;

    std::cout << "Introduce La Posiciones de los rotores (ejemplo: A C B):";
    std::cin >> ventana1 >> ventana2 >> ventana3;

    ventana1 = std::toupper(ventana1);
    ventana2 = std::toupper(ventana2);
    ventana3 = std::toupper(ventana3);

    ajustarRotor(rotor1.mapeo, ventana1);
    ajustarRotor(rotor2.mapeo, ventana2);
    ajustarRotor(rotor3.mapeo, ventana3);

    std::cout << "[INFO] Rotor 1 ajustado: " << rotor1.mapeo << std::endl;
    std::cout << "[INFO] Rotor 2 ajustado: " << rotor2.mapeo << std::endl;
    std::cout << "[INFO] Rotor 3 ajustado: " << rotor3.mapeo << std::endl;
}

// Función para redirigir al usuario a la opción introducida
void asignacionMenuPrincipal() {
    int opcionMenu;

    do {
        imprimirMenuPrincipal();
        std::cout << "Selecciona una opción: ";
        std::cin >> opcionMenu;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (opcionMenu == 1) {
            std::cout << "Cifrado" << std::endl;
            procesoCifrado();  // Llamamos directamente a procesoCifrado
        }
        else if (opcionMenu == 2) {
            std::cout << "Descifrado" << std::endl;
            procesoDescifrado();
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
        }
    } while (true);
}