// Santiago Valderrama


#include <iostream>
#include <array> 


using namespace std;


int main () {

    array <array<int, 3>, 4> matrix;

    cout << "\n\nDATOS DE LA MATRIZ.";

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {
            cout << "\n[" << i+1 << ", " << j+1 << "] = ";
            cin >> matrix[i][j];
            cin.ignore();
        }
    }

    cout << "\n\nMATRIZ GENERADA POR EL USUARIO.";

    for (array <int, 3> a : matrix) {
        cout << "\n| ";
        for(int n : a) {
            cout << n << " ";
        }
        cout << "|";
    }

    array <array<int, 1>, 4> sumaXfila;

    for (int i = 0; i < matrix.size(); i++) {
        int n = 0;

        for (int j = 0; j < matrix[i].size(); j++) {
          n += matrix[i][j];  
        }

        sumaXfila[i][0] = n*i;
    }

    cout << "\n\nMATRIZ GENERADA POR EL USUARIO.";


    for (array <int, 1> a : sumaXfila) {
            cout << "\n| ";
            for(int n : a) {
                cout << n << " ";
            }
            cout << "|";
        }

    return 0;
}
