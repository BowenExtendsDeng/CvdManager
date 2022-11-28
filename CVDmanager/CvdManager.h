#pragma once

#include "ui_CvdManager.h"

#include <QtWidgets/QMainWindow>
#include <QScreen>


class CvdManager : public QMainWindow
{
    Q_OBJECT
private:
    Ui::CvdManagerClass ui;

public:
    CvdManager(QWidget *parent = nullptr);
    ~CvdManager();

public slots:

};
