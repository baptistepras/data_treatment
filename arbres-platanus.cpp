#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le nombre d'arbres du genre Platanus, et le nombre d'espèces
 *  différentes pour ce genre Platanus, parmi les "arbres remarquables"
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
int main() {
    vector<vector<string>> data = litTableauCSV("donnees/arbresremarquablesparis.csv", 19);
    vector<vector<string>> lignes_platanes = selectLignes(data, 2, "Platanus");
    vector<string> especes = distinct(lignes_platanes, 3);
    cout << "Il y a " << lignes_platanes.size() << " arbres de genre Platanus à Paris et il existe " << especes.size() << " espèces différentes pour ce genre" << endl;

    return 0;
}

