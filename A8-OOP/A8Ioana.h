#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_A8Ioana.h"

class A8Ioana : public QMainWindow
{
    Q_OBJECT

public:
    A8Ioana(QWidget *parent = nullptr);
    ~A8Ioana();

private:
    Ui::A8IoanaClass ui;
};
