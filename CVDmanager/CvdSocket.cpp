#include "CvdSocket.h"

CvdSocket::CvdSocket(unsigned char m_1, unsigned char m_2, unsigned char m_3, 
	unsigned char m_4, unsigned char m_7, unsigned char m_data_addr, 
	unsigned char m_data_num) {

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

	this->m_1 = m_1;
	this->m_2 = m_2;
	this->m_3 = m_3;
	this->m_4 = m_4;
	this->m_7 = m_7;
	this->m_data_addr = m_data_addr;
	this->m_data_num = m_data_num;
}
CvdSocket::~CvdSocket() {

}
void CvdSocket::SendCvdData() {
	if (socket == NULL) {

	}
}
void CvdSocket::ReceiveCvdData() {

}