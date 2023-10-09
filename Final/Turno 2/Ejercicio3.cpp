// Santiago Valderrama


#include <iostream>
#include <string> 
#include <vector>
#include <set>



using namespace std;

struct palabra
{
    string pal;
    int rep;
};


vector <palabra> getVector();
void getPalsMaxMin (const vector <palabra> &v, palabra &pMax, palabra &pMin);
set<string> getSet(const vector <palabra> &v);
void mostrarSetInverso(const set <string> &s);

int main () {

    palabra palMax;
    palabra palMin;
    
    set <string> setPal;
    vector <palabra> vecPal = getVector();

    getPalsMaxMin(vecPal, palMax, palMin);

    cout << palMax.pal << " aparece mas veces: " << palMax.rep << endl;
    cout << palMin.pal << " aparece menos veces: " << palMin.rep << endl;

    setPal = getSet(vecPal);

    mostrarSetInverso(setPal);
    
    

    
    return 0;
}



vector <palabra> getVector() {

    vector <palabra> vecPal;
    palabra pal;
    
    do
    {
        cout << "\nEscribe una palabra (si quieres salir escribe \"salir\"): ";
        cin >> pal.pal;

        bool isPal = false;

        for (int i = 0; i < vecPal.size(); i++)
        {
            if (pal.pal == vecPal[i].pal) vecPal[i].rep++; isPal = true;
        }
        
        if (!isPal) pal.rep = 1; vecPal.push_back(pal);
        
    } while (pal.pal != "salir");

    vecPal.pop_back();

    return vecPal;
}

void getPalsMaxMin (const vector <palabra> &v, palabra &pMax, palabra &pMin) {

    pMax = v[0];
    pMin = v[0];

    for (palabra p : v) {

        if (p.rep > pMax.rep) pMax = p;
        if (p.rep < pMin.rep) pMin = p;
    }
}


set<string> getSet(const vector <palabra> &v) {

    set <string> s;

    for (palabra p : v) {

        s.insert(p.pal);
    }
    return s;
}

void mostrarSetInverso(const set <string> &s) {

    vector <string> v;


    for (string s1 : s) {
        v.push_back(s1);
    }

    for (int i = v.size() -1; i >= 0; i--) {
        cout << v[i] << " ";
    }
}