#include "pch.h"
#include "CShapeAction.h"
#include "IShape.h"

using namespace std;

int main(int __argc, char __argv[])
{
	try
	{
		CShapeAction shapeInfo(cin, cout);
		while (!cin.eof() && !cin.fail())
		{
			if (!shapeInfo.HandleCommand())
			{
				cout << "Unknown command!\nUsage: Circle, Trinagle, Rectangle or LineSegment with parameters" << endl;
			}
		}
		shapeInfo.PrintShapeWithMaxArea();
		shapeInfo.PrintShapeWithMinPerimeter();
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;

		return 1;
	}

	return 0;
}
