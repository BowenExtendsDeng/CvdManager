#include "CvdManager.h"

CvdManager::CvdManager(QWidget *parent)
    : QMainWindow(parent)
{
    //setWindowTitle("ͣ������");

    QTextEdit* te = new QTextEdit("MainWindow", this);
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);

    //ͣ������1
    QDockWidget* dw1 = new QDockWidget("ͣ������1", this);//����ͣ�����ڣ�ָ������

    dw1->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);//����ͣ���������ԣ����ƶ����ɹر�

    dw1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);//���ÿ�ͣ������Ϊ��������ߺ��ұ�

    QTextEdit* dte = new QTextEdit("DockWindow First");
    dw1->setWidget(dte);
    addDockWidget(Qt::RightDockWidgetArea, dw1);

    //ͣ������2
    QDockWidget* dw2 = new QDockWidget("ͣ������2", this);//����ͣ�����ڣ�ָ������

    dw2->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetClosable);//����ͣ���������ԣ��ɸ���,�ɹر�

    QTextEdit* dte2 = new QTextEdit("DockWindow Second");
    dw2->setWidget(dte2);
    addDockWidget(Qt::RightDockWidgetArea, dw2);

    //ͣ������3
    QDockWidget* dw3 = new QDockWidget("ͣ������3", this);//����ͣ�����ڣ�ָ������

    dw3->setFeatures(QDockWidget::DockWidgetFloatable);//����ͣ���������ԣ�����ȫ��ͣ�����ڵ�����

    QTextEdit* dte3 = new QTextEdit("DockWindow Third");
    dw3->setWidget(dte3);
    addDockWidget(Qt::RightDockWidgetArea, dw3);
}

CvdManager::~CvdManager()
{}
