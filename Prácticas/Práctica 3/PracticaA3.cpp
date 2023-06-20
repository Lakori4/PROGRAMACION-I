// Santiago Valderrama


#include <iostream>
#include <array>
#include <string>


using namespace std;

int menu();


void setPalabras(array <string, 10> &aString);

void setMatrix(array <array<int, 3>, 3> &m);
void setMatrixPar(const array <array<int, 3>, 3> &mI, array <array<string, 3>, 3> &mS);
void setMatrixImpar(const array <array<int, 3>, 3> &mI, array <array<string, 3>, 3> &mS);

void mostrarMatrix(const array <array<int, 3>, 3> &m);
void mostrarMatrix(const array <array<string, 3>, 3> &m);



string getPalabra(const array <string, 10> &aString, int i);

int main () {   

    array <string, 10> palabras;
    string frase;
    array <array<int, 3>, 3> matrix;
    array <array<string, 3>, 3> mpar;
    array <array<string, 3>, 3> mimpar;

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
            cout << "\n\nIntroduce a continuación los datos de la matriz (sólo se permiten números del 1 al 5).";
            setMatrix(matrix);
            mostrarMatrix(matrix);
            setMatrixPar(matrix, mpar);
            setMatrixImpar(matrix, mimpar);

            mostrarMatrix(mpar);
            mostrarMatrix(mimpar);
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

void setMatrix(array <array<int, 3>, 3> &m) {
    
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {

            int n;
            cout << "\n\t[" << i+1 << ", " << j+1 << "] = ";
            cin >> n;

            if (n < 1 || n > 5) j--;
            else m[i][j] = n;
        } 
    }
}

void mostrarMatrix(const array <array<int, 3>, 3> &m) {

    for(array <int, 3> a: m) {
        cout << "\n\t";
        for(int n : a) {
            cout << "|" << n;
        }
        cout << "|";
    }
    cout << "\n";
}

void setMatrixPar(const array <array<int, 3>, 3> &mI, array <array<string, 3>, 3> &mS) {

    for (int i = 0; i < mI.size(); i++) {

        for (int j = 0; j < mI[i].size(); j++) {
            if (mI[i][j] == 2) mS[i][j] = " 2 DOS ";
            else if (mI[i][j] == 4) mS[i][j] = " 4 CUATRO ";
            else if (mI[i][j] == 6) mS[i][j] = " 6 SEIS ";
            else if (mI[i][j] == 8) mS[i][j] = " 8 OCHO ";
            else mS[i][j] = " 0 CERO ";
        }
    }
}

void setMatrixImpar(const array <array<int, 3>, 3> &mI, array <array<string, 3>, 3> &mS) {
   
    for (int i = 0; i < mI.size(); i++) {

        for (int j = 0; j < mI[i].size(); j++) {
            if (mI[i][j] == 1) mS[i][j] = " 1 UNO ";
            else if (mI[i][j] == 3) mS[i][j] = " 3 TRES ";
            else if (mI[i][j] == 5) mS[i][j] = " 5 CINCO ";
            else if (mI[i][j] == 7) mS[i][j] = " 7 SIETE ";
            else if (mI[i][j] == 9) mS[i][j] = " 9 NUEVE ";
            else mS[i][j] = "0 CERO";
        }
    }
}

void mostrarMatrix(const array <array<string, 3>, 3> &m) {

    for(array <string, 3> a: m) {
        cout << "\n\t";
        for(string s : a) {
            cout << "|" << s;
        }
        cout << "|";
    }
    cout << "\n";

}

string getPalabra (const array <string, 10> &aString, int i) {

    return aString[i];
}
