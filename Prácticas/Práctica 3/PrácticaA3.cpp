//Santiago Valderrama y Pedro Zuñeda
//Grupo 7


#include <iostream>
#include <array>
#include <string>
#include "frase.h"





int main () {

    int menu;
    bool cont = true;
    array <string,10> palabras;
    a analisisFrase;

    while (cont == true) {

        cout << "\nSelecciona una de las siguientes opciones \n1. Longitud de las frases.\n2. Analizar frase.\n3. Matriz de números pares e impares.\n4. Salir del programa.\n" ;
        cin >> menu;

        switch (menu) {

        case 1:
            

            for (int i = 0; i < 10; i++) {

                cout << "Escribe una palabra: ";
                cin >> palabras.at(i);
            }

            for (int i = 0; i < palabras.size(); i++) {

                cout << "\nLa palabra " << palabras[i] << " tiene " << palabras[i].size() << " letras y su inicial es " << palabras[i].at(0);
            } 

            break;

            



        case 2:

            

            cout << "Escribe una frase: ";
            cin.ignore();
            getline(cin, analisisFrase.frase);
           

                for (int i = 0; i < analisisFrase.frase.size(); i++) {

                    if (analisisFrase.frase[i] == 'a' || analisisFrase.frase[i] == 'e' || analisisFrase.frase[i] == 'i' || analisisFrase.frase[i] == 'o' || analisisFrase.frase[i] == 'u') {

                        analisisFrase.voc++;
                    }

                    else if (analisisFrase.frase[i] == ' ') {

                        analisisFrase.esp++;
                    }

                    else if (analisisFrase.frase[i] == ',' || analisisFrase.frase[i] == '.' || analisisFrase.frase[i] == '?' || analisisFrase.frase[i] == '!') {

                        analisisFrase.car++;
                    }

                    else {

                        analisisFrase.cons = analisisFrase.frase.size() - analisisFrase.voc - analisisFrase.car - analisisFrase.esp; 
                    }

                    analisisFrase.pal = analisisFrase.esp + 1;

                }

                analisisFrase.pos = analisisFrase.frase.find("del", analisisFrase.pos);

                    while (analisisFrase.pos!= -1) {

                        analisisFrase.pos++;
                        analisisFrase.pos = analisisFrase.frase.find("del", analisisFrase.pos);
                        
                        analisisFrase.del++;
                    }

                cout << "La frase: " << analisisFrase.frase << " contiene: \n" << analisisFrase.voc << " vocales, " << analisisFrase.cons << " consonantes, " << analisisFrase.esp << " espacios y " << analisisFrase.car << " caracteres.";
                cout << analisisFrase.pal << " palabras donde hay " << analisisFrase.del << " que son \"del\"";

            break;



       case 3:

            array <array<int, 3>, 3> matriz;
            array <array<int, 3>, 3> matriz_par;

            cout << "Introduce los datos de una matriz con valores entre 1 y 5\n\n";
            cout << "\tDATOS DE LA MATRIZ\n\n";

            for (int fila = 0; fila < 3; fila++) {

            for (int col = 0; col < 3; col++) {

            cout << "matriz [" << fila << ", " << col <<"] = ";
            cin >> matriz[fila][col];

            if (matriz [fila][col] < 1 || matriz [fila][col] > 5) {

                cout << "El valor introducido no es correcto, vas a regresar al menú.";

                col = 4;
                fila = 4;
                break;
            }
            }
            }


            cout << "La matriz te ha quedado así: \n\n";

            for (array <int, 3>  fila : matriz) {

            cout << "\t|";

            for(int dato : fila) {

            cout << dato << " ";

            cout << "|\n";
            }
            }


           for (array <int, 3>  fila : matriz) {

            for(int dato : fila) {

                if (dato % 2) {


                }
            }
            }

            break;


       case 4:

            cout << "Gracias. Hasta pronto";
            cont = false;
            break;

        default:

            cout << "La opción no es válida, por favor vuelva a seleccionar otra opción.\n";
            break; 
    }
}

return 0;
}
