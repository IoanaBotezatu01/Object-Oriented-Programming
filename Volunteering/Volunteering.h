#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Volunteering.h"
#include "Service.h"
#include "Repository.h"
#include "Departament.h"
#include <QApplication>

class Volunteering : public QMainWindow
{
    Q_OBJECT

public:
    Volunteering(Service& service,QWidget *parent = nullptr);
    ~Volunteering();
    void populate();
    void openWindows();
    void createWindowsForDepartments();

private:
    Ui::VolunteeringClass ui;
    Service& service;
};
