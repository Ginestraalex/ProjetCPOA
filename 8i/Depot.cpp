#include "Depot.h"


Depot::Depot(){

}

Depot::Depot(std::string nomDuDepot, struct tm dOuverture, struct tm dFermeture){
    nomDepot = nomDuDepot;

    dateOuverture.tm_sec = dOuverture.tm_sec;
    dateOuverture.tm_min = dOuverture.tm_min;
    dateOuverture.tm_hour = dOuverture.tm_hour;
    dateOuverture.tm_mday = dOuverture.tm_mday;
    dateOuverture.tm_mon = dOuverture.tm_mon;
    dateOuverture.tm_year = dOuverture.tm_year;
    
    dateFermeture.tm_sec = dFermeture.tm_sec;
    dateFermeture.tm_min = dFermeture.tm_min;
    dateFermeture.tm_hour = dFermeture.tm_hour;
    dateFermeture.tm_mday = dFermeture.tm_mday;
    dateFermeture.tm_mon = dFermeture.tm_mon;
    dateFermeture.tm_year = dFermeture.tm_year;
}

void Depot::ajouterDepot(std::string nomDuFichierRendu, Etudiant* etud){
    if(estEnAvanceOuRetard()){
        std::cout << "Le travail est en retard, il n'a donc pas ete depose" << std::endl;
    }
    else{
        struct depotEtudiant monDepot;
        monDepot.etudiant = etud;
        monDepot.nomFichier = nomDuFichierRendu;
        monDepot.note = "non note";
        listeDepots.push_back(monDepot);
        std::cout << "Le travail a bien ete depose" << std::endl;
    }
}

void Depot::afficherLesDepots(){
    int i, taille;
    taille = listeDepots.size();
    std::cout << "Liste des depots de " + nomDepot << std::endl;
    for(i = 0 ; i < taille ; i++){
        std::cout << to_string(i) +": " + listeDepots[i].etudiant->getNom() << " "+listeDepots[i].nomFichier << std::endl;
    }
}

bool Depot::estLeNom(std::string nom){
    return !nomDepot.compare(nom);
}

bool Depot::estEnAvanceOuRetard(){
    double second;
    second = difftime(time(NULL), mktime(&dateFermeture));
    if(second < 0)
    {
        second = difftime(time(NULL), mktime(&dateOuverture));
        if(second > 0){
            return false;
        }
    }
    return true;
}

std::string Depot::toString(){
    return nomDepot;
}

void Depot::noter(int index, std::string note){
    if(index < listeDepots.size() && index >= 0){
        listeDepots[index].note = note;
        std::cout << "Le depot a bien ete note" << std::endl;
    }
    else{
        std::cout << "Erreur dans la notation du depot" << std::endl;
    }
}



