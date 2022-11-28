#pragma once

#include <QDateTime>

class Data
{
private:
	QDateTime time;
	double methane;
	double ethane;
	double vinyl;
	double propane;
	double acetylene;
public:
	Data(double methane, double ethane, 
		double vinyl, double propane, double acetylene);

	QDateTime GetTime();
	double GetMethane();
	double GetEthane();
	double GetVinyl();
	double GetPropane();
	double GetAcetylene();
};

