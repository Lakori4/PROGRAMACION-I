// Santiago Valderrama


#include <iostream>
#include <vector>


using namespace std;

int menu();
int getDim();
int obtenerMax_Min(const vector<vector<int>> &m, bool maxMin);

vector<vector<int>> getMatrix(int dim);
vector<vector<int>> getVectorFilas(const vector<vector<int>> &m);
vector<vector<int>> getVectorColumnas(const vector<vector<int>> &m);
vector<vector<int>> getProducto(const vector<vector<int>> &m1, const vector<vector<int>> &m2);
vector<vector<int>> getTraspuesta(const vector<vector<int>> &m);

void mostrarMatriz(const vector<vector<int>> &m);


int main () {

    bool cont = 1;

    vector <vector <int>> matrix, m2;

    int dim;
    

    while (cont)
    {
        switch (menu())
        {
        case 1:
            matrix = getMatrix(getDim());
            cout << "\n\nMATRIZ SOLICITADA AL USUARIO";
            mostrarMatriz(matrix);
            cout << "\n\n\tEl valor máximo es " << obtenerMax_Min(matrix, 1) << " y el valor mínimo es " << obtenerMax_Min(matrix, false);
            break;

        case 2:
            matrix = getMatrix(getDim());
            cout << "\n\nMATRIZ SOLICITADA AL USUARIO";
            mostrarMatriz(matrix);
            cout << "\n\nMATRIZ SUMA FILAS";
            mostrarMatriz(getVectorFilas(matrix));
            break;

        case 3:
            matrix = getMatrix(getDim());
            cout << "\n\nMATRIZ SOLICITADA AL USUARIO";
            mostrarMatriz(matrix);
            cout << "\n\nVECTOR SUMA COLUMNAS";
            mostrarMatriz(getVectorColumnas(matrix));
            
            break;

        case 4:
            dim = getDim();
            matrix = getMatrix(dim);
            m2 = getMatrix(dim);
            cout << "\n\nPRIMERA MATRIZ SOLICITADA AL USUARIO";
            mostrarMatriz(matrix);
            cout << "\n\nSEGUNDA MATRIZ SOLICITADA AL USUARIO";
            mostrarMatriz(m2);
            cout << "\n\nMATRIZ PRODUCTO";
            mostrarMatriz(getProducto(matrix, m2));
            
            break;
        
        case 5:
            matrix = getMatrix(getDim());
            cout << "\n\nMATRIZ SOLICITADA AL USUARIO";
            mostrarMatriz(matrix);
            cout << "\n\nMATRIZ TRASPUESTA";
            mostrarMatriz(getTraspuesta(matrix));
            
            break;

        case 6:

            cout << "\n\nGracias y hasta pronto\n";
            cont = 0;
            
            break;
        
        default:
            cout << "\n\nLa opción no es válida. Por favor, vuelva a seleccionar otra opción";
            break;
        }
    }
    
    return 0;
}


int menu() {

    int opc;

    cout << "\n\nBienvenido.\n\n\t1. Elementos máximo y mínimo de una matriz.";
    cout << "\n\t2. Crear vector filas de la matriz.\n\t3. Crear vector columnas de la matriz.";
    cout << "\n\t4. Multiplicar dos matrices. \n\t5. Crear la traspuesta de una matriz.\n\t6. Salir del programa"; 
    cout << "\n\nPor favor teclee la opción: ";
    cin >> opc;
    cin.ignore();

    system("cls");

    return opc;
}

int getDim() {

    int n;

    do
    {
        cout << "\n\n\tIntroduzca la dimensión de la matriz (2-100): ";
        cin >> n;
        cin.ignore();

        if (n < 2 || n > 100) cout << "\n\nLA DIMENSIÓN TIENE QUE ESTAR ENTRE 2 Y 100.";
    } while (n < 2 || n > 100);

    return n;
    
}

vector<vector<int>> getMatrix(int dim) {

    vector<vector<int>> m;

    m.resize(dim);

    for (int i = 0; i < m.size(); i++) {
        m[i].resize(dim);
    }

    cout << "\n\nDATOS DE LA MATRIZ";
    cout << "\n\n==================";
    for (int i = 0; i < m.size(); i++) {

        for (int j = 0; j < m[i].size(); j++) {
            cout << "\nElemento[" << i+1 << ", " << j+1 << "] ";
            cin >> m[i][j];
            cin.ignore();
        }
    }

    return m;
}

void mostrarMatriz(const vector<vector<int>> &m) {

    for (vector <int> v : m) {
        cout << "\n| ";
        for(int n : v) {
            cout << n << " ";
        }
        cout << "|";
    }
}

int obtenerMax_Min(const vector<vector<int>> &m, bool maxMin) {
    int max = m[0][0], min = m[0][0];

    for (vector <int> v : m) {
        for (int n : v) {
            if (n < min) min = n;
            if (n > max) max = n;
        }
    }

    if (maxMin) return max;
    else return min;
}

vector<vector<int>> getVectorFilas(const vector<vector<int>> &m) {

    vector<vector<int>> mFilas;

    mFilas.resize(m.size());
    

    for (int i = 0; i < m.size(); i++) {

        int n = 0;
        for (int j = 0; j < m[i].size(); j++) {

            n += m[i][j];
        }
        mFilas[i].push_back({n});
    }

    return mFilas;
}

vector<vector<int>> getVectorColumnas(const vector<vector<int>> &m) {

    vector<vector<int>> mColumnas;

    mColumnas.resize(m.size());
    

    for (int i = 0; i < m.size(); i++) {

        int n = 0;
        for (int j = 0; j < m[i].size(); j++) {

            n += m[j][i];
        }
        mColumnas[i].push_back({n});
    }

    return mColumnas;
}

vector<vector<int>> getProducto(const vector<vector<int>> &m1, const vector<vector<int>> &m2) {
    
    vector<vector<int>> mProducto = m1;

    for (int i = 0; i < m1.size(); i++) {

        
        for (int j = 0; j < m1[i].size(); j++) {

            int n = 0;

            for (int k = 0; k < m1.size(); k++) {
                n += m1[i][k] * m2[k][j];
            }
            mProducto[i][j] = n;
        }
    }
    return mProducto;
}


vector<vector<int>> getTraspuesta(const vector<vector<int>> &m) {

    vector<vector<int>> mTraspuesta = m;

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            mTraspuesta[j][i] = m[i][j];
        }
    }
    return mTraspuesta;
}