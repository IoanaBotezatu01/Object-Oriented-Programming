#include "DeliverNow1.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "CourierView.h"
#include "CompanyView.h"
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    DeliverNow1 w;

    RepoCourier courierRepo{};
    RepoPackage packageRepo{};
    Service service{ courierRepo, packageRepo };
    std::vector<Courier> couriers = service.getCouriers();
    std::vector<Package> packages = service.getPackages();
    std::vector<CourierView*> courier_views;
    for (auto& c : couriers)
    {
        std::vector<Package> zone_packages;
        for (auto p : packages)
        {
            std::vector<std::string> zone_streets = c.getStreets();
            int found = 0;
            for (auto s : zone_streets)
            {
                if (s == p.getAddress().street)
                {
                    found = 1;
                }
            }
            if (found == 1)
            {
                if (p.getStatus() == 0 || p.getStatus() == false)
                    zone_packages.push_back(p);
            }
            else
            {
                int dist = sqrt(pow(p.getX() - c.getZone().x, 2) - pow(p.getY() - c.getZone().y, 2));
                if (dist < c.getZone().r)
                {
                    if (p.getStatus() == 0 || p.getStatus() == false)
                        zone_packages.push_back(p);
                }
            }
        }

        CourierView* v = new CourierView{ zone_packages, c };
        courier_views.push_back(v);
    }

        for (auto& view : courier_views)
        {
            view->show();
        }
        
        
        CompanyView cv{ service };
        cv.show();
        
        return a.exec();
}