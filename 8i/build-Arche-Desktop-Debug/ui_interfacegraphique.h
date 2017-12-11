/********************************************************************************
** Form generated from reading UI file 'interfacegraphique.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACEGRAPHIQUE_H
#define UI_INTERFACEGRAPHIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InterfaceGraphique
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InterfaceGraphique)
    {
        if (InterfaceGraphique->objectName().isEmpty())
            InterfaceGraphique->setObjectName(QStringLiteral("InterfaceGraphique"));
        InterfaceGraphique->resize(400, 300);
        centralWidget = new QWidget(InterfaceGraphique);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 20, 99, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 20, 99, 27));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 20, 99, 27));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(180, 80, 113, 27));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(180, 110, 113, 27));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(140, 170, 99, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 80, 91, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 110, 101, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 0, 161, 20));
        InterfaceGraphique->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InterfaceGraphique);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        InterfaceGraphique->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InterfaceGraphique);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        InterfaceGraphique->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InterfaceGraphique);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        InterfaceGraphique->setStatusBar(statusBar);

        retranslateUi(InterfaceGraphique);

        QMetaObject::connectSlotsByName(InterfaceGraphique);
    } // setupUi

    void retranslateUi(QMainWindow *InterfaceGraphique)
    {
        InterfaceGraphique->setWindowTitle(QApplication::translate("InterfaceGraphique", "InterfaceGraphique", 0));
        pushButton->setText(QApplication::translate("InterfaceGraphique", "Etudiant", 0));
        pushButton_2->setText(QApplication::translate("InterfaceGraphique", "Enseignant", 0));
        pushButton_3->setText(QApplication::translate("InterfaceGraphique", "Admin", 0));
        pushButton_4->setText(QApplication::translate("InterfaceGraphique", "Connexion", 0));
        label->setText(QApplication::translate("InterfaceGraphique", "Identifiant :", 0));
        label_2->setText(QApplication::translate("InterfaceGraphique", "Mot de passe :", 0));
        label_3->setText(QApplication::translate("InterfaceGraphique", "Connexion en tant que", 0));
    } // retranslateUi

};

namespace Ui {
    class InterfaceGraphique: public Ui_InterfaceGraphique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACEGRAPHIQUE_H
