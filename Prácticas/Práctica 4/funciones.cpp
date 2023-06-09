#include <iostream>
#include <array>
#include "PrácticaA4.h"

using namespace std;

int menu () {   
    
    const int OPCIONES{4}; // Constante para cambiar fÃƒÂ¡cilmente el nÃƒÂºmero de opciones
    int miOpcion;

    cout << "\n\n\t1. Títulos de cuentos infantiles.";
    cout << "\n\n\t2. Operar con una matriz.";
    cout << "\n\n\t3. Determinar si una palabra es palindroma.";
    cout << "\n\n\t4. Salir Programa.";
    cout << "\n\n\t   Teclee la opcion: ";

    do {
    cin >> miOpcion;
    cin.ignore();   // Limpia el buffer de entrada

    if (miOpcion < 1 || miOpcion > OPCIONES)
        cout << "\n\n\tLa opcion no es valida. Por favor, vuelva a seleccionar otra opcion" << endl << endl;
    } while (miOpcion < 1 || miOpcion > OPCIONES);

    return miOpcion;
}


bool esPalindroma (string frase) {

    int pos = 0;
    string pal;

    
        pos = frase.find(" ", pos);

        if (pos == -1) {

            for (int i = frase.size()-1; i >= 0; i--) { 

                pal.push_back(frase.at(i));
            }
            cout << pal << endl << frase <<endl;
            if (pal == frase) {
                
                return true;
            }

            else 
                return false;
        }
        else 
            frase.erase(pos,1);

}

/*
void operarMatriz (array<array<int,dim>,dim> a) {

    array<array<opM,dim2>,dim2> matrizNew;

    cout << "Introduce los valores de la matriz del 0 al 9.\n";
        for(int f = 0; f < dim; f++)
            for(int c = 0; c < dim; c++){

            //while (a.at(f).at(c) < 0 || a.at(f).at(c) > 9) {

            cout << "\nIntroduzca el valor [" << f+1 << ", " << c+1 << "]: ";
            cin >> a.at(f).at(c);

            while (a.at(f).at(c) < 0 || a.at(f).at(c) > 9) { 
                cout << "\nIntroducir un valor válido\n\n";
                cout << "\nIntroduzca el valor [" << f+1 << ", " << c+1 << "]: ";
                cin >> a.at(f).at(c);
            }
            }
        

    cout << "MATRIZ DATO";

        for (array<int, dim> fila:a) {

            cout << "\n|";
        
            for (int dato: fila) {

                cout << dato << " ";
            }

            cout << "|";
        }
    cout << "\n";

    matrizNew.at(0).at(0) = 0;
    matrizNew.at(1).at(0) = 0;
    matrizNew.at(2).at(0) = 0;
    

        for(int f = 0; f < dim ; f++) {
            int c = f++;
            for(; c < dim; c++){

                matrizNew.at(0).at(0) = a.at(f).at(c) + matrizNew.at(0).at(0);

            }
        }

        for(int f = 0; f < dim ; f++) {

            int c = f;
                matrizNew.at(1).at(0) = a.at(f).at(c) + matrizNew.at(1).at(0);

        }

        for(int c = 0; c < dim ; c++) {
            int f = c++;
            for(; f < dim; f++){

                matrizNew.at(0).at(0) = a.at(f).at(c) + matrizNew.at(0).at(0);

            }
        }


        if (matrizNew.at(0).at(0) % 2 == 0) 

            matrizNew.at(0).at(1) = true;

        
        else 
            matrizNew.at(0).at(1) = false;


        if (matrizNew.at(1).at(0) % 2 == 0) 

            matrizNew.at(1).at(1) = true;

        
        else 
            matrizNew.at(1).at(1) = false;

        

        if (matrizNew.at(2).at(0) % 2 == 0) 

            matrizNew.at(2).at(1) = true;

        
        else 
            matrizNew.at(2).at(1) = false;

        
        matrizNew.at(0).at(2) = "Superior"
        matrizNew.at(1).at(2) = "Diagonal"
        matrizNew.at(2).at(2) = "Inferior";


        for (array<int, dim> fila:matrizNew) {

            cout << "\n|";
        
            for (int dato: fila) {

                cout << dato << " ";
            }

            cout << "|";
        }
    cout << "\n";
        


}



/*
void datosCuentos() {

    array<cuento, 5> datosCuentos;

    for (int i = 0; i < 5; i++) {

        string titulo;
        cout << "Escribe el título número " << i + 1 << ": ";
        getline(cin, titulo);
        cin.ignore();

        datosCuentos.at(i).titulo() = titulo;


    }
} 
*/


