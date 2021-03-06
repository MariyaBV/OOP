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

		WHEN("no port")
		{
			THEN("Protocol::HTTP")
			{
				url = "http://www.mysite.com/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTP);
				CHECK(port == 80);
				CHECK(host == "www.mysite.com");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("Protocol::HTTPS")
			{
				url = "https://www.mysite.com/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTPS);
				CHECK(port == 443);
				CHECK(host == "www.mysite.com");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("Protocol::FTP")
			{
				url = "ftp://www.mysite.com/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::FTP);
				CHECK(port == 21);
				CHECK(host == "www.mysite.com");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("Protocol in different case")
			{
				url = "FtP://www.mysite.com/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::FTP);
				CHECK(port == 21);
				CHECK(host == "www.mysite.com");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("empty document")
			{
				url = "Ftp://www.mysite.com";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::FTP);
				CHECK(port == 21);
				CHECK(host == "www.mysite.com");
				CHECK(document == "");
			}
		}
		AND_WHEN("with port")
		{
			THEN("Protocol::HTTP")
			{
				url = "http://host:1/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTP);
				CHECK(port == 1);
				CHECK(host == "host");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("Protocol::HTTPS")
			{
				url = "https://host:1/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTPS);
				CHECK(port == 1);
				CHECK(host == "host");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("Protocol::FTP")
			{
				url = "ftp://host:1/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::FTP);
				CHECK(port == 1);
				CHECK(host == "host");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("Protocol::HTTP")
			{
				url = "http://host:65535/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTP);
				CHECK(port == 65535);
				CHECK(host == "host");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("Protocol::HTTPS")
			{
				url = "https://host:65535/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTPS);
				CHECK(port == 65535);
				CHECK(host == "host");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("Protocol::FTP")
			{
				url = "ftp://host:65535/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::FTP);
				CHECK(port == 65535);
				CHECK(host == "host");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("Protocol in different case")
			{
				url = "FtP://host:65535/docs/document1.html?page=30&lang=en#title";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::FTP);
				CHECK(port == 65535);
				CHECK(host == "host");
				CHECK(document == "/docs/document1.html?page=30&lang=en#title");
			}
			AND_THEN("empty document")
			{
				url = "http://host:100";
				CHECK(ParseURL(url, protocol, port, host, document));
				CHECK(protocol == Protocol::HTTP);
				CHECK(port == 100);
				CHECK(host == "host");
				CHECK(document == "");
			}
		}
	}
	GIVEN("not correct url")
	{
		Protocol protocol;
		int port;
		string host;
		string document;
		string url;

		WHEN("with port")
		{
			THEN("port not in (1, 65535)")
			{
				url = "http://host:0/docs/document1.html?page=30&lang=en#title";
				CHECK_THROWS_WITH(ParseURL(url, protocol, port, host, document), "Error. Not correct port.\n");
			}
			AND_THEN("port not in (1, 65535)")
			{
				url = "http://host:65536/docs/document1.html?page=30&lang=en#title";
				CHECK_THROWS_WITH(ParseURL(url, protocol, port, host, document), "Error. Not correct port.\n");
			}
			AND_THEN("not existing protocol")
			{
				url = "httpw://host:100/docs/document1.html?page=30&lang=en#title";
				CHECK_THROWS_WITH(ParseURL(url, protocol, port, host, document), "Error. Not correct protocol.\n");
			}
		}
	}
}