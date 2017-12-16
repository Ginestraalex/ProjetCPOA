#ifndef DEF_COURS
#define DEF_COURS
#include "Inscription.cpp"

struct contenu{
    std::string nomContenu;
    std::string cheminFichier;
};

class Cours{
    
public:
    Cours();
    Cours(std::string nom, Enseignant* prof);
    
    std::string getNomCours();
    std::string getNomProfReferent();
    void creerDepot(std::string nomDepot, struct tm ouverture, struct tm fermeture);
    void deposer(int index, Etudiant* etud, std::string nomFichier);
    void inscrire(Etudiant* etud);
    bool estInscrit(Etudiant* etud);
    
    void afficherListeDepots();
    void afficherListeContenus();
    void afficherDepotsEffectues(int index);
    
    void setInscription(int nbMaxEtud, struct tm ouverture, struct tm fermeture);
    Depot* getDepot(int index);
    bool depotExiste(std::string nom);
    bool depotExiste(int index);
    void ajouterDuContenu(std::string leNom, std::string cheminAcces);
    bool contenuExiste(std::string nom);
    bool aAcces(Etudiant* etud);
    void supp();
    
protected:
    std::string nomCours;
    Enseignant* profReferent;
    Inscription* inscription;
    std::vector<Depot*> listeDepot;
    std::vector<struct contenu> listeContenu;
};

#endif
