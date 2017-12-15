#ifndef DEF_ETUDIANT
#define DEF_ETUDIANT

#include "Utilisateur.h"

class Etudiant : public Utilisateur{
    
public:
    Etudiant();
    Etudiant(std::string name, std::string identifier, std::string password);
    
    std::string getStringSauvegarde();
    bool connexion(std::string fonction, std::string Id, std::string mdp);

};
#endif
