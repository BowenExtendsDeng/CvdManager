#pragma once

#include <qdatetime.h>
#include <string>
#include <fstream>
#include <QMessageBox>

namespace Log
{
	const int INFO = 0;
	const int ERROR = 1;

	void Write(std::string msg, int type);
};

