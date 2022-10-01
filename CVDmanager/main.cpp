#include "CvdManager.h"
#include <QtWidgets/QApplication>
#include "CMyIni.h"
#include "Logger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CvdManager w;
    CMyIni config;
    config.ReadIni("config.ini");
    config.Travel();
    
    Logger::Log(config.GetValue("cvd_machine", "port"), Logger::INFO);
    w.show();
    return a.exec();
}

void StartSinglton() {
}
