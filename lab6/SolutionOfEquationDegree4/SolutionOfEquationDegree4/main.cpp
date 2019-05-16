#include "pch.h"
#include "AdditionalFunctions.h"
#include <iostream>

using namespace std;

int main()
{
	double a, b, c, d, e;

	while ((cin >> a) && (cin >> b) && (cin >> c) && (cin >> d) && (cin >> e))
	{
		try
		{
			PrintRoots(Solve4(a, b, c, d, e));
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
		}
	}

	return 0;
}
