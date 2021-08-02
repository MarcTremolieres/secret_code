#include <iostream>
#include "complexe.h"



class Arbre{

    public:
    Complex x;
    vector<Arbre> fils;
    vector<int> chiffres;

    Arbre(Complex racine, vector<int> liste_chiffres);

    void affiche();

     vector<int> conclusion();
    };
