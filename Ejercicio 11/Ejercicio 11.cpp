// Ejercicio 11.cpp: define el punto de entrada de la aplicación de consola.
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
				if (year % 4 != 0 || (year%100 == 0 && year % 400 != 0)) return true;
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

int getDays(int d, int m, int y, int DD, int  MM, int YY) {
	int totalDays = 0;

	for (int i = y + 1; i < YY; i++) {//Los años que están en el medio si los hay
		totalDays += 365 + (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0));
	}

	if (YY > y) {//No nació este año
		for (int i = m; i <= 12; i++) {//PRIMER AÑO PARCIAL (y)
			totalDays += 28 + 2 * (i != 2) + (((i - 1) % 7) % 2 == 0);
		}

		//ULTIMO AÑO PARCIAL (2018)
		for (int i = 1; i < MM; i++) {
			totalDays += 28 + 2 * (i != 2) + (((i - 1) % 7) % 2 == 0);
		}
	}
	else if (YY == y) {//NACIÓ ESTE AÑO
		for (int i = m; i < MM; i++) {//AÑO ACTUAL PARCIAL
			totalDays += 28 + 2 * (i != 2) + (((i - 1) % 7) % 2 == 0);
		}
	}
	totalDays -= d;
	totalDays += DD;
	if (totalDays < 0) totalDays = 0;
	return totalDays;
	/*
	for (int i = y + 1; i <= YY; i++) {
		totalDays += 365;
		if (i % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) leapDays++;
	}
	totalDays += leapDays;
	if (MM < m) {//falta para llegar al mes del cumpleaños, sobran días
		for (int i = MM + 1; i < m; i++) {
			totalDays -= 28 + 2 * (i != 2) + ((i % 7) % 2 == 0);
		}
		totalDays -= d;
		//totalDays += MM > 2;
		totalDays -= (28 + 2 * (MM != 2) + ((MM % 7) % 2 == 0)) - DD;
	}
	else if (MM > m) {//ya pasó el mes del cumpleaños, faltan días
		//totalDays -= (MM < 2);
		for (int i = m + 1; i <= MM; i++) {
			totalDays += 28 + 2 * (i != 2) + ((i % 7) % 2 == 0);
		}
		totalDays += DD;
		totalDays -= d;
	}
	else {//cumple o cumplió este mes
		if (DD < d) {//no cumplió aún, sobran días
			totalDays -= d - DD;
		}
		else {//ya cumplió, faltan días
			totalDays += DD - d;
		}
	}
	cout << leapDays << endl;
	*/

	/*
	if (totalDays / 365 > getAge(d, m, y, DD, MM, YY)) {//Excede mi edad, hay que ver cuantos dias sobran
		totalDays = getAge(d, m, y, DD, MM, YY) * 365 + leapDays;
		for (int i = MM; i < m; i++) {
			extraDays += 28 + 2 * (i != 2) + ((i % 7) % 2 == 0);
		}
		extraDays -= d;
	}
	else {//No llega a ser mi edad 
		for (int i = m; i < MM; i++) {
			daysLeft += 28 + 2 * (i != 2) + ((i % 7) % 2 == 0);
		}
		daysLeft += d;
	}
	*/

	/*
	for (int i = MM; i < m; i++) {
		daysLeft += 28 + 2 * (i != 2) + ((i % 7) % 2 == 0);
	}
	daysLeft -= 28 + (2 * (MM != 2) + ((MM % 7) % 2 == 0)) - DD;
	//totalDays += 365 + (YY % 4 == 0 && (YY % 100 != 0 || YY % 400 == 0)) - daysLeft;
	totalDays -= daysLeft;
	totalDays += d;
	*/
}

void printMenu() {
	cout << " _______________________________________\n";
	cout << "|========= CALCULADORA DE EDAD =========|\n";
	cout << "|                                       |\n";
	cout << "|        1. Obtener edad                |\n";
	cout << "|        2. Obtener dias vividos        |\n";
	cout << "|_______________________________________|\n>>> ";
}

int main()
{
	char answer;
	int birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear;
	getDate(&currentDay, &currentMonth, &currentYear, "actual");
	do {
		getDate(&birthDay, &birthMonth, &birthYear, "de nacimiento");

		int choice;
		do {
			printMenu();
			cin >> choice;
			if (choice != 1 && choice != 2) cout << "\nSeleccion invalida.\n\n";
		} while (choice != 1 && choice != 2);

		if (choice == 1) {
			cout << "\nUsted tiene ";
			cout << getAge(birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear) << " años de edad.\n\n";
		}
		else {
			cout << "\nUsted ha vivido ";
			cout << getDays(birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear) << " dias!\n\n";
		}
		cout << "Desea introducir otra fecha de nacimiento?(Y/N):\n>>> ";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	system("pause");
	return 0;
}