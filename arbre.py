class Arbre:
    def __init__(self, x: complex, liste_chiffres = []):
        self.x = x
        self.fils = []
        self.chiffres = liste_chiffres

    def affiche(self):
        print(self.x)
        print(self.chiffres)
        for fils in self.fils:
            fils.affiche()



        