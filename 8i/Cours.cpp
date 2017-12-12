#include "Cours.h"


Cours::Cours(){
    
}

Cours::Cours(std::string nom, Enseignant* prof){
    nomCours = nom;
    profReferent = prof;
    struct tm ouv, ferm;
    ouv.tm_sec = 0;
    ouv.tm_min = 0;
    ouv.tm_hour = 0;
    ouv.tm_mday = 1;
    ouv.tm_mon = 0;
    ouv.tm_year = 100;
    
    ferm.tm_sec = 0;
    ferm.tm_min = 0;
    ferm.tm_hour = 0;
    ferm.tm_mday = 1;
    ferm.tm_mon = 0;
    ferm.tm_year = 130;
    inscription = new Inscription(100, ouv, ferm);
}
    
std::string Cours::getNomCours(){
    return nomCours;
}

std::string Cours::getNomProfReferent(){
    return profReferent->getNom();
}

bool Cours::estInscrit(Etudiant* etud){
    if(inscription == NULL){
        return false;
    }
    else{
       return inscription->estInscrit(etud);
    }
}

void Cours::creerDepot(std::string nomDepot, struct tm ouverture, struct tm fermeture){
    listeDepot.push_back(new Depot(nomDepot, ouverture, fermeture));
}

void Cours::deposer(int index, Etudiant* etud, std::string nomFichier){
    listeDepot[index]->ajouterDepot(nomFichier, etud);
}

void Cours::afficherListeDepot(){
    int i, taille;
    taille = listeDepot.size();
    std::cout << "Liste des depots:" << std::endl;
    for(i = 0 ; i < taille ; i++){
        std::cout << listeDepot[i]->toString() << std::endl;
    }
}

void Cours::afficherDepotsEffectues(int index){
  int taille = listeDepot.size();
    if(taille >= index && index >= 0){
        listeDepot[index]->afficherLesDepots();
    }
}

void Cours::inscrire(Etudiant* etud){
  if(inscription == NULL){
    std::cout << "Il n'est pas encore possible de s'inscire a ce cours";
  }
  else{
    inscription->inscrire(etud);
  }
}

void Cours::setInscription(int nbMaxEtud, struct tm ouverture, struct tm fermeture){
  delete inscription;
  inscription = new Inscription(nbMaxEtud, ouverture, fermeture);
}


void Cours::supp(){
    int i, taille;
    taille = listeDepot.size();
    for(i = 0 ; i < taille ; i++){
        delete listeDepot[i];
    }
    if(inscription != NULL){
        delete inscription;
    }
}
