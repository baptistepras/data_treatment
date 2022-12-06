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

/** Affiche la gare où le plus de parapluies ont été perdus
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
int main() {
    // données du site de la SCNF
    vector<vector<string>> data = litTableauCSV("donnees/objets-trouves-restitution.csv", 7);
    vector<vector<string>> lignes_parapluies = selectLignes(data, 5, "Parapluies");
    vector<string> gares = distinct(lignes_parapluies, 2);
    vector<int> parapluies_par_gare = vector<int>(gares.size());
    for (int i = 0; i < gares.size(); i++)
        parapluies_par_gare[i] = 0;

    // pour chaque ligne, rajoute 1 à la gare où un parapluie a été perdu
    for (vector<string> ligne : lignes_parapluies) {
        int indice = chercheIndice(gares, ligne[2]);
        parapluies_par_gare[indice]++;
    }

    int max_parapluies = indiceMax(parapluies_par_gare);
    cout << "La gare où l'on a retrouvé le plus de parapluies perdus est " << gares[max_parapluies] << " avec " << parapluies_par_gare[max_parapluies] << " parapluies" << endl;

    return 0;
}