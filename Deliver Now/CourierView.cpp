#include "CourierView.h"
#include <set>

CourierView::CourierView(std::vector<Package> packages, Courier c, QWidget* parent) : couriers_packages{ packages },
courier{ c }, QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(c.getName()));
	Zone z = c.getZone();
	std::string zoneString = std::to_string(z.x) + ", " + std::to_string(z.y) + " Range: " + std::to_string(z.r);
	ui.label->setText(QString::fromStdString(zoneString));
	this->populateItemList(packages);
	this->populateComboBox();
	connect(ui.comboBox, &QComboBox::currentIndexChanged, this, &CourierView::showSelectedStreet);
	this->connectDeliver();

}

CourierView::~CourierView()
{}

void CourierView::populateItemList(std::vector<Package> packagesToPopulate)
{
	ui.listWidget->clear();
	for (auto& p : packagesToPopulate)
	{
		QListWidgetItem* currentPackage = new QListWidgetItem{ QString::fromStdString(p.toString()) };
		ui.listWidget->addItem(currentPackage);
	}
}

void CourierView::connectDeliver()
{
	connect(ui.pushButton, &QPushButton::clicked, this, &CourierView::deliver);
}

void CourierView::deliver()
{
	QListWidgetItem* selectedItem = this->ui.listWidget->selectedItems()[0];
	std::string data = selectedItem->text().toStdString();

	std::string recipient;
	std::stringstream ss(data);
	std::getline(ss, recipient, ' ');
	std::vector<Package> packagestodeliver;
	for (auto i : this->couriers_packages)
	{
		if (i.getRecipient() == recipient)
		{
			i.setStatus(true);
		}
		else {
			if (i.getStatus() == false || i.getStatus() == 0)
				packagestodeliver.push_back(i);
		}
	}
	
	this->populateItemList(packagestodeliver);
	this->couriers_packages=packagestodeliver;
	
}

void CourierView::showSelectedStreet()
{

	std::string street = this->ui.comboBox->currentText().toStdString();
	
	ui.listWidget->clear();
	if (street == "All")
	{
		for (auto p : this->couriers_packages)
			ui.listWidget->addItem(QString::fromStdString(p.toString()));
	}
	else
	{
		for (auto p : this->couriers_packages)
		{
			if (p.getAddress().street == street)
				ui.listWidget->addItem(QString::fromStdString(p.toString()));
		}
	}
}

void CourierView::populateComboBox()
{
	this->ui.comboBox->addItem(QString::fromStdString("All"));
	std::set<std::string> streets;
	for (auto p : this->couriers_packages)
		streets.insert(p.getAddress().street);
	for (auto s : streets)
		this->ui.comboBox->addItem(QString::fromStdString(s));

}
