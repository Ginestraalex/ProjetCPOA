ifndef DEF_COURS
#define DEF_COURS
#include "Enseignant.cpp"
#include "Etudiant.cpp"
#include <iostream>
#include <string>
#include <time.h>
#include <ctime>

class Depot{
    
public:
    Depot();
    Depot(std::string,std::int,std::int);
    
    
protected:
    std::string nomDepot;
    std::struct tm DateOuverture;
    std::struct tm DateFermeture;
    
};

#endif
