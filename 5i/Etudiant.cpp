#include "Etudiant.h"

Etudiant::Etudiant(){
    
}

Etudiant::Etudiant(std::string name, std::string identifier, std::string password){
    nom = name;
    id = identifier;
    motDePasse = password;
}
