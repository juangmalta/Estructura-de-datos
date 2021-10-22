#include <iostream>

using namespace std;

int suma_iterativa(int n){ //usa iteraciones para hacer la suma; Pertenece a O(n)
    int a=0;//variable de la suma
    for (int i = 1; i <= n; i++)//se repite n veces
    {
        a+=i;//le suma el numero que sigue a la variable 
    }
    return a;
}

int suma_recursiva(int n){//usa recursividad para hacer la suma; pertenece a O(n)
    
if(n==1) return 1;//si n es 1, el resultado de la suma es 1

return (suma_recursiva(n-1)+n);//se reingresan los datos en la funcion hasta llegar al resultado.

}

int suma_directa(int n){//usa un metodo matematico para hacer la suma
    return n*(n+1)/2;//usa una de las propiedades de sumatoria para hacer la suma; pertence a O(n^2)
}

int main()
{
    
    cout<<"Casos de prueba"<<endl;//se llama a cada una de las funciones
    cout<<"Suma con iteraciones de 1 a 9 "<<suma_iterativa(9)<<endl; 
    cout<<"Suma con recursividad de 1 a 9 "<<suma_recursiva(9)<<endl; 
    cout<<"Suma directa de 1 a 9 "<<suma_directa(9)<<endl; 
    cout<<"Suma con iteraciones de 1 a 25 "<<suma_iterativa(25)<<endl; 
    cout<<"Suma con recursividad de 1 a 25 "<<suma_recursiva(25)<<endl; 
    cout<<"Suma directa de 1 a 25 "<<suma_directa(25)<<endl;
    cout<<"Suma con iteraciones de 1 a 40 "<<suma_iterativa(40)<<endl; 
    cout<<"Suma con recursividad de 1 a 40 "<<suma_recursiva(40)<<endl; 
    cout<<"Suma directa de 1 a 40 "<<suma_directa(40)<<endl;
    cout<<"Suma con iteraciones de 1 a 73 "<<suma_iterativa(73)<<endl; 
    cout<<"Suma con recursividad de 1 a 73 "<<suma_recursiva(73)<<endl; 
    cout<<"Suma directa de 1 a 73 "<<suma_directa(73)<<endl;

    return 0;
}