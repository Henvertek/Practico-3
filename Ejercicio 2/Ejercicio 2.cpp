// Ejercicio 2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int age;
	cout << "Ingrese una edad entre 18 y 40 años\n>>> ";
	cin >> age;
	if (age >= 18 && age <= 40) cout << "CORRECTO\n";
	else cout << "ERROR, Ud. ha ingresado una edad fuera del rango\n";
	system("pause");
  return 0;
}

