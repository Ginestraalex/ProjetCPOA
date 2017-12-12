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

int main(){
  char c;
  std::cout << "Bienvenue, voulez-vous utiliser un fichier de connexion a vous ?(y or n)" << std::endl;
  std::cin >> c;
  while((c != 'y' && c != 'Y') && (c != 'n' && c != 'N')){
    std::cout << "Erreur: oui (y) ou non (n)" << std::endl;
    std::cin >> c;
  }
  if(c == 'y' || c == 'Y'){
    
  }
  else{
  Interface inter("listeValide.txt");  
  inter.sauv();
  }
  return 0;
}
