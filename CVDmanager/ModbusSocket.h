#pragma once

#include "Log.h"
#include "IniReader.h"

#include <QString>
#include <QTcpSocket>
#include <QByteArray>

class ModbusSocket
{
private:

	QTcpSocket *socket;

	std::string device_name;
	QString ip;
	int port;

	char send_buf[12] = {0x00};
	
	char m_1 = 0x00;
	char m_2 = 0x00;
	char m_3 = 0x00;
	char m_4 = 0x00;
	char m_7 = 0x00;

	long m_data_addr;
	char m_data_addr_high = 0x00;
	char m_data_addr_low = 0x00;
	long m_data_num;
	char m_data_num_high = 0x00;
	char m_data_num_low = 0x00;
	long m_data;
	int flag;

public:

	ModbusSocket(std::string device_name);

	~ModbusSocket();

	void SetupConnection();

	void SendModbusData();

	void GenerateModbusData();

	void ReceiveModbusData();
};

