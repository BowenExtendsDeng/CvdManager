#include "CvdManager.h"

CvdManager::CvdManager(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("CVD控制软件");

    QMenu* menu1 = menuBar()->addMenu(tr("开始"));
    QAction* act1 = new QAction(tr("打开"), this);
    QAction* act2 = new QAction(tr("保存"), this);
    QAction* act3 = new QAction(tr("退出"), this);
    //TODO:添加槽函数
    menu1->addAction(act1);
    menu1->addAction(act2);
    menu1->addAction(act3);

    QMenu* menu2 = menuBar()->addMenu(tr("视图"));

    QMenu* menu3 = menuBar()->addMenu(tr("查看"));

    QMenu* menu4 = menuBar()->addMenu(tr("分析"));

    QMenu* menu5 = menuBar()->addMenu(tr("帮助"));

    QMenu* menu6 = menuBar()->addMenu(tr("实验数据安全"));

    QMenu* menu7 = menuBar()->addMenu(tr("软件更新"));
    

    QTextEdit* te = new QTextEdit("CVD Chart", this);
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);




    //停靠窗口1
    QDockWidget* dw1 = new QDockWidget("命令字设置", this);//构建停靠窗口，指定父类

    dw1->setFeatures(QDockWidget::DockWidgetMovable);//设置停靠窗口特性，可移动，可关闭
    dw1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);//设置可停靠区域为主窗口左边和右边

    QTextEdit* dte = new QTextEdit("DockWindow First");
    dw1->setWidget(dte);
    addDockWidget(Qt::RightDockWidgetArea, dw1);




    //停靠窗口2
    QDockWidget* dw2 = new QDockWidget("控制操作", this);//构建停靠窗口，指定父类

    dw2->setFeatures(QDockWidget::DockWidgetMovable);
    dw2->setAllowedAreas(Qt::BottomDockWidgetArea);
  
    QHBoxLayout* mainLayout = new QHBoxLayout();
    QVBoxLayout* layout = new QVBoxLayout;

    // 水平 Layout 增加控件
    layout->addWidget(new QPushButton("button1"));
    layout->addWidget(new QPushButton("button2"));
    layout->addWidget(new QPushButton("button3"));
    // 水平 Layout 增加弹簧
    layout->addStretch(1);
    // 将水平 Layout 添加到垂直 Layout
    mainLayout->addLayout(layout);
    // 设置垂直 Layout 弹簧
    mainLayout->addStretch(1);

    QWidget* alWidget = new QWidget();
    alWidget->setLayout(mainLayout);
    dw2->setWidget(alWidget);

    addDockWidget(Qt::BottomDockWidgetArea, dw2);



    //停靠窗口3
    QDockWidget* dw3 = new QDockWidget("连接设置", this);//构建停靠窗口，指定父类

    dw3->setFeatures(QDockWidget::DockWidgetMovable);
    dw3->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    QTextEdit* dte3 = new QTextEdit("DockWindow Third");
    dw3->setWidget(dte3);
    addDockWidget(Qt::LeftDockWidgetArea, dw3);

    this->resize(1000, 600);
}

CvdManager::~CvdManager()
{}
