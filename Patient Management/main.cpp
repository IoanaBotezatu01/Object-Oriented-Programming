#include "PatientManagement.h"
#include "RepoDoctor.h"
#include "RepoPatient.h"
#include "Service.h"
#include "DoctorView.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PatientManagement w;
    RepoDoctor rd{};
    RepoPatient rp{};
    Service service{ rd,rp };
    std::vector<DoctorView*> doctor_views;
    for (auto i : service.getAllDoctors())
    {
        DoctorView* view=new DoctorView{ service,service.getAssignedPatients(i),i };
        doctor_views.push_back(view);
    }
    for (auto& view : doctor_views)
        view->show();
   
    return a.exec();
}
