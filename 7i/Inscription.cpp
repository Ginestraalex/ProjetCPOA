#include "Inscription.h"


Inscription::Inscription(){
    
}


Inscription::Inscription(int nbMaxEtud, struct tm ouvertureInsc, struct tm fermetureInsc){
    nombreMaximumEtudiant = nbMaxEtud;
    ouvertureInscription = ouvertureInsc;
    fermetureInscription = fermetureInsc;
}


void Inscription::inscrire(Etudiant* etud){
    bool pasTrouve = true;
    int i = 0;
    int taille = listeEtudiants.size();
    while(i < taille && true){
        if(listeEtudiants[i] == etud){
            pasTrouve = false;
        }
        i++;
    }
    if(pasTrouve){
        listeEtudiants.push_back(etud);
    }
    else{
        std::cout << "Vous etes deja inscrit a ce cours" << std::endl;
    }
}
