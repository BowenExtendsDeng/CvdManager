#include "DataDao.h"


void DataDao::InitConnection() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }
        
    //检测已连接的方式 - 自定义连接名
    /*if(QSqlDatabase::contains("mysql_connection"))
        db = QSqlDatabase::database("mysql_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE","mysql_connection");*/
        //设置数据库路径，不存在则创建
    db.setDatabaseName("sqltest.db");
    //db.setUserName("gongjianbo");  //SQLite不需要用户名和密码
    //db.setPassword("qq654344883");

    //打开数据库
    if (db.open()) {
        qDebug() << "open success";
        //关闭数据库
        db.close();
    }
}

void DataDao::CreateTable()
{
    const QString sql = R"(
                      CREATE TABLE IF NOT EXISTS  my_table (
                      id   INTEGER   PRIMARY KEY AUTOINCREMENT NOT NULL,
                      name CHAR (50) UNIQUE NOT NULL,
                      age  INTEGER
                      );)";

    QSqlQuery query;

    if (query.exec(sql)) {
        qDebug() << "init table success";
    }
    else {
        //打印sql语句错误信息
        qDebug() << "init table error" << query.lastError();
    }
}
