#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-lecture.hpp"


vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
    ifstream fichier;
    fichier.open(nom_fichier);
    string valeur;
    int ligne = 0;
    vector<vector<string>> tableau;
    while (fichier) {
        tableau.push_back({});
        for (int i = 0; i < nb_colonnes; i++) {
            fichier >> valeur;
            tableau[ligne].push_back(valeur);
        }
        ligne++;
    }
    vector<vector<string>> new_tableau;
    for (int i = 0; i < tableau.size() -1; i++)  // permet d'enlever la dernière ligne du fichier qui apparaît 2x
        new_tableau.push_back(tableau[i]);
    fichier.close();
    return new_tableau;
}

