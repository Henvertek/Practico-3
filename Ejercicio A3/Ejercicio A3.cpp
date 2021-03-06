// Ejercicio A3.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	char units[10][7] = {"cero", "uno", "dos","tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
	char tens[8][10] = { "veinti", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
	while (true) {
		do {
			cout << "\nIngrese un numero entre 0 y 99\n>>> ";
			cin >> num;
		} while (num > 99 || num < 0);
		cout << "    ";
		if (num > 9 && num <= 20) {
			switch (num) {
			case 10:
				cout << "diez";
				break;
			case 11:
				cout << "once";
				break;
			case 12:
				cout << "doce";
				break;
			case 13:
				cout << "trece";
				break;
			case 14:
				cout << "catorce";
				break;
			case 15:
				cout << "quince";
				break;
			case 16:
				cout << "dieciseis";
				break;
			case 17:
				cout << "diecisiete";
				break;
			case 18:
				cout << "dieciocho";
				break;
			case 19:
				cout << "diecinueve";
				break;
			case 20:
				cout << "veinte";
				break;
			}
		}
		else {
			if (num / 10 > 1) {
				cout << tens[num / 10 - 2];
				if (num / 10 > 2 && num % 10 > 0) cout << " y ";
			}
			if (num % 10 > 0) {
				cout << units[num % 10];
			}
			else if (num < 10) {
				cout << units[num];
			}
		}
	}
  return 0;
}