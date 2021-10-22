#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> ordena_intercambio(vector<int> A)//comlejidad de O(n^2)
{
    int n = A.size();
    int k, j;
    for (int i = 0; i < n; i++)
    {
        k = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > k)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = k;
    }
    return A;
}

vector<int> ordena_burbuja(vector<int> A)//complejidad de O(n^2)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])//manda los valores mas grandes hasta el final y asi acomoda
            {
                int tmp_value = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp_value;
            }
        }
    }
    return A;
}
void merge(vector<int> &a, int l, int m, int r)
{
    // Para ciclos
    int elel = m - l + 1;
    int eler = r - m;

    // Tamaño de subarreglos a fusionar
    int izquierda[elel];
    int derecha[eler];

    // Copiar datos en subarreglos temporales
    for (int i = 0; i < elel; i++)
    {
        izquierda[i] = a[l + i];
    }
    for (int j = 0; j < eler; j++)
    {
        derecha[j] = a[m + 1 + j];
    }

    // Variables para while
    int h = 0;
    int w = 0;
    int k = l;

    // Fusionar valores de los dos vectores
    while (h < elel && w < eler)
    {
        // Si el elemento del lado izquierdo es menor
        if (izquierda[h] <= derecha[w])
        {
            a[k] = izquierda[h];
            h = h + 1;
        }
        // Si no
        else
        {
            a[k] = derecha[w];
            w = w + 1;
        }
        k = k + 1;
    }

    // Copiar elementos restantes
    while (h < elel)
    {
        a[k] = izquierda[h];
        h = h + 1;
        k = k + 1;
    }

    while (w < eler)
    {
        a[k] = derecha[w];
        w = w + 1;
        k = k + 1;
    }
}

void ordenaMerge(vector<int> &a, int l, int r)//complejidad de O(nlogn)
{
    // Busca si el lado izquierdo es mayor que el derecho ya que es recursiva
    if (l < r)
    {

        int m = floor((r + l) / 2);
        ordenaMerge(a, l, m);
        ordenaMerge(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int busqueda_secuencial(vector<int> a, int k)
{ //
    int n = a.size();
    int i = 0;
    while (i < n and a[i] != k)
    {
        i = i + 1;
    }
    if (i < n)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int busqueda_Binaria(vector<int> a, int k)//Complejidad de O(logn)
{
    int n = a.size();
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = floor((l + r) / 2);
        if (k == a[m])
        {
            return m;
        }
        else if (k < a[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

void printVector(vector<int> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
}

int main()
{
    cout << "Actividad 2" << endl;
    cout << "--------------------------" << endl;
    cout << "vectors before sorting" << endl;
    cout << "--------------------------" << endl;
    vector<int> v1 = {2, 1, 3, 5, 4};
    vector<int> v2 = {1, 3, 8, 7, 4, 2, 9};
    vector<int> v3 = {11, 37, 13, 9, 16};
    vector<int> v4 = {7, 6, 3, 4, 2};
    printVector(v1);
    printVector(v2);
    printVector(v3);
    printVector(v4);
    cout << "--------------------------" << endl;
    cout << "vectors after insertion sorting" << endl;
    cout << "--------------------------" << endl;
    vector<int> v1is = ordena_intercambio(v1);
    vector<int> v2is = ordena_intercambio(v2);
    vector<int> v3is = ordena_intercambio(v3);
    vector<int> v4is = ordena_intercambio(v4);
    printVector(v1is);
    printVector(v2is);
    printVector(v3is);
    printVector(v4is);
    cout << "--------------------------" << endl;
    cout << "vectors after bubble sorting" << endl;
    cout << "--------------------------" << endl;
    vector<int> v1bu = ordena_burbuja(v1);
    vector<int> v2bu = ordena_burbuja(v2);
    vector<int> v3bu = ordena_burbuja(v3);
    vector<int> v4bu = ordena_burbuja(v4);
    printVector(v1bu);
    printVector(v2bu);
    printVector(v3bu);
    printVector(v4bu);
    cout << "--------------------------" << endl;
    cout << "vectors after merge sorting" << endl;
    cout << "--------------------------" << endl;
    ordenaMerge(v1,0,v1.size());
    ordenaMerge(v2,0,v2.size());
    ordenaMerge(v3,0,v3.size());
    ordenaMerge(v4,0,v4.size());
    printVector(v1);
    printVector(v2);
    printVector(v3);
    printVector(v4);
    cout << "--------------------------" << endl;
    int x;
    cout << "search vector (secuetial)" << endl;
    cout << "enter value to search on vector 1" << endl;
    cin >> x;
    cout << busqueda_secuencial(v1, x) << endl;
    cout << "search vector (binary)" << endl;
    cout << "enter value to search on vector 2" << endl;
    cin >> x;
    cout << busqueda_Binaria(v2, x) << endl;
    cout << "search vector (secuetial)" << endl;
    cout << "enter value to search on vector 3" << endl;
    cin >> x;
    cout << busqueda_secuencial(v3, x) << endl;
    cout << "search vector (binary)" << endl;
    cout << "enter value to search on vector 2" << endl;
    cin >> x;
    cout << busqueda_Binaria(v4, x) << endl;
    return 0;
}
