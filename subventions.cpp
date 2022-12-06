#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

// la compilation ne reconnaît pas les fonctions déjà écrites dans les autres fichiers, je les ai donc copiées ici
long sommeLong(vector<int> t) {
    long somme = 0;
    for (int i = 0; i < t.size(); i++)
        somme += t[i];
    return somme;
}

vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

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
        if (val >= 0) {
            tableau[val] += stoi(tab[j2]); }// converti un string en entier
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
        for (int i = 1; i < nb_colonnes - 1; i++) { // on prend toutes les colonnes sauf la dernière 
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

/** Affiche l'association ayant reçu le plus de subvention de la Mairie de Paris et le budget total accordé aux 
 * subventions des associations par la Mairie de Paris
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
int main() {
    // données du site de la Mairie de Paris
    vector<vector<string>> data = litTableauCSV("donnees/subventions-accordees-et-refusees.csv", 10);
    vector<string> associations = distinct(data, 3);

    // fais le total des subventions par association
    vector<int> subventions_par_associations = groupByInt(data, associations, 3, 6);
    int max_subventions = indiceMax(subventions_par_associations);
    cout << "L'association ayant reçu le plus de subventions est " << associations[max_subventions] << " avec un montant total de " << subventions_par_associations[max_subventions] << "€" << endl;
    cout << "Le budget total de la Mairie de Paris pour subventionner les associations est de " << sommeLong(conversionInt(colonne(data, 6))) << "€" << endl;

    return 0;
}
