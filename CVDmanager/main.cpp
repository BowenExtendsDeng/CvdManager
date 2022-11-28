#include "CvdManager.h"
#include "IniReader.h"
#include "Log.h"
#include "ExcelReadThread.h"
#include "ModbusSocket.h"
#include <qsqldatabase.h>

#include <windows.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CvdManager w;
    IniReader config;
    config.ReadIni("config.ini");
    config.Travel();

    ExcelReadThread::ReadCsv();

    w.show();
    return a.exec();
}

void StartSinglton() {
}
