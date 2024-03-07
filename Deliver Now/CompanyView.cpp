#include "CompanyView.h"

CompanyView::CompanyView(Service& service,QWidget *parent)
	: service(service),QMainWindow(parent)
{
	ui.setupUi(this);
	this->populate();
	this->connectAdd();
}

CompanyView::~CompanyView()
{}

void CompanyView::populate()
{
	ui.listWidget->clear();
	auto packages = this->service.getPackages();
	for (auto i : packages)
	{
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(i.toString()) };
		if (i.getStatus() == true || i.getStatus() == 1)
			item->setBackground(QColor(Qt::green));
		ui.listWidget->addItem(item);
	}
}

void CompanyView::connectAdd()
{
	connect(ui.pushButton, &QPushButton::clicked, this, &CompanyView::addPackage);
}

void CompanyView::addPackage()
{
	std::string recipient = this->ui.lineEdit->text().toStdString();
	std::string street = this->ui.lineEdit_2->text().toStdString();
	int number = this->ui.lineEdit_3->text().toInt();
	int x = this->ui.lineEdit_4->text().toInt();
	int y = this->ui.lineEdit_5->text().toInt();
	Address a{ street,number };
	Location l{ x,y };
	Package p{ recipient,a,l,0 };
	this->service.addPackage(p);
	this->populate();
}