#include <iostream>
#include <vector>
#include <string>
using namespace std;

int convertToASCII(string letter){
    for (int i = 0; i < letter.length(); i++){
        char x = letter.at(i);
        return int(x);
    }
    return 255;
}

int hashFunction(string nombre){
	int indice = 0;
	string a = "", b = "", c = "";
  	a = nombre[0];
  	b = nombre[1];
  	c = nombre[2];
  	indice += convertToASCII(a) + convertToASCII(b) + convertToASCII(c); // Sumamos los valores ASCII
  	return indice;
}

void insertar(vector< vector <string> > &hash, string palabra){
	int indice = hashFunction(palabra);
	hash[indice].push_back(palabra);
}

bool exist(vector< vector<string> > &hash, string palabra){
  int indice = hashFunction(palabra);
  for (int i= 0; i < hash[indice].size(); i++){
    if(palabra == hash[indice][i]){
      return true;
    }
  }
  return false;
}

int main() {
	vector< vector<string> > hashtable(1000); // Para guardar 10000 elementos
	insertar(hashtable, "Alexa");
    insertar(hashtable, "Carlos");
    cout << exist(hashtable, "Alexa");
	return 0;
}  

