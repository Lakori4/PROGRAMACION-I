// Santiago Valderrama


#include <iostream>
#include <array>
#include <vector>


using namespace std;


int main () {

    array <int, 20> datosSerie;
    vector <int> datosPos, datosNeg;


    datosSerie[0] = 1;
    datosSerie[1] = 5;


    for (int i = 2; i < datosSerie.size(); i++) {
        datosSerie [i] = (2*datosSerie[i-2]) - datosSerie[i-1];
    }

    cout << "\n\nRESULTADO DE LA SERIE";

    for (int  i = 0; i < datosSerie.size(); i++) {
        cout << "\n\tElemento " << i << ": " << datosSerie[i];

        if (datosSerie[i] < 0) datosNeg.push_back(datosSerie[i]);
        else if (datosSerie[i] > 0) datosPos.push_back(datosSerie[i]);
    }

    cout << "\n\nNÚMEROS POSITIVOS DE LA SERIE\n\t";

    for (int n : datosPos) {

        cout << n << ", ";
    }

    cout << "\n\nNÚMEROS NEGATIVOS DE LA SERIE\n\t";

    for (int n : datosNeg) {

        cout << n << ", ";
    }

    return 0;
}
