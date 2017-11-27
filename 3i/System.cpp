#include <iostream>
#include <fstream>
#include <string>
#include "System.h"

System::System(){
}

System::System(std::string nomFichier){
    std::string fonction, nom, id, mdp;
    std::ifstream monFlux(nomFichier);
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
                    std::exit(0);
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

System::System(Utilisateur::Utilisateur lesUtilisateurs[], int nbUtilisateurs){
    int i;
    for(i = 0 ; i < nbUtilisateurs ; i++){
        listeDesUtilisateurs.push_back(lesUtilisateurs[i]);
    }
}

bool connexion(std::string id, std::string pwd){
    int i = 0;
    bool pasTrouve = true;
    while (i < listeDesUtilisateurs.size() && pasTrouve){
        if((listeDesUtilisateurs[i].estLID(id) && listeDesUtilisateurs[i].estLeMPD(pwd)){
            pasTrouve = false;
            utilisateurCourrant = listeDesUtilisateurs[i];
            return true;
        }
        i++
    }
    return false;
}


int main(){
    std::cout << "rapport d\'erreur pour le fichier listeValide.txt" << std::endl;
    System *monSys = new System("listeValide.txt");
    delete monSys;
    std::cout << "rapport d\'erreur pour le fichier listeErronee.txt" << std::endl;
    monSys = new System("listeErronee.txt");
    
    return 0;
}
