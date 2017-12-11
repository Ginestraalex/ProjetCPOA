#ifndef DEF_ADMINISTRATEUR
#define DEF_ADMINISTRATEUR

#include "Utilisateur.h"

class Administrateur : public Utilisateur{

public:
    Administrateur();
    Administrateur(std::string name, std::string identifier, std::string password);
    
    std::string getStringSauvegarde();
};
#endif
