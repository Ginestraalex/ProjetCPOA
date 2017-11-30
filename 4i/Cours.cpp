#include "Cours.h"


Cours::Cours(){
    
}

Cours::Cours(std::string nom, std::string nomProf){
    nomCours = nom;
    nomProfReferent = nomProf;
}
    
std::string Cours::getNomCours(){
    return nomCours;
}

std::string Cours::getNomProfReferent(){
    return nomProfReferent;
}

/*int main(){
    Cours c("MonCours","LeNomDuProf");
    std::cout << "Le cours intitule : " << c.getNomCours() << " a pour prof referent : " << c.getNomProfReferent() << std::endl;
    return 0;
}*/

