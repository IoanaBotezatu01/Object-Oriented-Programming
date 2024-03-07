#pragma once
#include "Service.h"
#include "List.h"
#include <QtWidgets/QMainWindow>
#include "ui_ShoppingList.h"

class ShoppingList : public QMainWindow
{
    Q_OBJECT

public:
    ShoppingList(Service&,QWidget *parent = nullptr);
    ~ShoppingList();
    void populate();

private:
    Ui::ShoppingListClass ui;
    Service service;
};
