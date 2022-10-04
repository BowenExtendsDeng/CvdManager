#include "CvdManager.h"

CvdManager::CvdManager(QWidget *parent)
    : QMainWindow(parent)
{
    /// <summary>
    ///     界面基本配置
    /// </summary>
    /// <param name="parent"></param>
    this->resize(1000, 600);
    this->setWindowTitle("CVD控制软件");


    /// <summary>
    ///     菜单栏
    /// </summary>
    /// <param name="parent"></param>
    start_menu = menuBar()->addMenu(tr("开始"));
    start_menu_open_act = new QAction(tr("打开"), this);
    start_menu_save_act = new QAction(tr("保存"), this);
    start_menu_quit_act = new QAction(tr("退出"), this);
    //TODO:添加槽函数
    start_menu->addAction(start_menu_open_act);
    start_menu->addAction(start_menu_save_act);
    start_menu->addAction(start_menu_quit_act);

    view_menu = menuBar()->addMenu(tr("视图"));
    view_menu_show_command_act = new QAction(tr("显示/关闭命令字设置"), this);
    view_menu_show_connect_act = new QAction(tr("显示/关闭连接设置"), this);
    view_menu_show_control_act = new QAction(tr("显示/关闭手动控制设置"), this);
    view_menu->addAction(view_menu_show_command_act);
    view_menu->addAction(view_menu_show_connect_act);
    view_menu->addAction(view_menu_show_control_act);

    inspect_menu = menuBar()->addMenu(tr("查看"));

    analyze_menu = menuBar()->addMenu(tr("分析"));

    help_menu = menuBar()->addMenu(tr("帮助"));

    security_menu = menuBar()->addMenu(tr("实验数据安全"));

    update_menu = menuBar()->addMenu(tr("软件更新"));
    
    /// <summary>
    ///     主窗口
    /// </summary>
    /// <param name="parent"></param>
    QTextEdit* te = new QTextEdit("CVD Chart", this);
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);

    /// <summary>
    ///     命令字停靠窗口
    /// </summary>
    /// <param name="parent"></param>
    command_dock = new QDockWidget("命令字设置", this);

    command_dock->setFeatures(QDockWidget::DockWidgetMovable 
        | QDockWidget::DockWidgetFloatable);
    command_dock->setAllowedAreas(Qt::LeftDockWidgetArea 
        | Qt::RightDockWidgetArea);

    command_layout = new QGridLayout();

    high_bit = new QLabel("高字节");
    command_layout->addWidget(high_bit, 0, 1, 1, 1);
    low_bit = new QLabel("低字节");
    command_layout->addWidget(low_bit, 0, 2, 1, 1);

    issue_unit_identifier = new QLabel("事务元标识符：");
    command_layout->addWidget(issue_unit_identifier
        ,1,0,1,1);
    issue_unit_identifier_high_bit_edit = new QLineEdit();
    command_layout->addWidget(issue_unit_identifier_high_bit_edit,
        1, 1, 1, 1);
    issue_unit_identifier_low_bit_edit = new QLineEdit();
    command_layout->addWidget(issue_unit_identifier_low_bit_edit,
        1, 2, 1, 1);

    protocol_identifier = new QLabel("协议标识符：");
    command_layout->addWidget(protocol_identifier
        , 2, 0, 1, 1);
    protocol_identifier_high_bit_edit = new QLineEdit();
    command_layout->addWidget(protocol_identifier_high_bit_edit,
        2, 1, 1, 1);
    protocol_identifier_low_bit_edit = new QLineEdit();
    command_layout->addWidget(protocol_identifier_low_bit_edit,
        2, 2, 1, 1);

    unit_identifier = new QLabel("单元标识符：");
    command_layout->addWidget(unit_identifier
        , 3, 0, 1, 1);
    unit_identifier_edit = new QLineEdit();
    command_layout->addWidget(unit_identifier_edit,
        3, 1, 1, 2);

    command_char = new QLabel("请选择一个命令字");
    command_layout->addWidget(command_char
        , 4, 0, 1, 1);
    command_char_edit = new QComboBox();
    command_char_edit->addItem("");
    command_layout->addWidget(command_char_edit,
        4, 1, 1, 2);

    data_start_address = new QLabel("数据起始地址：");
    command_layout->addWidget(data_start_address
        , 5, 0, 1, 1);
    data_start_address_edit = new QLineEdit();
    command_layout->addWidget(data_start_address_edit,
        5, 1, 1, 2);

    data_amount = new QLabel("数据个数：");
    command_layout->addWidget(data_amount
        , 6, 0, 1, 1);
    data_amount_edit = new QLineEdit();
    command_layout->addWidget(data_amount_edit,
        6, 1, 1, 2);

    command_dock_widget = new QWidget();
    command_dock_widget->setLayout(command_layout);
    command_dock->setWidget(command_dock_widget);

    addDockWidget(Qt::LeftDockWidgetArea, command_dock);


    /// <summary>
    ///     控制台停靠窗口
    /// </summary>
    /// <param name="parent"></param>
    control_dock = new QDockWidget("控制操作", this);

    control_dock->setFeatures(QDockWidget::DockWidgetMovable | 
        QDockWidget::DockWidgetFloatable);;
    control_dock->setAllowedAreas(Qt::BottomDockWidgetArea);
  
    // 1级布局
    control_main_layout = new QHBoxLayout();
   
    // 2级布局1
    control_layout1 = new QVBoxLayout;
    control_layout1->addWidget(new QLabel("通道 1"));
    control_layout1->addWidget(new QSlider());
    control_layout1->addWidget(new QPushButton("发送"));
    control_layout1->addStretch(1);
    control_main_layout->addLayout(control_layout1);

    // 2级布局1
    control_layout2 = new QVBoxLayout;
    control_layout2->addWidget(new QLabel("通道 2"));
    control_layout2->addWidget(new QSlider());
    control_layout2->addWidget(new QPushButton("发送"));
    control_layout2->addStretch(1);
    control_main_layout->addLayout(control_layout2);

    control_layout3 = new QVBoxLayout;
    control_layout3->addWidget(new QLabel("通道 3"));
    control_layout3->addWidget(new QSlider());
    control_layout3->addWidget(new QPushButton("发送"));
    control_layout3->addStretch(1);
    control_main_layout->addLayout(control_layout3);

    control_layout4 = new QVBoxLayout;
    control_layout4->addWidget(new QLabel("通道 4"));
    control_layout4->addWidget(new QSlider());
    control_layout4->addWidget(new QPushButton("发送"));
    control_layout4->addStretch(1);
    control_main_layout->addLayout(control_layout4);

    control_layout5 = new QVBoxLayout;
    control_layout5->addWidget(new QLabel("通道 5"));
    control_layout5->addWidget(new QSlider());
    control_layout5->addWidget(new QPushButton("发送"));
    control_layout5->addStretch(1);
    control_main_layout->addLayout(control_layout5);

    control_layout6 = new QVBoxLayout;
    control_layout6->addWidget(new QLabel("通道 6"));
    control_layout6->addWidget(new QSlider());
    control_layout6->addWidget(new QPushButton("发送"));
    control_layout6->addStretch(1);
    control_main_layout->addLayout(control_layout6);

    control_layout7 = new QVBoxLayout;
    control_layout7->addWidget(new QLabel("通道 7"));
    control_layout7->addWidget(new QSlider());
    control_layout7->addWidget(new QPushButton("发送"));
    control_layout7->addStretch(1);
    control_main_layout->addLayout(control_layout7);

    control_layout8 = new QVBoxLayout;
    control_layout8->addWidget(new QLabel("通道 8"));
    control_layout8->addWidget(new QSlider());
    control_layout8->addWidget(new QPushButton("发送"));
    control_layout8->addStretch(1);
    control_main_layout->addLayout(control_layout8);

    control_layout9 = new QVBoxLayout;
    control_layout9->addWidget(new QLabel("通道 9"));
    control_layout9->addWidget(new QSlider());
    control_layout9->addWidget(new QPushButton("发送"));
    control_layout9->addStretch(1);
    control_main_layout->addLayout(control_layout9);

    control_layout10 = new QVBoxLayout;
    control_layout10->addWidget(new QLabel("通道 10"));
    control_layout10->addWidget(new QSlider());
    control_layout10->addWidget(new QPushButton("发送"));
    control_layout10->addStretch(1);
    control_main_layout->addLayout(control_layout10);

    // 设置垂直 Layout 弹簧
    control_main_layout->addStretch(1);

    control_dock_widget = new QWidget();
    control_dock_widget->setLayout(control_main_layout);
    control_dock->setWidget(control_dock_widget);

    addDockWidget(Qt::BottomDockWidgetArea, control_dock);


    /// <summary>
    ///     连接设置停靠窗口
    /// </summary>
    /// <param name="parent"></param>
    connect_dock = new QDockWidget("连接设置", this);

    connect_dock->setFeatures(QDockWidget::DockWidgetMovable 
        | QDockWidget::DockWidgetFloatable);
    connect_dock->setAllowedAreas(Qt::LeftDockWidgetArea 
        | Qt::RightDockWidgetArea);

    connect_main_layout = new QVBoxLayout();

    connect_layout1 = new QHBoxLayout;
    ip_label = new QLabel("ip 地址：  ");
    ip_line_edit = new  QLineEdit();
    connect_layout1->addWidget(ip_label);
    connect_layout1->addWidget(ip_line_edit);
    connect_main_layout->addLayout(connect_layout1);

    connect_layout2 = new QHBoxLayout;
    port_label = new QLabel("端口地址：");
    port_line_edit = new  QLineEdit();
    connect_layout2->addWidget(port_label);
    connect_layout2->addWidget(port_line_edit);
    connect_main_layout->addLayout(connect_layout2);

    connect_layout3 = new QHBoxLayout;
    connect_button = new QPushButton("连接");
    send_button = new QPushButton("发送");
    connect_layout3->addWidget(connect_button);
    connect_layout3->addWidget(send_button);
    connect_main_layout->addLayout(connect_layout3);

    connect_dock_widget = new QWidget();
    connect_dock_widget->setLayout(connect_main_layout);
    connect_dock->setWidget(connect_dock_widget);
    
    addDockWidget(Qt::LeftDockWidgetArea, connect_dock);

    command_dock->hide();
    control_dock->hide();
}

CvdManager::~CvdManager()
{}
