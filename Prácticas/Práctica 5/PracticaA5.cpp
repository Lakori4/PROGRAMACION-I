//Santiago Valderrama y Pedro Zuñeda
//Grupo 7

#include<iostream>
#include<array>
#include<set>
#include<string>
#include "hPracticaA5.h"
#include "fPracticaA5.cpp"


using namespace std;

int main () {

    bool cont = 1;

    while (cont) {

    int opcion = menu();
    int dim;
    vector <vector <int>> mA;

        switch (opcion) {

            case 1:

                dim  = solDim();
                mA = solicitarMatriz(dim);
                mostrarMatriz(mA);
                for (int elem:obtenerMax_Min(mA))
                    cout << elem << " ";
                break;


            case 2:


                /* code */
                break;

            case 3:
                /* code */
                break;

            case 4:
                
                return 0;
                break;


            case 5:
                
                return 0;
                break;

            case 6:
                
                cout << "Gracias y hasta pronto.\n";
                return 0;
                break;

            default:

                cout << "La opción introducida no es válida";
                break;
        }

    }


}