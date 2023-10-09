// Santiago Valderrama


#include <iostream>
#include <string>


using namespace std;

string cambiar (const string &t, const string &p, const string &s);
string cifrar (const string &s, int c);

//const string baseMayus = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//const string baseMinus = "abcdefghijklmnopqrstuvwxyz";

int main () {

    
    string frase = "Tu madre tiene una polla que ya la quisiera yooooo";
    string patron = "pe";
    string sust = "yYyYy";
    string cambiado = cambiar(frase, patron, sust); 

    cout << cifrar(frase, -5);

    
    return 0;
}

string cambiar (const string &t, const string &p, const string &s) {
    string c = t;

    while (c.find(p) != -1) {
        c.insert(c.find(p), s);
        c.erase(c.find(p), p.size());
    }
    

    return c;
}

string cifrar (const string &s, int c) {

    string cifrao;
    string baseMayus = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string baseMinus = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < s.size(); i++) {
        if (baseMayus.find(s[i]) != -1) {

            if (baseMayus.find(s[i]) + c >= 26) 
            cifrao.push_back(baseMayus[-26 + baseMayus.find(s[i]) + c]);

            else cifrao.push_back(baseMayus[baseMayus.find(s[i]) + c]);
        }
        else if (baseMinus.find(s[i]) != -1) {

            if (baseMinus.find(s[i]) + c >= 26) 
            cifrao.push_back(baseMinus[-26 + baseMinus.find(s[i]) + c]);

            else cifrao.push_back(baseMinus[baseMinus.find(s[i]) + c]);
        }
        else cifrao.push_back(s[i]);
    }
    return cifrao;
}