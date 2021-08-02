#include <iostream>
#include "complexe.h"

struct reponse {
    int chiffre;
    Complex next_x;
};


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



int main() {
    Complex x = Complex(-935, 2475);
    Complex b = Complex(-11, -15);
    vector<reponse> liste = prochains_chiffres(x, b);
    for (reponse c: liste) {
        cout << c.chiffre <<" ";
        c.next_x.affiche();
        cout << "\n";
    }
    x = Complex(-77, -120);
    liste = prochains_chiffres(x, b);
    for (reponse c: liste) {
        cout << c.chiffre <<" ";
        c.next_x.affiche();
        cout << "\n";
    }
    
}