#include "ExcelReadThread.h"

void ExcelReadThread::run() {
	system("excelGrabber.exe");
}

inline bool DataFileExists() {
    if (FILE* file = fopen("data.ini", "r")) {
        fclose(file);
        return true;
    }
    else {
        return false;
    }
}
