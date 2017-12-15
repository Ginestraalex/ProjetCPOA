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

bool Administrateur::connexion(std::string fonction, std::string Id, std::string mdp){
    if(!id.compare(Id) && !motDePasse.compare(mdp) && !fonction.compare("ADMINISTRATEUR")){
        return true;
    }
    return false;
}

