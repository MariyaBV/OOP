#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <string.h>

enum class Error
{
	EmptyReplaceString,
	EmptySearchString,
	Ok,
};

std::string FindAndReplace(std::string const& subjec, std::string const& searchString, std::string const& replaceString);
Error FindError(std::string const& searchString, std::string& replaceString);
void PrintError(Error err);