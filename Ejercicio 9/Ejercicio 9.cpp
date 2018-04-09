// Ejercicio 9.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	float number;
	do {
		cout << "Ingrese un numero entre 0 y 9999:\n>>> ";
		cin >> number;
		if (number < 0 || number > 9999) cout << "Error. Numero fuera de rango.\n\n";
	} while (number < 0 || number > 9999);
	unsigned short int figures = 1;
	while (number >= 10) {
		number /= 10;
		figures++;
	}
	cout << "El numero ingresado tiene " << figures << " cifras enteras.\n\n";
	system("pause");
  return 0;
}

