// Santiago Valderrama


#include <iostream>


using namespace std;


int main () {

    int nota;
    bool cont = 1;

    do
    {
        system("cls");
        cout << "Escribe tu nota numérica (0-10): ";
        cin >> nota;

        switch (nota)
        {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
                cout << "\n\n\tINSUFICIENTE";
                break;

            case 5:
            case 6:
                cout << "\n\n\tAPROBADO";
                break;

            case 7:
            case 8:
                cout << "\n\n\tNOTABLE";
                break;

            case 9:
                cout << "\n\n\tSOBRESALIENTE";
                break;

            case 10:
                cout << "\n\n\tMATRÍCULA DE HONOR";
                break;
            
            default:
                break;
        }

        char c;
        do {
            
            cout << "\n\n\t¿Quieres volver a ejecutar el programa? (S/N): ";
            cin >> c;
            c = toupper(c);

        } while(c != 'N' && c != 'S');

        if (c == 'N') cont = 0;
           
        
    } while (cont);
    

    return 0;
}
