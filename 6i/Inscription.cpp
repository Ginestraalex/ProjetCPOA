#include "Inscription.h"


Inscription::Inscription(){
        
}
    
Inscription::Inscription(int nbMaxEtud, tm* dateD, tm* dateF){
    nbMaxEtudiant = nbMaxEtud;
    dateDebut = dateD;
    dateFin = dateF;
}
    
bool Inscription::peutDeposer(){
    return true;
}


std::string Inscription::toString(){
    return "";
}

int main(){
    time_t timer;
    time(&timer);
    double second;
    std::cout << timer << std::endl;
    //tm * instant = localtime();
    tm* date = new tm();
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;
    date->tm_year = 120;  //2020 => 1900 + 120
    date->tm_mon = 0;
    date->tm_mday = 1;
    second = difftime(timer,mktime(date));
    std::cout << second << std::endl;
    Inscription* insc = new Inscription(3, date, date);
    delete insc;
    return 0;
}
