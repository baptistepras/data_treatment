#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture.hpp"
using namespace std;


/**
 * Demande à l'utilisateur un prénom et calcule
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {
    cout << "Nombre total de naissances: " << somme(conversionInt(colonne(litTableau("donnees/liste_des_prenoms.txt", 4), 3))) << endl;
    
    cout << "Choisissez un prénom: ";
    string prenom;
    cin >> prenom;
    int garcon = 0;
    int annee_max_garcon;
    int max_garcon = 0;
    int fille = 0;
    int annee_max_fille;
    int max_fille = 0;
    
    vector<vector<string>> tableau = selectLignes(litTableau("donnees/liste_des_prenoms.txt", 4), 2, prenom);
    vector<int> annee = conversionInt(colonne(tableau, 1));  // donne un tableau d'entiers avec les années
    vector<int> nombre = conversionInt(colonne(tableau, 3));  // donne un tableau d'entiers avec les nombres
    for (int i = 0; i < tableau.size(); i++) {  // parcours seulement les lignes qui nous intéressent
        if (tableau[i][0] == "M") {
            garcon += nombre[i];
            if (nombre[i] > max_garcon) {  // si deux années sont à égalité, seule la première est conservée
                max_garcon = nombre[i];
                annee_max_garcon = annee[i];
            }
        } else {
            fille += nombre[i];
            if (nombre[i] > max_fille) {  // si deux années sont à égalité, seule la première est conservée
                max_fille = nombre[i];
                annee_max_fille = annee[i];
            }
        }
    }

    if (garcon > 0) {
        cout << "Le prénom " << prenom << " a été donné à " << garcon << " garçons entre 2004 et 2021" << endl;
        cout << "L'année la plus forte est " << annee_max_garcon << " avec " << max_garcon << " enfants" << endl;
    } else
        cout << "Le prénom " << prenom << " n'a été donné à aucun garcon entre 2004 et 2021" << endl;
    if (fille > 0) {
        cout << "Le prénom " << prenom << " a été donné à " << fille << " filles entre 2004 et 2021" << endl;
        cout << "L'année la plus forte est " << annee_max_fille << " avec " << max_fille << " enfants" << endl;
    } else
        cout << "Le prénom " << prenom << " n'a été donné à aucune fille entre 2004 et 2021" << endl;

    return 0;
}

