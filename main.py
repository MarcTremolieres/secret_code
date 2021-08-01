from math import floor, sqrt
import sys


class Arbre:
    def __init__(self, x: complex, liste_chiffres=[]):
        self.x = x
        self.fils = []
        self.chiffres = liste_chiffres

    def affiche(self):
        print(self.x)
        print(self.chiffres)
        for fils in self.fils:
            fils.affiche()

    def conclusion(self):
        if self.x == 0:
            return self.chiffres
        else:
            for fils in self.fils:
                return fils.conclusion()


def prochain_chiffre(x: complex, b: complex):
    maxi = floor(sqrt(b.real**2 + b.imag**2))
#    print("maxi = ", maxi)
    for a in range(-maxi, maxi +1):
        calcul = (x - a) / b
        if (int(calcul.real) == calcul.real) and (int(calcul.imag) == calcul.imag):
            return a
    return None

def prochains_chiffres(x: complex, b: complex):
    maxi = floor(sqrt(b.real**2 + b.imag**2))
#    print("maxi = ", maxi)
    liste = []
    for a in range(-maxi, maxi +1):
        calcul = (x - a) / b
        if (int(calcul.real) == calcul.real) and (int(calcul.imag) == calcul.imag):
            liste.append(a)
    return liste

def rempli(arbre: Arbre):
    prochains_c = prochains_chiffres(arbre.x, b)
    for chiffre in prochains_c:
        if chiffre == 0:
            return arbre.chiffres
        fils = Arbre((arbre.x - chiffre)/b, arbre.chiffres + [chiffre])
        rempli(fils)
        arbre.fils.append(fils)

def succes(arbre: Arbre):
    if arbre.x == 0:
        return arbre.chiffres
    else:
        for fils in arbre.fils:
            return succes(fils)

f = open("entree.txt", "r")
#lignes = sys.stdin.readlines()
lignes = f.readlines()
for index in range(1, int(lignes[0]) + 1):
    for ligne in lignes:
        valeurs = ligne.split(' ')
        x = complex(int(valeurs[0]), int(valeurs[1]))
        b = complex(int(valeurs[2]), int(valeurs[3]))
        arbre = Arbre(x)
        rempli(arbre)
        liste = arbre.conclusion()
        if liste == []:
            print("The code cannot be decrypted.")
        else:
            resultat = ""
            for chiffre in liste:
                resultat = resultat + str(chiffre) + ' '
            print(resultat)




#x = -935 + 2475j
x = 0
#x = 93 + 16j
#b = -11 -15j
#b = 3 + 2j
b = 1j
arbre = Arbre(x)
rempli(arbre)
#arbre.affiche()
liste = arbre.conclusion()
print(liste)