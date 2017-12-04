#ifndef DEF_ENSEIGNANT
#define DEF_ENSEIGNANT

#include "Utilisateur.cpp"


class Enseignant : public Utilisateur{
    
public:
    Enseignant();
    Enseignant(std::string name, std::string identifier, std::string password);

};
#endif
