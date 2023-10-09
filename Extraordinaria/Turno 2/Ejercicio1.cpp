// Santiago Valderrama


#include <iostream>
#include <vector>


using namespace std;

int getNum (int n, int p);
int main () {

    int posicion, numero;
    do
    {
        cout << "\n\nEscribe un número: ";
        cin >> numero;

        cout << "\n\nIndica la posición (\"-1\" para salir): ";
        cin >> posicion; 

        if (posicion == -1) break;

        if (getNum(numero, posicion) != -1) cout << getNum(numero, posicion);
        else cout << "Índice fuera de rango.";


    } while (posicion != -1);
    
    return 0;
}


int getNum(int n, int p) {
    
    vector <int> v;
    for (int i = 0; n > 0; i++){
        v.push_back(n % 10);
        n = n / 10;
    }

    if (p >= v.size()) return -1;

    return v[v.size() - 1 - p];
}
