#ifndef DEF_ADMINISTRATEUR
#define DEF_ADMINISTRATEUR

#include "Utilisateur.h"

class Administrateur : public Utilisateur{

public:
    Administrateur();
    Administrateur(std::string name, std::string identifier, std::string password);
    
    bool connexion(std::string fonction, std::string Id, std::string mdp);
    std::string getStringSauvegarde();
};
#endif
