#include "Depot.h"

Depot::Depot(){

}

Depot::Depot(std::string nomDuDepot, struct tm dOuverture, struct tm dFermeture){
    nomDepot = nomDuDepot;

    dateOuverture.tm_mday = dOuverture.tm_mday;
    dateOuverture.tm_mon = dOuverture.tm_mon;
    dateOuverture.tm_year = dOuverture.tm_year;
    
    dateFermeture.tm_mday = dFermeture.tm_mday;
    dateFermeture.tm_mon = dFermeture.tm_mon;
    dateFermeture.tm_year = dFermeture.tm_year;
}

void Depot::ajouterDepot(std::string nomDuFichierRendu, Etudiant* etud){
    struct depotEtudiant monDepot;
    monDepot.etudiant = etud;
    monDepot.nomFichier = nomDuFichierRendu;
    listeDepots.push_back(monDepot);
}
