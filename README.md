## Practica_ENIGMA
Aquest projecte pretén simular la màquina Enigma creada el 1918 per l’enginyer alemany Arthur Scherbius, poc després de la Primera Guerra Mundial. La implementació recrea la lògica dels rotors i permet el xifratge i el desxifratge de fitxers mitjançant el llenguatge de programació C++.

## Abans de començar

Les instruccions següents us guiaran per configurar el simulador de màquina Enigma a la vostra màquina local, cosa que us permetrà executar el programa, configurar els paràmetres de la màquina i xifrar o desxifrar els missatges.

## Requisits previs

- Compilador de C++ amb suport per a C++ 17 (GCC 13 o més recent)

    - g++ --version --> comprova la versió que tens actualment per saber si has de seguir els següents pasos o no 
    - sudo apt-get update --> actualitza el sistema
    - sudo apt-get install build-essential --> per intsal·lar gcc i g++
    - g++ --version --> torna a comprova la versió
 

## Caracteristiques Técniques en parts del codi: 

En algunes parts del codi es pot veure que hi han funcions i accions més tecniques que hem fet servir, aquí expliquem les més difícils de poder entrendre. 
    *En el codi també están explicades en els llocs corresponenets. 

1) std::string& (passatge per referència):
   En aquest cas ho hem fet servir per a l'eficiència de la memòria, d'aquest cas evitem que el programa creï una 
   nova còpia del text en cada funció. Treballo amb l'adreça original a la RAM.

2) Operador de mòdul (% 26): 
   Assegurem la circularitat de l'alfabet, d'aquesta forma Si afegim posicions i anem més enllà de la 'Z', 
   el mòdul ens retorna a l'inici ('A'). 

3) static_cast<char>:
   Seguretat tipogràfica. Les operacions matemàtiques retornen enters, així que forço que el resultat torni a ser un caràcter vàlid. 

4) .find():
   En el codi podem veure que es fan servir .find(), sobretot en el Descifrar.cpp, amb aixó el que hem fet es un analisi invertit,
   el qeu fem es localitzar directament la posició del caracter xifrat en el rotor per a poder poder així recuperar el seu index original. 

## Instalació

1. Clona el repositori:

    git clone https://github.com/sergibalsells/Practica_ENIGMA.git

2. Entra en el directory del projecte

    cd Enigma_Progrmación/

3. Compila el codi

    g++ *.cpp -o main

4. Executa el programa

    ./main 
    main.exe --> Windows

## Executa proves

A continuació s'inclourien proves de funcionament del codi, en aquest cas com es per al professor
ell ho executarà, es fará la comprovació del codi per a ell mateix. 


## Desplegament

1. Compila el programa --> g++ *.cpp -o main

    Assegureu-vos que el sistema tingui instal·lat g++ o un altre compilador de C++ compatible.

2. Copia l'executable a una ubicació system-wide i definiu els permisos:

    Copiar --> sudo cp main /usr/local/bin/Enigma

    Dona drets d'execució--> sudo chmod +x /usr/local/bin/Enigma

3. Executa el programa: 

    Executar --> Enigma 


## Construit amb

- C++ – El llenguatge de programació  utilitzat per a la implementació d'Enigma.

- g++ – Col·lecció de compiladors GNU per compilar codi C++.

- Linux / macOS / Windows– Plataformes on es pot executar el programa.


## Contribucions

Les contribucions a aquest projecte són benvingudes!

Com fer-ho:

1. Feu un Fork del repositori.

2. Creau una nova branch per als canvis.

3. Aplique els canvis i feu un commit.

4. Feu un push de la branca i obrir una sol·licitud pull.

Assegureu-vos que el vostre codi segueix l'estil existent i garanteix el correcte funcionament del programa.

## Autors:

Sergi Ballsells i Simarprit Singh I Kaur

## Licencia:

Aquest projecte està sota la Llicència  GPL-3.0 - GNU GENERAL PUBLIC LICENSE Versió 3, 29 de juny de 2007

## Agraïments

Gràcies al professor per ajudar-nos amb el seguiment i resoldrens els dubtes que hem pogut tenir durant el projecte. 
