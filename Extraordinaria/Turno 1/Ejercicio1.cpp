//Santiago Valderrama

#include <iostream>
#include <array>

using namespace std;

const int dim = 3;

void getMatrix(array <array <int, dim>, dim> &m);

array <array <int, dim>, dim> getTraspuesta (const array <array <int, dim>, dim> &m);
array <array <int, dim>, dim> getAntiSim (const array <array <int, dim>, dim> &m);
void mostrarMatriz (const array <array <int, dim>, dim> &m);



int main () {


    bool cont = true;

    do {
        system("cls");

        array <array <int, dim>, dim> matriz; 
        bool esSim = false, esAnti = false;


        getMatrix(matriz);  
        

        if (matriz == getTraspuesta(matriz)) esSim = true;
        if (matriz == getAntiSim(matriz)) esAnti = true;

        cout << "\n\nMATRIZ ORIGINAL.\n";
        mostrarMatriz(matriz);

        cout << "\n\nMATRIZ TRASPUESTA.\n";
        mostrarMatriz(getTraspuesta(matriz));

        if (esSim) cout << "\n\n\tLa matriz orginal es SIMÉTRICA.";
        if (esAnti) cout << "\n\n\tLa matriz orginal es ANTISIMÉTRICA.";
        if (!esAnti && !esSim) cout << "\n\n\tLa matriz orginal NO es SIMÉTRICA ni ANTISIMÉTRICA.";



        char c;
        do
        {
            cout << "\n\n¿Desea volver a ejecutar el programa? (S/N): ";
            cin >> c;
            c = toupper(c);
        } while (c != 'N' && c != 'S');

        if (c == 'N') cont = false;
        
    } while (cont);



    return 0;
}


void getMatrix(array <array <int, dim>, dim> &m) {

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << "[" << i+1 << ", " << j+1 << "] = ";
            cin >> m[i][j];
        }
    }
}

array <array <int, dim>, dim> getTraspuesta (const array <array <int, dim>, dim> &m) {


    array <array <int, dim>, dim> t;

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            t[i][j] = m[j][i];
        }
    }
    return t;
}

array <array <int, dim>, dim> getAntiSim (const array <array <int, dim>, dim> &m) {

    array <array <int, dim>, dim> t;

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            t[i][j] = -m[j][i];
        }
    }
    return t;
}

void mostrarMatriz (const array <array <int, dim>, dim> &m) {

    for (array <int, dim> a : m) {
        cout << "\n\t| ";
        for (int n : a) {
            cout << n << " ";
        }
        cout << " |";
    }
}
