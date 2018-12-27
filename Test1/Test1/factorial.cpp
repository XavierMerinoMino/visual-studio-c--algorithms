#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//Calculate Factorial
long factorialCal(int n) {
	int result = 1;

	if (n == 0)
		return 1;

	for (int i = 2; i <= n; ++i) {
		result = result * i;
	}

	return result;
}

//Count zeros at the rigth of the factorial number
int factorialCh(long n) {
	int cont = 0;
	
	while (n >= 0) {
		if (n == 0) {
			++cont;
			break;
		}

		if (n % 10 == 0) {
			n = n / 10;
			++cont;
		}
		else
			break;
	}

	return cont;
}

void zerosRightFac(int n) {
	int fac = factorialCal(n);
	cout << "Existen " << factorialCh(fac) << " ceros a la derecha dle factorial" << endl;
}

//Count zeros at the rigth of the factorial number
void factorialCh2() {
	int factorialnumber = 0;
	cout << "Please enter a number: ";
	cin >> factorialnumber;
	int zero_count = 0;
	for (int five_factor = 5;
		five_factor <= factorialnumber;
		five_factor *= 5)
	{
		zero_count += factorialnumber / five_factor;
	}
	cout << "Trailing zeros of " << factorialnumber;
	cout << "! is " << zero_count << endl;
}