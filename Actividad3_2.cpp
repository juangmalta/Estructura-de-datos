//Programa que almacena datos en un vector, ordena la información y lo almacena en un nuevo archivo.
//Autores: David Román Velasco A01639645
//Paulina Lizet Gutiérrez Amezcua A01639948,
//Juan Pablo García Malta A01639025
//Fecha de creación: 7 de septiembre del 2021
//Act 1.3 - Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales.

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Abrir el archivo y almacenarlo los datos en un vector.
void leerArchivo(string nombreArchivo, vector<string> &bitacora)
{
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea))
  {
    // Lo vamos imprimiendo
    bitacora.push_back(linea);
  }
}

vector<vector<string>> separar(vector<string> &bitacora)
{
  vector<vector<string>> bitacoraAcomodada;
  string spaceDelimiter = " ";
  size_t pos = 0;
  std::string token;
  for (int i = 0; i < bitacora.size(); i++)
  {
    vector<string> vectorTemp;
    string s = bitacora[i];
    while ((pos = s.find(spaceDelimiter)) != std::string::npos)
    {
      token = s.substr(0, pos);
      vectorTemp.push_back(token);
      s.erase(0, pos + spaceDelimiter.length());
    }

    bitacoraAcomodada.push_back(vectorTemp);
  }
  cout << bitacoraAcomodada[4][3] << endl;
  return bitacoraAcomodada;
}

vector<string> dividir(string str, char pattern)
{
  int posInit = 0;
  int posFound = 0;
  string splitted;
  vector<string> results;

  while (posFound >= 0)
  {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }

  return results;
}

// Ordena la información por fecha para la realización de las búsquedas.
vector<vector<string>> convertirNumeros(vector<vector<string>> vector)
{
  for (int i = 0; i < vector.size(); i++)
  {
    if (vector[i][0] == "Jan")//convertimos los meses en números
    {
      vector[i][0] = "100000000"; //multiplicamos por 100000000 para generar un id unico para cada fecha
    }
    else if (vector[i][0] == "Feb")
    {
      vector[i][0] = "200000000";
    }
    else if (vector[i][0] == "Mar")
    {
      vector[i][0] = "300000000";
    }
    else if (vector[i][0] == "Apr")
    {
      vector[i][0] = "400000000";
    }
    else if (vector[i][0] == "May")
    {
      vector[i][0] = "500000000";
    }
    else if (vector[i][0] == "Jun")
    {
      vector[i][0] = "600000000";
    }
    else if (vector[i][0] == "Jul")
    {
      vector[i][0] = "700000000";
    }
    else if (vector[i][0] == "Aug")
    {
      vector[i][0] = "800000000";
    }
    else if (vector[i][0] == "Sep")
    {
      vector[i][0] = "900000000";
    }
    else if (vector[i][0] == "Oct")
    {
      vector[i][0] = "1000000000";
    }
    else if (vector[i][0] == "Nov")
    {
      vector[i][0] = "1100000000";
    }
    else if (vector[i][0] == "Dec")
    {
      vector[i][0] = "1200000000";
    }
    else
    {
      cout << "Error en conversión" << endl;//es para saber si ocurre un error
    }
  }
  return vector;
}

vector<vector<string>> convertirMeses(vector<vector<string>> vector) //esta funcion se llama despues de encontrar el valor.
{
  for (int i = 0; i < vector.size(); i++)
  {
    if (vector[i][0] == "100000000")//se convierte el mes de nuevo en su aberviatura para facilitar su lectura.
    {
      vector[i][0] = "Jan";
    }
    else if (vector[i][0] == "200000000")
    {
      vector[i][0] = "Feb";
    }
    else if (vector[i][0] == "300000000")
    {
      vector[i][0] = "Mar";
    }
    else if (vector[i][0] == "400000000")
    {
      vector[i][0] = "Apr";
    }
    else if (vector[i][0] == "500000000")
    {
      vector[i][0] = "May";
    }
    else if (vector[i][0] == "600000000")
    {
      vector[i][0] = "Jun";
    }
    else if (vector[i][0] == "700000000")
    {
      vector[i][0] = "Jul";
    }
    else if (vector[i][0] == "800000000")
    {
      vector[i][0] = "Aug";
    }
    else if (vector[i][0] == "900000000")
    {
      vector[i][0] = "Sep";
    }
    else if (vector[i][0] == "1000000000")
    {
      vector[i][0] = "Oct";
    }
    else if (vector[i][0] == "1100000000")
    {
      vector[i][0] = "Nov";
    }
    else if (vector[i][0] == "1200000000")
    {
      vector[i][0] = "Dec";
    }
    else
    {
      cout << "Error en conversión" << endl;//detecta si ubo un error en la conversion
    }
  }
  return vector;
}

vector<vector<string>> convertirHoras(vector<vector<string>> lista)//esta funcion convierte las horas y los dias en ints para sumarlas a la fecha
{
  vector<string> vectorTemp;
  int suma;
  string resultado;
  for (int i = 0; i < lista.size(); i++)
  {
    vectorTemp = dividir(lista[i][2], ':');
    suma = ((stoi(vectorTemp[0])) * 10000) + ((stoi(vectorTemp[1])) * 100) + stoi(vectorTemp[2]);//se hace la suma con el mes anteriormente convertido,
    if ((stoi(vectorTemp[0]) < 10) && (stoi(vectorTemp[0]) != 0))//así como la hora y el dia para crear un id unico para cada fecha
    {
      resultado = "0" + to_string(suma);//esta y la siguiente condicional se usan para dar formato y no haya error al buscar una fecha especifica
    }
    else if (stoi(vectorTemp[0]) == 0)
    {
      resultado = "00" + to_string(suma);
    }
    else
    {
      resultado = to_string(suma);
    }
    lista[i][2] = resultado;// este es nuestro id para cada entrada
  }
  return lista;
}

vector<vector<string>> desconvertirHoras(vector<vector<string>> lista)//aqui se le da formato a la hora para facilitar su lectura
{
  for (int i = 0; i < lista.size(); i++)
  {
    lista[i][2].insert(2, ":");
    lista[i][2].insert(5, ":");
  }
  return lista;
}






vector<vector<string>> ordenBurbuja(vector<vector<string>> a)//utiizamos el metodo de ordenamiento burbuja para ordenar la bitacora
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if ((stoi(a[j][0]) + stoi(a[j][1]) * 1000000 + stoi(a[j][2])) > (stoi(a[j + 1][0]) + stoi(a[j + 1][1]) * 1000000 + stoi(a[j + 1][2])))//se usa el id que creamos para buscar el valor
      {
        vector<string> tmp_value = a[j];
        a[j] = a[j + 1];
        a[j + 1] = tmp_value;
      }
    }
  }
  return a;
}


void merge(vector<string> &a, int l, int m, int r)
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

int busqBinaria(vector<vector<string>> a, int k)//esta funcion encuentra una fecha en especifico
{ //
  int n = a.size();
  int l = 0;
  int r = n - 1;
  while (l <= r)
  {
    int m = floor((l + r) / 2);
    if (k == (stoi(a[m][0]) + stoi(a[m][1])))
    {
      return m;
    }
    else if (k < (stoi(a[m][0]) + stoi(a[m][1])))
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

void printVector(vector<string> a)//imprmimos cada linea
{
  int n = a.size();
  for (int i = 0; i < n; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
}

int main()
{

  vector<string> bitacora;//declaramos cada variable que vamos a necesitar
  vector<vector<string>> vectorConvertido;
  vector<vector<string>> vectorSeparado;
  vector<vector<string>> vectorOrdenado;
  int mes;
  int dia;
  int fecha1;
  int fecha2;
  int indice1 = -1;
  int indice2 = -1;
  leerArchivo("bitacora.txt", bitacora);
  cout << bitacora[2] << endl;
  vectorSeparado = separar(bitacora);
  printVector(vectorSeparado[2]);//casos de prueba
  vectorConvertido = convertirNumeros(vectorSeparado);
  cout << vectorConvertido[0][1] << endl;
  printVector(vectorConvertido[2]);
  vectorConvertido = convertirHoras(vectorConvertido);
  printVector(vectorConvertido[2]);
  vectorOrdenado = ordenBurbuja(vectorConvertido);
  printVector(vectorOrdenado[2]);
  //printVector(vectorOrdenado);
  cout << "Ingresa el mes de inicio (numero de mes): ";//se ingresa el primer valor a buscar
  cin >> mes;
  cout << endl
       << "Ingresa el día de inicio: ";
  cin >> dia;
  fecha1 = (mes * 100000000) + dia;
  cout << endl
       << "Ingresa el mes de fin (numero de mes): ";//se ingresa el ultimo valor a imprimir
  cin >> mes;
  cout << endl
       << "Ingresa el día de fin: ";
  cin >> dia;
  fecha2 = (mes * 100000000) + dia;//se transforma la entrada del usuario en un id
  indice1 = busqBinaria(vectorOrdenado, fecha1);//se guardan ambas fechas para buscarlas despues
  indice2 = busqBinaria(vectorOrdenado, fecha2);
  while ((indice1 == -1) || (indice2 == -1))
  {
    cout << "Fechas no validas, reingrese fechas" << endl;//en caso de no encontrar la fecha
    cout << "Ingresa el mes de inicio (numero de mes): ";
    cin >> mes;
    cout << endl
         << "Ingresa el día de inicio: ";
    cin >> dia;
    fecha1 = (mes * 100000000) + dia;
    cout << endl
         << "Ingresa el mes de fin (numero de mes): ";
    cin >> mes;
    cout << endl
         << "Ingresa el día de fin: ";
    cin >> dia;
    cout << endl;
    fecha2 = (mes * 100000000) + dia;
    indice1 = busqBinaria(vectorOrdenado, fecha1);
    indice2 = busqBinaria(vectorOrdenado, fecha2);
  }

  vectorOrdenado = convertirMeses(vectorOrdenado);//se regresan los valores a su formato original para facilitar lectura
  vectorOrdenado = desconvertirHoras(vectorOrdenado);

  for (int i = indice1; i <= indice2; i++)
  {
    printVector(vectorOrdenado[i]);
  }

  // Creación del archivo
  ofstream bitacoraOrdenada;

  // Apertura y comprobación

  if (std::ofstream bitacoraOrdenada{"BitacoraResultado.txt"})//se guarda el resultado en un archivo de texto
  {
    for (int i = indice1; i <= indice2; i++)
    {
      for (int j = 0; j < vectorOrdenado[i].size(); j++)
      {
        bitacoraOrdenada << vectorOrdenado[i][j] << " ";
      }
      bitacoraOrdenada << endl;
    }
  }
  else
  {
    cout << "Error al intentar abrir el archivo BitacoraResultado" << endl;
  }
  bitacoraOrdenada.close();
}
