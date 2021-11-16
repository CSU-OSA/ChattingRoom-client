#include "CSUchatting.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CSUchatting w;
    w.show();
    return a.exec();
}
