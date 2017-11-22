#include <iostream>
#include <string>

class Utilisateur{

public:

  Utilisateur(std::string name, std::string identifier, std::string password){
    nom = name;
    id = identifier;
    motDePasse = password;
    
  }
  
  std::string getNom(){
    return nom;
  }

  bool estLID(std::string str)
  {
    return !id.compare(str);
  }

  bool estLeMDP(std::string str){
    return !motDePasse.compare(str);
  }

private:
  std::string nom;
  std::string id;
  std::string motDePasse;
};

int main(){
  Utilisateur util("monNom", "monID", "123");
  std::cout << "mon nom est " << util.getNom() << std::endl;
  std::cout << "l\'identifiant est identif ? " << util.estLID("identif") << std::endl;
  std::cout << "l\'identifiant est monID ? " << util.estLID("monID") << std::endl;
  std::cout << "le mot de passe est 123 ? " << util.estLeMDP("123") << std::endl;
  std::cout << "le mot de passe est 456 ? " << util.estLeMDP("456") << std::endl;
  return 0;
}
