#include <iostream>
#include <complex>
#include <vector>
#include "scribes_functions.h"
//#include <cmath>

using namespace std;
class Arbre{
    public:
    complex<double> x;
    vector<Arbre> fils;
    vector<double> chiffres;

    Arbre(complex<double> racine, vector<double> liste_chiffres) {
        x = racine;
        fils = {};
        chiffres = liste_chiffres;
    }

    void affiche() {
        cout << "racine de l'arbre : " << x << "\n";
        cout << "Chiffres de l'arbre : ";
        for (double c : chiffres) {
            cout << c << " ";
        }
        cout << "\nFils de l'arbre : \n";

        cout << "\n";
        for (Arbre fil : fils) {
            cout << "racine du fils : " << fil.x << " ";
        }
        cout << "\n";
        for (Arbre fil : fils ) {
            fil.affiche();
        }
    }

    vector<double> conclusion() {
        if (x == 0.) {
            return chiffres;
        }
        else {
            for (Arbre fil : fils){
                return fil.conclusion();
            }
        }
    }
};

vector<double> prochains_chiffres(complex<double> x, complex<double> b) {
	int maxi = floor(sqrt(norm(b)));
//    cout << maxi << "\n";
	vector<double> liste;
    complex<double> calcul;

    for (int a = - maxi; a <= maxi; a++) {
        complex<double> ac (a, 0);
        calcul = (x - ac) / b;
        int partie_relle = calcul.real();
        int partie_imag = calcul.imag();
//        cout << " a = " << a << "\n";
//        cout << " calcul = " << calcul << "\n";
        
        if (((calcul.real() - partie_relle) <= 0) and ((calcul.imag() - partie_imag) <= 0)) {
            liste.push_back(a);
        }
    }

    return liste;
}

void rempli(Arbre& arbre, complex<double> b) {
    vector<double> prochains_c = prochains_chiffres(arbre.x, b);
    vector<double> chiffres_fils = arbre.chiffres;

    for (double chiffre: prochains_c) {
        if (chiffre == 0) {
            return;
        }
    chiffres_fils.push_back(chiffre);
    Arbre fils = Arbre((arbre.x - chiffre) / b, chiffres_fils);
    rempli(fils, b);
    arbre.fils.push_back(fils);
    }
//    arbre.affiche();
}


vector<string> explode(string s,const char& sep) {
    string buff = "";
    vector<string> v = {};
    for (char c : s) {
        if (c != sep) {
            buff += c;
        }
        else if (c == sep and buff != ""){
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "") {v.push_back(buff);}
    return v;
}

int main(){
   vector<string> lignes = lecture_entree();
   int nb_tests = stoi(lignes[0]);
   for (int index = 1; index <= nb_tests; index++) {
        string ligne = lignes[index];
        vector<string> valeurs = explode(ligne, ' ');
        complex<double> x (stod(valeurs[0]), stod(valeurs[1]));
        complex<double> b (stod(valeurs[2]), stod(valeurs[3]));
        cout << "x = " << x << " and b = " << b << "\n";
        vector<double> liste_initiale = {};
        Arbre arbre = Arbre(x,liste_initiale );
        rempli(arbre, b);
        vector<double> liste = arbre.conclusion();
        if (liste.size() == 0) {
            cout << "The code cannot be decrypted.\n";
        }
        else {
            string resultat;
            for ( double chiffre : liste) {
                int int_chiffre = chiffre; 
                resultat = resultat + to_string(int_chiffre) + " ";
            }
        cout << "Les chiffres sont : " << resultat << "\n";

            }
   }
}

