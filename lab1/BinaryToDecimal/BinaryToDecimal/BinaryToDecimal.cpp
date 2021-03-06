#include "pch.h"
#include <bitset>
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

enum class Error
{
	Overflow,
	InvalidDigit,
	Ok,
};

Error BinaryToDecimal(const string& binaryRepresentation, int& decimalNumber)
{
	size_t sizeString = binaryRepresentation.size();
	Error err = Error::Ok;

	for (size_t i = 0; i < sizeString; i++)
	{
		if ((binaryRepresentation[i] != '0') && (binaryRepresentation[i] != '1'))
		{
			return err = Error::InvalidDigit;
		}

		if (binaryRepresentation[i] == '1')
		{
			if (decimalNumber > (INT_MAX - (1 << i)))
			{
				return err = Error::Overflow;
			}
			else
			{
				decimalNumber += (1 << i);
			}
		}
	}

	return err;
}

bool PrintError(Error error)
{
	if (error == (Error::InvalidDigit))
	{
		cout << "This is invalid digit" << endl;

		return false;
	}
	else if (error == (Error::Overflow))
	{
		cout << "Overflow, large number" << endl;

		return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: BinaryToDecimal.exe <binary number>" << endl;
		return 1;
	}

	const string binaryRepresentation = argv[1];
	int number = 0;

	if (auto err = BinaryToDecimal(binaryRepresentation, number); err != Error::Ok)
	{
		PrintError(err);

		return 1;
	}

	cout << number;

	return 0;
}
