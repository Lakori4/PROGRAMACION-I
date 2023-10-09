// Santiago Valderrama


#include <iostream>
#include <vector> 

using namespace std;


void getVector(vector <int> &v);
void mostrarVector(const vector <int> &v);
int binConsec (const vector <int> &v, int bin);
vector <int> rotar (const vector <int> &v, bool r);

int main () {

    vector <int> vecBin;

    getVector(vecBin);

    cout << "\n\nLa secuencia es: "; mostrarVector(vecBin); 
    cout << "\nHay " << binConsec(vecBin, 0) << " ceros consecutivos y " << binConsec(vecBin, 1) << " unos consecutivos.";

    
    return 0;
}


void getVector(vector <int> &v) {

    char c;

    do
    {
        cout << "\nEscribe 0 o 1 (\".\" para salir): ";
        cin >> c;
        if (c == '0') v.push_back(0);
        if (c == '1') v.push_back(1);
    } while (c != '.');
}

void mostrarVector(const vector <int> &v) {

    for (int i = 0; i < v.size(); i++) {

        cout << v[i];
    }
}

int binConsec (const vector <int> &v, int bin) {

    if (bin != 0 && bin != 1) return -1;

    int maxConsec = 0, consec = 0;


    for (int i = 0; i < v.size(); i++) {
        if (v[i] == bin) consec++;
        else {
            if(maxConsec < consec) maxConsec = consec;
            consec = 0;
        }
    }
    return maxConsec;
}

vector <int> rotar (const vector <int> &v, bool r) {

    int link;

    if (r) link = v[v.end()-1]
}