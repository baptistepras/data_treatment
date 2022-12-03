#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le genre et l'espece de l'arbre le plus haut de Paris
 * parmi les "arbres remarquables"
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
int main() {
    vector<vector<string>> data = litTableauCSV("donnees/arbresremarquablesparis.csv", 19);
    // récupère la colonne de toutes les données dont on a besoin
    vector<int> hauteur = conversionInt(colonne(data, 12));
    vector<string> nom = colonne(data, 1);
    vector<string> genre = colonne(data, 2);
    vector<string> espece = colonne(data, 3);
    int indice_max = indiceMax(hauteur);
    cout << "L'arbre le plus haut de Paris est un " << nom[indice_max] << " dont le genre est " << genre[indice_max] << " et l'espèce " << espece[indice_max] << ". Sa hauteur est de " << hauteur[indice_max] << "m" << endl;

    return 0;
}

