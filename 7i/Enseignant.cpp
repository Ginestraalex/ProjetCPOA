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

