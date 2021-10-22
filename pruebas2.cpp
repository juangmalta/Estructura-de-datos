#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int Busqyedasequencial(vector<int> a, int k)
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
int busqBinaria(vector<int> a, int k)
{ //
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
vector<int> bubble_sort(vector<int> A)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int tmp_value = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp_value;
            }
        }
    }
    return A;
}

vector<int> insertion_sort(vector<int> A){
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
void merge(vector<int> &arreglo, int inicio, int mitad, int final)
{
    int i, j, k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    vector<int> izquierda(elementosIzq);
    vector<int> derecha(elementosDer);

    for (int i = 0; i < elementosIzq; i++)
    {
        izquierda[i] = arreglo[inicio + i];
    }
    for (int j = 0; j < elementosDer; j++)
    {
        derecha[j] = arreglo[mitad + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < elementosIzq && j < elementosDer)
    {
        if (izquierda[i] <= derecha[j])
        {
            arreglo[k] = izquierda[i];
            i++;
        }
        else
        {
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (j < elementosDer)
    {
        arreglo[k] = derecha[j];
        j++;
        k++;
    }

    while (i < elementosIzq)
    {
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }
}

void mergeSort(vector<int> &arreglo, int inicio, int final)
{
    if (inicio < final)
    {
        int mitad = inicio + (final - inicio) / 2;
        mergeSort(arreglo, inicio, mitad);
        mergeSort(arreglo, mitad + 1, final);
        merge(arreglo, inicio, mitad, final);
    }
}

int main()
{
    vector<int> v1 = {2, 1, 3, 5, 4};
    vector<int> v2 = {1, 3, 5, 7, 4};
    vector<int> v3 = {11, 12, 13, 14, 16};
    vector<int> v4 = {7, 6, 3, 4, 2};

    cout << "vector before sorting." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << v1[i] << " ";
    }
    vector<int> v1_order = bubble_sort(v1);
    cout << endl
         << "Vector after sorting." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << v1_order[i] << " ";
    }
    cout << "vector before sorting." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << v2[i] << " ";
    }
    vector<int> v2_order = insertion_sort(v2);
    cout << endl
         << "Vector after sorting." << endl;
    for (int i = 0; i < 5; i++)
    {


        cout << v2_order[i] << " ";
    }
    cout << endl
         << busqBinaria(v1, 4) << endl;
}
