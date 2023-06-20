// Santiago Valderrama


#include <iostream>
#include <array>
#include <string>


using namespace std;

int menu();


void setPalabras(array <string, 10> &aString);
string getPalabra(array <string, 10> &aString, int i);

int main () {   

    array <string, 10> palabras;
    string frase;

    int voc {0}, cons {0}, esp{0}, carac{0}, pal{0}, dels{0};
    
    do {

        switch (menu())
        {
        case 1:

            setPalabras(palabras);

            for (int i = 0; i < palabras.size(); i++) {

                string pal = getPalabra(palabras, i);

                cout << "\n\n\tLa palabra " << pal << " tiene " << pal.size() << " letras y su inicial es " << pal[0];
            }
            break;

        case 2:

            cout << "\n\tEscribe una frase: ";
            cin.ignore();
            getline(cin, frase);

            for (int i = 0; i < frase.size(); i++) {

                char c = tolower(frase[i]);

                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') { voc++; }

                else if (c == ' ') esp++;

                else if (c == ',' || c == '.' || c == '?' || c == '!') { carac++; }

                else cons ++;

                pal = esp +1;
            }

            for (int pos = 0; pos != -1; pos = frase.find("del", pos+1)) {

                if (frase.find("del", pos) < frase.size()) dels++;
            }
            
            cout << "\n\n\tLa frase: " << frase << " contiene:\n\n\t" << voc << " vocales, " << cons << " consonantes, " << esp << " espacios y " << carac << " caracteres.\n\t";
            cout << pal << " palabras donde hay " << dels << " que son\"del\".\n\n"; 
            break;

        case 3:
            /* code */
            break;
            

        case 4:
            cout << "Gracias y hasta pronto\n\n";
            return 0;
            break;
        
        default:
            cout << "La opción no es válida. Por favor, vuelva a seleccionar otra opción";
            break;
        }
    
    } while (true);
    
    return 0;
}


int menu() {

    int opc;

    cout << "\nBienvenido.\n\nSeleccione una opción:";
    cout << "\n\t1. Longitud de las frases.\n\t2. Analizar frase. \n\t3. Matriz de números\n\t4. Salir del programa\n";

    cin >> opc;

    return opc;
}

void setPalabras(array <string, 10> &aString) {

    for (int i = 0; i < aString.size(); i++) {

        system("cls");
        string s;

        cout << "\n\tIntroduce una palabra: ";
        cin >> s;

        aString[i] = s;

    }
}

string getPalabra (array <string, 10> &aString, int i) {

    return aString[i];
}
