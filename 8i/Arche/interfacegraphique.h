#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H

#include <QMainWindow>

namespace Ui {
class InterfaceGraphique;
}

class InterfaceGraphique : public QMainWindow
{
    Q_OBJECT

public:
    explicit InterfaceGraphique(QWidget *parent = 0);
    ~InterfaceGraphique();

private:
    Ui::InterfaceGraphique *ui;
};

#endif // INTERFACEGRAPHIQUE_H
