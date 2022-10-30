#pragma once

#include "Logger.h"
#include "CMyIni.h"

#include <QThread>
#include <QString>
#include <QModbusTcpClient>
#include <QModbusDataUnit>

class ModbusSocket : public QThread
{
private:

	QModbusTcpClient *modbusDevice;

	std::string device_name;
	QString ip;
	int port;
	
	unsigned char m_1 = 0x00;
	unsigned char m_2 = 0x00;
	unsigned char m_3 = 0x00;
	unsigned char m_4 = 0x00;
	unsigned char m_7 = 0x00;

	long m_data_addr;
	unsigned char m_data_addr_high = 0x00;
	unsigned char m_data_addr_low = 0x00;
	long m_data_num;
	unsigned char m_data_num_high = 0x00;
	unsigned char m_data_num_low = 0x00;
	long m_data;
	int flag;

public:

	ModbusSocket(std::string device_name);

	~ModbusSocket();

	void GenerateModbusData();

	void ReceiveModbusData();

protected:
	void run() override;
};

