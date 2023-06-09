// Gina Ramírez y Santiago Valderrama
// Grupo 7
#include <iostream>

using namespace std;

int main () {

    int menu = 0;
    int divisoresNum = 0;
    int num = 0;
    int sumaDivisoresNum = 0;
    int n1 = 0;
    int n2 = 0;
    int num1 = 0;
    int num2 = 0;
    int mcdDosNum = 0;
    int q = 0;
    int r = 0;

while (1 == 1){

    cout << "\n\nElige entre las siguientes opciones. \n\n1. Determinar los divisores de un número. \n2. Determinar la suma de los divisores de un número. \n3. Determinar el m.c.d. (máximo común divisor) de dos números. \n4. Salir programa.\n";
    cin >> menu;

    switch (menu){

        case 1: 

            cout << "\n\nEscribe un número entre 1 y 500: ";
            cin >> num;

            if (num < 1 || num > 500) {

                cout << "\nEl número introducido no es correcto \n"; 
                break;
            }

            cout << "Los divisores de " << num << " son: ";
            for (int d = 1; d <= num; d++){

                if (num % d == 0){

                    cout << d << ", ";
                }

            }

            break;

        case 2: 

            cout << "\n\nEscribe un número entre 1 y 500: ";
            cin >> num;

            if (num < 1 || num > 500) {

                cout << "El número introducido no es correcto \n"; 
                break;
            }

            cout << "\nLa suma de los divisores de " << num << " es: ";
            for (int d = 1; d <= num; d++){

                if (num % d == 0){

                    sumaDivisoresNum = sumaDivisoresNum + d;
                }

            }

            cout << sumaDivisoresNum << endl << endl;

            break;


        case 3:

            cout << "\n\nEscribe un número entre 1 y 2500: ";
            cin >> n1;

            if (n1 < 1 || n1 > 2500) {

                cout << "El número introducido no es correcto \n"; 
                break;
            }

            cout << "\n\nEscribe otro número entre 1 y 2500: ";
            cin >> n2;

            if (n2 < 1 || n2 > 2500) {

                cout << "El número introducido no es correcto \n"; 
                break;
            }

            num1 = n1;
            num2 = n2;

            if (num1 < num2) {

                num = num1;
                num1 = num2;
                num2 = num;

            }

            r = num1 % num2;

            if (r == 0) {
                mcdDosNum = num2;
                cout << "m.c.d. (" << n1 << ", " << n2 << ") = " << mcdDosNum << endl;
            }

                
            while (r != 0) {


                 num1 = num2;
                 num2 = r;
                 r = num1 % num2;
                 if (r == 0) {
                mcdDosNum = num2;
                cout << "m.c.d. (" << n1 << ", " << n2 << ") = " << mcdDosNum << endl;
            }
                
                q = num1 / num2;

            }

            break; 

        case 4: 

            cout << "Gracias y hasta pronto" << endl;
            return 0;
            break; 


        default:

             cout << "La opción no es válida. Por favor vuelva a seleccionar otra opción." << endl;
             break;
     }
}

    return 0;
}