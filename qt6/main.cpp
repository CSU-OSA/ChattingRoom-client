#include "csu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    csu w;
    w.show();
    return a.exec();
}
