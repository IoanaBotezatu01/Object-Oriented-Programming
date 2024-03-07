#include "DriveConnect.h"
#include <QtWidgets/QApplication>
#include "RepoDriver.h"
#include "RepoReport.h"
#include "Service.h"
#include <vector>
#include <string>
#include "DriverView.h"
#include "PaintView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DriveConnect w;

    RepoDriver rd{};
    RepoReport rr{};
    Service service{ rd,rr };
    std::vector<DriverView*> views;
    for (auto d : service.getAllDrivers())
    {
        DriverView* view = new DriverView{service,d, service.getAssignedReports(d)};
        views.push_back(view);
    }
    for (auto& i : views)
        i->show();
    PaintView* v = new PaintView{ service.getValid() };
    v->show();
    
    
    return a.exec();
}
