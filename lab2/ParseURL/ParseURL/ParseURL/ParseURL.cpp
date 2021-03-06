#include "pch.h"
#include "ParseURL.h"

using namespace std;

bool GetProtocol(string const& protocolStr, Protocol& protocol)
{
	if (protocolStr == "HTTP")
	{
		protocol = Protocol::HTTP;
		return true;
	}
	else if (protocolStr == "HTTPS")
	{
		protocol = Protocol::HTTPS;
		return true;
	}
	else if (protocolStr == "FTP")
	{
		protocol = Protocol::FTP;
		return true;
	}

	return false;
}

bool ParseURL(string const& url, Protocol& protocol, int& port, string& host, string& document)
{
	regex RegexStringWithPort("([A-Za-z]+)://([A-Za-z0-9\\.-]+):([0-9]+)([^[:s:]]+){0,}");
	regex RegexStringWithoutPort("([A-Za-z]+)://([A-Za-z0-9\\.-]+)([^[:s:]]+){0,}");
	smatch match;

	if (regex_match(url, match, RegexStringWithPort))
	{
		string protocolStr = match[1].str();
		transform(protocolStr.begin(), protocolStr.end(), protocolStr.begin(), ::toupper);

		if (!GetProtocol(protocolStr, protocol))
		{
			throw invalid_argument("Error. Not correct protocol.\n");
		}

		host = match[2].str();
		port = atoi((match[3].str()).c_str());

		if ((port < 1) || (port > 65535))
		{
			throw invalid_argument("Error. Not correct port.\n");
		}

		document = match[4].str();

		return true;
	}
	else if (regex_match(url, match, RegexStringWithoutPort))
	{
		string protocolStr = match[1].str();
		transform(protocolStr.begin(), protocolStr.end(), protocolStr.begin(), ::toupper);

		if (!GetProtocol(protocolStr, protocol))
		{
			throw invalid_argument("Error. Not correct protocol.\n");
		}

		host = match[2].str();
		
		if (protocol == Protocol::HTTP)
		{
			port = 80;
		}
		else if (protocol == Protocol::HTTPS)
		{
			port = 443;
		}
		else if (protocol == Protocol::FTP)
		{
			port = 21;
		}

		document = match[3].str();

		return true;
	}

	return false;
}