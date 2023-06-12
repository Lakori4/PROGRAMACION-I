// Santiago Valderrama


#include <iostream>
#include <vector>


using namespace std;

vector <double> setVector() {

    double n;
    vector <double> vDoubles;

    do
    {
        cout << "Introduce un número con parte decimal (o 0 si quieres terminar): ";
        cin >> n;

        if(n == 0) break;

        vDoubles.push_back(n);


    } while (n != 0);

    return vDoubles;


}

double getMayor (vector <double> &V) {

    double n = V[0];

    for (int i = 1; i < V.size(); i++) {
        if (V[i] > n) n = V[i];
    }


    return n;
}


int main () {

    bool cont = 1;
    
    
    do {
    
    system("cls");

    double n;

    vector <double> vDoubles = setVector();

    cout << "\n\nEl mayor de los números que has introducido es: " << getMayor(vDoubles);
  
    
    
    char r;
    
    do {
    
        cout << "\n\n¿Quieres volver a ejecutar el programa? (S/N): ";
        cin >> r;
        r = toupper(r);
    
    } while (r != 'N' && r != 'S');
    
    if (r == 'N') cont = 0;
    
    } while (cont);
    
    return 0;
}
