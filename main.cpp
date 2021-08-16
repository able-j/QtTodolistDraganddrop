#include "ctodoapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CToDoApp w;
    w.show();
    return a.exec();
}
