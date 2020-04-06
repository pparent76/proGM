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

/*l'étape 3 de l'algorithme hongrois(kuhl) a pour but de recalculer une nouvelle matrice
de cout ayant la même solution de minimisation celon le procédé suivant:
calcule le minimum des ellements sur une ligne ou colonne marquée (non baré)
le retranche a tout ellement sur une ligne ou colonne marquée (non baré)
l'ajoute à tout éllement à la fois sur une ligne non marqué et sur une collone non marquée (baré)*/

int isBarreLigne(int **X,int i); /*regarde si la ligne est barée (non-marquée)*/
int nbBarre(int **X,int i, int j);/*combien de fois un ellement est baré(non marqué)(0 1 ou 2)*/
void etape3(int **v,int**X ,int taille);/*calcul le nouveau tableau de cout*/
