#pragma once

#include "Log.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DataDao
{
private:
	QSqlDatabase db;

	QSqlQuery query;
public:
	void InitConnection();
	void CreateTable();

};

