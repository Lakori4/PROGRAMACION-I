#include <iostream> 
#include <vector>

using namespace std;

float valMax (const vector <float> &v);
float valMin (const vector <float> &v);
float valMed (const vector <float> &v);


int main() {

    vector <vector <float>> v = {{1.1, 2.2, 3.3}, {3.3, 5.5}, {1.1, 1.1, 1.1, 1.1}};
    vector <float> vMax;
    float max = valMax(v[0]), min = valMin(v[0]), med = 0;

    for (vector <float> v1: v) {
        
        vMax.push_back(valMax(v1));
        
        if (max < valMax(v1)) max = valMax(v1); 
        if (min > valMin(v1)) min = valMin(v1);
    }

    med = valMed(vMax);

    cout << "El valor máximo es: " << max << "\nEl valor mínimo es: " << min << "\nEl valor medio es: " << med;


    return 0;
}

float valMin (const vector <float> &v) {

    float n = v[0];

    for (float m : v) {
        if (m < n) n = m;
    }

    return n;
}

float valMax (const vector <float> &v) {

    float n = v[0];

    for (float m : v) {
        if (m > n) n = m;
    }
    
    return n;
}

float valMed (const vector <float> &v) {

    float sum = 0;

    for (float f : v) {
        sum += f;
    }
    return (sum/v.size());
}