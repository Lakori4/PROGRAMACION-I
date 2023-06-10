// Santiago Valderrama


#include <iostream>


using namespace std;


int main () {

    int peso; 

    cout << "Introduce tu peso en libras: ";
    cin >> peso;

    peso = peso * 0.453592;

    cout << "\nTu peso en kilos es: " << peso << endl;

    return 0;
}
