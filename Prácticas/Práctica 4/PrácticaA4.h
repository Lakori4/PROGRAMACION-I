#ifndef PRACTICAA4_H
#define PRACTICAA4_H
#include <string>
#include <array>

using namespace std;

const int dim = 4;
const int dim2 = 3;


struct cuento {

    string titulo();
    int pal();
    int carac();
    
};


struct opM {

    int suma();
    bool espar();
    string zona();
};



int menu ();
//void datosCuentos(); 
int totpalabras(string titulo);

void operarMatriz (array<array<int,dim>,dim> a);

bool esPalindroma (string frase);






#endif 