#include "testwindow.h"
#include <QApplication>

#include "primeui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TestWindow w;
//    w.show();

//    PrimeUI pui;
//    pui.show();

    return a.exec();
}
