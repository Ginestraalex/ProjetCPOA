#ifndef DEF_INTERFACE
#define DEF_INTERFACE
#include "System.cpp"

class Interface{
    
public:
    Interface();
    Interface(System* monSyteme);
    Interface(std::string nomFichier);
    
    bool pageDeConnexion();
    void connexion();
    void homepageAdministrateur();
    void homepageEnseignant();
    void homepageEtudiant();
    void sauv();
    void supp();
       
protected:
    System* monSys;
};
#endif
