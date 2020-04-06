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

/*l'étape 0 de l'algorithme hongrois(kuhl) a pour but de réduire le tableau 
  c'est à dire qu'elle soustrait à chaque ligne et colonne son plus petit élement*/
#include "etape0.h"

int minLig (int *l, int taille)
{
  int i;
  int min;
  min=l[0];
  for(i=0;i<taille;i++)
    if(min>l[i]) min=l[i];
  return min;
}


void soustraitCol(int **v, int taille) /*soustrait son plus petit éllément aux colones*/
{
  int i,j,k;
  int min;
  for(i=0;i<taille;i++)/* pour chaque colone*/
  {
    min=v[0][i];
    for(k=0;k<taille;k++)/*calcule le min*/
    {
      if(v[k][i]<min) min=v[k][i];
    }

    for(j=0;j<taille;j++)/*le soustrait à toute la colone*/
      v[j][i]=v[j][i]-min;
  }
}


void soustraitLig(int **v, int taille) /*soustrait son plus petit éllément aux lignes*/
{
  int i,j;
  int min;
  for(i=0;i<taille;i++)/*pour chaque ligne*/
    {
      min=minLig(v[i],taille);/*soustrait le min à la ligne*/
      for(j=0;j<taille;j++)
	v[i][j]=v[i][j]-min;
    }
  
 
}


void etape0 (int **v, int taille) 
{  
  soustraitLig(v,taille);
  soustraitCol(v,taille);
 
}


