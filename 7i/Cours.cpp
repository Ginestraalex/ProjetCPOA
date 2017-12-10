#include "Cours.h"


Cours::Cours(){
    
}

Cours::Cours(std::string nom, Enseignant* prof){
    nomCours = nom;
    profReferent = prof;
}
    
std::string Cours::getNomCours(){
    return nomCours;
}

std::string Cours::getNomProfReferent(){
    return profReferent->getNom();
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
    if(listeDepot.size() >= index && index >= 0){
        listeDepot[index]->afficherLesDepots();
    }
}

void Cours::supp(){
    int i, taille;
    taille = listeDepot.size();
    for(i = 0 ; i < taille ; i++){
        delete listeDepot[i];
    }
}
