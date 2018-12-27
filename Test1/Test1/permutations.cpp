#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void heapAlgorithmRecursive(int size, string value);

//Algoritmo de Heap: Obtiene las permutaciones sin repetir de N objetos
void heapAlgorithmRecursive(int size, string value) {
	if (size == 1)
		cout << value << endl;
	else {
		for (int i = 0; i < size - 1; ++i) {
			heapAlgorithmRecursive(size - 1, value);

			if (size % 2 == 0)
				swap(value[i], value[size-1]);
			else
				swap(value[0], value[size - 1]);
		}

		heapAlgorithmRecursive(size - 1, value);
	}
}

void heapAlgorithm(int size, string value) {
	const int sizArr = size;
	int* numbers = new int[size];
	int i = 0;

	for (i = 0; i < size; ++i) {
		numbers[i] = 0;
	}

	cout << value << endl;
	i = 0;

	while (i < size) {
		if (numbers[i] < i)
		{
			if (i % 2 == 0)
				swap(value[0], value[i]);
			else
				swap(value[numbers[i]], value[i]);

			cout << value << endl;
			numbers[i] += 1;
			i = 0;
		}
		else {
			numbers[i] = 0;
			i += 1;
		}
	}
}
	//Algorithm Johnson-Trotter
	bool LEFT_TO_RIGHT = true;
	bool RIGHT_TO_LEFT = false;

	// Utility functions for finding the 
	// position of largest mobile integer in a[]. 
	int searchArr(int a[], int n, int mobile)
	{
		for (int i = 0; i < n; i++)
			if (a[i] == mobile)
				return i + 1;
	}

	// To carry out step 1 of the algorithm i.e. 
	// to find the largest mobile integer. 
	int getMobile(int a[], bool dir[], int n)
	{
		int mobile_prev = 0, mobile = 0;
		for (int i = 0; i < n; i++)
		{
			// direction 0 represents RIGHT TO LEFT. 
			if (dir[a[i] - 1] == RIGHT_TO_LEFT && i != 0)
			{
				if (a[i] > a[i - 1] && a[i] > mobile_prev)
				{
					mobile = a[i];
					mobile_prev = mobile;
				}
			}

			// direction 1 represents LEFT TO RIGHT. 
			if (dir[a[i] - 1] == LEFT_TO_RIGHT && i != n - 1)
			{
				if (a[i] > a[i + 1] && a[i] > mobile_prev)
				{
					mobile = a[i];
					mobile_prev = mobile;
				}
			}
		}

		if (mobile == 0 && mobile_prev == 0)
			return 0;
		else
			return mobile;
	}

	// Prints a single permutation 
	void printOnePerm(int a[], bool dir[], int n)
	{
		int mobile = getMobile(a, dir, n);
		int pos = searchArr(a, n, mobile);

		// swapping the elements according to the 
		// direction i.e. dir[]. 
		if (dir[a[pos - 1] - 1] == RIGHT_TO_LEFT)
			swap(a[pos - 1], a[pos - 2]);

		else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT)
			swap(a[pos], a[pos - 1]);

		// changing the directions for elements 
		// greater than largest mobile integer. 
		for (int i = 0; i < n; i++)
		{
			if (a[i] > mobile)
			{
				if (dir[a[i] - 1] == LEFT_TO_RIGHT)
					dir[a[i] - 1] = RIGHT_TO_LEFT;
				else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
					dir[a[i] - 1] = LEFT_TO_RIGHT;
			}
		}

		for (int i = 0; i < n; i++)
			cout << a[i];
		cout << " " << endl;
	}

	// To end the algorithm for efficiency it ends 
	// at the factorial of n because number of 
	// permutations possible is just n!. 
	int fact(int n)
	{
		int res = 1;
		for (int i = 1; i <= n; i++)
			res = res * i;
		return res;
	}

	// This function mainly calls printOnePerm() 
	// one by one to print all permutations. 
	void printPermutation(int n)
	{
		// To store current permutation 
		int* a = new int[n];
		//int a[n];

		// To store current directions 
		bool* dir = new bool[n];
		//bool dir[n];

		// storing the elements from 1 to n and 
		// printing first permutation. 
		for (int i = 0; i < n; i++)
		{
			a[i] = i + 1;
			cout << a[i];
		}
		cout << endl;

		// initially all directions are set 
		// to RIGHT TO LEFT i.e. 0. 
		for (int i = 0; i < n; i++)
			dir[i] = RIGHT_TO_LEFT;

		// for generating permutations in the order. 
		for (int i = 1; i < fact(n); i++)
			printOnePerm(a, dir, n);
	}