// Santiago Valderrama


#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;


struct maniobra
{
    int prof;
    double min, hora;
};

struct accion
{
    string maniobra;
    double velMed;
};
shared_ptr <vector<accion>> getAcciones (const vector <maniobra> &v);



int main () {

    
    vector <maniobra> vecManiobras = {{0, 0, 1}, {5, 0, 5}, {15, 0, 10},  {8, 0, 14}, {24, 0, 45},  {13, 1, 10},  {4, 1, 15},  {4, 3, 0},  {0, 3, 4}};
    
    shared_ptr <vector <accion>> vecAcciones = getAcciones(vecManiobras);
    return 0;
}


shared_ptr <vector<accion>> getAcciones (const vector <maniobra> &v) {

    shared_ptr <vector<accion>> man;
    vector<accion> v2;
    man = make_shared <vector <accion>> (v2);    

    for (int i = 1; i < v.size(); i++){

        double velMed = (v[i].prof - v[i-1].prof) / (((v[i].min * 60) + v[i].hora) - ((v[i-1].min * 60) + v[i-1].hora));

        if (v[i-1].prof < v[i].prof) man->push_back({"Inmersión", velMed});
        
        if (v[i-1].prof == v[i].prof) man->push_back({"Estable", velMed});
        if (v[i-1].prof > v[i].prof) man->push_back({"Emersión", velMed});
    }
    return man;
}



