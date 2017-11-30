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
    if(monFlux){ //teste  pour voir si le flux s'est ouvert
        while(monFlux >> fonction){
            if(monFlux >> nom && monFlux >> id && monFlux >> mdp){
                if(fonction.compare("AMDINISTRATEUR") == 0){
                    listeDesUtilisateurs.push_back(Administrateur(nom, id, mdp));
                }
                else if(fonction.compare("ETUDIANT") == 0){
                    listeDesUtilisateurs.push_back(Etudiant(nom, id, mdp));
                }
                else if(fonction.compare("ENSEIGNANT") == 0){
                    listeDesUtilisateurs.push_back(Enseignant(nom, id, mdp));
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

System::System(Utilisateur lesUtilisateurs[], int nbUtilisateurs){
    int i;
    for(i = 0 ; i < nbUtilisateurs ; i++){
        listeDesUtilisateurs.push_back(lesUtilisateurs[i]);
    }
}

bool System::connexion(std::string fonction, std::string id, std::string pwd){
    int i = 0;
    bool pasTrouve = true;
    while (i < listeDesUtilisateurs.size() && pasTrouve){
        if(listeDesUtilisateurs[i].estLID(id) && listeDesUtilisateurs[i].estLeMDP(pwd)){
            pasTrouve = false;
            utilisateurCourrant = listeDesUtilisateurs[i];
            return true;
        }
        i++;
    }
    return false;
}

void System::ajouterCours(Cours cours){
    listeDesCours.push_back(cours);
}

Cours System::getCours(int index){
    if(index < listeDesCours.size() && index >= 0)
    {
        return listeDesCours[index];
    }
    std::cout << "erreur lors de la recuperation du cours" << std::endl;
    exit(1);
}


int main(){
    bool res;
    std::cout << "Test avec une liste valide:" << std::endl << "rapport d\'erreur pour le fichier listeValide.txt" << std::endl;
    System *monSys = new System("listeValide.txt");
    res = (*monSys).connexion("AMDINISTRATEUR", "adminID1", "adminMDP1");
    std::cout << "le resultat de la connexion de amdinID1 avec le mdp adminMDP1 est : " << res << std::endl;
    res = (*monSys).connexion("AMDINISTRATEUR", "chien", "chat");
    std::cout << "le resultat de la connexion de chien avec le mdp chat est : " << res << std::endl;
    (*monSys).ajouterCours(Cours("leCours","nomProf"));
    std::cout << "le nom du cours est: " << (*monSys).getCours(0).getNomCours() << " le nom du prof referent pour ce cours est: " << (*monSys).getCours(0).getNomProfReferent() << std::endl;
    delete monSys;
    std::cout << std::endl << "Test avec une liste non valide" << std::endl << "rapport d\'erreur pour le fichier listeErronee.txt" << std::endl;
    monSys = new System("listeErronee.txt");
    delete monSys;
    return 0;
}
