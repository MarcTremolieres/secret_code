#include <iostream>
#include <vector>
#include "scribes_functions.h"
#include "class_arbre.h"

//#include <cmath>


using namespace std;
/*
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
            return {};
        }
    }
};
*/
/*
vector<double> prochains_chiffres(complex<double> x, complex<double> b) {
	int maxi = floor(sqrt(norm(b)));
//    cout << maxi << "\n";
	vector<double> liste;
    complex<double> calcul;

    for (int a = - maxi; a <= maxi; a++) {
        complex<double> ac (a, 0);
        double b2 = norm(b);
        complex<double> p = (x - ac)*conj(b);
        double r = p.real();
        double s = p.imag();
        if ((r % b2 == 0) and (s % b2 == 0)){
            liste.push_back(a);
        }
     }
    return liste;
}
*/


vector<reponse> prochains_chiffres(Complex x, Complex b) {
	int maxi = floor(sqrt(b.norme()));
	vector<reponse> liste;
    for (int a = - maxi; a <= maxi; a++) {
        int b2 = b.norme();
        Complex ac = Complex(a, 0);
        Complex p = produit(difference(x,ac), b.conj());
        
        int r = p.reel;
        int s = p.imag;
        if ((r % b2 == 0) and (s % b2 == 0)){
            int alpha = p.reel / b2;
            int beta = p.imag / b2;
            reponse rep;
            rep.chiffre = a;
            rep.next_x = Complex(alpha, beta);
            liste.push_back(rep);

        }
     }
    return liste;
}


void rempli(Arbre& arbre, Complex b) {
    vector<reponse> prochains_c = prochains_chiffres(arbre.x, b);
    vector<int> chiffres_fils = arbre.chiffres;

    for (reponse rep : prochains_c) {
        if (rep.chiffre == 0) {
            Arbre fils = Arbre(0, {});
            arbre.fils.push_back(fils);
        }
        else {
            chiffres_fils.push_back(rep.chiffre);
            Arbre fils = Arbre(rep.next_x, chiffres_fils);
            rempli(fils, b);
            arbre.fils.push_back(fils);
        }
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
        Complex x = Complex(stoi(valeurs[0]), stoi(valeurs[1]));
        Complex b = Complex(stoi(valeurs[2]), stoi(valeurs[3]));
        cout << "x = ";
        x.affiche();
        cout << " and b = ";
        b.affiche();
        vector<int> liste_initiale = {};
        Arbre arbre = Arbre(x,liste_initiale );
        rempli(arbre, b);
        arbre.affiche();
        vector<int> liste = arbre.conclusion();
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