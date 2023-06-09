//Santiago Valderrama y Pedro Zuñeda
//Grupo 7

#ifndef HPRACTICAA5_H
#define HPRACTICAA5_H

#include <string>
#include <vector>

using namespace std;

/*struct hPracticaA5
{
     data 
} */


int menu();

int solDim ();

vector <vector <int>> solicitarMatriz();


void mostrarMatriz (vector <vector <int>>mA);

vector <int> obtenerMax_Min (vector <vector <int>>mA);


#endif