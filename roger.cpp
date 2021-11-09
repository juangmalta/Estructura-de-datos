#include <iostream>
using namespace std;

class Cuenta
{
public:
    Cuenta(int sald_o);
    void credit();
    void cargar();
    int obtenerSaldo();

private:
    int saldo;
    int retiro;
    int aumento;
};

Cuenta::Cuenta(int sald_o)
{
    saldo = sald_o;
};

void Cuenta::credit()
{
    cout << "Monto a guardar: " << endl;
    cin >> aumento;
    saldo = saldo + aumento;
};

void Cuenta::cargar()
{
    cout << "Monto a retirar: " << endl;
    cin >> retiro;
    if (retiro > saldo)
    {
        cout << "Transaccion fallida, no hay suficientes fondos" << endl;
    }
    else
    {
        cout << "Transaccion fallida, no hay suficientes fondos" << endl;
    }
};

int Cuenta::obtenerSaldo()
{
    return saldo;
};

int main()
{
    int saldo_inicial;
    cout << "Escribe tu saldo inicial: " << endl;
    cin >> saldo_inicial;


    Cuenta saldoinicial(300);
    saldoinicial.credit();
    cout << saldoinicial.obtenerSaldo() << endl;
}
