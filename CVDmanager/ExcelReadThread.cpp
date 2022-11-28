#include "ExcelReadThread.h"

void ExcelReadThread::run() {
	system("excelGrabber.exe -w");
}

void ExcelReadThread::ReadCsv() {
    ExcelReadThread thread;
    Log::Write("start to read data from excel", Log::INFO);
    thread.start();
    thread.quit();
    thread.wait();
    Log::Write("read action finished", Log::INFO);
}
