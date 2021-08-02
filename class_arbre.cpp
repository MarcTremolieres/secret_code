#include <iostream>
#include "class_arbre.h"

Arbre::Arbre(Complex racine, vector<int> liste_chiffres) {
    x = racine;
    fils = {};
    chiffres = liste_chiffres;
}

void Arbre::affiche(){
           cout << "racine de l'arbre : ";
            x.affiche();
        cout << "Chiffres de l'arbre : ";
        for (double c : chiffres) {
            cout << c << " ";
        }
        cout << "\n";
        for (Arbre fil : fils) {
            cout << "racine du fils : ";
            fil.x.affiche();
        }
        cout << "\n";
        for (Arbre fil : fils ) {
            fil.affiche();
        }
}

vector<int> Arbre::conclusion() {
    if (x.reel == 0 and x.imag == 0) {
        return chiffres;
    }
    else {
            for (Arbre fil : fils){
                return fil.conclusion();
            }
            return {};
        }
    }


