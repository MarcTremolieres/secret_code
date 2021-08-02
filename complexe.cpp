#include <cmath>
#include <iostream>
#include "complexe.h"



using namespace std;

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
/*
int main() {
    Complex c1 = Complex(1, -3);
    Complex c2 = Complex(-3, 2);
    c1.affiche();
    Complex c3 = produit(c1, c2);
    c3.affiche();
}
*/