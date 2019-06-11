// NamuDarbas.cpp : Defines the entry point for the console application.
//

#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int calculateBorderLength(int helloString)
{
	int result;
	result = helloString + 4;
	return result;
}

int calculateBorderHight(int input)
{
	int result;
	result = (input * 2) + 2;
	return result;
}

int main()
{
	string name;
	string helloString;
	int lineCounter;

	cout << "Koks Jusu vardas: ";

	getline(std::cin, name);

	cout << "Iveskite remelio dydi (nuo 1 iki 10): ";
	cin >> lineCounter;

	helloString = "Sveiki, " + name + " !";

	int const length = calculateBorderLength(helloString.length());

	int const hight = calculateBorderHight(lineCounter);


	char **result = new char*[hight+1];

	for (int i = 0; i<hight+1; i++)
	{
		result[i] = new char[length];
	}

	//bottom and top
	for (int i = 0; i<length; i++)
	{
		result[0][i] = '*';
		result[hight][i] = '*';
	}

	//border hight
	for (int i = 1; i<hight/2; i++)
	{
		for (int j = length - 2; j >= 1; j--)
		{
			result[i][j] = ' ';
			result[hight - i][j] = ' ';
		}
		result[hight - i][0] = '*';
		result[hight - i][length - 1] = '*';
		result[i][0] = '*';
		result[i][length - 1] = '*';
	}

	//helloString
	for (int i = 0; i < helloString.length(); i++)
	{
		result[lineCounter+1][i+2] = helloString[i];
	}
	result[lineCounter + 1][0] = '*';
	result[lineCounter + 1][length-1] = '*';
	result[lineCounter + 1][1] = ' ';
	result[lineCounter + 1][length - 2] = ' ';

	//printing
	for (int i = 0; i < hight+1; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << result[i][j];
		}
		cout << endl;
	}

	//free memory
	for (int i = 0; i<hight; i++) delete[] result[i];
	delete[] result;

	return 0;
}
