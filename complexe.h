#include <cmath>
#include <iostream>
#include <vector>

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
