// Ejercicio A4.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int year, a, b, c, d, e, day = 0;
	bool April = true;
	do {
		cout << "Ingrese el año para saber en que fecha sera domingo de Pascua\n>>> ";
		cin >> year;
		if (year < 1900 || year > 2100) cout << "El año debe ser entre el 1900 y 2100.\n\n";
	} while (year < 1900 || year > 2100);
	a = year % 19;
	b = year % 4;
	c = year % 7;
	d = (19 * a + 24) % 30;
	e = (2 * b + 4 * c + 6 * d + 5) % 7;
	if (d + e < 10) {
		day = (d + e + 22);
		April = false;
	}
	else {
		day = (d + e - 9);
	}
	cout << "Pascua sera el dia ";
	if (April) {
		if (day == 26)day = 19;
		else if (day == 25)day = 18;
		cout << day << " de Abril\n\n";
	}
	else cout << day << " de Marzo\n\n";
	system("pause");
  return 0;
}