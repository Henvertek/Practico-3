// Ejercicio A2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#define YEAR 2018

using namespace std;

bool invalid(int day, int month) {
	if (month > 12 || month < 1 || day < 1 || day > 31) return true;//invalid month or invalid day.
	else {
		if (month == 2) {//If it's the second month
			if (day > 29) return true;
			else if (day == 29)
				if (YEAR % 4 != 0) return true;
		}
		else if (((month - 1) % 7) % 2 == 1 && day > 30) return true;
	}
	return false;
}

void getDate(int *day, int *month, string desc) {
	do {
		cout << "Ingrese la fecha ";
		cout << desc;
		cout <<	" en el siguiente formato: DD/MM:\n>>> ";
		scanf_s("%d/%d", &*day, &*month);
		if (invalid(*day, *month)) cout << "Fecha inexistente.\n\n";
	} while (invalid(*day, *month));
}

int getDays(int d, int m, int DD, int  MM) {
	int totalDays = 0;

	for (int i = m; i < MM; i++) {//AÑO ACTUAL PARCIAL
		totalDays += 28 + 2 * (i != 2) + (((i - 1) % 7) % 2 == 0);
	}
	totalDays -= d;
	totalDays += DD;
	if (totalDays < 0) totalDays = 0;
	return totalDays;
}

int main()
{
	char answer;
	int firstDay, firstMonth, secondDay, secondMonth;
	do {
		do {
			getDate(&firstDay, &firstMonth, "deseada");
			getDate(&secondDay, &secondMonth, "posterior");
			if (firstMonth > secondMonth || (firstMonth == secondMonth && firstDay > secondDay)) {
				cout << "La segunda fecha no es posterior a la primera\n\n";
			}
		} while (firstMonth > secondMonth || (firstMonth == secondMonth && firstDay > secondDay));
	  cout << "\nFaltan ";
	  cout << getDays(firstDay, firstMonth, secondDay, secondMonth) << " dias\n\n";
		cout << "Desea introducir otra fecha?(Y/N):\n>>> ";
		cin >> answer;
		cout << endl;
	} while (answer == 'y' || answer == 'Y');
	system("pause");
	return 0;
}