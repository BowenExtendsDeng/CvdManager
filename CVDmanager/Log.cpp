#include "Log.h"

void Log::Write(std::string msg,int type) {
	// open log.txt to write
	std::ofstream outfile;
	outfile.open("log.txt", std::ios::app);

	// print time when writing
	QDateTime time = QDateTime::currentDateTime();
	outfile << time.toString("yyyy-MM-dd-hh:mm:ss").toStdString() << " ";

	// print type to record
	if (type == ERROR) {
		outfile << "ERROR:";
	}
	else if(type == INFO) {
		outfile << "INFO: ";
	}
	else {
		outfile << "      ";
	}

	// print log message
	outfile << " "
			<< msg << std::endl;
	outfile.close();

	// print type to record
	if (type == ERROR) {

		QMessageBox::critical(NULL, "程序运行时出错！",
			QString::fromStdString(msg) ,
			QMessageBox::Ok);
	}
}
