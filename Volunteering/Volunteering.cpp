#include "Volunteering.h"
#include "Service.h"
#include <qboxlayout.h>
#include <qlabel.h>

Volunteering::Volunteering(Service& service,QWidget *parent)
    :QMainWindow(parent), service(service)
{
    ui.setupUi(this);
    this->openWindows();
    //this->populate();
}

Volunteering::~Volunteering()
{}

void Volunteering::populate()
{
    std::vector<Department*> deps = this->service.getDepartments();
    for (auto i : deps)
    {
        ui.listWidget->addItem(QString::fromStdString(i->toString()));
    }
}

void Volunteering::openWindows()
{
   
    std::vector<Department*> deps = this->service.getDepartments();

    for (auto i:deps)
    {
        QMainWindow* window = new QMainWindow;
        window->setWindowTitle(QString::fromStdString(i->getName()));
        QWidget* centralWidget = new QWidget(window);
        window->setCentralWidget(centralWidget);
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);
        QLabel* descriptionLabel = new QLabel(QString::fromStdString(i->getDescription()));
        QListWidget* list = new QListWidget(centralWidget);

        layout->addWidget(descriptionLabel);
        layout->addWidget(list);
        for (auto j : this->service.getVolunteers())
        {
            if (j->getDepartment()->getName() == i->getName())
            {
                list->addItem(QString::fromStdString(j->ToString()));
            }
           
        }
                window->show();
    }
}
