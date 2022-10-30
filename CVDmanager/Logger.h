#pragma once

#include <qdatetime.h>
#include <string>
#include <fstream>
#include <QMessageBox>

namespace Logger
{
	const int INFO = 0;
	const int ERROR = 1;

	void Log(std::string msg, int type);
};

