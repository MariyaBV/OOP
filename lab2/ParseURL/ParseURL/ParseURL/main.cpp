#include "pch.h"
#include "ParseURL.h"

using namespace std;

int main()
{
	Protocol protocol;
	int port;
	string host;
	string document;
	string url;

	while(getline(cin, url))
	{
		try
		{
			if(ParseURL(url, protocol, port, host, document))
			{
				cout << url << endl;
				cout << "HOST: " << host << endl;
				cout << "PORT: " << port << endl;
				cout << "DOC: " << document << endl;
			}
			else
			{
				throw invalid_argument("Error. Not correct URL.\n");
			}
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
		}
	}


	return 0;
}