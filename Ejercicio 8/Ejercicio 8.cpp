// Ejercicio 8.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

#define SWITCH 1
#define IF 0

using namespace std;

int gradeInput() {
	float g;
	do {
		cout << "Ingrese la calificacion obtenida\n>>> ";
		cin >> g;
		if (g < 0 || g > 10)
			cout << "El numero ingresado no es una calificacion valida.\n\n";
	} while (g < 0 || g > 10);
	return g;
}

int main()
{
	//Modificar el valor de method para que el programa ejecute la versión utilizando switch o if
	const bool method = IF;
	int grade = gradeInput();
	if (method) {
		switch (grade) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			cout << "Insuficiente";
			break;
		case 6:
		case 7:
			cout << "Bueno";
			break;
		case 8:
		case 9:
			cout << "Muy bueno";
			break;
		default:
			cout << "Excelente";
		}
	}
	else {
		if (grade < 6) cout << "Insuficiente";
		else if (grade < 7) cout << "Bueno";
		else if (grade < 10) cout << "Muy bueno";
		else cout << "Excelente";
	}
	cout << "\n\n";
	system("pause");
  return 0;
}