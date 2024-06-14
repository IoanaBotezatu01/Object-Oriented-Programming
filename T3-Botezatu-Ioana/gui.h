//
// Created by user on 25.05.2023.
//

#ifndef T3_BOTEZATU_IOANA_GUI_H
#define T3_BOTEZATU_IOANA_GUI_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Gui; }
QT_END_NAMESPACE

class Gui : public QWidget {
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);
    void populateList();
    ~Gui() override;

private:
    Ui::Gui *ui;
};


#endif //T3_BOTEZATU_IOANA_GUI_H
