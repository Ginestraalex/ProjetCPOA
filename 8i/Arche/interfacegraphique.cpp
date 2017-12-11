#include "interfacegraphique.h"
#include "ui_interfacegraphique.h"
#include "System.h"

InterfaceGraphique::InterfaceGraphique(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterfaceGraphique)
{
    ui->setupUi(this);
}

InterfaceGraphique::~InterfaceGraphique()
{
    delete ui;
}
