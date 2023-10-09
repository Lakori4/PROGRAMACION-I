// Santiago Valderrama


#include <iostream>


using namespace std;

void getNums(int &n1, int &n2);
int getSumDiv(int n);

int main () {

    bool cont = 1;
    
    
    do {
    
    system("cls");
    
    int num1, num2;

    int div1, div2;

    getNums(num1, num2);

    div1 = getSumDiv(num1);
    div2 = getSumDiv(num2);

    if (div1 == num2 && div2 == num1) cout << "\n\nLos números " << num1 << " y " << num2 << " son AMIGOS";
    else cout << "\n\nLos números " << num1 << " y " << num2 << " NO son AMIGOS";
    
    
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




void getNums(int &n1, int &n2) {

    do
    {
        cout << "\n\n\tIntroduzca un número positivo: ";
        cin >> n1;
        cin.ignore();

        cout << "\n\n\tIntroduzca otro número positivo distinto del primero: ";
        cin >> n2;
        cin.ignore();

        if (n1 < 0 || n2 < 0)  { system("cls"); cout << "\nUno de los números no es mayor que 0"; }
        else if (n2 == n1) { system("cls"); cout << "\nLos números son iguales"; }

    } while (n1 < 0 || n2 < 0 || n1 == n2);
}

int getSumDiv(int n) {

    int sumDiv = 0;

    cout << "\n\nDivisores de " << n << ": ";

    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) {
            sumDiv += i;
            cout << i << " ";
        }
    }

    return sumDiv;
}