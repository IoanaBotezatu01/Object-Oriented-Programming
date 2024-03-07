#pragma once

#include <QMainWindow>
#include "ui_CompanyView.h"
#include "Service.h"

class CompanyView : public QMainWindow
{
	Q_OBJECT

public:
	CompanyView(Service& service,QWidget *parent = nullptr);
	~CompanyView();
	void populate();
	void connectAdd();
	void addPackage();

private:
	Ui::CompanyViewClass ui;
	Service service;
};
