// Ejercicio 10.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool invalid(int day, int month, int year) {
	if (month > 12 || month < 1 || day < 1 || day > 31) return true;//invalid month or invalid day.
	else {
		if (month == 2) {//If it's the second month
			if (day > 29) return true;
			else if (day == 29)
				if (year % 4 != 0) return true;
		}
		else if (((month - 1) % 7) % 2 == 1 && day > 30) return true;
	}
	return false;
}

void getDate(int *day, int *month, int *year, string desc) {
	do {
		cout << "Ingrese la fecha ";
		cout << desc;
		cout << " en el siguiente formato: DD/MM/AAAA:\n>>> ";
		scanf_s("%d/%d/%d", &*day, &*month, &*year);
		if (invalid(*day, *month, *year)) cout << "Fecha inexistente.\n\n";
	} while (invalid(*day, *month, *year));
}

int getAge(int d, int m, int y, int DD, int  MM, int YY) {
	int substract = 0;
	if (m == MM) {
		if (d > DD) {
			substract = 1;
		}
	}
	else if (m > MM) substract = 1;

	return YY - y - substract;
}

int main()
{
	int birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear;
	getDate(&birthDay, &birthMonth, &birthYear, "de nacimiento");
	getDate(&currentDay, &currentMonth, &currentYear, "actual");
	cout << "Usted tiene ";
	cout << getAge(birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear) << " años de edad." << endl;
	system("pause");
  return 0;
}