//
// Created by user on 25.05.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Gui.h" resolved

#include "gui.h"
#include "ui_Gui.h"


Gui::Gui(QWidget *parent) :
        QWidget(parent), ui(new Ui::Gui) {
    ui->setupUi(this);
}

Gui::~Gui() {
    delete ui;
}
