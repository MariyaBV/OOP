#include "pch.h"
#include "../ParseURL/ParseURL.h"

using namespace std;

SCENARIO("parse URL")
{
	GIVEN("given correct URL")
	{
		Protocol protocol;
		int port;
		string host;
		string document;
		string url;
		CHECK("" == "");

		WHEN("no port")
		{
			THEN("Protocol::HTTP")
			{
				url = "http://www.mysite.com/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTP);
				CHECK(port == 80);
				CHECK(host == "www.mysite.com");
				CHECK(document == "docs/document1.html?page=30&lang=en#title1");
			}
			AND_THEN("Protocol::HTTPS")
			{
				url = "https://www.mysite.com/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTPS);
				CHECK(port == 443);
				CHECK(host == "www.mysite.com");
				CHECK(document == "docs/document1.html?page=30&lang=en#title1");
			}
			AND_THEN("Protocol::FTP")
			{
				url = "ftp://www.mysite.com/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::FTP);
				CHECK(port == 21);
				CHECK(host == "www.mysite.com");
				CHECK(document == "docs/document1.html?page=30&lang=en#title1");
			}
		}
		AND_WHEN("with port")
		{
			THEN("Protocol::HTTP")
			{
				url = "http://host:100/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTP);
				CHECK(port == 100);
				CHECK(host == "host");
				CHECK(document == "docs/document1.html?page=30&lang=en#title1");
			}
			AND_THEN("Protocol::HTTPS")
			{
				url = "https://host:100/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTPS);
				CHECK(port == 100);
				CHECK(host == "host");
				CHECK(document == "docs/document1.html?page=30&lang=en#title1");
			}
			AND_THEN("Protocol::FTP")
			{
				url = "ftp://host:100/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::FTP);
				CHECK(port == 100);
				CHECK(host == "host");
				CHECK(document == "docs/document1.html?page=30&lang=en#title1");
			}
		}
	}
}