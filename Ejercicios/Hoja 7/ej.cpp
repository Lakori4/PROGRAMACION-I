// Santiago Valderrama


#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct fecha
{
    int dia, mes, anio;
};


struct persona
{
    string nom, apellido;
    fecha fNac;
};


int menu();
void mosEmpty() {cout << "\n\n\tLo sentimos, la operación no se puede realizar porque la lista esta vacia";}

void mostrarFecha(fecha &f) { cout << f.dia << "/" << f.mes << "/" << f.anio; }

fecha getFecha();

persona getPersona(vector <unique_ptr<persona>> &v);

bool findPers(string const &n, string const &a, vector <unique_ptr<persona>> &v);

int main () {

    vector <unique_ptr<persona>> vPersonasPtr;
    bool cont;

    while (true)
    {
        switch (menu())
        {
        case 1:
            do
            {   

                vPersonasPtr.push_back(make_unique <persona> (getPersona(vPersonasPtr)));

                char r;

                do
                {
                    cout << "¿Desea añadir a otra persona? (S/N): ";
                    cin >> r;
                    r = toupper(r);

                } while (r != 'N' && r != 'S');

                if (r == 'N') break;

            } while (true);
            
            break;


        case 2:

            if (vPersonasPtr.empty()) mosEmpty();

            else{

                for (int i = 0; i < vPersonasPtr.size(); i++) {
                    cout << "\n\t" << i+1 << ". " << vPersonasPtr[i].get()->nom << " " << vPersonasPtr[i].get()->apellido << " "; mostrarFecha(vPersonasPtr[i].get()->fNac);
                }
            }
            break;


        case 3:
            if (vPersonasPtr.empty()) mosEmpty();

            else{

                string n, a;

                cout << "\n\tIntroduce el nombre de la persona que buscas: ";
                cin >> n;

                cout << "\n\tIntroduce los apellidos de la persona que buscas: ";
                cin.ignore();
                getline(cin, a);

                if (!findPers(n, a, vPersonasPtr)) cout << "La persona " << n << " " << a << " no existe en la lista.";;
                
            }
            break;


        case 4:

            if (vPersonasPtr.empty()) mosEmpty();

            else{
                
                int m;
                vector <persona> vPers;

                cout << "\n\n\tIntroduce un mes: ";
                cin >> m;

                for (int i = 0; i < vPersonasPtr.size(); i ++) {
                    if (vPersonasPtr[i].get()->fNac.mes == m) vPers.push_back(*vPersonasPtr[i]);
                }

                if (vPers.empty()) cout << "No hay personas que hayan nacido en el mes: " << m;
                else{

                    cout << "Las personas nacidas en el mes " << m << " son: ";

                    for (int i = 0; i < vPers.size(); i++) {

                        cout << vPers[i].nom << " " << vPers[i].apellido << " - "; mostrarFecha(vPers[i].fNac);
                    }
                }
                
            }
            break;


        case 5:
            
            if (vPersonasPtr.empty()) mosEmpty();

            else{
                
            }
            break;
        

        case 0:
            cout << "\n\n\tGracias y hasta pronto\n\n";
            system("pause");
            return 0;
            break;
        
        default:
            cout << "\n\n\tLa opción no es válida. Por favor, vuelva a seleccionar otra opción";
            break;
        }
    }
}

int menu() {

    int opc;

    cout << "\n\n\nBienvenido.\n\nPor favor seleccione una opción.";
    cout << "\n\n\t1. Introducir personas.\n\t2. Listado de personas";
    cout << "\n\t3. Buscar una persona.\n\t4. Listado de personas nacidas el mismo mes.";
    cout << "\n\t5. Listado de personas por fecha de nacimiento.\n\t0. Salir del programa\n\n";
    
    cin >> opc;

    system("cls");

    return opc;
}

fecha getFecha() {

    fecha f;

    cout << "\n\n\tIntroduce el día de nacimiento: ";
    cin >> f.dia;

    cout << "\n\tIntroduce el mes de nacimiento: ";
    cin >> f.mes;

    cout << "\n\tIntroduce el año de nacimiento: ";
    cin >> f.anio;

    return f;
}


persona getPersona(vector <unique_ptr<persona>> &v) {

    persona p;

    string a2;

    cout << "\n\n\tIntrouduce el nombre de la persona: ";
    cin >> p.nom;

    cout << "\n\tIntrouduce los apellidos de la persona: ";
    cin.ignore();
    getline(cin, p.apellido);
    

    if (!findPers(p.nom, p.apellido, v)) p.fNac = getFecha();

    return p;
}

bool findPers(string const &n, string const &a, vector <unique_ptr<persona>> &v) {

    for (int i = 0; i < v.size(); i++) {
        if (v[i].get()->nom == n && v[i].get()->apellido == a) {

            cout << "\n\nLa persona " << v[i].get()->nom << " " << v[i].get()->apellido << " ya existe y su fecha de nacimiento es: "; mostrarFecha(v[i].get()->fNac);
            return true;
        }
    }    
    return false;
}
