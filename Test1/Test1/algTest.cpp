#include "stdafx.h"
//#include <string>
#include <iostream>

#include <cmath>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
/*
*  Complete below function.And make sure to include all imports.
*
*/

/*
void rearrange(string words[], int wordCount) {
	//sort(words[0], words[wordCount]);
	//int *indexes = new int[wordCount];

	//for (int i = 0; i < wordCount; ++i)
		//indexes[i] = i;

	//Create a copy from the original array
	string *aux = new string[wordCount];
	aux = words;

	for (int i = 0; i < wordCount; ++i) {
		//Order each word alphabetically
		sort(aux[i].begin(), aux[i].end());
		//Delete the repeated letters from each word
		aux[i].erase(unique(aux[i].begin(), aux[i].end()), aux[i].end());
	}

	//sort(aux, aux + wordCount);

	cout << endl;

	for (int i = 0; i<wordCount; ++i)
		cout << aux[i] << endl;



	for (i = 0; i < n; i++)
	{
		array[i][0] = rand() % 6;
		array[i][1] = i;
	}

	//Order the array but keeping track of the indexes
}
*/
/*
void rearrange(string words[], int wordCount) {
	//Process the array
	for (int i = 0; i < wordCount; ++i) {
		//Order each word alphabetically
		sort(words[i].begin(), words[i].end());
		//Delete the repeated letters from each word
		words[i].erase(unique(words[i].begin(), words[i].end()), words[i].end());
	}

	//sort(aux, aux + wordCount);

	cout << endl;

	for (int i = 0; i<wordCount; ++i)
		cout << words[i] << endl;

	//Create a matrix for words and indexes
	string *aux = new string[wordCount][2];

	for (int i = 0; i < n; i++)
	{
		aux[i][0] = words[i];
		aux[i][1] = i;
	}

	//Order the array but keeping track of the indexes
}
*/

void rearrange(string words[], int wordCount) {
	/*
	In my solution, I create ordered patterns for the words so I can
	check the indexes of them against the original array of words
	For instance, for the sample input(1):
	6
	student
	students
	dog
	studentssess
	god
	cat

	I eliminate repeated letters and order them to create the patterns. We get:
	denstu
	denstu
	dgo
	denstu
	dgo
	act

	I order the pattern and get:
	denstu
	denstu
	denstu
	dgo
	dgo
	act

	With the pattern ordered, I can get the indexes and order the original array.
	Blank spaces are added comparing if the words in the pattern
	*/

	//Create a copy from the original array into a vector from processing
	vector<string> aux(words, words + wordCount);

	for (size_t i = 0; i < wordCount; ++i) {
		//Order each word alphabetically
		sort(aux[i].begin(), aux[i].end());
		//Delete the repeated letters from each word
		aux[i].erase(unique(aux[i].begin(), aux[i].end()), aux[i].end());
	}

	//Create a copy from the second array to order
	vector<string> aux1(aux);

	//Order the second array
	sort(aux1.begin(), aux1.end());
	
	//Insert a new line for aesthetics
	cout << endl;

	//Search the words of the ordered array into the previous array to get 
	//the indexes and show the words
	for (size_t i = 0; i < wordCount; ++i) {
		for (size_t j = 0; j < wordCount; ++j) {
			if (aux[j] != "" && aux1[i] == aux[j]) {
				//Insert new line
				if (i > 0 && aux1[i] != aux1[i - 1])
					cout << endl;

				//To avoid checking the same words n times, blank the string
				aux[j] = "";
				//Show the word
				cout << words[j] << ", ";
				//Go to the next word
				break;
			}
		}
	}
}

// DO NOT MODIFY anything outside the above function
void algTest() {
	/* Read input from STDIN. Print output to STDOUT */
	int wordCount;
	cin >> wordCount;
	string endLine;
	getline(cin, endLine);
	string *words = new string[wordCount]; //Do not include in code
	for (int i = 0; i<wordCount; i++) {
		getline(cin, words[i]);
	}
	rearrange(words, wordCount);
}