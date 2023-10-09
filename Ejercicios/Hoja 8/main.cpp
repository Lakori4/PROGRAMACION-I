// Santiago Valderrama


#include <iostream>
#include <vector>
#include <memory>

using namespace std;


vector <vector <shared_ptr <int>>> getMatrix();

vector <vector <shared_ptr <int>>> sumarMatrices (const vector <vector <shared_ptr <int>>> &m1, const vector <vector <shared_ptr <int>>> &m2);
vector <vector <shared_ptr <int>>> restarMatrices (const vector <vector <shared_ptr <int>>> &m1, const vector <vector <shared_ptr <int>>> &m2); 
vector <vector <shared_ptr <int>>> traspuesta (const vector <vector <shared_ptr <int>>> &m);
void mostrarMatriz (const vector <vector <shared_ptr <int>>> &m);



int main () {


    vector <vector <shared_ptr <int>>> m1 = getMatrix(); 

    vector <vector <shared_ptr <int>>> m2 = getMatrix();

    mostrarMatriz(sumarMatrices(m1, m2));
    mostrarMatriz(restarMatrices(m1, m2));
    mostrarMatriz(traspuesta(m1));

    
    

    return 0;
}

vector <vector <shared_ptr <int>>> getMatrix() {

    vector <vector <shared_ptr <int>>> matrix;

    int dim;

    cout << "\n\nIntroduce la altura de la matriz: ";
    cin >> dim;

    matrix.resize(dim);

    cout << "\n\nIntroduce la anchura de la matriz: ";
    cin >> dim;

    for (int i = 0; i < matrix.size(); i++) {
        matrix[i].resize(dim);

        for (int j = 0; j < matrix[i].size(); j++) {
            int n;
            cout << "\n\t[" << i+1 << ", " << j+1 << "] = ";
            cin >> n;
            matrix[i][j] = make_shared <int> (n);
        }
    }

    return matrix;
}

vector <vector <shared_ptr <int>>> sumarMatrices (const vector <vector <shared_ptr <int>>> &m1, const vector <vector <shared_ptr <int>>> &m2) {

    vector <vector <shared_ptr <int>>> m = m1;

    for (int i = 0; i < m.size(); i++) {
        
        for (int j = 0; j < m[i].size(); j++) {
            m[i][j] = make_shared <int> (*m1[i][j] + *m2[i][j]);
        }

    }
    return m;
}


vector <vector <shared_ptr <int>>> restarMatrices (const vector <vector <shared_ptr <int>>> &m1, const vector <vector <shared_ptr <int>>> &m2) {

    vector <vector <shared_ptr <int>>> m = m1;

    for (int i = 0; i < m.size(); i++) {
        
        for (int j = 0; j < m[i].size(); j++) {
            m[i][j] = make_shared <int> (*m1[i][j] - *m2[i][j]);
        }
    }
    return m;
}

vector <vector <shared_ptr <int>>> traspuesta (const vector <vector <shared_ptr <int>>> &m) {

    vector <vector <shared_ptr <int>>> t = m;

    for (int i = 0; i < m.size(); i++) {
        
        for (int j = 0; j < m[i].size(); j++) {

            t[i][j] = m[j][i];
        }
    }
    return t;
}


void mostrarMatriz (const vector <vector <shared_ptr <int>>> &m) {

    

    for (int i = 0; i < m.size(); i++) {
        cout << "\n | ";
        
        for (int j = 0; j < m[i].size(); j++) {
            cout << *m[i][j] << " ";
        }

        cout << " |";
    }
}
