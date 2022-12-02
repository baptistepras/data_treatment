#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-lecture-csv.hpp"


vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes) {
    ifstream fichier;
    fichier.open(nom_fichier);
    string entete;
    getline(fichier, entete);
    string valeur;
    int ligne = 0;
    vector<vector<string>> tableau;
    while (fichier) {
        tableau.push_back({});
        for (int i = 0; i < nb_colonnes - 1; i++) { // on prend toutes les colonnes sauf la dernière 
            getline(fichier, valeur, ';');
            tableau[ligne].push_back(valeur);
        }
        getline(fichier, valeur); // dernière colonne
        // gestion des fichiers windows sous Linux prise dans le fichier en_cas_d_urgence_briser_la_vitre
        // la chaîne de caractère de la dernière case comprend un retour à la ligne qu'il faut enlever ?
        if (valeur.size() > 0 and valeur[valeur.length() - 1] == '\r' )
            valeur.resize(valeur.length() - 1);
        tableau[ligne].push_back(valeur);
        ligne++;
    }
    vector<vector<string>> new_tableau;
    for (int i = 0; i < tableau.size() -1; i++)  // permet d'enlever la dernière ligne du fichier qui apparaît 2x
        new_tableau.push_back(tableau[i]);
    fichier.close();
    return new_tableau;
}

vector<vector<string>> litTableauCSV(string nom_fichier) {
    // Remplacer cette ligne et la suivante par le code adéquat
}




