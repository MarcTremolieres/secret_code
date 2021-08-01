#include <iostream>
#include <complex>
//using namespace std;
int main() {
    std::complex<int> z (10, -19);
    std::cout << sqrt(norm(z)) << "\n";
    std::cout << floor(sqrt(norm(z))) << "\n";
}
