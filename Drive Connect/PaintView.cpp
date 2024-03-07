#include "PaintView.h"
#include <QPainter>

PaintView::PaintView(std::vector<Report> reports,QWidget *parent)
	:validReports(reports), QMainWindow(parent)
{
	ui.setupUi(this);
}

PaintView::~PaintView()
{}

void PaintView::paintEvent(QPaintEvent* event)
{
    QMainWindow::paintEvent(event); // Call base class paintEvent first

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPoint center = rect().center();

    painter.fillRect(rect(), Qt::white);

    for (const Report& report : validReports)
    {
        QPoint position(center.x() + report.getlocation().longitude, center.y() + report.getlocation().latitude);

        painter.setBrush(report.getStatus() ? Qt::blue : Qt::gray);
        painter.setPen(Qt::black);
        painter.drawEllipse(position, 120, 120);

        painter.setPen(Qt::black);
        painter.drawText(position + QPoint(12, 0), QString::fromStdString(report.getDescription()));
    }
}

