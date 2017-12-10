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
    std::cout << "Liste des depots:" +to_string(taille)<< std::endl;
    for(i = 0 ; i < taille ; i++){
        std::cout << listeDepot[i]->toString() << std::endl;
    }
}

/*int main(){
    Cours c("MonCours",new Enseignant("NomEnseignant","idEnseignant","mdpEnseignant"));
    std::cout << "Le cours intitule : " << c.getNomCours() << " a pour prof referent : " << c.getNomProfReferent() << std::endl;
    return 0;
}*/

