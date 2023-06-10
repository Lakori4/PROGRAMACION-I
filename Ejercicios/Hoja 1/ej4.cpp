// Santiago Valderrama


#include <iostream>


using namespace std;

struct Recta
{
    int m, n;
};


int main () {

    bool cont = 1;


    do {
    
    system("cls");

    Recta R1, R2;

    cout << "\n\n\tIntroduce el término \"m\" de la recta 1: ";
    cin >> R1.m;

    cout << "\n\n\tIntroduce el término \"n\" de la recta 1: ";
    cin >> R1.n;

    cout << "\n\n\tIntroduce el término \"m\" de la recta 2: ";
    cin >> R2.m;

    cout << "\n\n\tIntroduce el término \"n\" de la recta 2: ";
    cin >> R2.n;

    if (R1.m == R2.m && R1.n == R2.n) { cout << "\n\n\tLas rectas son coincidentes."; }

    else if (R1.m == R2.m && R1.n != R2.n) { cout << "\n\n\tLas rectas son paralelas."; }

    else {

        float x = (R2.n - R1.n) / (R1.m - R2.m);
        float y = (R1.m * x ) + R1.n;

        cout << "\n\n\tLas rectas son secantes en el punto (" << x << ", " << y << ").";
    }


    char r;

    do
    {
        cout << "\n\n¿Quieres volver a ejecutar el programa? (S/N): ";
        cin >> r;
        r = toupper(r);

    } while (r != 'N' && r != 'S');

    if (r == 'N') cont = 0;
    
    } while (cont);
    
    return 0;
}
