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

/*l'étape 0  a de l'algorithme hongrois pour but de réduire le tableau 
  c'est à dire qu'elle soustrait à chaque ligne et colonne son plus petit élement*/

int minLig (int *l, int taille);
void soustraitCol(int **v, int taille); /*soustrait son plus petit éllément aux colones*/
void soustraitLig(int **v, int taille);/*soustrait son plus petit éllément aux lignes*/
void etape0 (int **v, int taille);


