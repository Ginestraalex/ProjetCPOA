#ifndef DEF_ENSEIGNANT
#define DEF_ENSEIGNANT

#include "Utilisateur.cpp"


class Enseignant : public Utilisateur{
    
public:
    Enseignant();
    Enseignant(std::string name, std::string identifier, std::string password);
    
    std::string getStringSauvegarde();
    bool connexion(std::string fonction, std::string Id, std::string mdp);

};
#endif
