#include "pch.h"
#include "CShapeAction.h"
#include "IShape.h"

using namespace std;

int main(int __argc, char __argv[])
{
	try
	{
		while (!cin.eof() && !cin.fail())
		{
			CShapeAction shapeInfo(cin, cout);
			if (!shapeInfo.HandleCommand())
			{
				cout << "Unknown command!\nUsage: Circle, Trinagle, Rectangle, LineSegment or Info" << endl;
			}
		}
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;

		return 1;
	}

	return 0;
}
