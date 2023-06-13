// Santiago Valderrama


#include <iostream>
#include <array>

const  int dim = 5;


using namespace std;


struct elemMatrix {
    int elem;
    int fila;
    int col;
};


int menu();
array <array<int, dim>, dim> getMatrix();
void mostrarMatrix(array <array<int, dim>, dim> const &m);
struct elemMatrix elemMenor(array <array<int, dim>, dim> const &m);


ostream &operator<< (ostream &os, const struct elemMatrix &e) {
    
    os << e.elem << " en la coordenada [" << e.col+1 << ", " << e.fila+1 << "]"; 

    return os;
}

array <array<int, dim>, dim> operator+ (array <array<int, dim>, dim> &m1, array <array<int, dim>, dim> &m2) {

    array <array<int, dim>, dim> matrix;

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return matrix;
}

array <array<int, dim>, dim> operator* (array <array<int, dim>, dim> &m1, array <array<int, dim>, dim> &m2) {

    array <array<int, dim>, dim> matrix;

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = m1[i][j] * m2[i][j];
        }
    }

    return matrix;
}

array <array<int, dim>, dim> operator* (array <array<int, dim>, dim> &m, int n) {

    array <array<int, dim>, dim> matrix;

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = m[i][j] * n;
        }
    }

    return matrix;
}





int main () {

    while (true) {

        system("cls");

        array <array<int, dim>, dim> m1;
        array <array<int, dim>, dim> m2;
        
        int n;


        switch (menu())
        {

        case 1:

            m1 = getMatrix();
            mostrarMatrix(m1);
            cout << "\n\n\tEl elemento menor de tu matriz es: " << elemMenor(m1) << endl;
            system ("pause");

            break;


        case 2:

            cout << "\n\n\tIntroduce a continuación los datos de la 1ª matriz: " << endl;
            m1 = getMatrix();

            cout << "\n\tIntroduce a continuación los datos de la 2ª matriz: " << endl;
            m2 = getMatrix();

            cout << "\n\tLa suma de las matrices es: ";
            mostrarMatrix(m1+m2); 

            system("pause");

            break;


        case 3:

            cout << "\n\n\tIntroduce a continuación los datos de la matriz: " << endl;
            m1 = getMatrix();

            cout << "\n\tIntroduce ahora tu escalar: ";
            cin >> n;

            cout << "El producto de tu matriz por " << n << " es: "; mostrarMatrix(m1*n);

            system("pause");

            break;


        case 4:

            cout << "\n\n\tIntroduce a continuación los datos de la 1ª matriz: " << endl;
            m1 = getMatrix();

            cout << "\n\tIntroduce a continuación los datos de la 2ª matriz: " << endl;
            m2 = getMatrix();

            cout << "\n\tEl producto de las matrices es: ";
            mostrarMatrix(m1*m2); 

            system("pause");

            break;


        case 5:

            cout << "\n\n\tIntroduce a continuación los datos de la matriz: " << endl;
            m1 = getMatrix();

            for (int i = 0; i < m1.size(); i++) {
                for (int j = 0; j < m1[i].size(); j++) {
                    m2[j][i] = m1[i][j];
                }
            }

            cout << "\n\tTu matriz traspuesta es: ";
            mostrarMatrix(m2);
            system("pause");

            break;


        case 6:
            cout << "\n\n\tGracias y hasta pronto.\n";
            return 0;
            break;
        

        default:
            cout << "\n\n\tLa opción no es válida. Por favor vuelva a seleccionar otra opción" << endl;
            system("pause");
            break;
        }
    }
}



int menu () {
    int opc;

    cout << "Bienvenido.\n\nPor favor seleccoina una opción.";
    cout << "\n\n\t1. Elemento menor de una matriz 5x5.";
    cout << "\n\t2. Sumar dos matrices 5x5.";
    cout << "\n\t3. Producto de un número por una matriz 5x5.";
    cout << "\n\t4. Multiplicar dos matrices 5x5.";
    cout << "\n\t5. Traspuesta de una matriz 5x5.";
    cout << "\n\t6. Salir del programa.\n\n";

    cin >> opc;

    return opc;
}


array <array<int, dim>, dim> getMatrix() {

    array <array<int, dim>, dim> matrix;
    

    for (int i = 0; i < matrix.size(); i++) {

        for (int j = 0; j < matrix[i].size(); j++) {
            cout << "\n[" << i+1 << ", " << j+1 << "]: ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void mostrarMatrix(array <array<int, dim>, dim> const &m) {

    

    cout << "\n\n";

    for (int i = 0; i < m.size(); i++) {

        cout << "\t|";

        for (int j = 0; j < m[i].size(); j++) {

            cout << m[i][j] << "|";
        }
        cout << "\n";
    }    
}

struct elemMatrix elemMenor(array <array<int, dim>, dim> const &m) {

    elemMatrix menor;
    menor.col = 0;
    menor.fila = 0;
    menor .elem = m [0][0];

    for (int i = 0; i < m.size(); i++) {

        for (int j = 0; j < m[i].size(); j++) {
            
            if (menor.elem > m[i][j]) { 
                
                menor.elem = m[i][j]; 
                menor.col = i; 
                menor.fila = j;
            }
        }
    }
    return menor;
}