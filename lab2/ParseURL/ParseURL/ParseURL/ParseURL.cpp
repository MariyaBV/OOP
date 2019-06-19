#include "pch.h"
#include "ParseURL.h"

using namespace std;

bool ParseURL(string const& url, Protocol& protocol, int& port, string& host, string& document)
{
	regex RegexStringWithPort("^((http[s]?|HTTP[S]?|ftp|FTP})://([A-Za-z0-9\\.-]+)(:[0-9]+)?(.*)$");
	regex RegexStringWithoutPort("^((http[s]?|HTTP[S]?|ftp|FTP})://([A-Za-z0-9\\.-]+)?(.*)$");
	smatch match;

	if (regex_match(url, match, RegexStringWithPort))
	{
		host = match[2].str();
		//port = atoi(match[3]);
		document = match[4].str();
	}

	return false;
}