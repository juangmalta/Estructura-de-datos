#include <iostream>
using namespace std;

int main()
{
    int num, menor = 100000;
    int x;
    string v;

    while (v != "no")
    {
        cout << "ingresa la cantidad de numeros: " << endl;
        cin >> x;

        for (int i = 1; i <= x; i++)
        {
            cout << "ingresa el numero " << i << endl;
            cin >> num;
            if (num < menor)
            {
                menor = num;
            }
        }
        cout << "el menor fue" << menor << endl;

        cout << "deseas continuar?" << endl;
        cin >> v;
    }
}
