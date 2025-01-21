#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

// la compilation ne reconnaît pas les fonctions déjà écrites dans les autres fichiers, je les ai donc copiées ici
vector<string> colonne(vector<vector<string>> t, int j) {
    vector<string> tableau;
    for (int i = 0; i < t.size(); i++)
        tableau.push_back(t[i][j]);
    return tableau;
}

vector<string> distinct(vector<vector<string>> data, int j) {
    vector<string> tableau;
    for (vector<string> tab : data) { // pour chaque ligne du tableau si la valeur n'a pas déjà été ajoutée
        if (chercheIndice(tableau, tab[j]) == -1)
            tableau.push_back(tab[j]);
    }
    return tableau;
}

vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> tableau;
    for (int i = 0; i < t.size(); i++) {
        if (t[i][j] == valeur)
            tableau.push_back(t[i]);
    }
    return tableau;
}

int chercheIndice(vector<string> t, string valeur) {
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == valeur) // renvoie la première occurence même si la valeur est présente plusieurs fois
            return i;
    }
    return -1;
}

int indiceMax(vector<int> t) {
    int max = -1;
    int indice_max = -1;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] > max) {  // si deux valeurs sont égales, on gardera l'indice de la première trouvée
            max = t[i];
            indice_max = i;
        }
    }
    return indice_max;
}

vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<int> tableau = vector<int>(valeurs.size());
    for (int i = 0; i < tableau.size(); i++)
        tableau[i] = 0;
    for (vector<string> tab : data) { // pour chaque ligne du tableau, on récupère l'indice de la valeur dans j1
        int val = chercheIndice(valeurs, tab[j1]);
        if (val >= 0)
            tableau[val] += stoi(tab[j2]); // converti un string en entier
    }
    return tableau;
}

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

/** Affiche l'arrondissement parisien où il y a le plus de trafic dans les stations de métro et RER
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
int main() {
    // données du site de la RATP
    vector<vector<string>> data = litTableauCSV("donnees/trafic-annuel-entrant-par-station-du-reseau-ferre-2021.csv", 11);
    vector<vector<string>> stations_paris = selectLignes(data, 9,"Paris");
    vector<string> arrondissements = distinct(stations_paris, 10);

    // pour chaque ligne, rajoute à l'arrondissement correspondant le trafic d'une gare
    vector<int> trafic_par_arrondissement = groupByInt(stations_paris, arrondissements, 10, 3);

    vector<string> nom_arrondissements = {"1er", "2ème", "3ème", "4ème", "5ème", "6ème", "7ème", "8ème", "9ème", "10ème", "11ème", "12ème", "13ème", "14ème", "15ème", "16ème", "17ème", "18ème", "19ème", "20ème"};
    int max_trafic = indiceMax(trafic_par_arrondissement);
    cout << "L'arrondissement avec le plus de trafic est le " << nom_arrondissements[stoi(arrondissements[max_trafic]) - 1] << " arrondissement avec un trafic de " << trafic_par_arrondissement[max_trafic] << " voyageurs" << endl; 

    return 0;
}