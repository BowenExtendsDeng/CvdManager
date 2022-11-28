#pragma once

#include "IniReader.h"

#include <string>
#include <map>
#include <QThread>

class ExcelReadThread : public QThread
{
protected:
	void run() override;

public:
	static void ReadCsv();
};


