#ifndef DEF_PROPOSITIONDECOURS
#define DEF_PROPOSITIONDECOURS

#include "Cours.cpp"

class PropositionDeCours{
    
public:
    PropositionDeCours();
    PropositionDeCours(std::string nom, Enseignant* nomProf);
    
    std::string getNomCours();
    std::string getNomProfReferent();
    
protected:
    std::string nomCours;
    Enseignant* profReferent;
};
#endif
