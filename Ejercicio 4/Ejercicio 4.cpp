// Ejercicio 4.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int sides[3];
	unsigned short int equals = 0;
	for (int i = 0; i < 3; i++) {
		cout << "Ingrese la longitud de ";
		if(i == 0)cout << "un";
		else cout << "otro";
		cout << " lado\n>>> ";
		cin >> sides[i];
		for (int j = 0; j < i; j++) {
			if (sides[i] == sides[j])equals++;
		}
	}
	cout << "El triangulo formado es ";
	if (equals == 0)cout << "escaleno.";
	else if (equals == 1) cout << "isosceles.";
	else cout << "equilatero.";
	cout << endl;
	system("pause");
	return 0;
}

