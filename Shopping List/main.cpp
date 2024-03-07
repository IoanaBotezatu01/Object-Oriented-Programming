#include "ShoppingList.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Service service;
    ShoppingList w(service);
    w.show();
    return a.exec();
}
