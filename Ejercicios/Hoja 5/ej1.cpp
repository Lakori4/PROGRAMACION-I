// Santiago Valderrama


#include <iostream>
#include <vector>


using namespace std;

int getNum();
vector <int> setDigits(int n);


int main () {

    bool cont = 1;
    
    
    do {
    
    system("cls");

    int n = getNum();

    vector <int> digitos = setDigits(n);

    for (int i = digitos.size() - 1; i > 0; i--) {

        cout << digitos[i] << "-";
    }

    cout << digitos[0] << endl;

    
    
    
    char r;
    
    do {
    
        cout << 
    
    "¿Quieres volver a ejecutar el programa? (S/N): ";
        cin >> r;
        r = toupper(r);
    
    } while (r != 'N' && r != 'S');
    
    if (r == 'N') cont = 0;
    
    } while (cont);
    
    return 0;
}




int getNum() {

    int n;

    do
    {
        cin.clear();
        cout << "Escribe un número entero positivo: ";
        cin >> n;
        

    } while (n < 0);

    return n;
    
}

vector <int> setDigits(int n) {

    vector <int> digitos;

    while (n >= 10) {

        digitos.push_back(n % 10);

        n = n / 10;

    }

    digitos.push_back(n);

    return digitos;

}
