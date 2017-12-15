#ifndef DEF_UTILISATEUR
#define DEF_UTILISATEUR
#include <iostream>
#include <string>

class Utilisateur{
    
public:
    Utilisateur();
    Utilisateur(std::string name, std::string identifier, std::string password);
    
    std::string getNom();
    bool estLID(std::string str);
    bool estLeMDP(std::string str);
    virtual bool connexion(std::string fonction, std::string Id, std::string mdp);
    virtual std::string getStringSauvegarde();
    std::string toString();
    
protected:
    std::string nom;
    std::string id;
    std::string motDePasse;
};
#endif
