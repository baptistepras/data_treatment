#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees.hpp"

void afficheTableau(vector<vector<string>> tableau) {
    for (int i = 0; i < tableau.size(); i++) {
        for (int j = 0; j < tableau[i].size(); j++) {
            if (j != 0)  // évite d'avoir un espace en plus à la fin de la ligne
                cout << " ";
            cout << tableau[i][j];
        }
        cout << endl;
    }
}

int moyenne(vector<int> t) {
    int somme = 0;
    for (int i = 0; i < t.size(); i++)
        somme += t[i];
    return somme / t.size();
}

int somme(vector<int> t) {
    int somme = 0;
    for (int i = 0; i < t.size(); i++)
        somme += t[i];
    return somme;
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

vector<string> colonne(vector<vector<string>> t, int j) {
    vector<string> tableau;
    for (int i = 0; i < t.size(); i++)
        tableau.push_back(t[i][j]);
    return tableau;
}


vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i = 0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> tableau;
    for (int i = 0; i < t.size(); i++) {
        if (t[i][j] == valeur)
            tableau.push_back(t[i]);
    }
    return tableau;
}

