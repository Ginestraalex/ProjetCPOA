#include "Enseignant.h"

Enseignant::Enseignant(){
    
}

Enseignant::Enseignant(std::string name, std::string identifier, std::string password){
    nom = name;
    id = identifier;
    motDePasse = password;
}

std::string Enseignant::getStringSauvegarde(){
    return "ENSEIGNANT " +nom + " " + id + " " + motDePasse;
}

bool Enseignant::connexion(std::string fonction, std::string Id, std::string mdp){
    if(!id.compare(Id) && !motDePasse.compare(mdp) && !fonction.compare("ENSEIGNANT")){
        return true;
    }
    return false;
}
