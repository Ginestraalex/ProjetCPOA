#ifndef DEF_INTERFACE
#define DEF_INTERFACE
#include "System.cpp"

class Interface{
    
public:
    Interface();
    Interface(System* monSyteme);
    Interface(std::string nomFichier);
    
    void sauv();
    void supp();
       
protected:
    System* monSys;
};
#endif
