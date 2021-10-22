/**
* Ejemplo que implementa un arbol AVL
*
* Compilacion para debug:
*    g++ -std=c++17 -g -o main *.cpp
* Ejecucion con valgrind:
*    valgrind --leak-check=full ./main
*
* Compilacion para ejecucion:
*    g++ -std=c++17 -O3 -o main *.cpp
* Ejecucion:
*    ./main
**/
#include <iostream>
#include "AVLTree.h"


int main() {
  std::cout << "Prueba de un AVL!\n";
  AVLTree<int> avl;

  avl.insert(10);
  avl.insert(20);
  avl.insert(30);
  avl.insert(40);
  avl.insert(50);
  avl.insert(25);
  /* The constructed AVL Tree would be
            30
            / \
            20 40
            / \ \
          10 25 50
  */
  avl.callPreorder();



}
