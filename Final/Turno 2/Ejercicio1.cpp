#include <iostream>
#include <array>

using namespace std;

const int dim = 3;

void getMatrix (array <array <int, dim>, dim> &m);
void mostrarMatriz(const array <array <int, dim>, dim> &m);
bool esTriSup(const array <array <int, dim>, dim> &m);
bool esTriInf(const array <array <int, dim>, dim> &m);

int main () {
    
    bool cont ;
    do {
        array <array <int, dim>, dim> matrix;

        getMatrix(matrix);
        mostrarMatriz(matrix);

        if (esTriInf(matrix)) cout <<"\n\nLa matriz es triangular inferior.";
        if (esTriSup(matrix)) cout << "\n\nLa matriz es triangular superior.";
        else cout << "\n\nLa matriz no es triangular.";

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


void getMatrix (array <array <int, dim>, dim> &m) {

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            cout << "\n[" << i+1 << ", " << j+1 << "] = ";
            cin >> m[i][j];
        }
    }
}

void mostrarMatriz(const array <array <int, dim>, dim> &m) {

    for (array <int, dim> a : m) {
        cout << "\n| ";
        for (int n : a) {
            cout << n << " ";
        }
        cout << "|";
    }
}

bool esTriSup(const array <array <int, dim>, dim> &m) {

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            if (i < j && m[i][j] != 0) return false;
        }
    }
    return true;
}

bool esTriInf(const array <array <int, dim>, dim> &m) {

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            if (i > j && m[i][j] != 0) return false;
        }
    }
    return true;
}