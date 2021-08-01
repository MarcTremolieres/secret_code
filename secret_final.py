from math import floor, sqrt
import sys


class Arbre:
    def __init__(self, x: complex, liste_chiffres = []):
        self.x = x
        self.fils = []
        self.chiffres = liste_chiffres


    def conclusion(self):
        if self.x == 0:
            return self.chiffres
        else:
            for fils in self.fils:
                liste = fils.conclusion()
                if liste is not None:
                    return liste
            return None


def prochain_chiffre(x: complex, b: complex):
    maxi = floor(sqrt(b.real**2 + b.imag**2))
    for a in range(-maxi, maxi +1):
        calcul = (x - a) / b
        if (int(calcul.real) == calcul.real) and (int(calcul.imag) == calcul.imag):
            return a
    return None

def prochains_chiffres(x: complex, b: complex):
    maxi = floor(sqrt(b.real**2 + b.imag**2))
    liste = []
    for a in range(-maxi, maxi +1):
        calcul = (x - a) / b
        if (int(calcul.real) == calcul.real) and (int(calcul.imag) == calcul.imag):
            liste.append(a)
    return liste

def rempli(arbre: Arbre):
    if len(arbre.chiffres) > 100:
	    return None
    prochains_c = prochains_chiffres(arbre.x, b)
    for chiffre in prochains_c:
        if chiffre == 0:
            return arbre.chiffres
        fils = Arbre((arbre.x - chiffre)/b, arbre.chiffres + [chiffre])
        rempli(fils)
        arbre.fils.append(fils)

f = open("entree.txt", "r")
lignes = f.readlines()
#lignes = sys.stdin.readlines()
for ligne in lignes[1:]:
    valeurs = ligne.split(' ')
    x = complex(int(valeurs[0]), int(valeurs[1]))
    b = complex(int(valeurs[2]), int(valeurs[3]))
    arbre = Arbre(x)
    rempli(arbre)
    liste = arbre.conclusion()
    if (liste is None) or (liste == []):
        print("The code cannot be decrypted.")
    else:
        resultat = str(liste[0])
        for chiffre in liste[1:]:
            resultat = str(chiffre) + ',' + resultat
        print(resultat)


