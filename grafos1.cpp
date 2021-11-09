#include <iostream>
#include <vector>

using namespace std;

class MatrizDeAdyacencia {

private:
  vector < vector <int> > matrix;

public:

  MatrizDeAdyacencia(){

  }

  void newNode(){
    vector <int> arreglo;

    arreglo.push_back(0);
    for (int i = 0; i < matrix.size() - 1 ; i++){
      arreglo.push_back(0);
      this->matrix[i].push_back(0);

    }

    this->matrix.push_back(arreglo);

  }

  void addRelation(int primero, int segundo, int peso){

    this->matrix[primero][segundo] = peso;
      // Solo si es bidireccional
      // matrix[segundo][primero] = peso;

  }

  void deleteRelation(int primero, int segundo){
    if (primero >= 0 && primero < this->matrix.size() && segundo >= 0 && segundo < this->matrix.size()){
      this->matrix[primero][segundo] = 0;
      // Solo si es bidireccional
      // matrix[segundo][primero] = 0;
    }
  }

  void print(){
    for (int i = 0; i < this->matrix.size() ; i++){
      for (int j = 0; j < this->matrix.size() ; j++){
        cout << this->matrix[i][j];
      }
      cout << endl;
    }

  }
};

int main() {
  cout << "antes";

  MatrizDeAdyacencia ejemplo;
  ejemplo.newNode();
  ejemplo.newNode();
  ejemplo.newNode();
  ejemplo.newNode();
  ejemplo.newNode();
  cout << "después";

  /*
  ejemplo.addRelation(0,3,1);
  ejemplo.addRelation(2,1,3);
  ejemplo.addRelation(3,1,2);
  ejemplo.addRelation(2,3,4);

  ejemplo.print();

  */
}
