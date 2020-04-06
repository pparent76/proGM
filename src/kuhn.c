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
/* l'algorithme de kuhn a pour but de trouver la solution d'affectation de cout minimal*/
#include"kuhn.h"
#include "etape0.h"
#include "etape1.h"
#include "etape2.h"
#include "etape3.h"
#include <stdlib.h>


int* kuhn ( int **mat, int taille)

{
  int i;
  int **symbol,**X,*res;
  int nbzero;
  int sol;
  X=malloc(2*sizeof(int*));
  X[0]=malloc(taille*sizeof(int));
  X[1]=malloc(taille*sizeof(int));
  symbol=malloc(taille*sizeof(int*));
  for(i=0;i<taille;i++) symbol[i]=malloc(taille*sizeof(int));
 
  etape0 (mat,taille);
  initTabTemp (symbol,mat,taille,&nbzero); 
   
  while(! etape1 (symbol,taille,&res))
    {etape2(X,symbol,taille);
      etape3(mat,X,taille);
      initTabTemp (symbol,mat,taille,&nbzero); 
    }

  return res;
}

