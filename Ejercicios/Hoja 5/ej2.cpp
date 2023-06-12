// Santiago Valderrama


#include <iostream>
#include <array>


using namespace std;

array <int, 2> getFecha();
bool chkBisiesto(int anio);

int main () {

    bool cont = 1;
    
    
    do {
    
    system("cls");

    int mes, anio;

    array <int, 2> fecha = getFecha();

    mes = fecha[0];
    anio = fecha[1]; 

    if (chkBisiesto(anio) && mes == 2) cout << "Febrero de " << anio << " tiene 29 días.";

    else {

        switch (mes)
        {
        case 1:
            cout << "Enero de ";
            break;

        case 2:
            cout << "Febrero de ";
            break;

        case 3:
            cout << "Marzo de ";
            break;

        case 4:
            cout << "Abril de ";
            break;

        case 5:
            cout << "Mayo de ";
            break;

        case 6:
            cout << "Junio de ";
            break;

        case 7:
            cout << "Julio de ";
            break;

        case 8:
            cout << "Agosto de ";
            break;

        case 9:
            cout << "Septiembre de ";
            break;

        case 10:
            cout << "Octubre de ";
            break;

        case 11:
            cout << "Noviembre de ";
            break;

        case 12:
            cout << "Diciembre de ";
            break;
        }

        cout << anio;

        switch (mes)
        {
        case 2:
            cout << " tiene 28 días";
            break;

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << " tiene 31 días";
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            cout << " tiene 30 días";
        
        }
    }





    
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


array <int, 2> getFecha() {

    int mes, anio;


    do
    {
        system("cls");
        cout << "\n\n\tIntroduce el mes: ";
        cin >> mes;

        cout << "\n\tIntroduce el año: ";
        cin >> anio;

    } while (mes > 12 || mes < 0 || anio < 1900 || anio > 2100);

    array <int, 2> fecha = {mes, anio};

    return fecha;
    
}

bool chkBisiesto(int anio) {

    if (anio % 400 == 0) return true;
    else if (anio % 100 != 0 && anio % 4 == 0) return true;

    else return false;
}