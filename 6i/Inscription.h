#ifndef DEF_INSCRIPTION
#define DEF_INSCRIPTION
#include <iostream>
#include <string>
#include <ctime>
#include <time.h>

class Inscription{
    
public:
    Inscription();
    Inscription(int nbMaxEtud, tm* dateD, tm* dateF);
    
    bool peutDeposer();
    std::string toString();
    
protected:
    int nbMaxEtudiant;
    tm* dateDebut;
    tm* dateFin;
};
#endif
