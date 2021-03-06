#include "PropositionDeCours.h"

PropositionDeCours::PropositionDeCours(){
    
}

PropositionDeCours::PropositionDeCours(std::string nom, Enseignant* prof){
    nomCours = nom;
    profReferent = prof;
}


std::string PropositionDeCours::getNomCours(){
    return nomCours;
}

std::string PropositionDeCours::getNomProfReferent(){
    return profReferent->getNom();
}

Enseignant* PropositionDeCours::getProfReferent(){
    return profReferent;
}

bool PropositionDeCours::estLeNom(std::string nom){
    return !nomCours.compare(nom);
}
