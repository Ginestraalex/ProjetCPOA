#ifndef DEF_INSCRIPTION
#define DEF_INSCRIPTION
#include "Depot.cpp"
#include <iostream>
#include <string>

class Inscription{
    
public:
    Inscription();
    Inscription(int nbMaxEtud, struct tm ouvertureInsc, struct tm fermetureInsc);
    
    void inscrire(Etudiant* etud);
    bool estInscrit(Etudiant* etud);
    
protected:
    int nombreMaximumEtudiant;
    struct tm ouvertureInscription;
    struct tm fermetureInscription;
    std::vector<Etudiant*> listeEtudiants;
};
#endif
