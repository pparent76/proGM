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


#include"etape2.h"

int noZeroLine(int *l, int taille)/*regarde si il n'y a pas de zero sur la ligne*/
{
  int i;
      for(i=0;i<taille;i++)
	if(l[i]==-1) return 0;
      return 1;
    
}

void firstMark(int **symbol,int *X[2],int taille)/*premier marquage de lignes (sous etape a)*/
{
  int i;
  for(i=0;i<taille;i++)/*initialise le tableau de marquage à zero*/
    {
      X[0][i]=0;
      X[1][i]=0;
    }
  for(i=0;i<taille;i++)
    if(noZeroLine(symbol[i],taille)) /*si il n'y a pas de zero sur la ligne*/
      X[0][i]=1;
 
}



int  markColon(int **symbol, int **X,int taille)/*marque les colones comme expliqué pour la sous-etape b*/
{
  int i,j;
  int change=0;
  for(i=0;i<taille;i++)/*pour toute les lignes*/
    if(X[0][i]==1)/*si elle est marquée*/
      for(j=0;j<taille;j++)/*recherche tous les zero baré (symbole>1)*/
	      if(symbol[i][j]>=2)
		if(X[1][j]==0)/*si la colone n'est pas déja marquée*/
		  {X[1][j]=1; change=1;}/*la marquer*/
 
  return change;
}



int markLine(int **symbol,int **X,int taille)  /*marque les lignes comme indiqué à l'étape c-*/
{
  int i,j;
  int change=0;
  for(i=0;i<taille;i++)/*pour toute les colonnes*/
    if(X[1][i]==1)/*si elle est marquée*/
      for(j=0;j<taille;j++)/*recherche les zero encadrés (symbole=-1)*/
	      if(symbol[j][i]==-1)
		if(X[0][j]==0)/*si la ligne est pas deja marquée*/
		  {X[0][j]=1;change=1;}/*la marquer.*/
  return change;
}

void etape2(int **X,int**symbol, int taille)/*effectue le marquage*/
{
  int a,b;
  firstMark(symbol,X,taille);
  do{a=markColon(symbol,X,taille); b=markLine(symbol,X,taille);} while(a || b);/*tant qu'il y a du marquage continue a marquer.*/
}

