#ifndef DEF_COURS
#define DEF_COURS
#include "Administrateur.cpp"
#include "Depot.cpp"
#include <iostream>
#include <string>

class Cours{
    
public:
    Cours();
    Cours(std::string nom, Enseignant* prof);
    
    std::string getNomCours();
    std::string getNomProfReferent();
    void creerDepot(std::string nomDepot, struct tm ouverture, struct tm fermeture);
    void deposer(int index, Etudiant* etud, std::string nomFichier);
    void afficherListeDepot();
    void afficherDepotsEffectues(int index);
    void supp();
    
protected:
    std::string nomCours;
    Enseignant* profReferent;
    std::vector<Depot*> listeDepot;
};

#endif
