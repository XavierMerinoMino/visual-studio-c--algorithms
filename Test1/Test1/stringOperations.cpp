#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//Search a string in another string
void stringSearch(string original, string sub) {
	int i = 0;
	bool exists = false, complete = false;
	//string sub = "";

	for (int j = 0; j < original.length(); ++j) {
		if (i < sub.length() && original[j] == sub[i]) {
			if (i == sub.length() - 1) {
				complete = true;
				exists = true;
			}
			++i;
		}
		else {
			i = 0;
			if (!complete)
				exists = false;
		}
	}

	if (exists)
		cout << sub << " is substring of " << original;
	else
		cout << "No substring detected";

	cout << endl;
}

void stringSearch2(string original, string sub) {
	int i = 0;
	bool exists = false, complete = false;
	//string sub = "";

	for (int j = 0; j < original.length(); ++j) {
		if ((i < sub.length() && original[j] == sub[i]) || sub[i] == '*') {
			if (i == sub.length() - 1) {
				complete = true;
				exists = true;
			}
			//if (!(sub[i] == '*'))
			if (sub[i] == '*' && i == sub.length() - 1) {
				complete = true;
				exists = true;
			}
			else if (sub[i] == '*' && i < sub.length() - 1) {
				if (j < original.length())
					if (original[j + 1] == sub[i + 1])
						++i;
			}
			else
				++i;
		}
		else {
			i = 0;
			if (!complete)
				exists = false;
		}
	}

	if (exists)
		cout << sub << " is substring of " << original;
	else
		cout << "No substring detected";

	cout << endl;
}

//Count asterisk from a string
int count_asterisks(char *str)
{
	int asterisk_count = 0;
	for (int x = 0; x<strlen(str); x++)
	{
		if (str[x] == '*' && (x == 0 || str[x - 1] != '\\'))

		{
			asterisk_count++;
		}
	}
	return asterisk_count;
}
bool match_within(char *, char *);

//Check if the second string is contained in the first string
bool match_at_front(char * search_in, char * search_for)
{
	if (search_for[0] == '\0') //everything matches
	{
		return true;
	}
	else if (search_in[0] == '\0') //end of first string
	{
		return false;
	}
	else if (search_for[0] == '*')
	{  //any number of initial characters are chewed up by the *
		return match_within(search_in, (search_for + 1));
	}
	else if (search_for[0] == '\\' && search_for[1] == '*')
	{
		if (search_in[0] == '*')
		{
			return match_at_front(search_in + 1, search_for + 2);
		}
		else
		{
			return false;
		}
	}
	else if (search_for[0] == search_in[0])
	{
		return match_at_front(search_in + 1, search_for + 1);
	}
	else
	{
		return false;
	}
}

bool match_within(char * search_in, char * search_for)
{
	for (int x = 0;
		x <= strlen(search_in) - strlen(search_for) - count_asterisks(search_for); x++)
	{
		if (match_at_front(search_in + x, search_for))
		{
			return true;
		}
	}
	return false;
}