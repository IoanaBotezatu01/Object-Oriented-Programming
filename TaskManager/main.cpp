#include "Ui.h"
#include "domain.h"
int main() {
    Repository repo = Repository();
    Service service = Service(repo);

    Task t1=Task("oop",123,1);
    Task t2=Task("graph", 23, 4);
    Task t3=Task("os", 233, 2);
    Task t4=Task("sda", 231, 4);
    Task t5=Task("geometry", 10, 10);

    repo.add(t1);
    repo.add(t2);
    repo.add(t3);
    repo.add(t4);
    repo.add(t5);

    Ui ui = Ui(service);
    ui.start();
}