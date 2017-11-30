#ifndef DEF_COURS
#define DEF_COURS

#include <iostream>
#include <string>

class Cours{
    
public:
    Cours();
    Cours(std::string nom, std::string nomProf);
    
    std::string getNomCours();
    std::string getNomProfReferent();
    
protected:
    std::string nomCours;
    std::string nomProfReferent;
};

#endif
