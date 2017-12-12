#include "Interface.h"


Interface::Interface(){

}

Interface::Interface(System* monSysteme){
  monSys = monSysteme;
}
    

Interface::Interface(std::string nomFichier){
  monSys = new System(nomFichier);
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
    char tabChar[50];
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
  return 0;
}
