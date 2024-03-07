#include "DoctorView.h"
#include <QWidgetItem>
#include <qmessagebox.h>
#include <qmessagebox.h>
#include<sstream>

DoctorView::DoctorView(Service& service, std::vector<Patient> assignedPatients, Doctor d, QWidget* parent)
	: service(service),assignedPatients(assignedPatients),doctor(d),  QMainWindow(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(d.getName()));
	this->populate(assignedPatients);
	this->connectCheckBox();
	this->connectPushButton();
	this->connectChangeDiagnosis();


}

DoctorView::~DoctorView()
{}

void DoctorView::populate(std::vector<Patient> patients)
{
	ui.listWidget->clear();
	for (auto i : patients)
	{
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(i.toString()) };
		if (i.getDoctor() == this->doctor.getName())
			item->setBackground(QColor(Qt::green));
		ui.listWidget->addItem(item);
	}
}

void DoctorView::showAPatients()
{
	std::vector<Patient> patients = this->assignedPatients;
	std::vector<Patient> newList;
	for (auto i : patients)
	{
		if (i.getDoctor() == this->doctor.getName())
			newList.push_back(i);
	}
	this->populate(newList);
}

void DoctorView::connectCheckBox()
{
	connect(ui.checkBox, &QCheckBox::stateChanged, this, &DoctorView::verifyCheckBox);
}

void DoctorView::verifyCheckBox()
{
	if (ui.checkBox->isChecked() == true)
		this->showAPatients();
	else
		this->populate(this->assignedPatients);
}

void DoctorView::connectPushButton()
{
	connect(ui.pushButton, &QPushButton::clicked, this, &DoctorView::handleAdd);
}

void DoctorView::handleAdd()
{
	std::string name = this->ui.lineEdit->text().toStdString();
	std::string diagnosis = this->ui.lineEdit_2->text().toStdString();
	std::string specialization = this->ui.lineEdit_3->text().toStdString();
	std::string doctor = this->ui.lineEdit_4->text().toStdString();
	std::string date = this->ui.lineEdit_5->text().toStdString();
	if(date=="")
		QMessageBox::critical(this, "Error", "Enter a valid year!");
	else
	{

		std::stringstream ss(date);
		std::string day, month, year;
		std::getline(ss, day, '.');
		std::getline(ss, month, '.');
		std::getline(ss, year, '.');
		int iday = stoi(day);
		int imonth = stoi(month);
		int iyear = stoi(year);
		if (iyear > 2023)
			QMessageBox::critical(this, "Error", "Enter a valid year!");
		if (iyear == 2023)
		{
			if (imonth > 6)
				QMessageBox::critical(this, "Error", "Enter a valid month!");
			if (imonth == 6)
			{
				if (iday > 30)
					QMessageBox::critical(this, "Error", "Enter a valid day!");
			}
		}
		else if (imonth > 12 || iday > 31)
			QMessageBox::critical(this, "Error", "Enter a valid date!");
		else if (name == "")
		{
			QMessageBox::critical(this, "Error", "Enter the name of the patient!");
		}
		else {
			Patient p(name, diagnosis, specialization, doctor, date);
			this->service.addPatient(p);
			this->assignedPatients.push_back(p);
			this->populate(this->assignedPatients);

		}
	}
	
}

void DoctorView::changeDiagnosis()
{
	std::string newDiagnosis = this->ui.lineEdit_6->text().toStdString();
	std::string newSpecialization = this->ui.lineEdit_7->text().toStdString();
	std::string data = this->ui.listWidget->selectedItems()[0]->text().toStdString();
	std::stringstream ss(data);
	std::string name, diagnosis,specialization;
	std::getline(ss, name, ' ');
	std::getline(ss, diagnosis, ' ');
	std::getline(ss, specialization, ' ');
	if (newDiagnosis == "undiagnosed")
		QMessageBox::critical(this, "Error", "Enter a valid diagnosis!");
	if (diagnosis == newDiagnosis && specialization == newSpecialization)
		QMessageBox::critical(this, "Error", "You need to modify something!");
	for (auto& p : this->assignedPatients)
	{
		if (p.getName() == name)
		{
			this->service.changeDiagnosisAndSpecialization(name, newDiagnosis, newSpecialization);

		}
		

	}
	std::vector<Patient> newvec;
	for (auto p : this->assignedPatients)
		if (p.getSpecialization() == this->doctor.getSpecialization())
			newvec.push_back(p);
	this->assignedPatients = newvec;
	this->populate(this->assignedPatients);
	
	for(auto d:this->service.getAllDoctors())
	{
		DoctorView* view = new DoctorView{ service,service.getAssignedPatients(d),d };
		view->populate(service.getAssignedPatients(d));
	}




}

void DoctorView::connectChangeDiagnosis()
{
	connect(ui.pushButton_2, &QPushButton::clicked, this, &DoctorView::changeDiagnosis);
}
