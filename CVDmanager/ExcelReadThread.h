#pragma once

#include "CMyIni.h"

#include <string>
#include <map>
#include <QThread>

class ExcelReadThread : public QThread
{
private:

	inline bool DataFileExists();

protected:

	void run() override;
};


