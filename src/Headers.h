#pragma once
#include <iostream>
#include <Windows.h>
#include <wininet.h>
#include <TlHelp32.h>
#include "nlohmann/json.hpp"

#pragma comment(linker, "/SUBSYSTEM:WINDOWS")
#pragma comment(lib, "WinInet.lib")
#pragma warning(disable : 4996)

const int buffer_size = 1024;