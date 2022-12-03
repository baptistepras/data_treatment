#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> tableauTest = {
    { "M", "2011", "Bubulle", "3"},
    { "F", "2012", "Bichette", "4"},
    { "F", "2011", "Babouche", "7"},
    { "F", "2011", "Ziboulette", "1"}
};

/** Affiche le contenu d'un tableau de chaînes à deux dimensions
 * @param tableau un tableau à deux dimensions
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
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

void testAfficheTableau() {
    afficheTableau(tableauTest);
}


/** Construction d'un tableau 2D de chaines de caractères lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * de colonnes séparées par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau de chaines de caractères à deux dimensions
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
    ifstream fichier;
    fichier.open(nom_fichier);
    string valeur;
    int ligne = 0;
    vector<vector<string>> tableau;
    while (fichier) {
        tableau.push_back({});
        for (int i = 0; i < nb_colonnes; i++) {
            fichier >> valeur;
            tableau[ligne].push_back(valeur);
        }
        ligne++;
    }
    vector<vector<string>> new_tableau;
    for (int i = 0; i < tableau.size() -1; i++)  // permet d'enlever la dernière ligne du fichier qui apparaît 2x
        new_tableau.push_back(tableau[i]);
    fichier.close();
    return new_tableau;
}

/** Test de la fonction litTableau **/
void testLitTableau() {
    CHECK(litTableau("donnees/donnees-test.txt", 4) == tableauTest);
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    CHECK(t.size() == 22994);
    CHECK(t[0][0] == "F");
    CHECK(t[4][2] == "Astrid");
    CHECK(t[5][3] == "12");
}

/** Extraction d'une colonne d'un tableau de données
 * @param t un tableau 2D de chaines de caractères
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur de chaines de caractères
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
vector<string> colonne(vector<vector<string>> t, int j) {
    vector<string> tableau;
    for (int i = 0; i < t.size(); i++)
        tableau.push_back(t[i][j]);
    return tableau;
}

/** Test de la fonction colonne **/
void testColonne() {
    CHECK(colonne(tableauTest, 0) == vector<string>({"M","F","F","F"}));
    CHECK(colonne(tableauTest, 1) == vector<string>({"2011","2012","2011","2011"}));
    CHECK(colonne(tableauTest, 2) == vector<string>({"Bubulle","Bichette","Babouche","Ziboulette"}));
    CHECK(colonne(tableauTest, 3) == vector<string>({"3","4","7","1"}));
}

/** Convertit un tableau de chaines de caractères en un tableau d'entiers
 * @param t, un vecteur de chaines de caractères
 * @return un vecteur d'entiers
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

void testConversionInt() {
    CHECK(conversionInt({}) == vector<int>({}));
    CHECK(conversionInt({"1","2","3"}) == vector<int>({1,2,3}));
}

/** copier la fonction somme déjà écrite **/
int somme(vector<int> t) {
    int somme = 0;
    for (int i = 0; i < t.size(); i++)
        somme += t[i];
    return somme;
}

/** copier la fonction moyenne déjà écrite **/
int moyenne(vector<int> t) {
    int somme = 0;
    for (int i = 0; i < t.size(); i++)
        somme += t[i];
    return somme / t.size();
}

/** copier la fonction indiceMax déjà écrite **/
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

/** Sélection des lignes d'un tableau de données
 * Sélectionne un ensemble de lignes en fonction d'un critère donné
 * @param t, un tableau contenant des lignes de données
 * @param j, l'indice de la colonne à vérifier
 * @param valeur, une chaine de caractères correspondant au critère
 * @return un tableau de données ne contenant que les lignes de t telles
 *  que la colonne j ait la valeur correspondant au critère
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    vector<vector<string>> tableau;
    for (int i = 0; i < t.size(); i++) {
        if (t[i][j] == valeur)
            tableau.push_back(t[i]);
    }
    return tableau;
}

/** Test de la fonction selectLignes **/
void testSelectLignes() {
    CHECK(selectLignes(tableauTest, 0, "M") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}}));
    CHECK(selectLignes(tableauTest, 1, "2011") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}, { "F", "2011", "Babouche", "7"}, { "F", "2011", "Ziboulette", "1"}}));
}

/** Lance les tests de litTableau, selectLignes et colonne puis
 * affiche le nombre total de naissances puis
 * demande à l'utilisateur un prénom et calcule et affiche
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
int main() {
    testAfficheTableau();
    testLitTableau();
    testColonne();
    testSelectLignes();

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

