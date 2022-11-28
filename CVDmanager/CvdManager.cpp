#include "CvdManager.h"

CvdManager::CvdManager(QWidget *parent)
    : QMainWindow(parent)
{
    //     界面基本配置
    this->resize(1000, 600);
    this->setWindowTitle("CVD控制软件");
    QRect mRect;
    mRect = QGuiApplication::primaryScreen()->geometry();
    this->resize(0.6 * mRect.width(), 0.6 * mRect.height());
}

CvdManager::~CvdManager()
{}
