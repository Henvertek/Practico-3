// Ejercicio 15.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	float urbanKM, ruralKM;
	const int dayCost = 120000, postCost = 20115, ruralPostDist = 100, urbanPostDist = 50, postsPerDay = 200;
	float totalCost, totalDays;
	int totalPosts;
	cout << "Ingrese la cantidad de kilómetros urbanos a iluminar\n>>> ";
	cin >> urbanKM;
	cout << "Ingrese la cantidad de kilómetros rurales a iluminar\n>>> ";
	cin >> ruralKM;

	totalPosts = int(urbanKM * 1000 / urbanPostDist) + int(ruralKM * 1000 / ruralPostDist);
	totalDays = (float)totalPosts / (float)postsPerDay;
	totalCost = ceil(totalDays) * dayCost + totalPosts * postCost;

	cout << "Se colocaran " << totalPosts << " postes en total\n";
	cout << "La tarea demorara " << totalDays << " dias\n";
	cout << "La tarea costara $" << totalCost << "\n";

	system("pause");
  return 0;
}

