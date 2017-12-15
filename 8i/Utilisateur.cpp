#include "Utilisateur.h"

Utilisateur::Utilisateur(){
    
}

Utilisateur::Utilisateur(std::string name, std::string identifier, std::string password){
    nom = name;
    id = identifier;
    motDePasse = password;
}
  
std::string Utilisateur::getNom(){
    return nom;
}

bool Utilisateur::estLID(std::string str){
    return !id.compare(str);
}

bool Utilisateur::estLeMDP(std::string str){
    return !motDePasse.compare(str);
}

bool Utilisateur::connexion(std::string fonction, std::string Id, std::string mdp){
    if(!id.compare(Id) && !motDePasse.compare(mdp) && !fonction.compare("UTILISATEUR")){
        return true;
    }
    return false;
}

std::string Utilisateur::getStringSauvegarde() {
  return "UTILISATEUR " +nom + " " + id + " " + motDePasse;
}


std::string Utilisateur::toString(){
    return "nom: " + nom + " id: " + id + " mdp: " + motDePasse;
}

/*int main(){
  Utilisateur util("monNom", "monID", "123");
  std::cout << "mon nom est " << util.getNom() << std::endl;
  std::cout << "l\'identifiant est identif ? " << util.estLID("identif") << std::endl;
  std::cout << "l\'identifiant est monID ? " << util.estLID("monID") << std::endl;
  std::cout << "le mot de passe est 123 ? " << util.estLeMDP("123") << std::endl;
  std::cout << "le mot de passe est 456 ? " << util.estLeMDP("456") << std::endl;
  return 0;
}*/
