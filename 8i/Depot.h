#ifndef DEF_DEPOT
#define DEF_DEPOT
#include "Administrateur.cpp"
#include "Enseignant.cpp"
#include "Etudiant.cpp"
#include "fonction.cpp"
#include <time.h>
#include <ctime>

struct depotEtudiant{
    Etudiant* etudiant;
    std::string nomFichier;
    std::string note;
};

class Depot{
    
public:
    Depot();
    Depot(std::string nomDuDepot, struct tm DOuverture, struct tm DFermeture);
    
    bool estLeNom(std::string nom);
    bool estEnAvanceOuRetard();
    void ajouterDepot(std::string nomFichier, Etudiant* etud);
    void afficherLesDepots();
    void noter(int index, std::string note);
    std::string toString();
    
protected:
    std::string nomDepot;
    struct tm dateOuverture;
    struct tm dateFermeture;
    std::vector<struct depotEtudiant> listeDepots;
};
#endif
