/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "tableau-lecture.hpp"
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
using namespace std;


/**
 * Calcule et affiche :
 * - le nombre total de naissances de garçons et de naissances de filles
 * - l'année qui a eu le plus de naissances (garçons et filles confondus), avec leur nombre
 * - le nombre de naissances en moyenne par an
 * - les nombres de prénoms féminins et masculins différents
 * - le prénom masculin et le prénom féminin le plus populaire
 **/
int main() {
    vector<vector<string>> data = litTableau("donnees/liste_des_prenoms.txt", 4);

    vector<vector<string>> lignes_filles = selectLignes(data, 0, "F");
    vector<vector<string>> lignes_garcons = selectLignes(data, 0, "M");
    
    vector<string> sexe = distinct(data, 0);
    vector<string> annee = distinct(data, 1);
    vector<string> prenoms_feminins = distinct(lignes_filles, 2);
    vector<string> prenoms_masculins = distinct(lignes_garcons, 2);
    int ind_femme = 1;
    int ind_homme = 0;
    if (sexe[0] == "F") {
        ind_femme = 0;
        ind_homme = 1;
    } else {
        ind_femme = 1;
        ind_homme = 0;
    }


    vector<int> total_sexe = groupByInt(data, sexe, 0, 3);
    vector<int> total_annee = groupByInt(data, annee, 1, 3);
    vector<int> total_prenoms_feminins = groupByInt(lignes_filles, prenoms_feminins, 2, 3);
    vector<int> total_prenoms_masculins = groupByInt(lignes_garcons, prenoms_masculins, 2, 3);
    
    cout << "Il y a eu " << total_sexe[ind_homme] << " naissances de garçons et " << total_sexe[ind_femme] << " naissances de filles" << endl;
    int max_annee = indiceMax(total_annee);
    cout << "L'année qui a eu le plus de naissances est: " << annee[max_annee] << " avec " << total_annee[max_annee] << " naissances" << endl;
    cout << "En moyenne naissent " << moyenne(total_annee) << " enfants par an" << endl;
    cout << "Il y a eu " << prenoms_feminins.size() << " prénoms de filles différents et " << prenoms_masculins.size() << " prénoms de garçons" << endl;
    int max_prenom_fille = indiceMax(total_prenoms_feminins);
    int max_prenom_garcon = indiceMax(total_prenoms_masculins);
    cout << "Le prénom féminin le plus populaire est " << prenoms_feminins[max_prenom_fille] << " avec " << total_prenoms_feminins[max_prenom_fille] << " naissances" << endl;
    cout << "Le prénom masculin le plus populaire est " << prenoms_masculins[max_prenom_garcon] << " avec " << total_prenoms_masculins[max_prenom_garcon] << " naissances" << endl;

    return 0;
}

