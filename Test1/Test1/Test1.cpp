// Test1.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include "calculator.h"
#include <string>
#include "TxtReader.h"
#include "permutations.h"
#include "IntToEng.h"
#include "factorial.h"
#include "stringOperations.h"
#include "linkedList.h"
#include <stdio.h>
#include <future> 
#include "algTest.h"

using namespace std;

int add1(int x, int y); // forward declaration of add() (using a function prototype)
/*
//Quine is a program that prints itself. It means, print its own source code
//The two key tricks here are using a string with an embedded %s specifier to allow the string to contain itself when printed, and to use the %c format specifier to allow printing out special characters like newlines, which could not otherwise be embedded in the output string. 
#include <stdio.h>
char*s = "#include <stdio.h>%cchar*s=%c%s%c;%cint main(void){printf(s,10,34,s,34,10,10);}%c";
int main(void) { printf(s, 10, 34, s, 34, 10, 10); }
*/
/*
unsigned int fact(int x) {
	return(x*fact(x - 1));
}
*/

#define VALUE 1+2

namespace {
	int a = 4;
}

int main()
{
	//algTest();

	/*
	Nodo *lista = NULL;
	int dato = 0;

	for (int i = 0; i < 3; ++i) {
		cout << "Digita numero " << i + 1 << ": ";
		cin >> dato;
		insertList(lista, dato);
	}

	showList(lista);
	printReverse(lista);
	cout << endl;
	showList(lista);
	*/
	//reverseList(lista);
	//showList(lista);
	/*
	cout << endl;
	cout << "Ingrese numero a buscar: ";
	cin >> dato;
	searchList(lista, dato);

	cout << endl;
	cout << "Ingrese numero a eliminar: ";
	cin >> dato;
	deleteElementList(lista, dato);

	deleteAllList(lista);
	showList(lista);
	*/
	//Calculates an specific position in Pascal Triangle
	//positionPascalTriangle();

	//Convert from decimal to binary
	//convertDecBin();
	//dectobin(28, 0);

	//*********************************************************************************

	//StringOperations
	/*
	cout << "Ingrese texto: ";
	string texto;
	cin >> texto;

	cout << "Ingrese texto a buscar: ";
	string textoB;
	cin >> textoB;

	stringSearch2(texto, textoB);
	*/
	/*
	cout << "Ingrese texto: ";
	char* texto = new char();
	cin >> texto;

	cout << "Ingrese texto a buscar: ";
	char* textoB = new char();
	cin >> textoB;

	if (match_within(texto, textoB))
	{
	cout << "String " << textoB;
	cout << " is contained within " << texto << ".";
	}
	else
	{
	cout << "String " << textoB << " is not contained within ";
	cout << texto << ".";
	}
	*/
	//*********************************************************************************

	//Factorial
	//cout << "El factorial es: " << factorialCh(factorialCal(3)) << endl;
	//zerosRightFac(10);
	//factorialCh2();

	//*********************************************************************************

	//Convertir numero en texto
	//string text = "1234";
	//int size = text.length();
	//heapAlgorithmRecursive(size, text);
	//heapAlgorithm(size, text);

	//*********************************************************************************

	//Permutaciones
	//Print the permutations of succesive numbres from 1 to n
	//Example: 12
	//Permutations: 123 , 132 , 213 , 231 , 312, 321
	//int n = 4;
	//printPermutation(n);
	//Convert from number to text
	//convert(125);

	//*********************************************************************************

	//countLines();
	//exeConvertion();

	//*********************************************************************************

	//Calculadora
	//calculator();
	//cout << "The sum of 3 and 4 is: " << add1(3, 4) << endl; // this works because we forward declared add() above
	cout << endl;
	system("pause");
	//getchar();
	return 0;
}

int add1(int x, int y) // even though the body of add() isn't defined until here
{
	return x + y;
}