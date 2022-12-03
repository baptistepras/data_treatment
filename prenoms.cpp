#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le prénom le plus utilisé une année donnée
 * ainsi que le nombre de naissances cette année là 
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
**/
int main() {
    cout << "Entrez une année entre 2004 et 2021: ";
    int annee;
    cin >> annee;
    while (not(2004 <= annee and annee <= 2021)) {  // assure la bonne valeur de la variable "année"
        cout << "Entrez une année entre 2004 et 2021: ";
        cin >> annee;
        // fonctionne si on compile avec info-111 g++ mais pas avec make
        // if (!cin) {  // Solution de Lucas Hermier-Gastineau pour éviter une boucle infinie si cin != int
            // cin.clear();
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        // }
    }
    
    ifstream fichier;
    fichier.open("donnees/liste_des_prenoms.txt");
    int valeur;
    string prenom;
    
    int max = 0;
    string prenom_max = " ";
    int naissances = 0;
    while (fichier) {
        fichier >> prenom >> valeur;  // prends d'abord le sexe et l'année
        if (fichier and valeur == annee) {  // Si l'année correspond, on prend le prénom et le nombre
            fichier >> prenom >> valeur;
            naissances += valeur;
            if (valeur > max) {  // S'il y a une égalité, le premier prénom sorti sera celui choisi
                max = valeur;
                prenom_max = prenom;
            }
        } else
            fichier >> prenom >> valeur;
    }
    fichier.close();
    cout << "En " << annee << ", il y a eu " << naissances << " naissances" << endl;
    cout << "Le prénom le plus donné a été " << prenom_max << " (donné " << max << " fois)" << endl;
    return naissances;
}

