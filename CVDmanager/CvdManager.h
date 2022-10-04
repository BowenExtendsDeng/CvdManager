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

    QMenu* inspect_menu;
    QMenu* analyze_menu;
    QMenu* help_menu;
    QMenu* security_menu;
    QMenu* update_menu;

    QDockWidget* command_dock;
    QDockWidget* control_dock;
    QDockWidget* connect_dock;

    QLabel* ip_label;
    QLineEdit* ip_line_edit;
    QLabel* port_label;
    QLineEdit* port_line_edit;
    QPushButton* connect_button;
    QPushButton* send_button;

    QLabel* issue_unit_identifier;
    QLabel* protocol_identifier;
    QLabel* unit_identifier;
    QLabel* command_char;
    QLabel* data_start_address;
    QLabel* data_amount;
    QLabel* high_bit;
    QLabel* low_bit;
    QLineEdit* issue_unit_identifier_high_bit_edit;
    QLineEdit* issue_unit_identifier_low_bit_edit;
    QLineEdit* protocol_identifier_high_bit_edit;
    QLineEdit* protocol_identifier_low_bit_edit;
    QLineEdit* unit_identifier_edit;
    QComboBox* command_char_edit;
    QLineEdit* data_start_address_edit;
    QLineEdit* data_amount_edit;

    QVBoxLayout* connect_main_layout;
    QHBoxLayout* connect_layout1;
    QHBoxLayout* connect_layout2;
    QHBoxLayout* connect_layout3;

    QHBoxLayout* control_main_layout;
    QVBoxLayout* control_layout1;
    QVBoxLayout* control_layout2;
    QVBoxLayout* control_layout3;
    QVBoxLayout* control_layout4;
    QVBoxLayout* control_layout5;
    QVBoxLayout* control_layout6;
    QVBoxLayout* control_layout7;
    QVBoxLayout* control_layout8;
    QVBoxLayout* control_layout9;
    QVBoxLayout* control_layout10;

    QGridLayout* command_layout;

    QWidget* connect_dock_widget;
    QWidget* control_dock_widget;
    QWidget* command_dock_widget;

public:
    CvdManager(QWidget *parent = nullptr);
    ~CvdManager();

public slots:

};
