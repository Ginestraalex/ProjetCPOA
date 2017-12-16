#include "Inscription.h"


Inscription::Inscription(){
    
}


Inscription::Inscription(int nbMaxEtud, struct tm ouvertureInsc, struct tm fermetureInsc){
    nombreMaximumEtudiant = nbMaxEtud;
    ouvertureInscription = ouvertureInsc;
    fermetureInscription = fermetureInsc;
}


void Inscription::inscrire(Etudiant* etud){
    if(estInscrit(etud)){
        std::cout << "Vous etes deja inscrit a ce cours" << std::endl;
    }
    else if(!inscriptionEncoreOuverte()){
        std::cout << "Les inscriptions pour ce cours sont fermees." << std::endl;
    }
    else{
        listeEtudiants.push_back(etud);
    }
}

bool Inscription::inscriptionEncoreOuverte(){
    double second;
    second = difftime(time(NULL), mktime(&fermetureInscription));
    if(second < 0)
    {
        second = difftime(time(NULL), mktime(&ouvertureInscription));
        if(second > 0){
            return true;
        }
    }
    return false;
}


bool Inscription::estInscrit(Etudiant* etud){
    bool pasTrouve = true;
    int i = 0;
    int taille = listeEtudiants.size();
    while(i < taille && pasTrouve){
        if(listeEtudiants[i] == etud){
            pasTrouve = false;
        }
        i++;
    }
    return !pasTrouve;
}

bool Inscription::aAcces(Etudiant* etud){
    bool autorise = false;
    int i = 0;
    int taille = listeEtudiants.size();
    while(i < taille && !autorise && i < nombreMaximumEtudiant){
        if(listeEtudiants[i] == etud){
            autorise = true;
        }
        i++;
    }
    return autorise;
}

