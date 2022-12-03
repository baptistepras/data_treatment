---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.14.1
kernelspec:
  display_name: C++17
  language: C++17
  name: xcpp17
---

# Rapport de projet *Données libres*

+++

## Auteur

- Pras Baptiste, baptiste.pras@universite-paris-saclay.fr

+++

## Résumé du travail effectué


- Exercice 1: entièremment complété, compile et fonctionne correctement
              mariage-total affiche le nombre de mariages au total de 2010 à 2015
              mariage-samedi affiche le nombre de mariges au total sur un samedi de 2010 à 2015
              J'ai fait le choix de garder en mémoire le moins de variables possibles (donc d'écraser par exemple la 
              valeur de la première case si je n'en avais pas besoin) pour gagner en complexité spatiale
  
- Exercice 2: entièremment complété, compile et fonctionne correctement
              prenoms demande une année dans le terminal, puis affiche le nombre de naissances au total sur cette 
              année ainsi que le prénom le plus donné cette même année
  
- Exercice 3: entièremment complété, compile et fonctionne correctement
              mariage-complet permet d'avoir un tableau avec tous les mariages par année et un tableau avec tous les 
              mariages par jour de la semaine, nous permettant de donner de nombreuses statistiques
              La manipulation de toutes les fonctions implantées demande de la concentration et de la schématisation 
              de la donnée que l'on veut et des données que chaque fonction nous renvoie

- Exercice 4: entièremment complété, compile et fonctionne correctementent
              prenoms-tableau crée un tableau à partir du fichier texte pour travailler directement dessus
              Depuis ce tableau, on peut, grâce à d'autres fonctions auxiliaires, trouver tout type de données et 
              faire tout genre de statistiques souhaitées sur les prénoms donnés à la naissance

- Exercice 5: entièremment complété, compile et fonctionne correctement
              prenoms-tableau-2 et mariage-complet-2 se servent maintenant d'un tableau de données crée à partir du 
              fichier txt pour arriver aux mêmes résultats que les exercices 3 et 4

- Exercice 6: complété jusqu'au 5) inclu (6) non obligatoire), compile et fonctionne correctement
              Les fonctions dans tableau-donnees-avance.cpp permettent des requêtes bien plus complexes pour obtenir 
              les mêmes résultats qu'avant plus efficacement dans prenoms-tableau-avance et mariage-complet-3
              J'ai eu quelques difficultés à coder la fonction groupByInt qui m'a demandé de schématiser toutes les 
              nombreuses données que j'avais dans chaque variable et comment je devais les traiter pour arriver au 
              résultat final voulu
              Pour le 6), je n'arrive pas à schématiser comment se passer du type pour créer une template

- Exercice 7: entièremment complété, compile et fonctionne correctement
              prenoms-csv est le même programme que prenoms mais lit ses données depuis un fichier CSV plutôt que txt
              L'utilisation de la fonction getline() permet de lire le fichier case par case

- Exercice 8: 1) complété, 2) non obligatoire complété mais ne fonctionne pas, compile et fonctionne (pour le 1)
              Le programme tableau-lecture-csv permet de créer un tableau à partir d'un fichier CSV donné
              Dans le 1), la fonction litTableauCSV (avec colonne) fonctionne très bien et ne pose aucun problème
              Dans le 2), la fonction litTableauCSV (sans colonne) est implémentée et compile, mais ne renvoie pas 
              le bon résultat, je n'arrive pas à trouver la bonne condition me permettant de savoir si je suis ou 
              non sur la dernière case de la ligne pour laquelle getline() ne prend que 2 paramètres et non pas 3

- Exercice 9: entièremment complété, compile, le 1) et 2) fonctionne correctement, le 3) a une erreur
              arbres-hauteur renvoie le nom, le genre, l'espèce et la hauteur de l'arbre le plus haut de Paris
              J'ai ici choisi d'utiliser la fonctionne colonne pour récupérer la colonne des 4 paramètres dont j'ai 
              besoin, puis j'ai cherché l'indice maximum dans hauteur pour déterminer ces paramètres
              arbres-platanus renvoie le nombre d'arbres de genre "Platanus" à Paris ainsi que le nombre d'espèces 
              différentes pour ce genre
              J'ai ici choisi de récupérer toutes les lignes où le genre était "Platanus" grâce à selectLignes(), 
              puis avec distinct() de créer une liste avec toutes les espèces différentes pour les lignes 
              préalablements extraites
              actes-civils compile mais l'appel de la fonction litTableauCSV() renvoie une segmentation fault. Je suis 
              assez convaincu du fonctionnement du reste de la fonction qui d'abord récupère toutes les lignes liées 
              aux naissances et aux mariages, puis parcours ces lignes pour additionner à chaque année le nombre de 
              naissances ou mariages et trouver le total par année

- Exercice 11: entièremment complété, compile et fonctionne correctement
               La fonction main se sert des fonctions précédemment implémentées, plus de 4 nouvelles 
               pour donner le véhicule le plus et moins gourmand en essence selon le type de trajet, 
               ainsi que la marque faisant les véhicules les plus et moins gourmands en moyenne pour 
               chaque type de trajet.
               Nouvelles fonctions: - indiceMaxDouble et indiceMinDouble (similaires à indiceMax)
                                    - moyenneElements, fait la moyenne de chaque élément d'un tableau
                                    - litTableauCSV a un peu été modifiée pour pouvoir lire dans ce 
                                      tableau uniquement le type de carburant et ainsi éliminer les 
                                      voitures dont la consommation serait nulle (électrique etc...) 
                                      pour avoir un traitement de données plus pertinent
               L'exercice est celui qui m'a posé le plus de problèmes d'une part à cause du nombre de 
               données différentes à traiter dans ce tableau et d'autre part à cause du manque de 
               certaines données que l'on peut retrouver, mais qui ne se lisent pas directement dans le 
               fichier csv. De plus, il a fallu trouver et identifier à la main les véhicules à éliminer du 
               tableau afin d'éliminer les consommations nulles.

- Exercice 12: entièremment complété, compile et fonctionne correctement
               Donne la gare comptant le plus de parapluies perdus à partir du fichier objets-trouves de 
               la SNCF. J'ai choisi de prendre seulement les lignes de parapluies, puis de compter 
               combien de lignes correspondaient à chaque gare en utilisant les fonctions existantes

- Exercice 13: entièremment complété, compile et fonctionne correctement
               Donne l'arrondissement avec le plus de trafic dans les stations métro / RER en se servant 
               des fonctions déjà implantées précédemment et du fichier du trafic par station fourni par 
               la RATP

- Exercice 15: entièremment complété, compile et fonctionne correctement
               A partir du jeu de données des subventions demandées à la Mairie de Paris et le montant 
               accordé, on détermine à l'aide des fonctions déjà implantées l'association ayant reçu le 
               plus d'argent de la Mairie de Paris et le budget total de la Mairie dans le milieu 
               associatif
               Le tableau CSV proposé a posé problèmes car sur les quelques 84 000 lignes, il y avait 
               presque 130 000 point-virgules dans les noms des associations et descriptions, décalant 
               toutes les cas et cause des erreurs critiques. J'ai donc dû (avec la précieuse aide de 
               Cmd+F) remplacer tous ces point-virgules par des espaces.
               De plus, le montant total des subventions dépassait la capacité d'un int, il a donc fallu 
               régler ce problème-ci pour éviter d'avoir quelque chose d'incohérent (résultat négatif).
               Une autre application intéressante du traitement de données pourrait être de récupérer 
               en temps réel sur RTE les données de production et de consommation électrique pour se 
               faire une alerte sur son téléphone des risques de coupure. On pourrait alors avec un 
               système autonome (Alexa, Google Home etc...) couper certains de nos appareils.

+++

## Démonstration

Je souhaiterais montrer les programmes suivants:
- Exercice 6: les programmes tableau-donnees-avance et prenoms-tableau-avance me paraissent être intéressants 
              tant dans la façon de créer les fonctions pour lire les tableaux que dans l'application de ces 
              dernières pour en ressortir les données voulues
- Exercice 9: les programmes arbres-platanus et arbres-hauteur qui fonctionnent sont un bon exemple d'application de 
              toutes nos fonctions précédemment créées. Le programme actes-civils, bien qu'ayant une erreur identifiée, est 
              aussi un très bon exemple d'une manipulation plus complexe liée à un tableau avec plus de données
  
- Exercice 11: exercice le plus difficile m'ayant été donnée de faire dans ce TP pour ma part. Il permet 
               de montrer une application complexe de tout un tas de données dans un tableau, ainsi que 
               la création de nouvelles données qu'on juge manquantes et de vérifier la pertinence des 
               données que l'on récupère pour éviter d'avoir un résultat inintéressant

```{code-cell}
! make clean
```

```{code-cell}
! rm voitures
```

```{code-cell}
! rm objets-trouves
```

```{code-cell}
! rm metro
```

```{code-cell}
! rm subventions
```

```{code-cell}
! make all
```

```{code-cell}
! make voitures
```

```{code-cell}
! make objets-trouves
```

```{code-cell}
! make metro
```

```{code-cell}
! make subventions
```

```{code-cell}
! make test
// erreur make: *** [Makefile:39: test] Error 255 que je ne comprends pas, mais tous les tests
// fonctionnent si on les exécute un par un avec les commandes ci-dessous
```

```{code-cell}
! ./tableau-donnees-test
```

```{code-cell}
! ./tableau-lecture-test
```

```{code-cell}
! ./tableau-lecture-csv-test
```

```{code-cell}
// exercice 6
```

```{code-cell}
! ./tableau-donnees-avance-test
```

```{code-cell}
:tags: []

! ./mariage-complet-3
```

```{code-cell}
! ./prenoms-tableau-avance
```

```{code-cell}
// exercice 9
```

```{code-cell}
! ./arbres-hauteur
```

```{code-cell}
! ./arbres-platanus
```

```{code-cell}
! ./actes-civils
```

```{code-cell}
// Segmentation fault dans actes-civils, liée à l'utilisation de la fonction litTableauCSV
// commandes pour lire le rapport d'erreur
```

gdb actes-civils
core core.191763
where full
list
quit

```{code-cell}
// exercice 11
```

```{code-cell}
! ./voitures
```

```{code-cell}
// exercice 12
```

```{code-cell}
! ./objets-trouves
```

```{code-cell}
// exercice 13
```

```{code-cell}
! ./metro
```

```{code-cell}
// exercice 15
```

```{code-cell}
! ./subventions
```

Raccourcis pour toutes les commandes dans le terminal:
cd ProgImperative/Projet-DonneesLibres

Commandes de compilation:
info-111 g++ mariage-total.cpp -o mariage-total
info-111 g++ mariage-samedi.cpp -o mariage-samedi
info-111 g++ mariage-complet.cpp -o mariage-complet
info-111 g++ prenoms.cpp -o prenoms
info-111 g++ prenoms-tableau.cpp -o prenoms-tableau
make tableau-donnees-test
make tableau-lecture-test
make prenoms-tableau-2
make mariage-complet-2
make tableau-donnees-avance-test
make mariage-complet-3
make prenoms-tableau-avance
make prenoms-csv
make tableau-lecture-csv-test
make arbres-hauteur
make arbres-platanus
make actes-civils
make voitures
make objets-trouves
make metro
make subventions

Commandes d'exécution:
./mariage-total
./mariage-samedi
./mariage-complet
./prenoms
./prenoms-tableau
./tableau-donnees-test
./tableau-lecture-test
./prenoms-tableau-2
./mariage-complet-2
./tableau-donnees-avance-test
./mariage-complet-3
./prenoms-tableau-avance
./prenoms-csv
./tableau-lecture-csv-test
./arbres-hauteur
./arbres-platanus
./actes-civils
./voitures
./objets-trouves
./metro
./subventions

+++ {"tags": [], "jp-MarkdownHeadingCollapsed": true}

## Organisation du travail

Le nombre d'heures passées sur le projet doit être d'environ 20 à 30h.
J'ai majoritairement travaillé depuis chez moi, me permettant une meilleure concentration tout en éviter de travailler trop en ayant un accès proche à des en-cas, à boire, toilettes et activités pour se reposer entre deux programmes si besoin (lit, vidéo, canapé, balade etc...).
J'ai préféré travailler seul car le projet étant petit et pas trop compliqué, j'estime avancer plus vite et plus efficacement seul qu'à plusieurs, notamment que ne connaissant pas très bien la façon de coder de mes amis, l'adaptation aurait pris du temps. Je préfère travailler en groupe seulement sur les gros projets et avec quelqu'un donc je connais la façon de programmer.
J'ai, pour un soucis de propreté de mon code, eu l'aide d'un camarade pour une sorte d'assertion sur les cin dans les fichiers prenoms.cpp et prenoms-csv.cpp (comme écrit à côté du morceau en question dans ces fichiers).

+++

## Prise de recul

Aucune difficulté majeure rencontrée, que ce soit dans le code ou dans l'organisation du travail.
Si je pouvais refaire ce projet, je le commencerais tout de même une semaine plus tôt car la charge de travail était un peu plus importante que ce que je pensais, et l'arrivée sur le mois de décembre était chargée en examens à préparer et DM à rendre, ce qui a considérablement augmenté mon niveau de stress, et qui aurait pu être réduit en ayant fini le projet un peu plus tôt.
