#pragma once

#include <QMainWindow>
#include "ui_CourierView.h"
#include "Service.h"

class CourierView : public QMainWindow
{
	Q_OBJECT

public:
	CourierView(std::vector<Package> packages, Courier c, QWidget* parent = nullptr);
	~CourierView();
	void populateItemList(std::vector<Package> packagesToPopulate);
	void connectDeliver();
	void deliver();
	void showSelectedStreet();
	void populateComboBox();
private:
	Ui::CourierViewClass ui;
	std::vector<Package> couriers_packages;
	Courier courier;
};