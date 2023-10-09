// Santiago Valderrama


#include <iostream>
#include <vector>
#include <memory>

using namespace std;


void getSerie (unique_ptr <vector <float>> &v, char c);

int main () {
    unique_ptr <bool> cont;


    do{
        
        unique_ptr <vector <float>> serieA, serieB;
        vector <float> sA, sB;
        int numTer;

        serieA = make_unique <vector <float>> (sA);
        serieB = make_unique <vector <float>> (sB);

        cout << "\n\n\tEscribe el número de términos de las series: ";
        cin >> numTer;
        cin.ignore();

        serieA->resize(numTer);
        serieB->resize(numTer);
        

        cout << "\n\n\tEscribe el primer término de las series: ";
        cin >> serieA->at(0);

        serieB->at(0) = serieA->at(0);

        cout << "\n\n\tEscribe el segundo término de las series: ";
        cin >> serieA->at(1);

        serieB->at(1) = serieA->at(1);
        

        getSerie(serieA, 'a');
        getSerie(serieB, 'b');

        char c;

        do
        {
            cout << "\n\n\t¿Quieres volver a ejecutar el programa? (S/N): ";
            cin >> c;
            c = toupper(c);
        } while (c != 'N' && c != 'S');

        if (c == 'N') cont = make_unique <bool> (false);

        
    } while(*cont);

    return 0;
}

void getSerie (unique_ptr <vector <float>> &v, char c) {

    if (c == 'a') {
        for (int i = 2; i < v->size(); i++) {
            v->at(i) = v->at(i-1) + v->at(i-2);
        }
    }

    else if (c == 'b') {
        for (int i = 2; i < v->size(); i++) {
            v->at(i) = i * ((v->at(i-1) / 2) + v->at(i-2));
        }
    }
}
