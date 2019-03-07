#include "pch.h"
#include "FindAndReplace.h"

std::string FindAndReplace(std::string subjec, std::string const& searchString, std::string const& replaceString)
{
	size_t pos = subjec.find(searchString, 0);
	size_t searchStringLength = searchString.length();
	std::string leftSideOfSubject, rightSideOfSubject;

		while (pos != std::string::npos)
		{
			leftSideOfSubject = subjec.substr(0, pos);
			rightSideOfSubject = subjec.substr(pos + searchStringLength, std::string::npos);
			subjec = leftSideOfSubject + replaceString + rightSideOfSubject;
			pos = subjec.find(searchString, pos);
		}

	return subjec;
};

Error FindError(std::string const& searchString, std::string& replaceString)
{
	Error err = Error::Ok;

	if (replaceString.size() == 0)
	{
		err = Error::EmptyReplaceString;
	}

	if (searchString.size() == 0)
	{
		err = Error::EmptySearchString;	
	}

	return err;
}

void PrintError(Error err)
{
	if (err == Error::EmptyReplaceString)
	{
		std::cout << "Empty replace string.\n"
				  << "Usage: replace.exe <input string> <search-string> [not empty search-string] <replace-string> [not empty replace-string]" << std::endl;
	}

	if (err == Error::EmptySearchString)
	{
		std::cout << "Empty search string.\n"
				  << "Usage: replace.exe <input string> <search-string> [not empty search-string] <replace-string> [not empty replace-string]" << std::endl;
	}
}