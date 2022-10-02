#pragma once

#include <QTcpSocket>

#include "Logger.h"
#include "CMyIni.h"

#include <qhostaddress.h>
#include <QString>

class CvdSocket
{
private:

	QTcpSocket* socket;

	QString ip;
	int port;
	
	unsigned char m_1;
	unsigned char m_2;
	unsigned char m_3;
	unsigned char m_4;
	unsigned char m_7;

	long m_data_addr;
	unsigned char m_data_addr_high;
	unsigned char m_data_addr_low;
	long m_data_num;
	unsigned char m_data_num_high;
	unsigned char m_data_num_low;
	long m_data;
	int flag;

public:
	CvdSocket(unsigned char m_1, unsigned char m_2, unsigned char m_3, 
		unsigned char m_4, unsigned char m_7, unsigned char m_data_addr,
		unsigned char m_data_num);
	~CvdSocket();
	void SendCvdData();
	void ReceiveCvdData();
};

