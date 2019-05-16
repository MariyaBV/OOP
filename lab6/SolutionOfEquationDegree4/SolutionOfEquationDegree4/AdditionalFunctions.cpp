#include "pch.h"
#include "EquationRoot4.h"

using namespace std;

void PrintRoots(EquationRoot4 const & roots)
{
	if (roots.numRoots > 0)
	{
		cout << "There are " << roots.numRoots << " roots: " << endl;
		for (double number : roots.roots)
		{
			if (IsEqual(number, 0))
			{
				cout << fixed << setprecision(4) << abs(number) << ' ';
			}
			else
			{
				cout << fixed << setprecision(4) << number << ' ';
			}
		}
			
		cout << endl;
	}
}