#pragma once

#include "ui_CvdManager.h"

#include <QtWidgets/QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QDockWidget>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>


class CvdManager : public QMainWindow
{
    Q_OBJECT
private:
    Ui::CvdManagerClass ui;

    QMenu* start_menu;
    QAction* start_menu_open_act;
    QAction* start_menu_save_act;
    QAction* start_menu_quit_act;

    QMenu* view_menu;
    QAction* view_menu_show_command_act;
    QAction* view_menu_show_connect_act;
    QAction* view_menu_show_control_act;

    QDockWidget* connect_dock;

    QLabel* ip_label;
    QLineEdit* ip_line_edit;
    QLabel* port_label;
    QLineEdit* port_line_edit;
    QPushButton* connect_button;
    QPushButton* send_button;

    QVBoxLayout* connect_main_layout;
    QHBoxLayout* connect_layout1;
    QHBoxLayout* connect_layout2;
    QHBoxLayout* connect_layout3;

    QWidget* connect_dock_widget;

public:
    CvdManager(QWidget *parent = nullptr);
    ~CvdManager();

public slots:

};
