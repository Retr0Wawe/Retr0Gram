#pragma once
#include "Headers.h"

class Requests
{
private:
	HINTERNET hSocket;
	HINTERNET hConnection;
	bool SSL;
public:
	Requests(): hSocket(nullptr), hConnection(nullptr), SSL(0)
	{	}

	Requests(const char* useragent, const char* url, bool https = 0) : SSL(https)
	{
		hSocket = InternetOpenA(useragent, INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);

		if (!hSocket) {
			std::cout << "Error to open connection! Error: " << GetLastError() << std::endl;
			exit(1);
		}

		hConnection = InternetConnectA(hSocket, url, SSL == true ? INTERNET_DEFAULT_HTTPS_PORT 
			: INTERNET_DEFAULT_HTTP_PORT, 0, 0, INTERNET_SERVICE_HTTP, 0, 0);

		if (!hConnection) {
			std::cout << "Error to connect url! Error: " << GetLastError() << std::endl;
			exit(1);
		}
	}

	~Requests()
	{
		InternetCloseHandle(hSocket);
		InternetCloseHandle(hConnection);
	}

	std::string Send_Request(const char* metod, const char* path, const char* content) const;
};