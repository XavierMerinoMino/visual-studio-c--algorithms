#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void countLines() {
	ifstream inFile;
	string x;
	int count = 0;

	inFile.open("‪C:\\Xavier\\datafile.txt");
	//inFile.open("‪datafile.txt");

	//if (!inFile.is_open()) {
	//	cout << "No se puede abrir el archivo datafile.txt\n";
	//}
	//else {
		while (getline(inFile, x)) {
			++count;
		}
		cout << "El total de lineas es: " << count << endl;
	//}

	inFile.close();
}