#-------------------------------------------------
#
# Project created by QtCreator 2017-12-11T10:55:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Arche
TEMPLATE = app


SOURCES += main.cpp\
        interfacegraphique.cpp \
    Utilisateur.cpp \
    System.cpp \
    PropositionDeCours.cpp \
    Inscription.cpp \
    fonction.cpp \
    Etudiant.cpp \
    Enseignant.cpp \
    Depot.cpp \
    Cours.cpp \
    Administrateur.cpp

HEADERS  += interfacegraphique.h \
    Utilisateur.h \
    System.h \
    PropositionDeCours.h \
    Inscription.h \
    Etudiant.h \
    Enseignant.h \
    Depot.h \
    Cours.h \
    Administrateur.h

FORMS    += interfacegraphique.ui
