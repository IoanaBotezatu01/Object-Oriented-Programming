#include "A8Ioana.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUI w;
    w.show();
    return a.exec();
}
