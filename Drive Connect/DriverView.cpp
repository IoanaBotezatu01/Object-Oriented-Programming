#include "DriverView.h"

DriverView::DriverView(Service& s,Driver d,std::vector<Report> reports,QWidget *parent)
	:service(s),driver(d),assignedReports(reports), QMainWindow(parent)
{
	ui.setupUi(this);
	this->assignedReports = reports;
	this->setWindowTitle(QString::fromStdString(d.getName()));
	std::string text = std::to_string(d.getLocation().latitude) + "," + std::to_string(d.getLocation().longitude) + " " + std::to_string(d.getScore());
	this->ui.label->setText(QString::fromStdString(text));
	this->populate();
	this->connectAdd();
	
}

DriverView::~DriverView()
{}

void DriverView::populate()
{
	this->ui.listWidget->clear();
	for (auto r : this->assignedReports)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(r.toString()));
		if (r.getStatus())
		{
			QFont font;
			font.setBold(true);
			item->setFont(font);
		}
			
		this->ui.listWidget->addItem(item);
	}
}

void DriverView::connectAdd()
{
	connect(ui.pushButton, &QPushButton::clicked, this, &DriverView::handleAdd);
}

void DriverView::handleAdd()
{
	std::string description = ui.lineEdit->text().toStdString();
	int latitude = ui.lineEdit_2->text().toInt();
	int longitude = ui.lineEdit_3->text().toInt();
	std::string reporter = this->driver.getName();
	if (description == "")
		QMessageBox::critical(this, "Error", "Description can't be empty!");
	else
	{
		auto dist = sqrt((latitude - this->driver.getLocation().latitude) * (latitude - this->driver.getLocation().latitude) + (longitude - this->driver.getLocation().longitude) * (longitude - this->driver.getLocation().longitude));
		if (dist > 20)
			QMessageBox::critical(this, "Error", "The distance is to big!");
		else {
			ExactLocation l{ latitude,longitude };
			Report r = Report(description, reporter, l, false);
			this->service.addReport(r);
			this->assignedReports.push_back(r);
		
			this->populate();
			
			
		}
	}

}

