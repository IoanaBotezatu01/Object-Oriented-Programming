#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DeliverNow1.h"

class DeliverNow1 : public QMainWindow
{
    Q_OBJECT

public:
    DeliverNow1(QWidget *parent = nullptr);
    ~DeliverNow1();

private:
    Ui::DeliverNow1Class ui;
};
