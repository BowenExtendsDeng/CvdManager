#include "CvdSocket.h"

CvdSocket::CvdSocket() {
	// read from config
	CMyIni reader;
	reader.ReadIni("config.ini");
	port = atoi(reader.GetValue("cvd_machine", "port").c_str());
	ip = QString::fromStdString(reader.GetValue("cvd_machine", "ip"));
	
	Logger::Log("try to connect cvd server with param ip="
		+ reader.GetValue("cvd_machine", "ip")
		+ " port= "
		+ reader.GetValue("cvd_machine", "port"), Logger::INFO);
	
	socket = new QTcpSocket();
	socket->connectToHost(ip, port, QTcpSocket::ReadWrite);
}
CvdSocket::~CvdSocket() {

}
void CvdSocket::SendCvdData() {

}
void CvdSocket::ReceiveCvdData() {

}