#include "Etudiant.h"

Etudiant::Etudiant(){
    
}

Etudiant::Etudiant(std::string name, std::string identifier, std::string password){
    nom = name;
    id = identifier;
    motDePasse = password;
}


std::string Etudiant::getStringSauvegarde(){
    return "ETUDIANT " +nom + " " + id + " " + motDePasse;
}


bool Etudiant::connexion(std::string fonction, std::string Id, std::string mdp){
    if(!id.compare(Id) && !motDePasse.compare(mdp) && !fonction.compare("ETUDIANT")){
        return true;
    }
    return false;
}
