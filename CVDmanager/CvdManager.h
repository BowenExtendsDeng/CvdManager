#pragma once

#include "ui_CvdManager.h"

#include <QtWidgets/QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QDockWidget>
#include <QPushButton>


class CvdManager : public QMainWindow
{
    Q_OBJECT

public:
    CvdManager(QWidget *parent = nullptr);
    ~CvdManager();

private:
    Ui::CvdManagerClass ui;
};
