#ifndef REQ_HPP
#define REQ_HPP

#include <string>
#include <windows.h>

#include "Debug.hpp"

typedef void* HINTERNET;

class Requests
{
private:
	const char* url;
	const char* useragent;
	HINTERNET hSocket;
	HINTERNET hConnection;
	bool SSL;
public:
	mutable int error_code;

	Requests& operator=(const Requests&) = delete;
	Requests& operator=(const Requests&&) = delete;

	Requests(const Requests&) = delete;
	Requests(Requests&&) = delete;
public:
	Requests(const char* useragent, const char* url, bool https);

	Requests();

	~Requests();

	std::string Send_Request_Get(const char* path, const char* content) const;

	int Init();
};

#endif