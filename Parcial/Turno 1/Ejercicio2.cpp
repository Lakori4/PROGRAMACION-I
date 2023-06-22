// Santiago Valderrama


#include <iostream>
#include <string>


using namespace std;

struct id {

    string s;
    int n;
};

int main () {

    id miNom, miApel, miNApel;

    cout << "\n\n\tEscriba su nombre: ";
    cin >> miNom.s;
    cin.ignore();

    miNom.n = miNom.s.size();

    cout << "\n\n\tEscriba sus apellidos: ";
    getline(cin, miApel.s);

    miApel.n = miApel.s.size();

    char ini = miNom.s[0];

    miNApel.s = ini;
    miNApel.s += "." + miApel.s;
    
    miNApel.n = miNApel.s.size();

    cout << miNApel.s;

    return 0;
}
