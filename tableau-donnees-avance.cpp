#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include <iostream>
#include "tableau-donnees-avance.hpp"

int chercheIndice(vector<string> t, string valeur) {
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == valeur) // renvoie la première occurence même si la valeur est présente plusieurs fois
            return i;
    }
    return -1;
}

vector<string> distinct(vector<vector<string>> data, int j) {
    vector<string> tableau;
    for (vector<string> tab : data) {
        if (chercheIndice(tableau, tab[j]) == -1)
            tableau.push_back(tab[j]);
    }
    return tableau;
}

vector<double> conversionDouble(vector<string> t) {
    vector<double> resultat = vector<double>(t.size());
    for(int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<int> tableau = vector<int>(valeurs.size());
    for (int i = 0; i < tableau.size(); i++)
        tableau[i] = 0;
    return tableau;
}

vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    // Remplacer cette ligne et la suivante par le code adéquat
    throw runtime_error("Fonction groupByDouble non implantée ligne 29");
}

template<class T>
vector<T> conversion(vector<string> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
    throw runtime_error("Fonction conversion non implantée ligne 35");
}

template<class T>
vector<T> groupBy(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    // Remplacer cette ligne et la suivante par le code adéquat
    throw runtime_error("Fonction groupBy non implantée ligne 41");
}

// Force l'instanciation des templates
template vector<int> conversion<int>(vector<string> t);
template vector<double> conversion<double>(vector<string> t);
template vector<int> groupBy<int>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
template vector<double> groupBy<double>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);

