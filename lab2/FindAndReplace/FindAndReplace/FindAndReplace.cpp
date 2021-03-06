#include "pch.h"
#include "FindAndReplace.h"

std::string FindAndReplace(std::string const& subjec, std::string const& searchString, std::string const& replaceString)
{
	size_t posStart = 0;
	size_t posEnd = subjec.find(searchString, 0);
	size_t searchStringLength = searchString.length();
	std::string outputSubjec;

	if ((searchStringLength != 0) && (posEnd != std::string::npos) && (searchString != replaceString))
	{
		while (posEnd != std::string::npos)
		{
			outputSubjec.append(subjec, posStart, posEnd - posStart).append(replaceString);
			posStart = posEnd + searchStringLength;
			posEnd = subjec.find(searchString, posStart);
		}
		outputSubjec.append(subjec, posStart, posEnd - posStart);

		return outputSubjec;
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
