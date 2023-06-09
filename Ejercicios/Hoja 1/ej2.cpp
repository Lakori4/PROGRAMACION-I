// Santiago Valderrama


#include <iostream>

const double pi = 3.14159265359;

using namespace std;



double areaCil (int r, int h) { return (2*pi*r*h) + (2*pi*pow(r, 2)); }
double volCil(int r, int h) { return pi*pow(r, 2)*h; }

int main () {

    bool cont = 1;

    do
    {
        int r, h;
        
        cout << "\n\n\tIntroduce el radio del cilindro: ";
        cin >> r;

        cout << "\n\tIntroduce la altura del cilindro: ";
        cin >> h;

        cout << "\n\n\tEl área superficial del cilindro es: " << areaCil(r, h);
        cout <<"\n\tEl volumen del cilindro es: " << volCil(r, h);


        char c;

        do
        {
            cout << "\n\n\n\t¿Quieres volver a ejecutar el programa? (S/N)";
            cin >> c;
            c = toupper(c);
        } while (c != 'N' && c != 'S');

        if (c == 'N') cont = 0;
        
    } while (cont);
    
    
    return 0;
}

