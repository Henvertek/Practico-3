// Ejercicio A1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool invalid(int hour, int minute, int second) {
	if (minute > 59 || minute < 0 || second < 0 || second > 59 || hour < 0 || hour > 23) return true;//invalid minute or invalid second.
	return false;
}

void getTime(int *hour, int *minute, int *second) {
	do {
		cout << "Ingrese la hora deseada";
		cout << " en el siguiente formato: hh:mm:ss\n>>> ";
		scanf_s("%d:%d:%d", &*hour, &*minute, &*second);
		if (invalid(*hour, *minute, *second)) cout << "Hora invalida.\n\n";
	} while (invalid(*hour, *minute, *second));
}

int main()
{
	int second, minute, hour;
	char ansr;
	do {
		getTime(&hour, &minute, &second);
		if (invalid(hour, minute, ++second)) {
			second = 0;
			minute++;
		}
		if (invalid(hour, minute, second)) {
			minute = 0;
			hour++;
		}
		if (invalid(hour, minute, second)) {
			hour = 0;
		}
		cout << "La hora al segundo siguiente es ";
		if (hour < 10)cout << "0"; cout << hour << ":";
		if (minute < 10)cout << "0"; cout << minute << ":";
		if (second < 10)cout << "0"; cout << second << "\n\n";
		cout << "Reintentar?(Y/N)\n>>> ";
		cin >> ansr;
	} while (ansr == 'y' || ansr == 'Y');
	system("pause");
	return 0;
}