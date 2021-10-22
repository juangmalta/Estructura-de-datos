#include <iostream>

using namespace std;

int fibonacci_compute(int x){
    //base
    if(x<=1) return 1;
    //induccion 
    return fibonacci_compute(x-1)+fibonacci_compute(x-2); // usa induccion (no recomendado para numeros grandes)
}

int factorial(int x){
    if(x <= 1) return 1;

    return factorial(x-1)*x;
}

int main()
{
    cout<<"Fibonacci of 10: "<<fibonacci_compute(9)<<endl;

    cout<<"Factorial of 5: "<<factorial(5)<<endl;

    return 0;
}

