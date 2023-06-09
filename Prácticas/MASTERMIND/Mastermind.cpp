//Carlos Bauluz y Santiago Valderrama
//Trabajo Final: Mastermind

#include "Mastermind.h"

using namespace std;



string nom1 () { //Pide el nombre del primer jugador

    string nom1;

    cout << "\n\t!Bienvenidos a Mastermind!\n\nEn este juego de deducción dos jugadores se enfrentarán para intentar adivinar el código secreto del rival.";

    cout << "\n\nPor favor, jugador 1, introduce tu nombre: ";
    cin >> nom1;
    cin.ignore();

    return nom1;
}

string nom2 () { //Pide el nombre del segundo jugador

    string nom2;
    cout << "\n\nMuy bien, ahora jugador 2, introduce tu nombre: ";
    cin >> nom2;
    cin.ignore();
    return nom2;
}

bool chkName (string const&j1, string const&j2) { //Pregunta a los jugadores si los nombres son correctos

    bool cont;

    cout << "\n¡Genial! Entonces el jugador 1 se llamará " << j1 << ", y el jugador 2 se llamará " << j2 << ". \n¿Es correcto?\n\nNo = 0\nSí = 1\n";

    cin >> cont;
    cin.ignore();

    if (!cont) {

        system("cls");
        return cont;
    }

    else {

        return cont;
    }
    
} 

//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------------------------------------

 void Reglas(string const&j1, string const&j2) { //Explica las reglas del juego

    string enter;

    cout << "\n¡Genial! Ahora os contaré las reglas del juego.\n\n\n";
    cout << "1. " << j1 << " tecleará una sucesión de letras correspondientes con los ocho colores disponibles, por ejemplo \"bnzag\" (blanco, negro, azul, amarillo y gris), " << j2 << " no pude mirar esta combinación\n\n";
    cout << "2. Dicha combinación será de cinco colores y no se podrá repetir color\n\n";
    cout << "3. Una vez que " << j1 << " haya tecleado la combinación, pulsa Intro.\n\n";
    cout << "4. Ahora es el turno de " << j2 << ", deberás adivinar la combinación secreta.\n\n";
    cout << "5. Después de cada intento, dos números aparecerán a la derecha, uno indica la cantidad de colores cuya posición has acertado, y otro que indica la cantidad de colores que has acertado pero has posicionado mal\n\n";
    cout << "6. " << j2 << " dispondrá de 20 intentos para adivinar la combinación secreta.\n\n";
    cout << "7. Tras la primera ronda, se cambiarán los puestos, y " << j1 << " intentará adivinar el código secreto de " << j2 << " siguiendo las reglas anteriores.\n\n";
    cout << "8. El ganador será el que adivine la combinación en menos intentos\n\n";
    cout << "9. ¡A divertirse!\n";
    //cout << "\n\nPULSA ENTER PARA CONTINUAR";
    //cin.ignore();
    system("pause");
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------


string sec1 (string const&j1, string const&j2) {

    string sec;
    system("cls");
    cout << "\n\n" << j1 << " escribe tu código secreto. Recuerda que la combinación tiene que ser de cinco colores y no se pueden repetir.\n\n" << j2 << " NO PUEDE MIRAR.";

    cout << "\n\n\tR - Rojo\tV - Verde\tA - Amarillo\tZ - Azul\n\tG - Gris\tM - Morado\tB - Blanco\tN - Negro\n";
    cin >> sec;
    system("cls");    

    return sec;
}

string chkSec (string const&j1, string const&j2) {

    bool cont = true;
    string c;

     do {

        c = sec1(j1, j2);
        cont = true;
        
        if (c.size() == 5) { 

            for (char elem: c) {
                
                if (elem != 'a' && elem != 'b' && elem != 'n' && elem != 'g' && elem != 'r' && elem != 'v' && elem != 'm' && elem != 'z') {

                    cont = false;
                }
            }

            for (int i = 0; i < c.size(); i++){

                int j = 0;

                for (char elem: c){

                    if (c.at(i) == elem){

                        j++;
                    }

                     if (j > 1){

                        cont = false;
                    }
                }
            }

            if (!cont) {

                cout << "\nHas introducido una letra no válida o has introducido una letra dos veces.\nRecuerda que las letras las tienes que escribir en minúsculas y que no se pueden repetir colores.";
            }
        }

        else {

            cont = false;
            cout << "\nNo has introducido cinco letras. recuerda que la combinación debe de ser de cinco colores.";
        }

    } while (!cont);

    return c;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------


string guess(string const&j2) {

    string g;

    cout << "\n" << j2 << ", intenta adivinar la combinación. \nRecuerda escribir cinco letras, sin repetir, correspondientes con el código de colores";
    cout << "\n\n\tR - Rojo\tV - Verde\tA - Amarillo\tZ - Azul\n\tG - Gris\tM - Morado\tB - Blanco\tN - Negro\n";
    cin >> g;

    return g;
}

string chkGuess (string const&j2) {

    bool cont = true;
    string g;

     do {

        g = guess(j2);
        cont = true;
        
        if (g.size() == 5) { 

            for (char elem: g) {
                
                if (elem != 'a' && elem != 'b' && elem != 'n' && elem != 'g' && elem != 'r' && elem != 'v' && elem != 'm' && elem != 'z') {

                    cont = false;
                }
            }

            for (int i = 0; i <= 4; i++){

                int j = 0;

                for (char elem: g){

                    if (g.at(i) == elem){

                        j++;
                    }

                     if (j > 1){

                        cont = false;
                    }
                }
            }

            if (!cont) {

                cout << "\nHas introducido una letra no válida o has introducido una letra dos veces. Recuerda que no se pueden repetir colores y que las letras las tienes que escribir en minúsculas.";
            }
        }

        else {

            cont = false;
            cout << "\nNo has introducido cinco letras. recuerda que la combinación debe de ser de cinco colores.";
        }

    } while (!cont);

    return g;
}

int score(string const&j2, string &g, string const&c) {

    int line = 1;

    for (line = 1; line <= 20; line++) {

        g = chkGuess(j2);

        int cyp = 0;
        int sc = 0;

        for (int i = 0; i < 5; i++) {

            if (g.at(i) == c.at(i)){

                cyp++;
            }
        }

        for (int i = 0; i < 5; i++) {

            for (char elem: c) {

                if (g.at(i) == elem) {

                    sc++;
                }
            }
        }

        if (cyp == 5) {

            cout << "\n\n¡ACERTASTE! Has adivinado el código secreto en " << line << " líneas.\n";
            //cout << "\nPULSA ENTER PARA CONTINUAR";
            //cin.ignore();
            system("pause");
            system("cls");
            return line;
        }
        cout << "\n\t$\t$\t$\t$\t$\tColor y posición\tSólo color\t(" << line << "/20)\n";
        cout << "\t" << (g.at(0)) << "\t" << (g.at(1)) << "\t" << (g.at(2)) << "\t" << (g.at(3)) << "\t" << (g.at(4)) << "\t\t" << cyp << "\t\t\t" << sc << "\n\n";
    }

    return line;       
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------------------

void end (string const&j1, string const&j2, int line1, int line2) {

    system("cls");

    if (line1 < line2) {
        
        cout << "\n¡ENHORABUENA " << j1 << ". Has ganado con una puntuación de " << line1 << " línea(s).\n";
    }

    else if (line2 < line1) {

        cout << "\nENHORABUENA " << j2 << ". Has ganado con una puntuación de " << line2 << " línea(s).\n";
    } 

    else {

        cout << "\n¡EMPATE! Los dos habéis adivinado el código secreto en " << line1 << " línea(s).\n";
    }
}
