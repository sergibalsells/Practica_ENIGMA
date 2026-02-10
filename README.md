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

A continuació s'inclouen proves automatitzades per garantir que el programa funciona correctament i compleix el seu objectiu.

- 

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

Sergi Ballsells
Simarprit Singh I Kaur

## Licencia:

Aquest projecte està sota la Llicència  GPL-3.0 - GNU GENERAL PUBLIC LICENSE Versió 3, 29 de juny de 2007

## Agraïments

Gràcies als nostres companys de classe per provar-ho i donar-nos la seves opinions i crítiques.
