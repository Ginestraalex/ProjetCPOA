#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QMainWindow>

namespace Ui {
class Inscription;
}

class Inscription : public QMainWindow
{
    Q_OBJECT

public:
    explicit Inscription(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
};



#endif // INSCRIPTION_H
