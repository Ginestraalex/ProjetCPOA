#ifndef DEF_SYSTEM
#define DEF_SYSTEM
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "PropositionDeCours.cpp"

class System{
public:
    System();
    System(std::string nomFichier);
    System(Utilisateur* lesUtilisateurs[], int nbUtilisateurs);
    
    bool connexion(std::string fonction, std::string id, std::string pwd);
    void ajouterCours(Cours* cours);
    Cours* getCours(int index);
    Cours* getCours(std::string nomCours);
    void proposerCours(std::string nomCours, Enseignant* enseignantReferent);
    void accepterPropositionCours(int index);
    
    void afficherListeCours();
    void afficherListePropositionsCours();
    void sauvegarderIdentifiants();
    
    void supp();
    
    Utilisateur* utilisateurCourrant;
    std::vector<Utilisateur*> listeDesUtilisateurs;
    std::vector<Cours*> listeDesCours;
    std::vector<PropositionDeCours*> listePropositionCours;
};

#endif
