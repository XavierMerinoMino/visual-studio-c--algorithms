#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <ctype.h>
#include "factorial.h"

int multiply(int x, int y)
{
	return x*y;
}


double divide(int x, int y)
{
	return x / y;
}

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}


using namespace std;

void calculator()
{
	char op = 'c';
	int x, y;
	while (op != 'e')
	{
		cout << "What operation would you like to perform: add(+), subtract(-), divide(/), multiply(*), [e]xit ? ";
		cin >> op;
		switch (op)
		{
		case '+':
			cin >> x;
			cin >> y;
			cout << x << " + " << y << " = " << add(x, y) << endl;
			break;
		case '-':
			cin >> x;
			cin >> y;
			cout << x << "-" << y << "=" << subtract(x, y) << endl;
			break;
		case '/':
			cin >> x;
			cin >> y;
			cout << x << "/" << y << "=" << divide(x, y) << endl;
			break;
		case '*':
			cin >> x;
			cin >> y;
			cout << x << "*" << y << "=" << multiply(x, y) << endl;
			break;
		case 'e':
			break;
		default:
			cout << "Sorry, try again" << endl;
		}
	}
}

//Convert from Celsius to Fahrenheit
//void convertTemp(int startTmp, int endTemp, int step) {
void convertTemp(int data[]) {
	double result;

	cout << "Celsius         Fahrenheit\n";
	cout << "-------         ----------\n";

	while (data[0] <= data[1]) {
		result = (data[0] * 1.8) + 32;
		cout << data[0] << "       " << result << endl;
		data[0] += data[2];
	}
}

void exeConvertion() {
	bool flagLoop = true;
	//int lower = 0, higher = 0, step = 0;
	int data[3];

	while (flagLoop)
	{
		cout << "Please give in a lower limit, limit >= 0: ";
		cin >> data[0];

		if (data[0] >= 0)
			flagLoop = false;
		else
		{
			cout << "Number must be >=0" << endl;
		}
	}

	flagLoop = true;
	while (flagLoop)
	{
		cout << "Please give in a higher limit, 10 > limit <= 50000: ";
		cin >> data[1];

		if (data[1] >= 10 && data[1] <= 50000)
			flagLoop = false;
		else
		{
			cout << "Number must be 10 > limit <= 50000" << endl;
		}
	}

	flagLoop = true;
	while (flagLoop)
	{
		cout << "Please give in a step, 0 < step <= 10: ";
		cin >> data[2];

		if (data[2] >= 0 && data[2] <= 10)
			flagLoop = false;
		else
		{
			cout << "Number must be 0 < step <= 10" << endl;
		}
	}

	convertTemp(data);
}

//Convert decimal to binary
void convertDecBin() {
	cout << "Please give a number in decimal format: ";
	int numDec;
	cin >> numDec;
	cout << numDec;

	int rest = 0;
	string numBin = "";
	while (numDec > 1) {
		rest = numDec % 2;
		numDec = numDec / 2;

		numBin += to_string(rest);
	}

	numBin += to_string(numDec);
	string aux = "";
	for (int i = numBin.size() - 1; i >= 0; --i) {
		aux += numBin[i];
	}

	cout << " = " << aux;
}

//Convert decimal to binary
int dectobin(int dec, int power_of_two)
{
	if (dec == 0)
	{
		cout << "0";
	}
	else if (dec / (int)pow(2, power_of_two))
	{
		int remainder = dectobin(dec, power_of_two + 1);
		if (remainder / (int)pow(2, power_of_two))
		{
			cout << "1";
			return remainder - (int)pow(2, power_of_two);
		}
		else
		{
			cout << "0";
			return remainder;
		}
	}
	else
	{
		return dec;
	}
}

//Calculate combination
int combination(int n, int m) {
	return factorialCal(n) / (factorialCal(m) * factorialCal(n - m));
}

//Given a row and column the function calculates the number in the position of the Pascal Triangle
void positionPascalTriangle() {
	int x, y;
	
	do {
		cout << "Ingrese numero de la fila: ";
		cin >> x;

		if (x < 0)
			cout << "Numero incorrecto, ingrese numero mayor o igual a cero" << endl;
	} while (x < 0);

	do {
		cout << "Ingrese numero de la columna: ";
		cin >> y;

		if (y < 0 || y > x) {
			cout << "Numero incorrecto. Numero debe ser: " << endl;
			cout << "1. Mayor o igual a cero" << endl;
			cout << "2. Menor o igual que el valor de la columna" << endl;
		}
	} while (y < 0 || y > x);

	cout << "El valor en la posicion (" << x << "," << y << ") en el Triangulo de Pascal es ";

	if (x == 0 || y == 0)
		cout << "1";
	else
		cout << combination(x, y);
}

/*
int factorial(int number) {
	int result = 1;
	
	for (; number > 1; --number) {
		result = result * number;
	}
}
*/