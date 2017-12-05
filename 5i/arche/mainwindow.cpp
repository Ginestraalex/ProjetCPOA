#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_label_4_linkActivated(const QString &link)
{
    Inscription *i=new Inscription();
}

void MainWindow::on_pushButton_clicked()
{

}
