#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CvdManager.h"

class CvdManager : public QMainWindow
{
    Q_OBJECT

public:
    CvdManager(QWidget *parent = nullptr);
    ~CvdManager();

private:
    Ui::CvdManagerClass ui;
};
