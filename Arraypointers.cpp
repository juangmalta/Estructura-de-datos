#include <iostream>

using namespace std;

int main(){
    int a[10],*pa;
    for (int i = 0; i < 10; i++)
    {
        a[i]=(1+i)*100;
    }
    pa=&a[0];
    cout<<*pa<<endl;
    pa++;
    cout<<*pa<<endl;

}