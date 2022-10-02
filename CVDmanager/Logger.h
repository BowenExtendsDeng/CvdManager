#pragma once

#include <qdatetime.h>
#include <string>
#include <fstream>

namespace Logger
{
	const int INFO = 0;
	const int ERROR = 1;

	void Log(std::string msg, int type);
};

