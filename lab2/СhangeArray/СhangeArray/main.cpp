#include "pch.h"
#include "ChangeArray.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	vector<double> inputVector(istream_iterator<double>(cin), (istream_iterator<double>()));

	ProcessVector(inputVector);
	sort(inputVector.begin(), inputVector.end());
	PrintVector(inputVector);

	return 0;
}
