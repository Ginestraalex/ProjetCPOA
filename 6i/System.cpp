#include "System.h"
#include <sstream>

System::System(){
}


template <typename T> std::string to_string(T value){
    //create an output string stream
    std::ostringstream os;

    //throw the value into the string stream
    os << value;

    //convert the string stream into a string and return
    return os.str();
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
        if(listeDesUtilisateurs[i]->estLID(id) && listeDesUtilisateurs[i]->estLeMDP(pwd)){
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

Cours System::getCours(int index){
  if(index < (int)listeDesCours.size() && index >= 0)
    {
        return *listeDesCours[index];
    }
    std::cout << "erreur lors de la recuperation du cours" << std::endl;
    exit(1);
}

Cours System::getCours(std::string nomCours){
    int i = 0;
    int taille = listeDesCours.size();
    bool pasTrouve = true;
    while(i < taille && pasTrouve){
        if(!listeDesCours[i]->getNomCours().compare(nomCours)){
            return *listeDesCours[i];
        }
        i++;
    }
    std::cout << "le cours demande n existe pas" << std::endl;
    Cours *coursTemp = new Cours();
    return *coursTemp;
}

void System::proposerCours(std::string nomCours, Enseignant* enseignantReferent){
    listePropositionCours.push_back(new PropositionDeCours(nomCours, enseignantReferent));
}


void System::afficherListeCours(){
    int i, taille;
    taille = listeDesCours.size();
    std::cout << "Liste des cours du systeme:" << std::endl;
    for(i = 0 ; i < taille ; i++){
        std::cout << std::to_string(i)+": COURS = " +listeDesCours[i]->getNomCours() + "   PROF REFERENT = " +listeDesCours[i]->getNomProfReferent() << std::endl;
    }
    std::cout << std::endl;
}

void System::afficherListePropositionsCours(){
    std::cout << "la liste des propositions de cours est la suivate" << std::endl;
    int i, tailleListe;
    tailleListe = listePropositionCours.size();
    for(i = 0 ; i < tailleListe ; i++){
        std::cout << std::to_string(i) + " COURS = " +listePropositionCours[i]->getNomCours() + " PROF REFERENT = "+listePropositionCours[i]->getNomProfReferent() << std::endl;
    }
    std::cout << std::endl;
}


void System::accepterPropositionCours(int index){
    ajouterCours(new Cours(listePropositionCours[index]->getNomCours(),listePropositionCours[index]->getProfReferent()));
    delete listePropositionCours[index];
    listePropositionCours.erase(listePropositionCours.begin() + index);
}



void System::supp(){
    int i;
    int taille = listeDesUtilisateurs.size();
    for( i = 0 ; i < taille ; i++){
        delete listeDesUtilisateurs[i];
    }
    taille = listeDesCours.size();
    for( i = 0 ; i < taille ; i++){
        delete listeDesCours[i];
    }
    taille = listePropositionCours.size();
    for( i = 0 ; i < taille ; i++){
        delete listePropositionCours[i];
    }
}


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
    monSys->supp();
    delete monSys;
   
    std::cout << "===Test numero 2 ===" << std::endl;
    bool res;
    std::cout << "Test avec une liste valide:" << std::endl << "rapport d\'erreur pour le fichier listeValide.txt" << std::endl;
    monSys = new System("listeValide.txt");
    res = monSys->connexion("AMDINISTRATEUR", "adminID1", "adminMDP1");
    std::cout << "le resultat de la connexion avec la fonction administrateur de amdinID1 avec le mdp adminMDP1 est : " << res << std::endl;
    res = monSys->connexion("AMDINISTRATEUR", "chien", "chat");
    std::cout << "le resultat de la connexion avec la fonction administrateur de chien avec le mdp chat est : " << res << std::endl;
    monSys->ajouterCours(new Cours("leCours",new Enseignant("nomProf","idProf","mdpProf")));
    std::cout << "le nom du cours est: " << monSys->getCours(0).getNomCours() << " le nom du prof referent pour ce cours est: " << monSys->getCours(0).getNomProfReferent() << std::endl;
    monSys->supp();
    delete monSys;
    return 0;
}
