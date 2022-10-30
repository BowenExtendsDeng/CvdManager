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
    
    /// <summary>
    ///     主窗口
    /// </summary>
    /// <param name="parent"></param>
    QTextEdit* te = new QTextEdit("CVD Chart", this);
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);


}

CvdManager::~CvdManager()
{}
