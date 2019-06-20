enum class Protocol
{
	HTTP,
	HTTPS,
	FTP
};

bool ParseURL(std::string const& url, Protocol& protocol, int& port, std::string& host, std::string& document);
bool GetProtocol(std::string const& protocolStr, Protocol& protocol);