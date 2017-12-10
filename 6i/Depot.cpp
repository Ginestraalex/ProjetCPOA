#include "Depot.h"
#include <sstream>


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
    if(estEnRetard()){
        std::cout << "Le travail est en retard, il n'a donc pas ete depose" << std::endl;
    }
    else{
        struct depotEtudiant monDepot;
        monDepot.etudiant = etud;
        monDepot.nomFichier = nomDuFichierRendu;
        listeDepots.push_back(monDepot);
    }
}

bool Depot::estEnRetard(){
    double second;
    time_t timer;
    time(&timer);
    second = difftime(timer, mktime(&dateFermeture));
    if(second > 0)
    {
        return false;
    }
    second = difftime(timer, mktime(&dateOuverture));
    if(second < 0){
        return false;
    }
    return true;
}

std::string Depot::toString(){
    return nomDepot;
}




template <typename T> std::string to_string(T value){
    //create an output string stream
    std::ostringstream os;
    
    //throw the value into the string stream
    os << value;
    
    //convert the string stream into a string and return
    return os.str();
}
