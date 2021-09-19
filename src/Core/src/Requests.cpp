#include "Requests.hpp"

#include <iostream>
#include <wininet.h>

Requests::Requests(const char* useragent, const char* url, bool https = 0) : SSL(https)
{
	hSocket = InternetOpenA(useragent, INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);

	if (!hSocket) {
		LOG_CRITICAL("Error to open connection! Error: {0}", GetLastError());
		exit(1);
	}

	hConnection = InternetConnectA(hSocket, url, SSL == true ? INTERNET_DEFAULT_HTTPS_PORT
		: INTERNET_DEFAULT_HTTP_PORT, 0, 0, INTERNET_SERVICE_HTTP, 0, 0);

	if (!hConnection) {
		LOG_CRITICAL("Error to connect url! Error: {0}", GetLastError());
		exit(1);
	}
}

Requests::Requests() : hSocket(nullptr), hConnection(nullptr), SSL(0)
{	}

Requests::~Requests()
{
	InternetCloseHandle(hSocket);
	InternetCloseHandle(hConnection);
}

std::string Requests::Send_Request_Get(const char* path, const char* content) const
{
	std::string result;
	char data[1024];

	HINTERNET hRequest;
	DWORD bytes_read = 0;

	hRequest = HttpOpenRequestA(hConnection, "GET", path,
		NULL, NULL, 0, SSL == true ? INTERNET_FLAG_RELOAD | INTERNET_FLAG_SECURE :
		INTERNET_FLAG_RELOAD | INTERNET_FLAG_KEEP_CONNECTION, 1);

	if (!hRequest) {
		LOG_CRITICAL("Error to open request! Error: {0}", GetLastError());
		exit(1);
	}

	if (content == "") {
		HttpSendRequestA(hRequest, NULL, 0, NULL, 0);
	} else {
		HttpSendRequestA(hRequest, content, sizeof(content), NULL, NULL);
	}

	while (InternetReadFile(hRequest, data, 1024, &bytes_read) && bytes_read > 0) {
		result.append(static_cast<char*>(data), bytes_read);
	} 

	InternetCloseHandle(hRequest);

	return result;
}