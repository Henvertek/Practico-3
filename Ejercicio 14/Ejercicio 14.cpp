// Ejercicio 14.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	float averages[6] = {};
	int i = 0;
	cout << "Complete la tabla:\n\n";
	cout << " ___________________________\n";
	cout << "|Mes/Año|Promedio de lluvias|\n";
	cout << "|_______|___________________|\n";
	cout << "| 07/17 |Promedio: ";cin >> averages[i++];
	cout << "| 08/17 |Promedio: ";cin >> averages[i++];
	cout << "| 09/17 |Promedio: ";cin >> averages[i++];
	cout << "| 10/17 |Promedio: ";cin >> averages[i++];
	cout << "| 11/17 |Promedio: ";cin >> averages[i++];
	cout << "| 12/17 |Promedio: ";cin >> averages[i++];
	cout << "|___________________________|\n";

	float avg = 0;
	float min[2] = {0, 9999};
	float max[2] = { 0, -9999};
	for (i = 0; i < 6; i++) {
		avg += averages[i];
		if (averages[i] < min[1]) {
			min[0] = i + 7;
			min[1] = averages[i];
		}
		if (averages[i] > max[1]) {
			max[0] = i + 7;
			max[1] = averages[i];
		}
	}
	avg /= 6;

	cout << "El promedio llovido es de " << avg << "mm.\n";
	cout << "El mes con mas lluvia fue el " << (int)max[0] << "/17 con " << max[1] << "mm llovidos.\n";
	cout << "El mes con menos lluvia fue el " << (int)min[0] << "/17 con " << min[1] << "mm llovidos.\n\n";
	system("pause");
  return 0;
}

