//Santiago Valderrama y Pedro Zuñeda
//Grupo 7

#include <iostream>
#include <array>
#include <vector>
#include <set>
#include "hPracticaA5.h"
;

using namespace std;

int menu () {

    int opcion;

    cout << "¡Bienvenido!\n\n";
    cout << "\t1. Elementos máximos y mínimos de una matriz\n";
    cout << "\t2. Crear vector filas de la matriz.\n";
    cout << "\t3. Crear vector columnas de la matriz.\n";
    cout << "\t4. Multiplicar dos matrices.\n";
    cout << "\t5. Crear la traspuesta de una matriz.\n";
    cout << "\t6. Salir del programa.\n";
    cout << "Teclea la opción: ";
  

    cin >> opcion;
    cin.ignore();
  
    return opcion;
}



int solDim() {

    bool isValid;
    int di;
    do {
    cout << "Escribe la dimensión de la matriz: ";
    cin >> di;
    cin.ignore();
    } while (di < 2 || di > 100);

    return di;
}


vector <vector <int>> solicitarMatriz(int dim) {

    int dato;

    vector <vector <int>> matriz;
    matriz.resize(dim);

    for (int f = 0; f < dim; f++){

        for (int c = 0; c < dim; c++) {

            cout << "POSICIÓN DE LA MATRIZ: [" << f << ", " << c << "]: ";
            cin >> dato;

            matriz[f].push_back(dato);
        }
    } 

    return matriz;
}



void mostrarMatriz (vector <vector <int>>mA) {
    
    int dim = mA.size();
    
    for (int f = 0; f < dim; f++){

        cout << "| ";

        for (int c = 0; c < dim; c++) {

            cout <<  mA.at(f).at(c);

        }
        cout << " |\n";
    } 
}

vector <int> obtenerMax_Min (vector <vector <int>>mA){

        vector <int> max_min;
        int dim = mA.size();
        int max = -2147483648;
        int min = 2147483647;
    
    for (int f = 0; f < dim; f++){

        for (int c = 0; c < dim; c++) {

            if (mA.at(f).at(c) > max) {
                
                max = mA.at(f).at(c);
            }


            if (mA.at(f).at(c) < min) {
             
                min = mA.at(f).at(c);
            }
        }
    } 

    max_min.push_back(max);
    max_min.push_back(min);

    return max_min;

}
