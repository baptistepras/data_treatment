#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/** Calcule et affiche le prénom le plus donné une année donnée
 * ainsi que le nombre de naissance cette année là **/
int main() {
    cout << "Entrez une année entre 2004 et 2021: ";
    int annee;
    cin >> annee;
    while (not(2004 <= annee and annee <= 2021)) {  // assure la bonne valeur de la variable "année"
        cout << "Entrez une année entre 2004 et 2021: ";
        cin >> annee;
        if (!cin) {  // Solution de Lucas Hermier-Gastineau pour éviter une boucle infinie si cin != int
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    
    ifstream fichier;
    fichier.open("donnees/liste_des_prenoms.csv");
    string entete;
    getline(fichier, entete);
    
    string valeur; // récupère uniquement l'année sous forme de string
    string prenom;
    string cumul;

    int max = 0;
    string prenom_max = " ";
    int naissances = 0;
    
    while (fichier) {
        getline(fichier, valeur, ';');
        getline(fichier, valeur, ';');
        getline(fichier, valeur, ';');
        getline(fichier, prenom, ';');
        getline(fichier, cumul);
        if (fichier and stoi(valeur) == annee) {
            naissances += stoi(cumul);
            if (stoi(cumul) > max) {  // S'il y a une égalité, le premier prénom sorti sera celui choisi
                max = stoi(cumul);
                prenom_max = prenom;
            }
        }
    }
    fichier.close();
    cout << "En " << annee << ", il y a eu " << naissances << " naissances" << endl;
    cout << "Le prénom le plus donné a été " << prenom_max << " (donné " << max << " fois)" << endl;
    return naissances;
}

