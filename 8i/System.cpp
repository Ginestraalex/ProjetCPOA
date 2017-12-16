#include "System.h"

System::System(){

}


System::System(std::string nomFichier){
    std::string fonction, nom, id, mdp;
    std::ifstream monFlux(nomFichier.c_str());
    if(monFlux){ //teste  pour voir si le flux s'est ouvert
        while(monFlux >> fonction){
            if(monFlux >> nom && monFlux >> id && monFlux >> mdp){
                if(fonction.compare("AMDINISTRATEUR") == 0){
                    listeDesUtilisateurs.push_back(new Administrateur(nom, id, mdp));
                }
                else if(fonction.compare("ETUDIANT") == 0){
                    listeDesUtilisateurs.push_back(new Etudiant(nom, id, mdp));
                }
                else if(fonction.compare("ENSEIGNANT") == 0){
                    listeDesUtilisateurs.push_back(new Enseignant(nom, id, mdp));
                }
                else{
                    std::cout << "Les donnees sont corrompue" << std::endl;
                    exit(0);
                }
            }
            else{
                std::cout << "erreur dans la lecture des donees" << std::endl;
            }
        }
    }
    else{
        std::cout << "le flux àdu fichier a lire ne s\'est pas ouvert : ERREUR" << std::endl;
    }
}

System::System(Utilisateur *lesUtilisateurs[], int nbUtilisateurs){
    int i;
    for(i = 0 ; i < nbUtilisateurs ; i++){
      listeDesUtilisateurs.push_back(lesUtilisateurs[i]);
    }
}

bool System::connexion(std::string fonction, std::string id, std::string pwd){
    int i = 0;
    int taille = listeDesUtilisateurs.size();
    bool pasTrouve = true;
    while (i < taille && pasTrouve){
        if(listeDesUtilisateurs[i]->connexion(fonction, id, pwd)){
            pasTrouve = false;
            utilisateurCourrant = listeDesUtilisateurs[i];
            return true;
        }
        i++;
    }
    return false;
}

void System::ajouterCours(Cours *cours){
    listeDesCours.push_back(cours);
}

Cours* System::getCours(int index){
  if(index < (int)listeDesCours.size() && index >= 0)
    {
        return listeDesCours[index];
    }
    std::cout << "erreur lors de la recuperation du cours" << std::endl;
    exit(1);
}

Cours* System::getCours(std::string nomCours){
    int i = 0;
    int taille = listeDesCours.size();
    for(i = 0 ; i < taille ; i++){
        if(!listeDesCours[i]->getNomCours().compare(nomCours)){
            return listeDesCours[i];
        }
    }
    std::cout << "le cours demande n existe pas" << std::endl;
    Cours *coursTemp = new Cours();
    return coursTemp;
}

void System::proposerCours(std::string nomCours, Enseignant* enseignantReferent){
    bool trouve = false;
    int i = 0;
    int taille = listeDesCours.size();
    while(i < taille && !trouve){
        if(!listeDesCours[i]->getNomCours().compare(nomCours)){
            trouve = true;
        }
        i++;
    }
    if(trouve){
        std::cout << "Erreur ! Le nom choisi pour la proposition de cours existe deja." << std::endl;
    }
    else{
        listePropositionCours.push_back(new PropositionDeCours(nomCours, enseignantReferent));
    }
}


std::string System::getNomUtilisateurCourrant(){
    return utilisateurCourrant->getNom();
}

void System::afficherListeCours(){
    int i, taille;
    taille = listeDesCours.size();
    std::cout << "Liste des cours du systeme:" << std::endl;
    for(i = 0 ; i < taille ; i++){
        std::cout << to_string(i)+": COURS = " + listeDesCours[i]->getNomCours() + "   PROF REFERENT = " +listeDesCours[i]->getNomProfReferent() << std::endl;
    }
    std::cout << std::endl;
}

void System::afficherListeCoursUtilisateurCourrant(){
    int i, taille;
    taille = listeDesCours.size();
    std::cout << "Liste des vos cours:" << std::endl;
    for(i = 0 ; i < taille ; i++){
        if(!utilisateurCourrant->getNom().compare(listeDesCours[i]->getNomProfReferent())){
            std::cout << to_string(i)+": COURS = " +listeDesCours[i]->getNomCours() + "   PROF REFERENT = " +listeDesCours[i]->getNomProfReferent() << std::endl;
        }
    }
}

void System::afficherListePropositionsCours(){
    std::cout << "Liste des propositions de cours :" << std::endl;
    int i, tailleListe;
    tailleListe = listePropositionCours.size();
    for(i = 0 ; i < tailleListe ; i++){
        std::cout << to_string(i) + " COURS = " +listePropositionCours[i]->getNomCours() + " PROF REFERENT = "+listePropositionCours[i]->getNomProfReferent() << std::endl;
    }
    std::cout << std::endl;
}


void System::accepterPropositionCours(int index){
    if( index >= 0 && index < listePropositionCours.size()){
        ajouterCours(new Cours(listePropositionCours[index]->getNomCours(),listePropositionCours[index]->getProfReferent()));
        delete listePropositionCours[index];
        listePropositionCours.erase(listePropositionCours.begin() + index);
        
    }
    else{
        std::cout << "Erreur la valeur entree n'est pas valide." << std::endl;
    }
}

void System::inscrire(Cours* leCours){
    if(!leCours->estInscrit((Etudiant*)utilisateurCourrant)){
        leCours->inscrire((Etudiant*)utilisateurCourrant);
    }
    else{
        std::cout << "L'etudiant est deja sur la liste d'inscription de ce cours" << std::endl;
    }
}

void System::sauvegarderIdentifiants(){
  int i, taille;
  std::string strNomFichier("NouvelleListeID.txt");
  taille = listeDesUtilisateurs.size();
  std::ifstream fichier(strNomFichier.c_str());
  if(fichier){   // test si le fichier existe => ajout a la fin de ce fichier
    fichier.close();
    std::ofstream fichierSortie("NouvelleListeID.txt",std::ios::app);
    if(fichierSortie){
      for( i = 0 ; i < taille ; i++){
	fichierSortie << listeDesUtilisateurs[i]->getStringSauvegarde() << std::endl;
      }
      fichierSortie.close();
    }
    else{
      std::cout << "erreur dans l ouverture du fichier en ecriture" << std::endl;
    }
  }
  else{
    std::ofstream fichierSortie("NouvelleListeID.txt",std::ios::out);
    if(fichierSortie){
      for( i = 0 ; i < taille ; i++){
	fichierSortie << listeDesUtilisateurs[i]->getStringSauvegarde() << std::endl;
      }
      fichierSortie.close();
    }
    else{
      std::cout << "erreur dans l ouverture du fichier en ecriture" << std::endl;
    }
  }
  
}


void System::supp(){
    int i;
    int taille = listeDesUtilisateurs.size();
    for( i = 0 ; i < taille ; i++){
        delete listeDesUtilisateurs[i];
    }
    taille = listeDesCours.size();
    for( i = 0 ; i < taille ; i++){
        listeDesCours[i]->supp();
        delete listeDesCours[i];
    }
    taille = listePropositionCours.size();
    for( i = 0 ; i < taille ; i++){
        delete listePropositionCours[i];
    }
}

/*
int main(){
    std::cout << "===Test numero 1 ===" << std::endl;
    int i;
    Utilisateur *lesUtil[3];
    lesUtil[0] = new Utilisateur("nom1","id1","mdp1");
    lesUtil[1] = new Utilisateur("nom2","id2","mdp2");
    lesUtil[2] = new Utilisateur("nom3","id3","mdp3");
    for(i = 0 ; i < 3 ; i++){
        std::cout << lesUtil[i]->toString() << std::endl;
    }
    System *monSys = new System(lesUtil, 3);
    monSys->proposerCours("Reseau", new Enseignant("Duflot","idProf","mdpProf"));
    monSys->afficherListeCours();
    monSys->afficherListePropositionsCours();
    std::cout << "----validation du cours----" << std::endl;
    monSys->accepterPropositionCours(0);
    monSys->afficherListeCours();
    monSys->afficherListePropositionsCours();
    struct tm ouv, ferm;
    ouv.tm_sec = 0;
    ouv.tm_min = 0;
    ouv.tm_hour = 0;
    ouv.tm_mday = 1;
    ouv.tm_mon = 11;
    ouv.tm_year = 117;
    
    ferm.tm_sec = 0;
    ferm.tm_min = 0;
    ferm.tm_hour = 0;
    ferm.tm_mday = 1;
    ferm.tm_mon = 0;
    ferm.tm_year = 118;
    monSys->getCours(0)->creerDepot("Depot 1", ouv, ferm);
    monSys->getCours(0)->afficherListeDepot();
    Etudiant* etud = new Etudiant("Alex","idAlex","mdpAlex");
    monSys->getCours(0)->deposer(0, etud, "nomFichier");
    monSys->getCours(0)->afficherDepotsEffectues(0);
    monSys->getCours(0)->setInscription(20, ouv,ferm);
    monSys->getCours(0)->inscrire(etud);
    std::cout << "Resultat du test pour voir si Alex est inscrit: " << monSys->getCours(0)->estInscrit(etud) << std::endl;
    monSys->sauvegarderIdentifiants();

    monSys->supp();
    delete monSys;
   
    std::cout << std::endl << "===Test numero 2 ===" << std::endl;
    bool res;
    std::cout << "Test avec une liste valide:" << std::endl << "rapport d\'erreur pour le fichier listeValide.txt" << std::endl;
    monSys = new System("listeValide.txt");
    res = monSys->connexion("AMDINISTRATEUR", "adminID1", "adminMDP1");
    std::cout << "le resultat de la connexion avec la fonction administrateur de amdinID1 avec le mdp adminMDP1 est : " << res << std::endl;
    res = monSys->connexion("AMDINISTRATEUR", "chien", "chat");
    std::cout << "le resultat de la connexion avec la fonction administrateur de chien avec le mdp chat est : " << res << std::endl;
    monSys->supp();
    delete monSys;
    std::cout << "=== fin des tests ===" << std::endl;
    return 0;
}
*/
