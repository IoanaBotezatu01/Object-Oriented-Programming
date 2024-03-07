#pragma once

#include <QMainWindow>
#include "ui_DriverView.h"
#include"Report.h"
#include <vector>
#include "Driver.h"
#include <qmessagebox.h>
#include "Service.h"
#include "RepoReport.h"

class DriverView : public QMainWindow
{
	Q_OBJECT

public:
	DriverView(Service& s,Driver driver,std::vector<Report> reports,QWidget *parent = nullptr);
	~DriverView();
	void populate();
	void connectAdd();
	void handleAdd();
private:
	Ui::DriverViewClass ui;
	std::vector<Report> assignedReports;
	Service service;
	Driver driver;

};
