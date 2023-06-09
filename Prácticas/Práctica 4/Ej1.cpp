#include <iostream>
#include <array>
#include "PrácticaA4.h"
#include "funciones.cpp"

using namespace std;


int main() {

    string frase;
    bool cont = 1;
    array<array<int,dim>,dim> mA;
    
    

    while (cont) {
        
        
        switch (menu()) {

            case 1:

                //datosCuentos();
                break;

            case 2: 

                //operarMatriz (mA);
                break;

            case 3:

                
                cout << "\n\nIMPORTANTE: ESCRIBE O TODO EN MAYÚSCULAS O TODO EN MÍNISCULAS\n\nEscribe una frase cualquiera:";

                getline(cin, frase);
                cout << (esPalindroma(frase));
                cin.ignore();

        
                break;            

            case 4:

            cont = false;

            cout << "\nGracias, y hasta pronto.";

            break;


            default:

                cout << "La opción introducida no es válida";
                break;
        }


    } 
    return 0;
}