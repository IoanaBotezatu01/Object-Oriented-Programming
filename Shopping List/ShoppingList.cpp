#include "ShoppingList.h"

ShoppingList::ShoppingList(Service&,QWidget *parent)
    : service(service),QMainWindow(parent)
{
    ui.setupUi(this);
    this->populate();
}

ShoppingList::~ShoppingList()
{}

void ShoppingList::populate()
{
    service.sortByCategoryAndName();
    for ( List& item : service.getList())
    {
        QListWidgetItem* listItem = new QListWidgetItem(QString::fromStdString(item.toString()));
        ui.listWidget->addItem(listItem);
    }
}
