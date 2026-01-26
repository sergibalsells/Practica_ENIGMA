#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <limits> // Para limpiar el buffer del cin

// Estructura para almacenar un rotor y su notch
struct Rotor {
    std::string mapeo;
    char notch;
};

// Rotores predefinidos (como en tu código original)
Rotor rotor1 = { "MNBVCXZLKJHGFDSAPOIUYTREWQ", 'Z' };
Rotor rotor2 = { "ZYXWVUTSRQPONMLKJIHGFEDCBA", 'I' };
Rotor rotor3 = { "XYZWVUTSRQPONMLKJIHGFEDCBA", 'L' };

// Función para validar un rotor
bool validarRotor(const std::string& mapeo, char notch) {
    // 1. Verificar longitud de 26 letras
    if (mapeo.length() != 26) {
        std::cerr << "[ERROR] El rotor debe tener exactamente 26 letras.\n";
        return false;
    }

    // 2. Verificar que solo contiene letras (A-Z, sin espacios ni símbolos)
    for (char c : mapeo) {
        if (!isalpha(c)) {
            std::cerr << "[ERROR] El rotor solo puede contener letras (A-Z).\n";
            return false;
        }
    }

    // 3. Verificar que no hay letras repetidas
    for (size_t i = 0; i < mapeo.length(); i++) {
        for (size_t j = i + 1; j < mapeo.length(); j++) {
            if (toupper(mapeo[i]) == toupper(mapeo[j])) {
                std::cerr << "[ERROR] El rotor tiene letras repetidas.\n";
                return false;
            }
        }
    }

    // 4. Verificar que el notch está en el mapeo
    bool notchValido = false;
    for (char c : mapeo) {
        if (toupper(c) == toupper(notch)) {
            notchValido = true;
            break;
        }
    }
    if (!notchValido) {
        std::cerr << "[ERROR] El notch '" << notch << "' no está en el mapeo del rotor.\n";
        return false;
    }

    return true;
}

// Función para mostrar los rotores actuales
void mostrarRotores() {
    std::cout << "\n--- ROTORES ACTUALES ---\n";
    std::cout << "Rotor 1: " << rotor1.mapeo << " (Notch: " << rotor1.notch << ")\n";
    std::cout << "Rotor 2: " << rotor2.mapeo << " (Notch: " << rotor2.notch << ")\n";
    std::cout << "Rotor 3: " << rotor3.mapeo << " (Notch: " << rotor3.notch << ")\n";
}

// Función para editar un rotor
void editarRotor(Rotor& rotor, const std::string& nombre) {
    std::string nuevoMapeo;
    char nuevoNotch;

    std::cout << "\nEditando " << nombre << ":\n";
    std::cout << "Mapeo actual: " << rotor.mapeo << "\n";
    std::cout << "Notch actual: " << rotor.notch << "\n";

    std::cout << "Introduce el nuevo mapeo (26 letras únicas, sin espacios): ";
    std::getline(std::cin, nuevoMapeo);

    std::cout << "Introduce el nuevo notch (1 letra del mapeo): ";
    std::cin >> nuevoNotch;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

    // Validar antes de asignar
    if (validarRotor(nuevoMapeo, nuevoNotch)) {
        rotor.mapeo = nuevoMapeo;
        rotor.notch = toupper(nuevoNotch);
        std::cout << "[INFO] " << nombre << " actualizado correctamente.\n";
    }
    else {
        std::cout << "[ERROR] No se pudo actualizar " << nombre << ". Datos inválidos.\n";
    }
}

// Función para guardar un rotor en un archivo
void guardarRotorEnArchivo(const Rotor& rotor, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << rotor.mapeo << "\n" << rotor.notch;
        std::cout << "[INFO] " << nombreArchivo << " guardado correctamente.\n";
    }
    else {
        std::cerr << "[ERROR] No se pudo guardar en " << nombreArchivo << ".\n";
    }
}

// Función para guardar todos los rotores en archivos
void guardarRotoresEnArchivos() {
    guardarRotorEnArchivo(rotor1, "rotor1.txt");
    guardarRotorEnArchivo(rotor2, "rotor2.txt");
    guardarRotorEnArchivo(rotor3, "rotor3.txt");
}

// Función para imprimir el menú de rotores
void imprimirMenuRotores() {
    std::cout << "\n=== MENÚ GESTIÓN DE ROTORES ===\n";
    std::cout << "1. Mostrar rotores actuales\n";
    std::cout << "2. Editar Rotor 1\n";
    std::cout << "3. Editar Rotor 2\n";
    std::cout << "4. Editar Rotor 3\n";
    std::cout << "5. Guardar rotores en archivos\n";
    std::cout << "0. Volver al menú principal\n";
    std::cout << "Selecciona una opción: ";
}

// Función para manejar el menú de rotores
void asignacionMenuRotores() {
    int opcion;
    do {
        imprimirMenuRotores();
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

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
            std::cout << "Volviendo al menú principal...\n";
            break;
        default:
            std::cout << "[ERROR] Opción no válida. Intenta de nuevo.\n";
        }
    } while (opcion != 0);
}

// Función para imprimir el menú principal
void imprimirMenuPrincipal() {
    std::cout << "\n=== MENÚ PRINCIPAL ===\n";
    std::cout << "1. Gestión de rotores\n";
    std::cout << "2. Cifrar/Descifrar mensaje\n";
    std::cout << "0. Salir\n";
    std::cout << "Selecciona una opción: ";
}

// Función para manejar el menú principal
void asignacionMenuPrincipal() {
    int opcion;
    do {
        imprimirMenuPrincipal();
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer

        switch (opcion) {
        case 1:
            asignacionMenuRotores();
            break;
        case 2: {
            // Lógica de cifrado/descifrado (tu código original)
            std::string mensajeParaCifrar;
            char posR1, posR2, posR3;

            std::cout << "Introduce la posición inicial de los rotores (ejemplo: A B C): ";
            std::cin >> posR1 >> posR2 >> posR3;
            std::cin.ignore();

            // Ajustar rotores (usar tu función ajustarRotor)
            // ajustarRotor(rotor1.mapeo, posR1);
            // ajustarRotor(rotor2.mapeo, posR2);
            // ajustarRotor(rotor3.mapeo, posR3);

            std::cout << "[INFO] Rotor 1 ajustado: " << rotor1.mapeo << std::endl;
            std::cout << "[INFO] Rotor 2 ajustado: " << rotor2.mapeo << std::endl;
            std::cout << "[INFO] Rotor 3 ajustado: " << rotor3.mapeo << std::endl;

            std::cout << "Dame un mensaje para cifrar: ";
            std::getline(std::cin, mensajeParaCifrar);

            // Procesar mensaje (usar tus funciones existentes)
            // quitarSimbolosEspeciales(mensajeParaCifrar);
            // mensajeParaCifrar = quitarAcentos(mensajeParaCifrar);
            // mensajeParaCifrar = convertirMayusculas(mensajeParaCifrar);
            // mensajeParaCifrar = agruparLetras(mensajeParaCifrar);

            std::cout << "[INFO] Mensaje procesado: " << mensajeParaCifrar << std::endl;
            break;
        }
        case 0:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "[ERROR] Opción no válida. Intenta de nuevo.\n";
        }
    } while (opcion != 0);
}

// Función principal
int main() {
    std::cout << "=== MÁQUINA ENIGMA - FASE 1: GESTIÓN DE ROTORES ===\n";
    asignacionMenuPrincipal();
    return 0;
}