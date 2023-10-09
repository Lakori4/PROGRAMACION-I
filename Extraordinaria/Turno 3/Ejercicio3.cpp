//Santiago valderrama 
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <array>

using namespace std;

struct vocal
{
    int rep = 0;
    vector <int> pos;
};



unique_ptr <array <vocal, 5>> analisis (const string &s);
void mostrarAnalisis(const string &s, const unique_ptr <array <vocal, 5>> &ptr);

int main () {

    string frase; // = "Si no puedo dibujarlo, es que no lo entiendo";

    cout << "Escribe una frase: ";
    getline(cin, frase);
    unique_ptr <array<vocal, 5>> analisisPtr = analisis(frase);
    mostrarAnalisis(frase, analisisPtr);
    return 0;
}


unique_ptr <array <vocal, 5>> analisis (const string &s) {

    array <vocal, 5> vocales;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'A') {

            vocales[0].rep++; vocales[0].pos.push_back(i);
        }

        else if (s[i] == 'e' || s[i] == 'E') {

            vocales[1].rep++; vocales[1].pos.push_back(i);
        }

        else if (s[i] == 'i' || s[i] == 'I') {

            vocales[2].rep++; vocales[2].pos.push_back(i);
        }

        else if (s[i] == 'o' || s[i] == 'O') {

            vocales[3].rep++; vocales[3].pos.push_back(i);
        }

        else if (s[i] == 'u' || s[i] == 'U') {

            vocales[4].rep++; vocales[4].pos.push_back(i);
        }
    }
    return (make_unique <array<vocal, 5>> (vocales));    
}

void mostrarAnalisis(const string &s, const unique_ptr <array <vocal, 5>> &ptr) {
    cout << "\n\nLas vocales de la frase: " << s << " son: ";

    cout << "\n\n\tLetra a/A: " << ptr ->at(0).rep << " en la/s posicion/es: ";
    for (int i = 0; i < ptr->at(0).pos.size(); i++) {
        cout << ptr->at(0).pos.at(i) << ", ";
    }

    cout << "\n\tLetra e/E: " << ptr ->at(1).rep << " en la/s posicion/es: ";
    for (int i = 0; i < ptr->at(1).pos.size(); i++) {
        cout << ptr->at(1).pos.at(i) << ", ";
    }

    cout << "\n\tLetra i/I: " << ptr ->at(2).rep << " en la/s posicion/es: ";
    for (int i = 0; i < ptr->at(2).pos.size(); i++) {
        cout << ptr->at(2).pos.at(i) << ", ";
    }

    cout << "\n\tLetra o/O: " << ptr ->at(3).rep << " en la/s posicion/es: ";
    for (int i = 0; i < ptr->at(3).pos.size(); i++) {
        cout << ptr->at(3).pos.at(i) << ", ";
    }

    cout << "\n\tLetra u/U: " << ptr ->at(4).rep << " en la/s posicion/es: ";
    for (int i = 0; i < ptr->at(4).pos.size(); i++) {
        cout << ptr->at(4).pos.at(i) << ", ";
    }
}