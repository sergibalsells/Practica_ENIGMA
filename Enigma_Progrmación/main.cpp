#include <iostream>
#include <fstream>
#include <string>



// ROTOR 1
std::string r1 = "MNBVCXZLKJHGFDSAPOIUYTREWQ",
char notchR1 = 'Z';

// ROTOR 2
std::string r2 = "ZYXWVUTSRQPONMLKJIHGFEDCBA ",
char notchR2 = 'I';

// ROTOR 3
std::string r3 = "XYZWVUTSRQPONMLKJIHGFEDCBA",
char notchR3 = 'L';


int main() {

	std::string mensajeParaCifrar;

	std::cout << " Dame un mensaje para cifrar: " << std::endl;
	std::getline(std::cin, mensajeParaCifrar);


	// 1. Quitar puntos, comas y simbolos y letras especiales. 
	std::string simboloEsp = "',.!¡¿?:;ñç";
	for (size_t i = 0; i < mensajeParaCifrar.length(); i++) // Para cada letra..
	{
		for (size_t j = 0; j < simboloEsp.length(); j++) // y por cada simbolo especial
		{
			if (mensajeParaCifrar[i] == simboloEsp[j])
			{
				mensajeParaCifrar.erase(i, 1);

			}
		}
	}
	std::cout << "[INFO] Quitamos los simbolos especiales:" << mensajeParaCifrar << std::endl;

	// 2. Quitar Accentos.


	// 3. Todo en mayusculas.
	// 4. Separar en grupos de 5. 
}