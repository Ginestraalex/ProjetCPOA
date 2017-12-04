#ifndef DEF_COURS
#define DEF_COURS
#include "Administrateur.cpp"
#include "Enseignant.cpp"
#include "Etudiant.cpp"
#include <iostream>
#include <string>

class Cours{
    
public:
    Cours();
    Cours(std::string nom, Enseignant* prof);
    
    std::string getNomCours();
    std::string getNomProfReferent();
    
protected:
    std::string nomCours;
    Enseignant* profReferent;
};

#endif
