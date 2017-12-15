#include "Interface.h"


Interface::Interface(){

}

Interface::Interface(System* monSysteme){
  monSys = monSysteme;
}
    

Interface::Interface(std::string nomFichier){
  monSys = new System(nomFichier);
}


bool Interface::pageDeConnexion(){
    std::cout << std::endl << " === Bienvenue sur Arche ===" << std::endl;
    std::cout << "Connectez vous pour acceder au site" << std::endl;
    char c('n');
    while(c != 'O' && c != 'o'){
        connexion();
        std::cout << "Voulez-vous quitter ? (O = oui, N = non) " << std::endl;
        std::cin >> c;
    }
    std::cout << "Au revoir !";
    return false;
}

void Interface::connexion(){
    char c;
    char id[20];
    char mdp[20];
    std::cout << "Etes-vous un Administateur (A), un Enseignant (T), ou un Etudiant (S)" << std::endl;
    std::cin >> c;
    while(c != 'A' && c != 'a' && c != 'T' && c != 't' && c != 'S' && c != 's'){
        std::cout << "Erreur: entrez A ou T ou S" << std::endl;
    }
    std::cout << "Entrez votre identifiant:" << std::endl;
    std::cin >> id;
    std::cout << "Entrez votre mot de passe:" << std::endl;
    std::cin >> mdp;
    std::string strID(id);
    std::string strMDP(mdp);
    if(c == 'a' || c == 'A'){
        if(monSys->connexion("ADMINISTRATEUR", strID, strMDP)){
            homepageAdministrateur();
        }
        else{
            std::cout << "erreur lors de la connexion" << std::endl;
        }
    }
    else if (c == 'T' || c == 't'){
        if(monSys->connexion("ENSEIGNANT", strID, strMDP)){
            homepageEnseignant();
        }
        else{
            std::cout << "erreur lors de la connexion" << std::endl;
        }
    }
    else{
        if(monSys->connexion("ETUDIANT", strID, strMDP)){
            homepageEtudiant();
        }
        else{
            std::cout << "erreur lors de la connexion" << std::endl;
        }
    }
}


void Interface::homepageAdministrateur(){
    
}


void Interface::homepageEnseignant(){
    
}


void Interface::homepageEtudiant(){
    
}


void Interface::sauv(){
  monSys->sauvegarderIdentifiants();
}

void Interface::supp(){
  monSys->supp();
  delete monSys;
}

int main(){
  char c;
  Interface* inter;
  std::cout << "Bienvenue, voulez-vous utiliser un fichier d'identifiant a vous ?(y or n)" << std::endl;
  std::cin >> c;
  while((c != 'y' && c != 'Y') && (c != 'n' && c != 'N')){
    std::cout << "Erreur: oui (y) ou non (n)" << std::endl;
    std::cin >> c;
  }
  if(c == 'y' || c == 'Y'){
    char tabChar[30];
    std::cout << "Saisissez le nom de votre fichier:" << std::endl;
    std::cin >> tabChar;
    std::string str(tabChar);
    inter = new Interface(str);
    inter->sauv();
  }
  else{
    inter = new Interface("listeValide.txt");  
    inter->sauv();
  }
  

    inter->supp();
    delete inter;
  return 0;
}
