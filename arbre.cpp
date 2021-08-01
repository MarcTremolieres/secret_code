#include <iostream>
#include <complex>
#include <vector>

using namespace std;

class Arbre{
    public:
    complex<int> x;
    vector<Arbre> fils;
    vector<int> chiffres;

    Arbre(complex<int> racine, vector<int> liste_chiffres) {
        x = racine;
        fils = {};
        chiffres = liste_chiffres;
    }

    void affiche() {
        cout << x << "\n";
        for (Arbre fil : fils ) {
            fil.affiche();
        }
    }

    vector<int> conclusion() {
        if (x == 0) {
            return chiffres;
        }
        else {
            for (Arbre fil : fils){
                return fil.conclusion();
            }
        }
    }
};



int main(){
    complex<int> racine  (5, -3);
    cout << racine << "\n";
    vector<int> liste = {};
    Arbre arbre = Arbre(racine, liste);
    Arbre arbre2 = Arbre(racine, liste);
    arbre.fils.push_back(arbre2);
    arbre.affiche();
}