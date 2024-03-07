#pragma once

#include <QMainWindow>
#include "ui_PaintView.h"
#include <QPaintEvent>
#include "Report.h"

class PaintView : public QMainWindow
{
	Q_OBJECT

public:
	PaintView(std::vector<Report> reports,QWidget *parent = nullptr);
	~PaintView();
	void paintEvent(QPaintEvent* event);
private:
	Ui::PaintViewClass ui;
	std::vector<Report> validReports;
};
