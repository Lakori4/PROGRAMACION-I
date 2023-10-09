//Santiago valderrama 
#include <iostream>
#include <vector>

using namespace std;

struct valores
{
    int min = 0, max = 0;
    vector <int> vec;
};


void getSerie(vector <int> &v);
valores getValores (const vector <int> &v, bool pos);


int main () {

    valores valPos, valNeg;
    vector <int> serie;


    serie.resize(20);
    serie[0] = 1;
    serie[1] = -1;

    getSerie(serie);

    valPos = getValores(serie, true);
    valNeg = getValores(serie, false);

    cout << "\n\nDATOS DE LA SERIE: ";
    for (int n : serie) {
        cout << n << ", ";
    }

    cout << "\n\nDATOS POSITIVOS: ";
    for (int n : valPos.vec) {
        cout << n << ", ";
    }
    cout << "\nMayor valor positivo: " << valPos.max;
    cout << "\nMenor valor positivo: " << valPos.min;
    

    cout << "\n\nDATOS NEGATIVOS: ";

    for (int n : valNeg.vec) {
        cout << n << ", ";
    }
    cout << "\nMayor valor negativo: " << valNeg.max;
    cout << "\nMenor valor negativo: " << valNeg.min;


    return 0;
}

void getSerie(vector <int> &v) {

    for (int i = 2; i < v.size(); i++) {

        v[i] =((-3) * v[i-2]) + (2*v[i-1]);
    }
}

valores getValores (const vector <int> &v, bool pos) {

    valores val;

    if (pos) {
        val.max = v[0];
        val.min = v[0];
    }
    
    if (!pos) {
        val.max = v[1];
        val.min = v[1];
    }

        
    for (int i = 2; i < v.size(); i++)
    {
        if (v[i] >= 0 && pos) {


            if (v[i] > val.max) { val.max = v[i]; }
            if (v[i] < val.min) { val.min = v[i]; }
            val.vec.push_back(v[i]);
        }

        else if (v[i] < 0 && !pos) {

            if (v[i] > val.max) { val.max = v[i]; }
            if (v[i] < val.min) { val.min = v[i]; }
            val.vec.push_back(v[i]);
        }
    }

    return val;
}