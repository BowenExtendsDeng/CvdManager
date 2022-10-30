#include "ModbusSocket.h"

ModbusSocket::ModbusSocket(std::string device_name) {

	this->device_name = device_name;
	// read from config
	CMyIni reader;
	reader.ReadIni("config.ini");
	port = atoi(reader.GetValue(device_name, "port").c_str());
	ip = QString::fromStdString(reader.GetValue("cvd_machine", "ip"));
	
	Logger::Log("try to connect cvd device with param ip="
		+ reader.GetValue(device_name, "ip")
		+ " port= "
		+ reader.GetValue(device_name, "port"), Logger::INFO);

	// generate SendBufs
	GenerateModbusData();
	
	// get an instance of TcpModbusClient
	modbusDevice = new QModbusTcpClient();
	modbusDevice->setConnectionParameter(
		QModbusDevice::NetworkPortParameter, port);
	modbusDevice->setConnectionParameter(
		QModbusDevice::NetworkAddressParameter, ip);
	Logger::Log("set " + device_name + " timeout 2000",Logger::INFO);
	modbusDevice->setTimeout(2000);
	Logger::Log("set " + device_name + " max retries 2000", Logger::INFO);
	modbusDevice->setNumberOfRetries(3);

	m_data_addr = ((m_data_addr - 1) & 0xffff);
	m_data_addr_low = (unsigned char)((m_data_addr) & 0x00ff);
	m_data_addr_high = (unsigned char)(((m_data_addr) >> 8) & 0x00ff);
	m_data_num = (m_data_num & 0xffff);
	m_data_num_low = (unsigned char)((m_data_num) & 0x00ff);
	m_data_num_high = (unsigned char)(((m_data_num) >> 8) & 0x00ff);
}

ModbusSocket::~ModbusSocket() {

}

void ModbusSocket::run() {

	Logger::Log("try to setup connection with"
		+ device_name, Logger::INFO);
	modbusDevice->connectDevice();

	if (modbusDevice->state() != QModbusDevice::ConnectedState) {
		Logger::Log("failed to setup connection with"
			+ device_name, Logger::ERROR);
		return;
	}
}

void ModbusSocket::GenerateModbusData() {
	unsigned char SendBuf[12] = {0};
	//生成Modbus格式数据
	SendBuf[0] = m_1;//事务元标识符,高字节在前,低字节在后
	SendBuf[1] = m_2;
	SendBuf[2] = m_3;//协议标识符,高字节在前,低字节在后
	SendBuf[3] = m_4;
	SendBuf[4] = 0x00;//后续字节长度,高字节在前,低字节在后
	SendBuf[5] = 0x06;
	SendBuf[6] = m_7;//单元标识符
	SendBuf[7] = 0x06;//m_cmdword;//命令字
	SendBuf[8] = m_data_addr_high;//数据起始地址,高字节在前,低字节在后
	SendBuf[9] = m_data_addr_low;
	SendBuf[10] = m_data_num_high;//数据长度,高字节在前,低字节在后
	SendBuf[11] = m_data_num_low;


}
void ModbusSocket::ReceiveModbusData() {

}