#include "interfacegraphique.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InterfaceGraphique w;
    w.show();

    return a.exec();
}
