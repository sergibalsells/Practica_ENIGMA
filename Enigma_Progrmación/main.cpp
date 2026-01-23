#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

// ROTOR 1
std::string r1 = "MNBVCXZLKJHGFDSAPOIUYTREWQ";
char notchR1 = 'Z';

// ROTOR 2
std::string r2 = "ZYXWVUTSRQPONMLKJIHGFEDCBA ";
char notchR2 = 'I';

// ROTOR 3
std::string r3 = "XYZWVUTSRQPONMLKJIHGFEDCBA";
char notchR3 = 'L';

// 1. Quitar puntos, comas y simbolos y letras especiales. 

void quitarSimbolosEspeciales(std::string &mensajeParaCifrar) {
    std::string simboloEsp = "',.!??:;"; // keep your variable name
    size_t i = 0;
    while (i < mensajeParaCifrar.length()) {
        for (size_t j = 0; j < simboloEsp.length(); j++) {
            if (mensajeParaCifrar[i] == simboloEsp[j]) {
                mensajeParaCifrar.erase(i, 1);
                i--; // stay on same index after erase
                break; // stop checking other special chars for this index
            }
        }
        i++;
    }
}

// 2. Quitar Acentos.
//CHATGPT
std::string quitarAcentos(std::string mensajeParaCifrar) {
    std::string sinAcentos = mensajeParaCifrar;

    std::string original  = "áàäâãéèëêíìïîóòöôõúùüûñÁÀÄÂÃÉÈËÊÍÌÏÎÓÒÖÔÕÚÙÜÛÑ";
    std::string reemplazo = "aaaaaeeeeiiiiooooouuuunAAAAAEEEEIIIIOOOOOUUUUN";

    for (size_t i = 0; i < sinAcentos.length(); i++) {
        size_t pos = original.find(sinAcentos[i]);
        if (pos != std::string::npos) {
            sinAcentos[i] = reemplazo[pos];
        }
    }

    return sinAcentos;
}


// 3. Todo en mayusculas.
std::string convertirMayusculas(std::string &mensajeParaCifrar) {

    for (size_t i = 0; i < mensajeParaCifrar.length(); i++) {
        mensajeParaCifrar[i] = std::toupper(mensajeParaCifrar[i]); // coverrt each char in string to upper case
    }

    return mensajeParaCifrar;
}


// 4. Separar en grupos de 5. 
std::string agruparLetras(const std::string &mensaje) {

    std::string result = "";
    int count = 0;

    for (size_t i = 0; i < mensaje.length(); i++) {
        resultado += mensaje[i];
        contador++;

        if (contador == 5) {
            resultado += ' '; // add a space after every 5 letters
            contador = 0;
        }
    }

    return result;
}

int main() {

	std::string mensajeParaCifrar;

	std::cout << " Dame un mensaje para cifrar: " << std::endl;
	std::getline(std::cin, mensajeParaCifrar);

	quitarSimbolosEspeciales(mensajeParaCifrar);
	std::cout << "[INFO] Quitamos los simbolos especiales:" << mensajeParaCifrar << std::endl;

	
	quitarAcentos(mensajeParaCifrar);
	std::cout << "[INFO] Quitamos los acentos:" << mensajeParaCifrar << std::endl;


	convertirMayusculas(mensajeParaCifrar);
	std::cout << "[INFO] Convertimos en mayuscula:" << mensajeParaCifrar << std::endl;

	agruparLetras(mensajeParaCifrar);
	std::cout << "[INFO] Agrupamos las letras en grupos de 5:" << mensajeParaCifrar << std::endl;

	
}