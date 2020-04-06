/*
  Copyright (c) 2009 Pierre Houssin
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
/*l'etape 2 de l'algorithme de kuhn a pour but de marquer des lignes et des collones celon le procédé suivant:
a-marquer toute ligne n'ayant pas de zero encadré
b-marquer toute colone ayant un zero baré sur une ligne marquée
c-marquer toute ligne ayant un zero encadré sur une colone marqué
d-revenir à b- juqsu'a ce qu'on ne puisse plus rien marquer

le marquage s'effectue dans X
X[0][n] represente la niéme ligne
X[1][n] représente la niéme colonne
la symbolique est la suivante:
0: non marqué
1: marqué

Cette etape utilise la matrice symbol (cf epate1)
 */



int noZeroLine(int *l, int taille);/*regarde si il n'y a pas de zero sur la ligne*/
void firstMark(int **symbol,int *X[2],int taille);/*premier marquage de lignes (sous etape a)*/
int markColon(int **symbol, int **X,int taille);/*marque les colones comme expliqué pour la sous-etape b*/
int markLine(int **symbol,int **X,int taille); /*marque les lignes comme indiqué à la sous-étape c*/
void etape2(int **X,int**symbol, int taille);/*effectue le marquage*/
