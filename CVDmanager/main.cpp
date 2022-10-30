#include "CvdManager.h"
#include "CMyIni.h"
#include "Logger.h"
#include "ExcelReadThread.h"
#include "ModbusSocket.h"

#include <windows.h>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CvdManager w;
    CMyIni config;
    config.ReadIni("config.ini");
    config.Travel();

    ModbusSocket* modbusSocket = new ModbusSocket("device_1"); 
    modbusSocket->SetupConnection();
    modbusSocket->GenerateModbusData();
    modbusSocket->SendModbusData();

    w.show();
    return a.exec();
}

void StartSinglton() {
}
