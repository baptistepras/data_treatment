#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche l'année avec le plus de naissances et l'année avec le plus de mariages
  * Auteur: Baptiste Pras
  * Degré de confiance: 90%
  * Raisons: Je ne peux tester le programme à cause de l'erreur ligne 15, mais je reste confiant dans la lecture du tableau 
  * qui est similaire aux exercices précédents
 **/
int main() {
    vector<vector<string>> data = litTableauCSV("statistiques_de_creation_d_actes_d_etat_civil_par_arrondissement.csv", 4);
    vector<vector<string>> naissances = selectLignes(data, 0, "Naissances");
    vector<vector<string>> mariages = selectLignes(data, 0, "Mariages");
    
    // crée un tableau avec autant d'années qu'il y a de recensées dans le fichier, l'indice i correspond à l'année i + 2004
    vector<string> annees_naissance = distinct(naissances, 1);
    vector<int> naissances_par_an = vector<int>(annees_naissance.size());
    for (int i = 0; i < naissances_par_an.size(); i++)
        naissances_par_an[i] = 0;
    vector<string> annees_mariage = distinct(mariages, 1);
    vector<int> mariages_par_an = vector<int>(annees_mariage.size());
    for (int i = 0; i < mariages_par_an.size(); i++)
        mariages_par_an[i] = 0;

    // récupère l'année de chaque mariage ou naissance et ajoute à l'année correspondante le nombre d'évènements recensés
    for (vector<string> ligne : naissances)
        naissances_par_an[stoi(ligne[0]) - 2004] += stoi(ligne[3]); // transforme une chaîne de caractère en int
    for (vector<string> ligne : mariages)
        mariages_par_an[stoi(ligne[0]) - 2004] += stoi(ligne[3]); // transforme une chaîne de caractère en int

    int indice_max_naissances = indiceMax(naissances_par_an);
    int indice_max_mariages = indiceMax(mariages_par_an);
    cout << "L'année avec le plus grand nombre de déclarations de naissances est " << indice_max_naissances + 2004 << " avec " << naissances_par_an[indice_max_naissances] << " naissances" << endl; 
    cout << "L'année avec le plus grand nombre de déclarations de mariages est " << indice_max_mariages + 2004 << " avec " << mariages_par_an[indice_max_mariages] << " mariages" << endl;

    return 0;
}

