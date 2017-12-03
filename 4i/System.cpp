#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "System.h"

System::System(){
}

System::System(std::string nomFichier){
    std::string fonction, nom, id, mdp;
    std::ifstream monFlux(nomFichier.c_str());
    Administrateur* adminTemp;
    Etudiant* etudTemp;
    Enseignant* ensTemp;
    if(monFlux){ //teste  pour voir si le flux s'est ouvert
        while(monFlux >> fonction){
            if(monFlux >> nom && monFlux >> id && monFlux >> mdp){
                if(fonction.compare("AMDINISTRATEUR") == 0){
                    adminTemp = new Administrateur(nom, id, mdp);
                    listeDesUtilisateurs.push_back(adminTemp);
                }
                else if(fonction.compare("ETUDIANT") == 0){
                    etudTemp = new Etudiant(nom, id, mdp);
                    listeDesUtilisateurs.push_back(etudTemp);
                }
                else if(fonction.compare("ENSEIGNANT") == 0){
                    ensTemp = new Enseignant(nom, id, mdp);
                    listeDesUtilisateurs.push_back(ensTemp);
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
    bool pasTrouve = true;
    while (i < listeDesUtilisateurs.size() && pasTrouve){
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
    if(index < listeDesCours.size() && index >= 0)
    {
        return *listeDesCours[index];
    }
    std::cout << "erreur lors de la recuperation du cours" << std::endl;
    exit(1);
}


int main(){
    int i;
    Utilisateur *lesUtil[3];
    Utilisateur util1("nom1","id1","mdp1");
    Utilisateur util2("nom2","id2","mdp2");
    Utilisateur util3("nom3","id3","mdp3");
    lesUtil[0] = &util1;
    lesUtil[1] = &util2;
    lesUtil[2] = &util3;
    for(i = 0 ; i < 3 ; i++){
        std::cout << lesUtil[i]->toString() << std::endl;
    }
    System *monSys = new System(lesUtil, 3);
    delete monSys;
    
    
    bool res;
    std::cout << "Test avec une liste valide:" << std::endl << "rapport d\'erreur pour le fichier listeValide.txt" << std::endl;
    monSys = new System("listeValide.txt");
    res = monSys->connexion("AMDINISTRATEUR", "adminID1", "adminMDP1");
    std::cout << "le resultat de la connexion avec la fonction administrateur de amdinID1 avec le mdp adminMDP1 est : " << res << std::endl;
    res = monSys->connexion("AMDINISTRATEUR", "chien", "chat");
    std::cout << "le resultat de la connexion avec la fonction administrateur de chien avec le mdp chat est : " << res << std::endl;
    monSys->ajouterCours(new Cours("leCours","nomProf"));
    std::cout << "le nom du cours est: " << monSys->getCours(0).getNomCours() << " le nom du prof referent pour ce cours est: " << monSys->getCours(0).getNomProfReferent() << std::endl;
    delete monSys;
    std::cout << std::endl << "Test avec une liste non valide:" << std::endl << "rapport d\'erreur pour le fichier listeErronee.txt" << std::endl;
    monSys = new System("listeErronee.txt");
    delete monSys;
    return 0;
}
