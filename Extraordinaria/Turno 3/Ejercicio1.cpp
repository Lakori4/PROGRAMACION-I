//Santiago valderrama 
#include <iostream>
#include <array>

using namespace std;

struct monomio {
    float coef;
    int exp;
};

void getPolinomio (array <monomio, 11> &p);
array <monomio, 11> getSuma(const array <monomio, 11> &p1, const array <monomio, 11> &p2);
void mostrarPolinomio(const array <monomio, 11> &p);

int main () {

    array <monomio, 11> polin1;
    array <monomio, 11> polin2;
    array <monomio, 11> polinSuma;

    cout << "\n\nDATOS POLINOMIO 1: ";
    getPolinomio(polin1);
    cout << "\n\nDATOS POLINOMIO 2: ";
    getPolinomio(polin2);

    polinSuma = getSuma(polin1, polin2); 
    
    
    cout << "\n\nP1(x) = ";
    mostrarPolinomio(polin1);
    cout << "\n\nP2(x) = ";
    mostrarPolinomio(polin2);
    cout << "\n\nPS(x) = ";
    mostrarPolinomio(polinSuma);


    return 0;
}


void getPolinomio (array <monomio, 11> &p) {

    for (int i = 0; i < p.size(); i++) {
        p[i].exp = i;
        cout << "\n\tCoeficiente de x^" << i << ": ";
        cin >> p[i].coef;
    }
}

array <monomio, 11> getSuma(const array <monomio, 11> &p1, const array <monomio, 11> &p2) {

    array <monomio, 11> pSuma;

    for (int i = 0; i < pSuma.size(); i++) {
        pSuma[i].exp = i;
        pSuma[i].coef = p1[i].coef + p2[i].coef;
    }

    return pSuma;
}

void mostrarPolinomio(const array <monomio, 11> &p) {
    for (int i = p.size()-1; i >= 0; i--) {
        if (p[i].coef != 0) {

            if (p[i].coef > 0) {
                cout << " + " << p[i].coef; 
            }
            else {
                cout << " " << p[i].coef;
            }

            if (p[i].exp != 0)
            cout << "x^" << p[i].exp; 
        }
    }
}