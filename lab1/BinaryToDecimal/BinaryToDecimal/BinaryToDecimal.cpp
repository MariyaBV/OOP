#include "pch.h"
#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

bool IsZero(const char* binaryNumberString)
{
	bool isZero = false;

	if ((strlen(binaryNumberString) == 1) && (binaryNumberString[0] == '0'))
	{
		isZero = true;
	}

	return isZero;
}

bool IsBinaryNumber(const char* binaryNumberString)
{
	bool isBinaryNumber = true;
	int sizeString = strlen(binaryNumberString);
	
	for (int i = 0; i < sizeString; i++)
	{
		if ((binaryNumberString[i] != '0') && (binaryNumberString[i] != '1'))
		{
			isBinaryNumber = false;
		}
	}

	return isBinaryNumber;
}

double fromBinaryToDecimal(const char* binaryNumberString)
{
	int sizeString = strlen(binaryNumberString);
	double decimalNumber = 0;

	if (!IsZero(binaryNumberString))
	{
		for (int i = 0; i < sizeString; i++)
		{
			if (binaryNumberString[i] == '1')
			{
				decimalNumber += pow(2, i);
			}
		}
	}

	return decimalNumber;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
				<< "Usage: BinaryToDecimal.exe <binary number>" << endl;
		return 1;
	}

	const char* binaryNumberString = argv[1];

	if (!IsBinaryNumber(binaryNumberString))
	{
		cout << "This number isn't binary" << endl;

		return 1;
	}

	cout << fromBinaryToDecimal(binaryNumberString) << endl;

	return 0;
}
