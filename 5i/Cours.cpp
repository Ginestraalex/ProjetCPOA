#include "Cours.h"


Cours::Cours(){
    
}

Cours::Cours(std::string nom, Enseignant* prof){
    nomCours = nom;
    profReferent = prof;
}
    
std::string Cours::getNomCours(){
    return nomCours;
}

std::string Cours::getNomProfReferent(){
    return profReferent->getNom();
}

/*int main(){
    Cours c("MonCours",new Enseignant("NomEnseignant","idEnseignant","mdpEnseignant"));
    std::cout << "Le cours intitule : " << c.getNomCours() << " a pour prof referent : " << c.getNomProfReferent() << std::endl;
    return 0;
}*/

