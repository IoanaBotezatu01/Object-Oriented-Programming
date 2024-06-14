#include <iostream>
#include "Repository.h"
#include "Service.h"
#include "Ui.h"
int main() {
Repository repo=Repository();
Service service=Service(repo);
Protein p1=Protein("Human","Myosin-2","MSSDSELAVFGEAA");
Protein p2=Protein("Human","Keratin","TCGSGFGGRAFSCISACGPRPGRCC");
Protein p3=Protein("Mouse","Keratin","MLWWEEVEDCYEREDDEDVQKK");
Protein p4=Protein("E_Coli","tufA","VTLIHPIAMDDGLRFAIRE");
Protein p5=Protein("E_Coli","cspE","MSKIKGNVKWFNESKGFGFITPEDG");
repo.add(p1);
repo.add(p2);
repo.add(p3);
repo.add(p4);
repo.add(p5);

Ui ui=Ui(service);
ui.start();
}
