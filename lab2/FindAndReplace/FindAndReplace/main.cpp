#include "pch.h"
#include "FindAndReplace.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "Invalid arguments count\n"
			 << "Usage: replace.exe <input-string> <search-string> <replace-string>" << endl;
		return 1;
	}

	string subject = argv[1];
	string searchString = argv[2];
	string replaceString = argv[3];
	Error err = FindError(searchString, replaceString);

	if (err != Error::Ok)
	{
		PrintError(err);

		return 1;
	}

	cout << FindAndReplace(subject, searchString, replaceString) << endl;

	return 0;
}