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

Cours System::getCours(std::string nomCours){
    int i = 0;
    bool pasTrouve = true;
    while(i < listeDesCours.size() && pasTrouve){
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

void System::afficherListePropositionsCours(){
    std::string liste("la liste des proposition de cours est la suivate \n");
    int i, tailleListe;
    tailleListe = listePropositionCours.size();
    for(i = 0 ; i < tailleListe ; i++){
        liste.append("index: " + std::to_string(i) + " nom: " + listePropositionCours[i]->getNomCours() +"\n");
    }
    std::cout << liste << std::endl;
}



void System::supp(){
    int i;
    for( i = 0 ; i < listeDesUtilisateurs.size() ; i++){
        delete listeDesUtilisateurs[i];
    }
    for( i = 0 ; i < listeDesCours.size() ; i++){
        delete listeDesCours[i];
    }
}


int main(){
    int i;
    Utilisateur *lesUtil[3];
    lesUtil[0] = new Utilisateur("nom1","id1","mdp1");
    lesUtil[1] = new Utilisateur("nom2","id2","mdp2");
    lesUtil[2] = new Utilisateur("nom3","id3","mdp3");
    for(i = 0 ; i < 3 ; i++){
        std::cout << lesUtil[i]->toString() << std::endl;
    }
    System *monSys = new System(lesUtil, 3);
    monSys->proposerCours("nom du cours", new Enseignant("Duflot","idProf","mdpProf"));
    monSys->afficherListePropositionsCours();
    monSys->supp();
    delete monSys;
   

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
    std::cout << std::endl << "Test avec une liste non valide:" << std::endl << "rapport d\'erreur pour le fichier listeErronee.txt" << std::endl;
    monSys = new System("listeErronee.txt");
    monSys->supp();
    delete monSys;
    return 0;
}
