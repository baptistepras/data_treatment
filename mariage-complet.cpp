#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<string> jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};


/** Construction du tableau des mariages par années
 * On suppose que le fichier contient sur chaque ligne une année entre 2010 et 2015
 * suivi d'un jour, puis d'un nombre de mariages
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages de l'année 2010+i
 **/
vector<int> litTableauAnnee(string nom_fichier) {
    ifstream fichier;
    fichier.open(nom_fichier);
    vector<int> tableau_annee = {0, 0, 0, 0, 0, 0};
    int annee;
    string valeur;
    while (fichier) {
        fichier >> annee >> valeur >> valeur;  // on ne garde que la valeur des colonnes "annee" et "nombre"
        if (fichier)
            tableau_annee[annee - 2010] += stoi(valeur); // convertis la valeur de la colonne "nombre" d'un string à un int
    }
    return tableau_annee;
}

/** Test de la fonction litTableauAnnee **/
void testLitTableauAnnee() {
    vector<int> t = litTableauAnnee("donnees/statistiques-des-jours-des-mariages.txt");
    CHECK(t[0] == 9195); // Nombre de mariages en 2010
    CHECK(t[3] == 9443); // Nombre de mariages en 2013
    CHECK(t[5] == 9046); // Nombre de mariages en 2015
}

/** Renvoie le numéro du jour correspondant à la chaîne de caractères
 * @param jour une chaine de caractère contenant un jour de la semaine (première lettre en majuscule)
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

/** Construction du tableau des mariages par jour
 * On suppose que le fichier contient sur chaque ligne une année entre 2010 et 2015
 * suivie d'un jour, puis d'un nombre de mariages
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages célébrés le jour i
 **/
vector<int> litTableauJours(string nom_fichier) {
    ifstream fichier;
    fichier.open(nom_fichier);
    vector<int> tableau_jour = {0, 0, 0, 0, 0, 0, 0};
    int valeur;
    string jour;
    while (fichier) {
        fichier >> valeur >> jour >> valeur;  // on ne garde que la valeur des colonnes "jour" et "nombre"
        if (fichier)
            tableau_jour[indiceJour(jour)] += valeur;
    }
    return tableau_jour;
}

/** Test de la fonction litTableauJours **/
void testLitTableauJours() {
    vector<int> t = litTableauJours("donnees/statistiques-des-jours-des-mariages.txt");
    CHECK(t[0] == 4171); // Nombre de mariages le lundi
    CHECK(t[3] == 4393); // Nombre de mariages le jeudi
    CHECK(t[6] == 2); // Nombre de mariages le dimanche
}

/** Renvoie la somme d'un tableau d'entiers
 * @param t, un tableau d'entier
 * @return la somme des valeurs du tableau
 **/
int somme(vector<int> t) {
    int somme = 0;
    for (int i = 0; i < t.size(); i++)
        somme += t[i];
    return somme;
}

/** Test de la fonction somme **/
void testSomme() {
    CHECK(somme({1,2,3}) == 6);
    CHECK(somme({}) == 0);
    CHECK(somme({2,2,4,8}) == 16);
}

/** Renvoie la moyenne d'un tableau d'entier
 * @param t, un tableau d'entiers
 * @return la moyenne (entière) des valeurs
 * (on arrondit à l'entier inférieur)
 **/
int moyenne(vector<int> t) {
    int somme = 0;
    for (int i = 0; i < t.size(); i++)
        somme += t[i];
    return somme / t.size();
}

/** Test de la fonction moyenne **/
void testMoyenne() {
    CHECK(moyenne({1,2,3}) == 2);
    CHECK(moyenne({1}) == 1);
    CHECK(moyenne({2,2,4,8}) == 4);
}


/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/
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

/** Test de la fonction IndiceMax **/
void testIndiceMax() {
    CHECK(indiceMax({}) == -1);
    CHECK(indiceMax({1,2,3}) == 2);
    CHECK(indiceMax({1,3,2}) == 1);
    CHECK(indiceMax({1}) == 0);
    CHECK(indiceMax({2,8,4,4}) == 1);
}

/** Lance les fonctions de test puis affiche :
 * - le nombre total de mariages
 * - le nombre moyen de mariages célébrés par an
 * - l'année où l'on a célébré le plus de mariages (et leur nombre)
 * - le jour de la semaine où l'on célèbre le plus de mariages (et leur nombre)
 * - le pourcentage de mariages célébrés un samedi
 **/
int main() {
    testLitTableauAnnee();
    testLitTableauJours();
    testSomme();
    testMoyenne();
    testIndiceMax();
    
    vector<int> tableau_annee = litTableauAnnee("donnees/statistiques-des-jours-des-mariages.txt");
    vector<int> tableau_jour = litTableauJours("donnees/statistiques-des-jours-des-mariages.txt");
    cout << "Le nombre total de mariages célébrés entre 2010 et 2015 est de " << somme(tableau_annee) << endl;
    cout << "Le nombre moyen de mariages célébrés par an est de " << moyenne(tableau_annee) << endl;
    cout << "L'année où l'on a célébré le plus de mariages est " << indiceMax(tableau_annee) + 2010 << " avec " << tableau_annee[indiceMax(tableau_annee)] << " mariages" << endl;
    cout << "Le jour de la semaine où l'on a célébré le plus de mariages est le " << jours[indiceMax(tableau_jour)] << " avec " << tableau_jour[indiceMax(tableau_jour)] << " mariages" << endl;
    float valeur_samedi = tableau_jour[5];
    cout << "Le pourcentage de mariages célébrés le samedi est de " << 100 * (valeur_samedi / somme(tableau_jour)) << "%" << endl;

    return 0;
}

