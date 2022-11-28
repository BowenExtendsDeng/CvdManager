#include "Data.h"

Data::Data(double methane, double ethane,
	double vinyl, double propane, double acetylene) {
	this->methane = methane;
	this->ethane = ethane;
	this->vinyl = vinyl;
	this->propane = propane;
	this->acetylene = acetylene;
}

QDateTime Data::GetTime() {
	return time;
}

double Data::GetMethane() {
	return methane;
}

double Data::GetEthane() {
	return ethane;
}

double Data::GetVinyl() {
	return vinyl;
}

double Data::GetPropane() {
	return propane;
}

double Data::GetAcetylene() {
	return acetylene;
}
