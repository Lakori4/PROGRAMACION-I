// Santiago Valderrama


#include <iostream>
#include <string>
#include <array>


using namespace std;

struct datosCuento {

    string titulo;
    int numPalab;
    int numCarac = titulo.size();
};

struct datoMatriz
{
    int suma = 0;
    bool esPar = 0;
    string zona;
};


int menu();
int totPalabra(const string &s);

bool esPalindroma (string &s);

void datosCuentos();
void operarMatriz();


int main () {

    while (true) {
        string s;

        switch (menu())
        {
        case 1:
            datosCuentos();
            break;

        case 2:
            operarMatriz();
            break;

        case 3:

            
            cout << "\n\nPor favor introduzca un texto en minusculas: ";
            getline(cin, s);
            cout << "\n\n\tEl texto ";
            if (esPalindroma(s)) cout << "es PALINDROMO.";
            else cout << "NO es PALINDROMO.";
            break;

        case 4:
            cout << "\n\nGracias y hasta pronto.\n";
            return 0;
            break;
        
        default:
            cout << "\n\n\tLa opción no es válida. Por favor, vuelva a seleccionar otra opción";
            break;
        }



    }
    return 0;
}

int menu() {

    int opc;

    cout << "\n\nBienvenido.\n\n\tPor favor seleccione una opción.";
    cout << "\n\t1. Títulos de cuentos infantiles.\n\t2. Operar con una matriz.";
    cout << "\n\t3. Determinar si un texto es palíndromo.\n\t4. Salir del programa.\n\nTeclee la opción: ";

    cin >> opc;
    cin.ignore();

    system("cls");

    return opc;
}

void datosCuentos() {

    array <datosCuento, 5> aCuentos;

    cout << "\nINTRODUZCA LOS DATOS DE 5 CUENTOS\n";
    
    for (int i = 0; i < aCuentos.size(); i++) {

        cout << "Introduzca el titulo numero " << i+1 << " ";        
        getline(cin, aCuentos[i].titulo);

    }

    cout << "\n\n\nLOS DATOS DE LOS CUENTOS SON:";

    for (datosCuento c : aCuentos) {

        c.numPalab = totPalabra(c.titulo);
        c.numCarac = c.titulo.size();
        cout << "\n\tEl cuento titulado: " << c.titulo << " tiene " << c.numPalab << " palabras y su longitud es " << c.numCarac;
    }
}

int totPalabra(const string &s) {

    int esp = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') esp ++;
    }

    return esp +1;
}





void operarMatriz() {

    array <array<int, 4>, 4> matrix;

    cout << "\n\nINTRODUZCA LOS DATOS DE LA MATRIZ.\n";

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {

            int n;
            cout << "[" << i+1 << ", " << j+1 << "] = ";
            cin >> n;
            cin.ignore();

            if (n < 0 || n > 9) j--;
            else matrix[i][j] = n;
        }
    }

    cout << "\n\nLA MATRIZ DATO ES";
    for (array <int, 4> a: matrix) {
        cout << "\n | ";
        for (int n: a) {
            cout << n << " ";
        }
        cout << "|";
    }

    array <datoMatriz, 3> matrizNew;
    matrizNew[0].zona = "superior";
    matrizNew[1].zona = "diagonal";
    matrizNew[2].zona = "inferior";


    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {

            if (i == j) matrizNew[1].suma += matrix[i][j];
            if (i < j) matrizNew[0].suma += matrix[i][j];
            if (i > j) matrizNew[2].suma += matrix[i][j];
        }
    }

    cout << "\n\nLA MATRIZ GENERADA ES\n";

    for (int i = 0; i < matrizNew.size(); i++) {
        if (matrizNew[i].suma % 2 == 0) matrizNew[i].esPar = 1;
        cout << "\n | " << matrizNew[i].suma << " " << matrizNew[i].esPar << " " << matrizNew[i].zona << " |";
    }

}


bool esPalindroma(string &s) {

    int pos = 0;
    
    pos = s.find(' ');

    while (pos != -1) {

        pos = s.find(' ');
        if (pos == -1) break;
        s.erase(pos, 1);
    }

    string s2;
    for (int i = s.size()-1; i > -1; i--) {
        s2 = s2 + s[i];
    }

    if (s2 == s) return true;
    else return false;
}