#include <iostream>
#include <string>

using namespace std;

int main () {

     string frase;
     int voc = 0;
     int cons = 0;
     int esp = 0;
     int car = 0;
     int pal = 0;
     int pos = 0;
     int del = 0;

            cout << "Escribe una frase: ";
            getline(cin, frase);

            for (int i = 0; i < frase.size(); i++) {

                if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u') {

                    voc++;
                }

                else if (frase[i] == ' ') {

                    esp++;
                }

                else if (frase[i] == ',' || frase[i] == '.' ||frase[i] == '?' ||frase[i] == '!') {

                    car++;
                }

                else {

                    cons = frase.size() - voc - car - esp; 
                }

                pal = esp + 1;

            }

             pos = frase.find("del", pos);

                while (pos!= -1) {

                    pos++;
                    pos = frase.find("del", pos);
                    
                    del++;
                }

            cout << "La frase: " << frase << " contiene: \n" << voc << " vocales, " << cons << " consonantes, " << esp << " espacios y " << car << " caracteres.";
            cout << pal << " palabras donde hay " << del << " que son \"del\"";
}