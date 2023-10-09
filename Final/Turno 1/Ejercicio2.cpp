// Santiago Valderrama


#include <iostream>
#include <string>
#include <array>

using namespace std;

array <string, 2> getStrings();
void chkIncluded (int &pI, int &pF, bool &iS, const string &s1, const string &s2);

int main () {

    array <string, 2> fraseYpalabra = getStrings();
    int posIni, posFin;
    bool isIncluded;

    chkIncluded(posIni, posFin, isIncluded, fraseYpalabra[0], fraseYpalabra[1]);

    if (!isIncluded) {

        cout << "La cadena: " << fraseYpalabra[1] << " NO está incluida en la cadena: " << fraseYpalabra[0] << endl;
    }

    else {
        cout << "La cadena: " << fraseYpalabra[1] << " SI está incluida en la cadena: " << fraseYpalabra[0] << endl;
        cout << "Empieza en la posición " << posIni << " y acaba en la posición " << posFin << endl;
    }

    

    
    return 0;
}

array <string, 2> getStrings() {

    array <string, 2> aString;

    cout << "\n\n\tEscribe una frase: ";
    getline(cin, aString[0]);

    cout << "\n\tAhora escribe una palabra: ";
    cin >> aString[1];
    cin.ignore();

    return aString;
}

void chkIncluded (int &pI, int &pF, bool &iS, const string &s1, const string &s2) {

    for (int i = 0; i < s1.size(); i++) {

        if(s1[i] == s2[0]) {

            

            iS = true;
            pI = i;
            for (int j = 1; j < s2.size(); j++) {

                if (s1[i+j] != s2[j]) iS = false;

            }

            if (iS) { 
                pF = i + s2.size();
                break;
            }
        }
    }
}