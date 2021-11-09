#include <iostream>
#include <string>
using namespace std;
int main() {
    string texto;
    int aux = 0, igual = 0;
    
    cout << "palabra : ";
    getline(cin >> ws, texto);
    
    for(int ind = texto.length() - 1; ind >= 0; ind--) {
        if(texto[ind] == texto[aux]) {
            igual++;
        }
        aux++;
    }
    
    if(texto.length() == igual) {
        cout << "Si es" << endl;
    } else {
        cout << "No es" << endl;
    }
    
    return 0;
}