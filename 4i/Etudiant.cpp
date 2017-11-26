#include <iostream>
#include "Etudiant.h"

Etudiant::Etudiant(std::string name, std::string identifier, std::string password){
    nom = name;
    id = identifier;
    motDePasse = password;
}
