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


