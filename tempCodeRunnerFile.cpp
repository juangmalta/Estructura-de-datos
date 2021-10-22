
       << "Ingresa el día de inicio: ";
  cin >> dia;
  fecha1 = ((mes)*100000000) + (dia);
  cout << endl
       << "Ingresa el mes de fin (numero de mes): "; //Se ingresa el ultimo valor a imprimir.
  cin >> mes;
  cout << endl
       << "Ingresa el día de fin: ";
  cin >> dia;
  if (dia != 31)
  {
    fecha2 = (mes * 100000000) + (dia + 1); //Se transforma la entrada del usuario en un id.
  }
  else
  {
    fecha2 = ((mes + 1) * 100000000) + 1;
  }
  //Se guardan ambas fechas para buscarlas después.
  indice1 = busqSecuencialOrd(vectorOrdenado, fecha1);
  indice2 = busqSecuencialOrd(vectorOrdenado, fecha2);
  while ((indice1 == -1) || (indice2 == -1))
  {
    cout << endl
         << "Fechas no validas, reingrese fechas" << endl; //En caso de no encontrar la fecha.
    cout << "Ingresa el mes de inicio (numero de mes): ";
    cin >> mes;
    cout << endl
         << "Ingresa el día de inicio: ";
    cin >> dia;
    fecha1 = ((mes)*100000000) + (dia);
    cout << endl
         << "Ingresa el mes de fin (numero de mes): ";
    cin >> mes;
    cout << endl
         << "Ingresa el día de fin: ";
    cin >> dia;
    if (dia != 31)
    {
      fecha2 = (mes * 100000000) + (dia + 1);
    }
    else
    {
      fecha2 = ((mes + 1) * 100000000) + 1;
    }
    cout << endl;
    fecha2 = (mes * 100000000) + (dia + 1);
    indice1 = busqSecuencialOrd(vectorOrdenado, fecha1);
    indice2 = busqSecuencialOrd(vectorOrdenado, fecha2);
  }
  //Se regresan los valores a su formato original para facilitar lectura
  vectorOrdenado = convertirMeses(vectorOrdenado);
  vectorOrdenado = desconvertirHoras(vectorOrdenado);

  for (int i = indice1; i <= indice2 - 1; i++)
  {
    printVector(vectorOrdenado[i]);
  }

  // Creación del archivo
  ofstream bitacoraOrdenada;

  // Apertura y comprobación
  if (std::ofstream bitacoraOrdenada{"BitacoraResultado.txt"}) //Se guarda el resultado en un archivo de texto
  {
    for (int i = indice1; i <= indice2 - 1; i++)
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
    cout << "Error al intentar abrir el archivo BitacoraResultado" << endl; //En caso de error.
  }
  bitacoraOrdenada.close();
}
