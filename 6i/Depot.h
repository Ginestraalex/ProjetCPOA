#ifndef DEF_DEPOT
#define DEF_DEPOT
#include "Enseignant.cpp"
#include "Etudiant.cpp"
#include <iostream>
#include <string>
#include <time.h>
#include <ctime>

struct depotEtudiant{
    Etudiant* etudiant;
    std::string nomFichier;
};

class Depot{
    
public:
    Depot();
    Depot(std::string nomDuDepot, struct tm DOuverture, struct tm DFermeture);
    
    void ajouterDepot(std::string nomFichier, Etudiant* etud);
    
protected:
    std::string nomDepot;
    struct tm dateOuverture;
    struct tm dateFermeture;
    std::vector<struct depotEtudiant> listeDepots;
};
#endif
