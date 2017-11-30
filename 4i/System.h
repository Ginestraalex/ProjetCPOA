#ifndef DEF_SYSTEM
#define DEF_SYSTEM
#include <iostream>
#include <vector>
#include <string>
#include "Utilisateur.cpp"
#include "Administrateur.cpp"
#include "Enseignant.cpp"
#include "Etudiant.cpp"
#include "Cours.cpp"

class System{
public:
    System();
    System(std::string nomFichier);
    System(Utilisateur lesUtilisateurs[], int nbUtilisateurs);
    
    bool connexion(std::string fonction, std::string id, std::string pwd);
    void ajouterCours(Cours cours);
    Cours getCours(int index);
    
    Utilisateur utilisateurCourrant;
    std::vector<Utilisateur> listeDesUtilisateurs;
    std::vector<Cours> listeDesCours;
};

#endif
