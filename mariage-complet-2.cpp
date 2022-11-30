#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "tableau-donnees.hpp"
#include "tableau-lecture.hpp"
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<string> annees = {"2010", "2011", "2012", "2013", "2014", "2015"};
vector<string> jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};


/** Construction du tableau des mariages par années à partir d'un
 * tableau de données 2D (de chaines de caractères)
 * Chaque ligne contient : l'année, le jour, puis le nombre de mariages
 * @param t un tableau de données 2D de chaines de caractère
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages de l'année 2010+i
 **/
vector<int> creeTableauAnnee(vector<vector<string>> data) {
    vector<int> tableau = {0, 0, 0, 0, 0, 0};
    for (int i = 2010 ; i <= 2015; i++) {
        vector<string> tab = colonne(selectLignes(data, 0, annees[i - 2010]), 2);
        vector<int> tab_int;
        for (string j : tab)
            tab_int.push_back(stoi(j)); // crée un tableau d'entiers avec le nombre de mariages dans l'année
        tableau[i - 2010] += somme(tab_int);
    }
    return tableau;
}

/** Test de la fonction CreeTableauAnnee **/
void testCreeTableauAnnee() {
    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t = creeTableauAnnee(data);
    CHECK(t[0] == 9195); // Nombre de mariages en 2010
    CHECK(t[3] == 9443); // Nombre de mariages en 2013
    CHECK(t[5] == 9046); // Nombre de mariages en 2015
}

/** Renvoie le numéro du jour correspondant à la chaîne de caractères
 * @param jour une chaine de caractères contenant un jour de la semaine (première lettre en majuscule)
 * @return un numéro entre 0 et 6 correspondant au jour de la semaine ou
 * -1 si le jour n'est pas valide
 **/
int indiceJour(string jour) {
    for(int i=0; i < jours.size(); i++) {
        if (jour == jours[i]) {
            return i;
        }
    }
    return -1;
}

void testIndiceJour() {
    CHECK(indiceJour("Lundi") == 0);
    CHECK(indiceJour("Samedi") == 5);
    CHECK(indiceJour("Dimanche") == 6);
    CHECK(indiceJour("samedi") == -1);
}

/** Construction du tableau des mariages à partir d'un
 * tableau de données 2D (de chaines de caractères)
 * suivi d'un jour, puis d'un nombre de mariages
 * Chaque ligne contient : l'année, le jour, puis le nombre de mariages
 * @param t un tableau de données 2D de chaines de caractère
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages célébrés le jour i
 **/
vector<int> creeTableauJours(vector<vector<string>> data) {
    vector<int> tableau = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 0 ; i <= 6; i++) {
        vector<string> tab = colonne(selectLignes(data, 1, jours[i]), 2);
        vector<int> tab_int;
        for (string j : tab)
            tab_int.push_back(stoi(j)); // crée un tableau d'entiers avec le nombre de mariages dans l'année
        tableau[i] += somme(tab_int);
    }
    return tableau;
}

/** Test de la fonction litTableauJours **/
void testCreeTableauJours() {
    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> t = creeTableauJours(data);
    CHECK(t[0] == 4171); // Nombre de mariages le lundi
    CHECK(t[3] == 4393); // Nombre de mariages le jeudi
    CHECK(t[6] == 2); // Nombre de mariages le dimanche
}


/** Lance les fonctions de test puis affiche :
 * - le nombre total de mariages
 * - le nombre moyen de mariages célébrés par an
 * - l'année où l'on a célébré le plus de mariages (et leur nombre)
 * - le jour de la semaine où l'on célèbre le plus de mariages (et leur nombre)
 * - le pourcentage de mariages célébrés un samedi
 **/
int main() {
    testCreeTableauAnnee();
    testCreeTableauJours();

    vector<vector<string>> data = litTableau("donnees/statistiques-des-jours-des-mariages.txt", 3);
    vector<int> tableau_annee = creeTableauAnnee(data);
    vector<int> tableau_jour = creeTableauJours(data);
    cout << "Le nombre total de mariages célébrés entre 2010 et 2015 est de " << somme(tableau_annee) << endl;
    cout << "Le nombre moyen de mariages célébrés par an est de " << moyenne(tableau_annee) << endl;
    cout << "L'année où l'on a célébré le plus de mariages est " << indiceMax(tableau_annee) + 2010 << " avec " << tableau_annee[indiceMax(tableau_annee)] << " mariages" << endl;
    cout << "Le jour de la semaine où l'on a célébré le plus de mariages est le " << jours[indiceMax(tableau_jour)] << " avec " << tableau_jour[indiceMax(tableau_jour)] << " mariages" << endl;
    float valeur_samedi = tableau_jour[5];
    cout << "Le pourcentage de mariages célébrés le samedi est de " << 100 * (valeur_samedi / somme(tableau_jour)) << "%" << endl;
    
    return 0;
}

