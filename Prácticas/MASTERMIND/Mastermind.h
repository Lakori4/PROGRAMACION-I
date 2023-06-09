//Carlos Bauluz y Santiago Valderrama
//Trabajo Final: Mastermind

#ifndef MASTERMIND_H
#define MASTERMIND_H

#include <iostream>
#include <string>

using namespace std;


// ESTRUCTURAS-----------------------------------------------------

struct jug {

    string nom;
    string sec;
    string guess;
    int lin = 1;
    bool winner;


};

//DECLARACIÓN DE FUNCIONES-----------------------------------

string nom1();
string nom2();
bool chkName (string const&j1, string const&j2);

//------------------------------------------------

void Reglas(string const&j1, string const&j2);

//------------------------------------------------

string sec1 (string const&j1, string const&j2);
string chkSec (string const&j1, string const&j2);

//------------------------------------------------

string guess(string const&j2);
string chkGuess (string const&j2);
int score (string const&j2, string &g, string const&c);

//------------------------------------------------

void end (string const&j1, string const&j2, int line1, int line2); 


#endif