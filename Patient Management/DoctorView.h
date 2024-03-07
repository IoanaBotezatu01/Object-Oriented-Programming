#pragma once

#include <QMainWindow>
#include "ui_DoctorView.h"
#include <vector>
#include <string>
#include "Patient.h"
#include "Doctor.h"
#include "Service.h"


class DoctorView : public QMainWindow
{
	Q_OBJECT

public:
	DoctorView(Service& service,std::vector<Patient> patients,Doctor d,QWidget *parent = nullptr);
	~DoctorView();
	void populate(std::vector<Patient> patients);
	void showAPatients();
	void connectCheckBox();
	void verifyCheckBox();
	void connectPushButton();
	void handleAdd();
	void changeDiagnosis();
	void connectChangeDiagnosis();

private:
	Ui::DoctorViewClass ui;
	Doctor doctor;
	Service service;
	std::vector<Patient> assignedPatients;

};
