#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le nombre de mariages un samedi entre 2010 et 2015 **/
int main() {
    ifstream fichier;
    fichier.open("donnees/statistiques-des-jours-des-mariages.txt");
    int somme = 0;
    int valeur;
    string jour;
    while (fichier) {
        fichier >> valeur >> jour >> valeur;  // on ne garde que la valeur des colonnes "jour" et "nombre"
        if (fichier and jour == "Samedi")
            somme += valeur;  
    }
    fichier.close();
    cout << somme << endl;
    return somme;
}

