#ifndef DEF_ADMINISTRATEUR
#define DEF_ADMINISTRATEUR

#include <iostream>
#include "Utilisateur.h"

class Administrateur : public Utilisateur{

public:
    Administrateur(std::string name, std::string identifier, std::string password);
};
#endif
