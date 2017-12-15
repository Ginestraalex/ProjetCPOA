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
    std::cout << "Au revoir !" << std::endl;
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
        std::cin >> c;
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
    std::cout << "Page administrateur: " << std::endl << "Bienvenue " + monSys->getNomUtilisateurCourrant() + ","<< std::endl;
    char c('z');
    int i;
    while(c != 'q' && c != 'Q'){
        std::cout << "Que voulez-vous faire ?" << std::endl << "Afficher la liste des propositions de cours (L)" << std::endl << "Accepter des propositions de cours (A)" << std::endl << "Vous deconnecter (Q)" << std::endl;
        std::cin >> c;
        if(c != 'A' && c != 'a' && c != 'q' && c != 'Q' && c != 'l' && c != 'L'){
            std::cout << "erreur dans la selection." << std::endl << "que voulez-vous faire ?" << std::endl << "Afficher la liste des propositions de cours (L)" << std::endl << "Accepter des propositions de cours (A)" << std::endl << "Vous deconnecter (Q)" << std::endl;
        }
        else if(c == 'l' || c == 'L'){
            monSys->afficherListePropositionsCours();
        }
        else if(c == 'a' || c == 'A'){
            std::cout << "Quel est le numero de la proposition de cours que vous souhaitez accepter ?" << std::endl;
            std::cin >> i;
            monSys->accepterPropositionCours(i);
        }
    }
    std::cout << "Au revoir!" << std::endl;
}


void Interface::homepageEnseignant(){
    std::cout << "page Ens " << std::endl;
}


void Interface::homepageEtudiant(){
    std::cout << "page Etu " << std::endl;
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
  }
  else{
    inter = new Interface("listeValide.txt");  
  }
    inter->pageDeConnexion();
    inter->supp();
    delete inter;
  return 0;
}
