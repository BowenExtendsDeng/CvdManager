#include "Logger.h"

void Logger::Log(std::string msg,int type) {
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
}
