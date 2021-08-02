#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


class Complex {
    public:
    int reel, imag;

    Complex(int a = 0, int b = 0);

    Complex set(int r, int i);
    int norme();
    Complex conj();
    void affiche();
};

Complex produit(Complex u, Complex v);

Complex somme(Complex u, Complex v);

Complex difference(Complex u, Complex v);

struct reponse {
    int chiffre;
    Complex next_x;
};


Complex Complex::set(int r, int i) {
        reel = r;
        imag = i;
    }

int Complex::norme() {
        return pow(reel, 2) + pow(imag, 2);
    }

Complex Complex::conj() {
        Complex c = Complex(reel, -imag);
        return c;
    }

void Complex::affiche() {
        cout << reel << "  +  " << imag <<" i\n";
    }

Complex::Complex(int a , int b) {
        reel = a;
        imag = b;
    }

Complex produit(Complex u, Complex v) {
    int r = u.reel*v.reel - u.imag*v.imag;
    int i = u.reel*v.imag + u.imag*v.reel;
    Complex c = Complex(r, i);
    return c;
}

Complex somme(Complex u, Complex v) {
    int r = u.reel + v.reel;
    int i = u.imag + v.imag;
    Complex c = Complex(r, i);
    return c;
}

    Complex difference(Complex u, Complex v) {
    int r = u.reel - v.reel;
    int i = u.imag - v.imag;
    Complex c = Complex(r, i);
    return c;
}

vector<string> lecture_entree();

vector<string> lecture_entree() {
    vector<string> lignes;
    string ligne;
    while (getline(cin, ligne)) {
        if (ligne == "") {
            break;
        }
        lignes.push_back(ligne);
    }
    return lignes;
};


class Arbre{

    public:
    Complex x;
    vector<Arbre> fils;
    vector<int> chiffres;

    Arbre(Complex racine, vector<int> liste_chiffres);
    vector<int> conclusion();
};


Arbre::Arbre(Complex racine, vector<int> liste_chiffres) {
    x = racine;
    fils = {};
    chiffres = liste_chiffres;
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
        vector<int> liste_initiale = {};
        Arbre arbre = Arbre(x,liste_initiale );
        rempli(arbre, b);
        vector<int> liste = arbre.conclusion();
        if (liste.size() == 0) {
            cout << "The code cannot be decrypted.\n";
        }
        else {
            string resultat = to_string(liste[0]);
            for ( int index2 = 1; index2 < liste.size(); index2++) {
                int chiffre = liste[index2];
                resultat = to_string(chiffre) + "," + resultat;
            }
            cout << resultat << "\n";
        }
    }
}