#ifndef DEF_ENSEIGNANT
#define DEF_ENSEIGNANT

#include <iostream>
#include "Utilisateur.h"

class Enseignant : public Utilisateur{
    
public:
    Enseignant(std::string name, std::string identifier, std::string password);

};
#endif
