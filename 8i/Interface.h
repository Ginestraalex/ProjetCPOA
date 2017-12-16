#ifndef DEF_INTERFACE
#define DEF_INTERFACE
#include "System.cpp"

class Interface{
    
public:
    Interface();
    Interface(System* monSyteme);
    Interface(std::string nomFichier);
    
    /* page de connexion */
    bool pageDeConnexion();
    void connexion();
    void homepageAdministrateur();
    void homepageEnseignant();
    void homepageEtudiant();
    
    /* etudiant */
    void accederCours(Cours* monCours, Etudiant* etud);
    void rendreTravail(Depot* leDepot, Etudiant* etud);

    /* enseignant */
    void editerCours(Cours* monCours);
    void ajouterContenu(Cours* monCours);
    void proposerCours(Enseignant* ensei);
    void creerDepot(Cours* monCours);
    void noterDepot(Depot* leDepot);
    void setInscription(Cours* cours);
    
    /* autre */
    void sauv();
    void supp();
       
protected:
    System* monSys;
};
#endif
