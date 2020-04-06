/*
  Copyright (c) 2009 Pierre Parent and Pierre Houssin
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
L'étape 1 de l'algorithme de kuhn permet d'encadrer un zero par ligne et par collone si possible (et donc de trouver la solution finale), sinon encadre un maximum de zero de maniére aléatoire.
Cette étape utilise le tableau de symbole dont la symbolique est la suivante

1: zero non encadré et non baré
-1:zero encadré
>1: zero baré (le chiffre correspond au nb fois qu'il a été baré +1)
 */



void initTabTemp (int **symbol,int **v,int taille, int *nbzero);/*Initialise le tableau de symbole avec la matrice*/
int searchLine(int **symbol, int taille);/*recherche la ligne ayant le moins de zero.*/
void handleZero(int i, int j, int **symbol, int taille, int *nbzero);/*permet d'encadre un zero et barer ceux sur la meme colone ou ligne*/
int nbZero(int **symbol,int taille,int i, int ligne); /* calcul le nombre de zero sur une ligne ou une colone.*/
int getRownZero(int **symbol,int taille,int n, int i,int ligne);/*récupére l'endroit de la ligne ou collone qui est la iéme a avoir n zero.*/
int findnZero(int **symbol,int taille,int i,int n, int ligne);/*trouve la position du nieme zero d'une ligne ou colone i*/
int zeroSamePlace(int **symbol,int taille,int i, int j,int nbZero, int ligne);/*regarde si deux ligne ou colone i j on leur nbZero zero à la même place*/
int nbSameRow(int **symbol,int taille, int i, int ligne);/*calcul le nombre de ligne ou colone ayant les même zero que i*/
void markRow(int **symbol,int taille, int i, int ligne);/*encadre arbitrairement un zero d'une ligne ou colone i*/
int * markSameRow(int **symbol,int taille,int i,int ligne);/*marque toutes les lignes/collone pareils que i*/
int checkSol(int *sol,int taille); /*verifie si la solution est compléte et cohérente*/
int etape1(int **symbol, int taille,int **res) ;/*l'étape 1 encadre des zeros (cf. au dessus)*/
