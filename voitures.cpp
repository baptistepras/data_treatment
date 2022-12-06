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

vector<double> conversionDouble(vector<string> t) {
    vector<double> resultat = vector<double>(t.size());
    for(int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

vector<string> distinct(vector<vector<string>> data, int j) {
    vector<string> tableau;
    for (vector<string> tab : data) { // pour chaque ligne du tableau si la valeur n'a pas déjà été ajoutée
        if (chercheIndice(tableau, tab[j]) == -1)
            tableau.push_back(tab[j]);
    }
    return tableau;
}

vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<double> tableau = vector<double>(valeurs.size());
    for (int i = 0; i < tableau.size(); i++)
        tableau[i] = 0;
    for (vector<string> tab : data) { // pour chaque ligne du tableau, on récupère l'indice de la valeur dans j1
        int val = chercheIndice(valeurs, tab[j1]);
        vector<double> tab_double = conversionDouble(tab);
        if (val >= 0)
            tableau[val] += tab_double[j2];
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

vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes) {
    ifstream fichier;
    fichier.open(nom_fichier);
    string entete;
    getline(fichier, entete);
    string valeur;
    int ligne = 0;
    vector<vector<string>> tableau;
    while (fichier) {
        // permet d'avoir un tableau sans véhicules électriques pour un meilleur traitement
        // plus précisément toutes les voitures avec des données manquantes
        string val0;
        string val1;
        string val2;
        string val3;
        string val4;
        string val5;
        string val6;
        string val7;
        getline(fichier, val0, ';');
        getline(fichier, val1, ';');
        getline(fichier, val2, ';');
        getline(fichier, val3, ';');
        getline(fichier, val4, ';');
        getline(fichier, val5, ';');
        getline(fichier, val6, ';');
        getline(fichier, val7, ';');
        if (val7 != "EE " && val7 != "EL " && val7 != "GL ") {
            tableau.push_back({});
            tableau[ligne].push_back(val0);
            tableau[ligne].push_back(val1);
            tableau[ligne].push_back(val2);
            tableau[ligne].push_back(val3);
            tableau[ligne].push_back(val4);
            tableau[ligne].push_back(val5);
            tableau[ligne].push_back(val6);
            tableau[ligne].push_back(val7);
            for (int i = 8; i < nb_colonnes - 1; i++) { // on prend toutes les colonnes sauf la dernière 
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
        } else {
            for (int i = 8; i < nb_colonnes - 1; i++)
                getline(fichier, valeur, ';');
            getline(fichier, valeur);
        }
    }
    vector<vector<string>> new_tableau;
    for (int i = 0; i < tableau.size() -1; i++)  // permet d'enlever la dernière ligne du fichier qui apparaît 2x
        new_tableau.push_back(tableau[i]);
    fichier.close();
    return new_tableau;
}

/** Renvoie l'indice de la valeur minimale d'un tableau de double
 * @param tab un tableau de doubles
 * @return renvoie l'indice de la valeur minimale dans le tableau
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
int indiceMinDouble(vector<double> tab) {
    int ind = 0;
    double minimum = tab[0];
    for (int i = 1; i < tab.size(); i++) {
        if (tab[i] < minimum) { // si deux valeurs sont à égalité, on gardera uniquement la première occurence
            minimum = tab[i];
            ind = i;
        }
    }
    return ind;
}

/** Renvoie l'indice de la valeur maximale d'un tableau de double
 * @param tab un tableau de doubles
 * @return renvoie l'indice de la valeur maximale dans le tableau
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
int indiceMaxDouble(vector<double> tab) {
    int ind = 0;
    double maximum = tab[0];
    for (int i = 1; i < tab.size(); i++) {
        if (tab[i] > maximum) { // si deux valeurs sont à égalité, on gardera uniquement la première occurence
            maximum = tab[i];
            ind = i;
        }
    }
    return ind;
}

/** Renvoie la moyenne de chaque élément d'un tableau de doubles
 * en sachant le coefficient de chaque élément depuis un autre tableau
 * @param tab un tableau de doubles, les valeurs totales
 * @param coef un tableau de doubles, les coefficients
 * @return renvoie le tableau contenant la moyenne de chaque élément
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
vector<double> moyenneElements(vector<double> tab, vector<int> valeurs) {
    for (int i = 0; i < tab.size(); i++)
        tab[i] /= valeurs[i];
    return tab;
}

/** Affiche la voiture commercialisée en France qui 
 * pollue le plus et celle qui pollue le moins
 * ainsi que la marque produisant les véhicules
 * les plus et moins gourmands
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
int main() {
    vector<vector<string>> data = litTableauCSV("donnees/fic_etiq_edition_40-mars-2015.csv", 26);
    // les colonnes 13, 14, 15 représentent respectivement la consommation urbaine, extra-urbaine et mixte
    vector<double> conso_urbaine = conversionDouble(colonne(data, 13));
    vector<double> conso_extra_urbaine = conversionDouble(colonne(data, 14));
    vector<double> conso_mixte = conversionDouble(colonne(data, 15));
    vector<string> voitures = colonne(data, 4); // nom des voitures

    // récupere l'indice max et min pour chaque type de consommation
    int max_urbaine = indiceMaxDouble(conso_urbaine);
    int min_urbaine = indiceMinDouble(conso_urbaine);
    int max_extra_urbaine = indiceMaxDouble(conso_extra_urbaine);
    int min_extra_urbaine = indiceMinDouble(conso_extra_urbaine);
    int max_mixte = indiceMaxDouble(conso_mixte);
    int min_mixte = indiceMinDouble(conso_mixte);

    cout << "La voiture consommant le moins en consommation urbaine est la " << voitures[min_urbaine] << " avec une consommation de " << conso_urbaine[min_urbaine] << "L/100km" << endl;
    cout << "La voiture consommant le plus en consommation urbaine est la " << voitures[max_urbaine] << " avec une consommation de " << conso_urbaine[max_urbaine] << "L/100km" << endl;
    cout << endl;
    cout << "La voiture consommant le moins en consommation extra-urbaine est la " << voitures[min_extra_urbaine] << " avec une consommation de " << conso_urbaine[min_extra_urbaine] << "L/100km" << endl;
    cout << "La voiture consommant le plus en consommation extra-urbaine est la " << voitures[max_extra_urbaine] << " avec une consommation de " << conso_urbaine[max_extra_urbaine] << "L/100km" << endl;
    cout << endl;
    cout << "La voiture consommant le moins en consommation mixte est la " << voitures[min_mixte] << " avec une consommation de " << conso_urbaine[min_mixte] << "L/100km" << endl;
    cout << "La voiture consommant le plus en consommation mixte est la " << voitures[max_mixte] << " avec une consommation de " << conso_urbaine[max_mixte] << "L/100km" << endl;
    cout << endl;
    cout << endl;

    // fait un tableau contenant chaque marque différente et un tableau avec le nombre de véhicules par marque
    vector<string> marques = distinct(data, 0);
    vector<int> nombre_modeles = vector<int>(marques.size()); // compte le nombre total de véhicules par marque
    for (int i = 0; i < marques.size(); i++)
        nombre_modeles[i] = 0;
    vector<string> colonne_marques = colonne(data, 0);
    for (string valeur : colonne_marques) { // modifie le fichier nombre_modeles pour le rendre correct
        int indice = chercheIndice(marques, valeur);
        nombre_modeles[indice]++;
    }

    // fait pour chaque marque et chaque type de consommation la moyenne de la consommation des véhicules
    vector<double> marque_conso_urbaine = moyenneElements(groupByDouble(data, marques, 0, 13), nombre_modeles); 
    vector<double> marque_conso_extra_urbaine = moyenneElements(groupByDouble(data, marques, 0, 14), nombre_modeles);
    vector<double> marque_conso_mixte = moyenneElements(groupByDouble(data, marques, 0, 15), nombre_modeles);

    // récupere l'indice max et min pour chaque type de consommation
    int max_moyenne_urbaine = indiceMaxDouble(marque_conso_urbaine);
    int min_moyenne_urbaine = indiceMinDouble(marque_conso_urbaine);
    int max_moyenne_extra_urbaine = indiceMaxDouble(marque_conso_extra_urbaine);
    int min_moyenne_extra_urbaine = indiceMinDouble(marque_conso_extra_urbaine);
    int max_moyenne_mixte = indiceMaxDouble(marque_conso_mixte);
    int min_moyenne_mixte = indiceMinDouble(marque_conso_mixte);

    cout << "La marque produisant les voitures les moins gourmandes en consommation urbaine est " << marques[min_moyenne_urbaine] << " avec une consommation moyenne de " << marque_conso_urbaine[min_moyenne_urbaine] << "L/100km" << endl;
    cout << "La marque produisant les voitures les plus gourmandes en consommation urbaine est " << marques[max_moyenne_urbaine] << " avec une consommation moyenne de " << marque_conso_urbaine[max_moyenne_urbaine] << "L/100km" << endl;
    cout << endl;
    cout << "La marque produisant les voitures les moins gourmandes en consommation extra-urbaine est " << marques[min_moyenne_extra_urbaine] << " avec une consommation moyenne de " << marque_conso_extra_urbaine[min_moyenne_extra_urbaine] << "L/100km" << endl;
    cout << "La marque produisant les voitures les plus gourmandes en consommation extra-urbaine est " << marques[max_moyenne_extra_urbaine] << " avec une consommation moyenne de " << marque_conso_extra_urbaine[max_moyenne_extra_urbaine] << "L/100km" << endl;
    cout << endl;
    cout << "La marque produisant les voitures les moins gourmandes en consommation mixte est " << marques[min_moyenne_mixte] << " avec une consommation moyenne de " << marque_conso_mixte[min_moyenne_mixte] << "L/100km" << endl;
    cout << "La marque produisant les voitures les plus gourmandes en consommation mixte est " << marques[max_moyenne_mixte] << " avec une consommation moyenne de " << marque_conso_mixte[max_moyenne_mixte] << "L/100km" << endl;

    return 0;
}