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

// Función para redigir al usuario a la opcion introducida
void asignacionMenuPrincipal() {

    int opcionMenu;

    imprimirMenuPrincipal();
    std::cin >> opcionMenu;

    while (true){
        if (opcionMenu == 1) {

            std::cout << "cifrado aún no implementado" << std::endl;
            return;    //quan s'hagi gestionat el xifrat redirigir usuari allà per ara ha de sortir del menu

        }
        else if (opcionMenu == 2) {

            std::cout << "descifrado aún no implementado" << std::endl;
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
