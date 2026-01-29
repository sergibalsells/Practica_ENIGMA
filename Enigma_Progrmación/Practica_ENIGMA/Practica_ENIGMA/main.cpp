#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits> //Llibreria per a netejar el buffer del cin

// Estructura per a emmagatzemar un rotor y el seu notch.
struct Rotor {
    std::string mapeo;
    char notch;
};

//Rotors predefinits establerts per nosaltres.
Rotor rotor1 = { "MNBVCXZLKJHGFDSAPOIUYTREWQ", 'Z' };
Rotor rotor2 = { "ZYXWVUTSRQPONMLKJIHGFEDCBA", 'I' };
Rotor rotor3 = { "XYZWVUTSRQPONMLKJIHGFEDCBA", 'L' };

// Funció per a validar un rotor
bool validarRotor(const std::string& mapeo, char notch) {

    //Verifiquem que el rotor té 26 lletres
    if (mapeo.length() != 26) {
        std::cerr << "[ERROR] El rotor ha de contenir exactament 26 lletres.\n";
        return false;
    }

    //Verifiquem que només conté lletres de la A a la Z, sense espais ni símbols
    for (char c : mapeo) {
        if (!isalpha(c)) {
            std::cerr << "[ERROR] El rotor nomes pot tenir lletres, (A-Z).\n";
            return false;
        }
    }

    //Verifiquem que no hi ha lletres repetides
    for (size_t i = 0; i < mapeo.length(); i++) {
        for (size_t j = i + 1; j < mapeo.length(); j++) {
            if (toupper(mapeo[i]) == toupper(mapeo[j])) {
                std::cerr << "[ERROR] El rotor te lletres repetides.\n";
                return false;
            }
        }
    }

    //Verificar que el notch está en el mapeo
    bool notchValido = false;
    for (char c : mapeo) {
        if (toupper(c) == toupper(notch)) {
            notchValido = true;
            break;
        }
    }
    if (!notchValido) {
        std::cerr << "[ERROR] El notch '" << notch << "' no està en el mapeo del rotor.\n";
        return false;
    }

    return true;
}

//Funció per a mostrar els rotors actuals
void mostrarRotores() {
    std::cout << "\n--- ROTORS ACTUALS ---\n";
    std::cout << "Rotor 1: " << rotor1.mapeo << " (Notch: " << rotor1.notch << ")\n";
    std::cout << "Rotor 2: " << rotor2.mapeo << " (Notch: " << rotor2.notch << ")\n";
    std::cout << "Rotor 3: " << rotor3.mapeo << " (Notch: " << rotor3.notch << ")\n";
}

//Funció per a editar un dels rotors (Ajuda de la IA per la complexitat)
void editarRotor(Rotor& rotor, const std::string& nombre) {
    std::string nuevoMapeo;
    char nuevoNotch;

    std::cout << "\nEditan " << nombre << ":\n";
    std::cout << "Mapeo actual: " << rotor.mapeo << "\n";
    std::cout << "Notch actual: " << rotor.notch << "\n";

    std::cout << "Introduei el nou mapeo (26 letras uniques, sense espais): ";
    std::getline(std::cin, nuevoMapeo);

    std::cout << "Introdueix el nou notch (1 lletra del mapeo): ";
    std::cin >> nuevoNotch;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Netejar el Buffer de entrada de text

    //Validar avans d'asignar
    if (validarRotor(nuevoMapeo, nuevoNotch)) {
        rotor.mapeo = nuevoMapeo;
        rotor.notch = toupper(nuevoNotch);
        std::cout << "[INFO] " << nombre << " actualizant correctament.\n";
    }
    else {
        std::cout << "[ERROR] No s'ha pogut actualizar " << nombre << ". Dades invalides.\n";
    }
}

//Funció per a guardar un rotor en un archiu
void guardarRotorEnArchivo(const Rotor& rotor, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << rotor.mapeo << "\n" << rotor.notch;
        std::cout << "[INFO] " << nombreArchivo << " guardad correctament.\n";
    }
    else {
        std::cerr << "[ERROR] No s'ha pogut guardar en " << nombreArchivo << ".\n";
    }
}

//Funció per a guardar tots els rotors en archius
void guardarRotoresEnArchivos() {
    guardarRotorEnArchivo(rotor1, "rotor1.txt");
    guardarRotorEnArchivo(rotor2, "rotor2.txt");
    guardarRotorEnArchivo(rotor3, "rotor3.txt");
}

//Funció per a imprimir el menú de rotors
void imprimirMenuRotores() {
    std::cout << "\n=== MENU GESTIO DE ROTORS ===\n";
    std::cout << "1. Mostrar rotors actuals\n";
    std::cout << "2. Editar Rotor 1\n";
    std::cout << "3. Editar Rotor 2\n";
    std::cout << "4. Editar Rotor 3\n";
    std::cout << "5. Guardar rotors en archius\n";
    std::cout << "0. Sortir\n";
    std::cout << "Selecciona una opcio: ";
}

//Funció per a poder controlar el menú dels rotors (Ajuda de la IA per a poder netejar el BUffer)
void asignacionMenuRotores() {
    int opcion;
    do {
        imprimirMenuRotores();
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Netejar el Buffer de entrada de text

        switch (opcion) {
        case 1:
            mostrarRotores();
            break;
        case 2:
            editarRotor(rotor1, "Rotor 1");
            break;
        case 3:
            editarRotor(rotor2, "Rotor 2");
            break;
        case 4:
            editarRotor(rotor3, "Rotor 3");
            break;
        case 5:
            guardarRotoresEnArchivos();
            break;
        case 0:
            std::cout << "Sortint del programa...\n";
            break;
        default:
            std::cout << "[ERROR] Opció no valida. Intenta de nou.\n";
        }
    } while (opcion != 0);
}

//Funció principal (DE MOMENT NOMÉS PER A LA GESTIÓ DE ROTORS)
int main() {
    std::cout << "=== MAQUINA ENIGMA - GESTIO DE ROTORS ===\n";
    asignacionMenuRotores();
    return 0;
} 
