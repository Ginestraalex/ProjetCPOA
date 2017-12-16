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
    std::cout << "Etes-vous un Administateur (A), un Enseignant (T), un Etudiant (S) ou entrez (Q) pour quiter" << std::endl;
    std::cin >> c;
    while(c != 'A' && c != 'a' && c != 'T' && c != 't' && c != 'S' && c != 's' && c != 'q' && c != 'Q'){
        std::cout << "Erreur: entrez A ou T ou S ou Q" << std::endl;
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
    else if(c == 'S' || c == 's'){
        if(monSys->connexion("ETUDIANT", strID, strMDP)){
            homepageEtudiant();
        }
        else{
            std::cout << "erreur lors de la connexion" << std::endl;
        }
    }
    else{
        std::cout << std::endl << "Au revoir" << std::endl;
    }
}


void Interface::homepageAdministrateur(){
    std::cout << "Page administrateur: " << std::endl << "Bienvenue " + monSys->getNomUtilisateurCourrant() + ","<< std::endl;
    char c('z');
    int i;
    while(c != 'q' && c != 'Q'){
        std::cout << "Que voulez-vous faire ?" << std::endl << "Afficher la liste des propositions de cours (L)" << std::endl << "Accepter des propositions de cours (A)" << std::endl << "Vous deconnecter (Q)" << std::endl;
        std::cin >> c;
        if(c == 'l' || c == 'L'){
            monSys->afficherListePropositionsCours();
        }
        else if(c == 'a' || c == 'A'){
            std::cout << "Quel est le numero de la proposition de cours que vous souhaitez accepter ?" << std::endl;
            std::cin >> i;
            monSys->accepterPropositionCours(i);
        }
        else if(c == 'q' || c == 'Q'){
        }
        else{
            std::cout << std::endl << "erreur dans la selection." << std::endl;
        }
    }
    std::cout << "Au revoir!" << std::endl;
}


void Interface::homepageEnseignant(){
    std::cout << "Page enseignant: " << std::endl << "Bienvenue " + monSys->getNomUtilisateurCourrant() + ","<< std::endl;
    char c('z');
    int i;
    while(c != 'q' && c != 'Q'){
        std::cout << "Que voulez-vous faire ?" << std::endl << "Afficher la liste de vos cours (L)" << std::endl << "Accéder à un cours (A)"  << std::endl << "Proposer un nouveau cours (P)" << std::endl << "Vous deconnecter (Q)" << std::endl;
        std::cin >> c;
        if(c == 'l' || c == 'L'){
            monSys->afficherListeCoursUtilisateurCourrant();
        }
        else if(c == 'a' || c == 'A'){
            std::cout << "Quel est le numero du cours auqel vous souhaitez acceder ?" << std::endl;
            std::cin >> i;
            editerCours(monSys->getCours(i));
        }
        else if(c == 'p' || c == 'P'){
            proposerCours((Enseignant*)monSys->getUtilisateurCourrant());
        }
        else if(c == 'q' || c == 'Q'){
        }
        else{
            std::cout << std::endl << "erreur dans la selection." << std::endl ;
        }
    }
    std::cout << "Au revoir!" << std::endl;
}


void Interface::homepageEtudiant(){
    std::cout << "Page etudiant: " << std::endl << "Bienvenue " + monSys->getNomUtilisateurCourrant() + ","<< std::endl;
    char c('z');
    char str[20];
    int i;
    while(c != 'q' && c != 'Q'){
        std::cout << "Que voulez-vous faire ?" << std::endl << "Afficher la liste de vos cours (L)" << std::endl << "Acceder a un de vos cours (A)"  << std::endl << "Afficher la liste de tous les cours (T)" << std::endl << "S'inscrire a un nouveau cours (S)" << std::endl << "Vous deconnecter (Q)" << std::endl;
        std::cin >> c;
        if(c == 'l' || c == 'L'){
            monSys->afficherListeCoursUtilisateurCourrant();
        }
        else if(c == 'a' || c == 'A'){
            std::cout << "Quel est le numero de la proposition de cours que vous souhaitez acceder ?" << std::endl;
            std::cin >> i;
            accederCours(monSys->getCours(i), (Etudiant*) monSys->getUtilisateurCourrant());
        }
        else if(c == 's' || c == 'S'){
            std::cout << "Quel est le nom du cours auquel vous voulez vous inscrire ?" << std::endl;
            std::cin >> str;
            monSys->inscrire(monSys->getCours(str));
        }
        else if(c == 't' || c == 'T'){
            monSys->afficherListeCours();
        }
        else if(c == 'q' || c == 'Q'){
        }
        else{
            std::cout << std::endl << "erreur dans la selection." << std::endl;
        }
    }
    std::cout << "Au revoir!" << std::endl;
}


void Interface::editerCours(Cours* monCours){
    char c('z');
    int numDepot;
    while(c != 'q' && c != 'Q'){
        std::cout << "Que voulez vous faire sur le cours " + monCours->getNomCours() +":" << std::endl << "Ajouter du contenu (A)" << std::endl << "Creer un depot (C)" << std::endl << "Noter un depot (N)" << std::endl << "Definir les parametres d'inscription (P)" << std::endl << "Quitter l'editeur de cours (Q)" << std::endl;
        std::cin >> c;
        if(c == 'a' || c != 'A'){
            ajouterContenu(monCours);
        }
        else if(c == 'C' || c == 'c'){
            creerDepot(monCours);
        }
        else if(c == 'n' || c == 'N'){
            std::cout << "Quel est le numero du depot que vous desirez noter ?" << std::endl;
            std::cin >> numDepot;
            noterDepot(monCours->getDepot(numDepot));
        }
        else if(c == 'p' || c == 'P'){
            setInscription(monCours);
        }
        else if(c == 'q' || c == 'Q'){
        }
        else{
            std::cout << std::endl << "Erreur. ";
        }
    }
}


void Interface::accederCours(Cours* monCours, Etudiant* etud){
    char c('z');
    int index;
    if(monCours->aAcces(etud)){
        while(c != 'q' && c != 'Q'){
            std::cout << "Que voulez vous faire sur le cours " + monCours->getNomCours() +":" << std::endl << "Avoir la liste des contenus (C)" << std::endl << "Avoir la liste des depots (D)" << std::endl << "Rendre un travail pour un depot (R)" << std::endl << "Quitter l'editeur de cours (Q)" << std::endl;
            std::cin >> c;
            if(c == 'd' || c == 'D'){
                monCours->afficherListeDepots();
            }
            else if(c == 'c' || c == 'C'){
                monCours->afficherListeContenus();
            }
            else if(c == 'R' || c == 'r'){
                std::cout << "Quel est le numero du depot auquel vous voulez acceder ?" << std::endl;
                std::cin >> index;
                if(monCours->depotExiste(index)){
                    rendreTravail(monCours->getDepot(index), etud);
                }
            }
            else if(c == 'q' || c == 'Q'){
            }
            else{
                std::cout << std::endl << "Erreur. ";
            }
        }
    }
    else{
        std::cout << "Erreur. Vous n'avez pas acces a ce cours" << std::endl;
    }
}

void Interface::rendreTravail(Depot* leDepot, Etudiant* etud){
    char cFichier[30];
    std::cout << "Donner le chemin d'acces au fichier" << std::endl;
    std::cin >> cFichier;
    leDepot->ajouterDepot(cFichier, etud);
}



void Interface::ajouterContenu(Cours* monCours){
    char cNom[20];
    char cChemin[30];
    std::cout << "Quel sera le nom de votre contenu ?" << std::endl;
    std::cin >> cNom;
    std::cout << "Quel est le chemin d'acces au document ?" << std::endl;
    std::cin >> cChemin;
    monCours->ajouterDuContenu(cNom, cChemin);
}


void Interface::proposerCours(Enseignant* ensei){
    char cNomCours[20];
    std::cout << "Quel sera le nom de votre cours ?" << std::endl;
    std::cin >> cNomCours;
    if(monSys->existePropositionCours(cNomCours)){
        std::cout << "Le nom choisit pour le cours existe deja" << std::endl;
    }
    else{
        monSys->proposerCours(cNomCours,(Enseignant*)monSys->getUtilisateurCourrant());
        std::cout << "La proposition de cours est faite" << std::endl;
    }
}

void Interface::noterDepot(Depot* leDepot){
    char c('z');
    int numDep;
    char cNote[5];
    std::cout << "Notation du depot: " + leDepot->toString() << std::endl;
    while(c != 'q' && c != 'Q'){
        std::cout << "Que voulez-vous faire?" << std::endl << "Afficher la liste des depots effectues (A)" << std::endl << "Noter un depot (N)" << std::endl;
        std::cin >> c;
        if(c == 'A' || c == 'a'){
            leDepot->afficherLesDepots();
        }
        else if(c == 'N' || c == 'n'){
            std::cout << "Quel est le numero du depot de l'etudiant que vous souhaitez noter ?" << std::endl;
            std::cin >> numDep;
            std::cout << "Quelle note attribuez-vous au depot de l'etudiant ?" << std::endl;
            std::cin >> cNote;
            leDepot->noter(numDep, cNote);
        }
        else if(c == 'q' || c == 'Q'){
        }
        else{
            std::cout << "Erreur dans la selection. ";
        }
    }
}

void Interface::setInscription(Cours* cours){
    int nbEtud;
    struct tm ouv, ferm;
    std::cout << "Quel est le nombre maximum d'etuidant pouvait assister au cours" << std::endl;
    std::cin >> nbEtud;
    std::cout << "ouverture des inscriptions:" << "annee ?" << std::endl;
    std::cin >> ouv.tm_year;
    ouv.tm_year -= 1900;
    std::cout << "mois ? (chiffre: janvier = 0 , decembre = 11)" << std::endl;
    std::cin >> ouv.tm_mon;
    std::cout << "jour ?" << std::endl;
    std::cin >> ouv.tm_mday;
    std::cout << "heure ?" << std::endl;
    std::cin >> ouv.tm_hour;
    std::cout << "minute ?" << std::endl;
    std::cin >> ouv.tm_min;
    ouv.tm_sec = 0;
    
    std::cout << "fermeture des inscriptions:" << "annee ?" << std::endl;
    std::cin >> ferm.tm_year;
    ferm.tm_year -= 1900;
    std::cout << "mois ? (chiffre: janvier = 0 , decembre = 11)" << std::endl;
    std::cin >> ferm.tm_mon;
    std::cout << "jour ?" << std::endl;
    std::cin >> ferm.tm_mday;
    std::cout << "heure ?" << std::endl;
    std::cin >> ferm.tm_hour;
    std::cout << "minute ?" << std::endl;
    std::cin >> ferm.tm_min;
    ferm.tm_sec = 0;
    cours->setInscription(nbEtud, ouv, ferm);
    
}

void Interface::creerDepot(Cours* monCours){
    char c[20];
    struct tm ouv, ferm;
    std::cout << "Quel nom voulez-vous donner a ce depot ?" << std::endl;
    std::cin >> c;
    if(monCours->depotExiste(c)){
        std::cout << "ouverture du depot:" << "annee ?" << std::endl;
        std::cin >> ouv.tm_year;
        ouv.tm_year -= 1900;
        std::cout << "mois ? (chiffre: janvier = 0 , decembre = 11)" << std::endl;
        std::cin >> ouv.tm_mon;
        std::cout << "jour ?" << std::endl;
        std::cin >> ouv.tm_mday;
        std::cout << "heure ?" << std::endl;
        std::cin >> ouv.tm_hour;
        std::cout << "minute ?" << std::endl;
        std::cin >> ouv.tm_min;
        ouv.tm_sec = 0;
        
        std::cout << "fermeture du depot:" << "annee ?" << std::endl;
        std::cin >> ferm.tm_year;
        ferm.tm_year -= 1900;
        std::cout << "mois ? (chiffre: janvier = 0 , decembre = 11)" << std::endl;
        std::cin >> ferm.tm_mon;
        std::cout << "jour ?" << std::endl;
        std::cin >> ferm.tm_mday;
        std::cout << "heure ?" << std::endl;
        std::cin >> ferm.tm_hour;
        std::cout << "minute ?" << std::endl;
        std::cin >> ferm.tm_min;
        ferm.tm_sec = 0;
        monCours->creerDepot(c, ouv, ferm);
        std::cout << "Le depot a bien ete cree" << std::endl;
    }
    else{
        std::cout << "Erreur, un depot portant ce nom existe deja" << std::endl;
    }
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
  while(c != 'y' && c != 'Y' && c != 'n' && c != 'N'){
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
