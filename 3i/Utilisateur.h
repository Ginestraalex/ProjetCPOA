#ifndef DEF_UTILISATEUR
#define DEF_UTILISATEUR

#include <string>

class Utilisateur{
    
public:
    Utilisateur();
    Utilisateur(std::string name, std::string identifier, std::string password);
    
    std::string getNom();
    bool estLID(std::string str);
    bool estLeMDP(std::string str);
    
protected:
    std::string nom;
    std::string id;
    std::string motDePasse;
};

#endif
