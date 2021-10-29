#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

template <class T> class maxHeapTree
{
public:
  vector<pair<T, int>> heapArr;
  int key;

  maxHeapTree()
  {
  }
  maxHeapTree(T data, int key)
  {
    heapArr[0] = make_pair(data, key);
  }

  int padre(int n)
  {
    return (n - 1) / 2;
  }

  int izquierdo(int n)
  {
    return (2 * n) + 1;
  }

  int derecho(int n)
  {
    return (2 * n) + 2;
  }

  int size()
  {
    return heapArr.size() + 1;
  }

  void push(T data, int key)
  {
    heapArr.push_back(make_pair(data, key));
    int pos = heapArr.size() - 1;
    while (pos != 0 && heapArr[pos].second > padre(pos))
    {
      swap(heapArr[pos], heapArr[padre(pos)]);
      pos = padre(pos);
    }
  }

  int maximum(int index)
  {
    int newPos;
    int newPadre = max(heapArr[izquierdo(index)].second, heapArr[izquierdo(index)].second);
    if (newPadre == heapArr[izquierdo(index)].second)
      newPos = izquierdo(index);
    if (newPadre == heapArr[izquierdo(index)].second)
      newPos = izquierdo(index);
    return newPos;
  }

  void pop(int n)
  {
    int size = heapArr.size() - 1;
    if (izquierdo(n) > size && derecho(n) > size)
    {
      heapArr.pop_back();
      return;
    }
    swap(heapArr[n], heapArr[maximum(n)]);
    pop(maximum(n));
  }

  bool empty()
  {
    if (heapArr.size() == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  void printarr()
  {
    for (int i = 0; i < heapArr.size(); i++)
    {
      cout << heapArr[i].first << ", ";
    }
    cout << endl;
  }
};

int main()
{
  maxHeapTree<int> tree;
  tree.push(10, 10);
  tree.push(30, 30);
  tree.push(20, 20);
  tree.push(40, 40);

  tree.printarr();

  tree.pop(0);

  tree.printarr();

  cout << tree.size() << endl;

  tree.printarr();

  tree.pop(1);

  tree.printarr();
  return 0;
}
