#ifndef DEF_UTILISATEUR
#define DEF_UTILISATEUR

#include <string>

class Utilisateur{

 public:
  std::string getNom();
  bool estLID(std::string str);
  bool estLeMDP(std::string str);
 
 private:
  std::string nom;
  std::string id;
  std::string motDePasse;
};

#endif
