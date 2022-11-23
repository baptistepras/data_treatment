#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le nombre total de mariages célébrés entre 2010 et 2015 **/
int main() {
    ifstream fichier;
    fichier.open("donnees/statistiques-des-jours-des-mariages.txt");
    int somme = 0;
    string valeur;
    while (fichier) {
        fichier >> valeur >> valeur >> valeur;  // on ne garde que la valeur de la colonne "nombre"
        if (fichier)
            somme += stoi(valeur);  // convertis la valeur de la colonne "nombre" d'un string à un int
    }
    fichier.close();
    cout << somme << endl;
    return somme;
}

