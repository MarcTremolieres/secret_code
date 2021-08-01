lignes = ["1 2 3 4", "-1 -2 -3 -4"]
for ligne in lignes:
    valeurs = ligne.split(' ')
    print(complex(int(valeurs[0]), int(valeurs[1])))
    print(complex(int(valeurs[2]), int(valeurs[3])))
