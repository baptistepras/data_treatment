/** @file **/
#include <vector>
#include <string>
using namespace std;

/** Construction d'un tableau 2D de chaînes lu depuis un fichier CSV
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * d'entiers par ligne, séparés par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau d'entiers à deux dimensions
 * Auteur: Baptiste Pras
 * Degré de confiance: 100%
 **/
vector<vector<string>> litTableauCSV(string fichier, int nb_colonnes);

/** Construction d'un tableau 2D de chaînes lu depuis un fichier CSV
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * d'entiers par ligne, séparés par des espaces
 * @return un tableau d'entiers à deux dimensions
 * Auteur: Baptiste Pras
 * Degré de confiance: 10%
 * Raison: Je pense avoir une bonne base, mais je traite très mal le fait de savoir si l'on se trouve sur la dernière case de la 
 * ligne ou non, résultat sur un return faux
 **/
vector<vector<string>> litTableauCSV(string fichier);



