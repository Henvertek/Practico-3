// Ejercicio 12.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool invalid(int day, int month, int year) {
	if (month > 12 || month < 1 || day < 1 || day > 31 || year < 1800) return true;//invalid month or invalid day.
	else {
		if (month == 2) {//If it's the second month
			if (day > 29) return true;
			else if (day == 29)
				if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) return true;
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

int main()
{
	int day, month, year;
	char ansr;
	do {
		getDate(&day, &month, &year, "deseada");
		if (invalid(++day, month, year)) {
			day = 1;
			month++;
		}
		if (invalid(day, month, year)) {
			month = 1;
			year++;
		}
		cout << "La fecha siguiente es " << day << "/" << month << "/" << year << "\n\n";
		cout << "Reintentar?(Y/N)\n>>> ";
		cin >> ansr;
	} while (ansr == 'y' || ansr == 'Y');
	system("pause");
  return 0;
}