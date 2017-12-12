#include "Administrateur.h"

Administrateur::Administrateur(){
    
}

Administrateur::Administrateur(std::string name, std::string identifier, std::string password){
    nom = name;
    id = identifier;
    motDePasse = password;
}

std::string Administrateur::getStringSauvegarde(){
    return "ADMINISTRATEUR " +nom + " " + id + " " + motDePasse;
}

