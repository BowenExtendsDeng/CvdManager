#include "ModbusSocket.h"

ModbusSocket::ModbusSocket(std::string device_name) {

	this->device_name = device_name;
	// read from config
	IniReader reader;
	reader.ReadIni("config.ini");
	port = atoi(reader.GetValue(device_name, "port").c_str());
	ip = QString::fromStdString(reader.GetValue(device_name, "ip"));

}

ModbusSocket::~ModbusSocket() {
	delete socket;
}


void ModbusSocket::GenerateModbusData() {
	//生成Modbus格式数据
	send_buf[0] = m_1;//事务元标识符,高字节在前,低字节在后
	send_buf[1] = m_2;
	send_buf[2] = m_3;//协议标识符,高字节在前,低字节在后
	send_buf[3] = m_4;
	send_buf[4] = 0x00;//后续字节长度,高字节在前,低字节在后
	send_buf[5] = 0x06;
	send_buf[6] = m_7;//单元标识符
	send_buf[7] = 0x06;//m_cmdword;//命令字

	m_data_addr = ((m_data_addr - 1) & 0xffff);
	m_data_addr_low = (char)((m_data_addr) & 0x00ff);
	m_data_addr_high = (char)(((m_data_addr) >> 8) & 0x00ff);
	m_data_num = (m_data_num & 0xffff);
	m_data_num_low = (char)((m_data_num) & 0x00ff);
	m_data_num_high = (char)(((m_data_num) >> 8) & 0x00ff);

	send_buf[8] = m_data_addr_high;//数据起始地址,高字节在前,低字节在后
	send_buf[9] = m_data_addr_low;
	send_buf[10] = m_data_num_high;//数据长度,高字节在前,低字节在后
	send_buf[11] = m_data_num_low;
}

void ModbusSocket::SetupConnection() {
	Log::Write("try to connect " + device_name + " with param ip="
		+ ip.toStdString() + " port=" + std::to_string(port), Log::INFO);

	socket = new QTcpSocket();
	socket->connectToHost(ip, port);
}

void ModbusSocket::SendModbusData() {
	Log::Write("try to send modbus data to " + device_name, Log::INFO);
	socket->write(send_buf,12);
	socket->waitForBytesWritten();
	Log::Write("done" + device_name, Log::INFO);
}

void ModbusSocket::ReceiveModbusData() {

}