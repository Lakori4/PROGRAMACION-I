//Santiago Valderrama

#include <iostream>
#include <set>
#include <array>
#include <vector>

using namespace std;


void getPrimos (vector <int> &v);
set <array <int, 2>> getParejas(const vector <int> &v);
void mostrarParejas (const set <array<int, 2>> &s);

int main () {

    vector <int> primos;
    getPrimos(primos);
    set <array <int, 2>> parejas = getParejas(primos);
    mostrarParejas(parejas);

    return 0;
}

void getPrimos (vector <int> &v) {

    for (int i = 100; i <= 200; i++) {
        bool esPrimo = true;
        for (int d = 2; d < i; d++) {
            if (i % d == 0) {
                esPrimo = false;
                break;
            }   
        }

        if (esPrimo) v.push_back(i);
    }
}


set <array <int, 2>> getParejas(const vector <int> &v) { 

    set <array <int, 2>> s;

    for (int i = 1; i < v.size(); i++) {

        if (v[i] - v[i-1] == 2) {
            s.insert({v[i-1], v[i]});
        }
    }
    return s;
}

void mostrarParejas (const set <array<int, 2>> &s) {

    for (array<int, 2> a : s) {
        
        cout << "(" << a[0] << ", " << a[1] << "), ";       
    }
}
