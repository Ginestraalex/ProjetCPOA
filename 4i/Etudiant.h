#ifndef DEF_ETUDIANT
#define DEF_ETUDIANT

#include <iostream>
#include "Utilisateur.h"

class Etudiant : public Utilisateur{
    
public:
    Etudiant(std::string name, std::string identifier, std::string password);
};
#endif
