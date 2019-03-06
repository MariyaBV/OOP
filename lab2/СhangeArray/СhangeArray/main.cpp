#include "pch.h"
#include <iostream>
#include <vector>
#include "ChangeArray.h"
#include <algorithm>

using namespace std;

int main()
{
	vector<double> inputVector;
	double min;

	ReadVectorFromStream(cin, inputVector);

	if (inputVector.size() == 0)
	{
		cout << "Invalid input. /n"
			 << "Usage: <double number> [use spaces between numbers]" << endl;
		return 1;
	}
	ProcessVector(inputVector);
	sort(inputVector.begin(), inputVector.end());
	PrintVector(inputVector);

	return 0;
}