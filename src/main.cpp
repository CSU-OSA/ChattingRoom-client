/*
 * 由 OctAutumn 编写, 基于 Qt 的 CSU-Chatting 客户端
 *
 * 当前版本 0.1.0-Alpha
*/

#include <QApplication>
#include <QPushButton>
#include "MainWindow/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
