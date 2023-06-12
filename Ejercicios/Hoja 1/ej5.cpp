// Santiago Valderrama


#include <iostream>


using namespace std;


int main () {

    bool cont = 1;
    
    
    do {
    
    float a, b, c;

    cout << "\n\n\tIntroduce el coeficiente \"a\" de la ecuación: ";
    cin >> a;

    cout << "\n\n\tIntroduce el coeficiente \"b\" de la ecuación: ";
    cin >> b;

    cout << "\n\n\tIntroduce el coeficiente \"c\" de la ecuación: ";
    cin >> c;

    if (a == 0 && b == 0) cout << "La ecuación es degenerada.";

    else if (pow(b, 2) - (4*a*c) < 0) cout << "La ecuación no tiene solución real.";

    else { cout << "Las soluciones a la ecuación son\n\tx = " << (-b + sqrt(pow(b, 2) - (4*a*c)) ) / 2*a << "\t x = " << (-b - sqrt(pow(b, 2) - (4*a*c)) );}
    
    
    char r;
    
    do {
    
        cout << "¿Quieres volver a ejecutar el programa? (S/N): ";
        cin >> r;
        r = toupper(r);
    
    } while (r != 'N' && r != 'S');
    
    if (r == 'N') cont = 0;
    
    } while (cont);
    
    return 0;
}
