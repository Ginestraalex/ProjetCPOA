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
    void editerCours(Cours* monCours);
    void accederCours(Cours* monCours);
    void ajouterContenu(Cours* monCours);
    void proposerCours();
    void creerDepot(Cours* monCours);
    void noterDepot(Depot* leDepot);
    void sauv();
    void supp();
       
protected:
    System* monSys;
};
#endif