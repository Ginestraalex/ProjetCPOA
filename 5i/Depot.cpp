#include "Depot.h"

Depot::Depot(){

}

Depot::Depot(std::string nom,std::int ouverture_j,std::int ouverture_m,std::int ouverture_a,std::int fermeture_j,std::int fermeture_m,std::int fermeture_a){
  nomDepot=nom;
  DateOuverture.tm_mday=ouverture_j;
  DateOuverture.tm_mon=ouverture_m;
  DateOuverture.tm_year=ouverture_a;
  DateFermeture.tm_mday=fermeture_j;
  DateFermeture.tm_mon=fermeture_m;
  DateFermeture.tm_year=fermeture_a;
}
