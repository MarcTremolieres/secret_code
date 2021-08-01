#include <fstream>
#include "scribes_functions.h"
using namespace std;
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