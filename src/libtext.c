/*
  Copyright (c) 2009 Pierre Parent
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

#include "libtext.h"
#include <stdlib.h>

int  readName(char  path[50],tex **Name,int *nb) /*lis une liste de nom dans un fichier*/
{ 
  int i;
  FILE* fichier = NULL;/*ouverture du fichier*/
  fichier = fopen(path, "r");
  if (fichier == NULL)
    return 0;
    
  int taille=fSize(path);
  if (*nb==-1) *nb=taille+1;

  *Name= malloc(*nb*sizeof(tex));/*allocation dynamique*/

  for (i=0;i<*nb;i++)/*lecture*/
    {
      if (i<=taille){fscanf(fichier,"%s",((*Name)[i]).s);}
      else{sprintf(((*Name)[i]).s,"%d",i+1);}
    }

    fclose(fichier);   
 return 1;
}



int readMinName(char  path[50],tex **Name,int *nb) /*lis une liste de nom dans un fichier en forcant le nombre minimal uniquement*/
{
  int i;
  FILE* fichier = NULL;
  fichier = fopen(path, "r");/*ouverture du fichier*/
  
  if (fichier==NULL){return 0;}

  int taille=fSize(path);
  if (*nb==-1 || taille+1>*nb) *nb=taille+1;
 
  *Name= malloc(*nb*sizeof(tex));/*allocation dynamique*/

  for (i=0;i<*nb;i++)/*lecture*/
    {
      if (i<=taille){fscanf(fichier,"%s",((*Name)[i]).s);}
      else{sprintf(((*Name)[i]).s,"%d",i+1);}
    }

    fclose(fichier);   
 return 1;
}




void  numName(tex **Name,int *nb)/*attribu au nom une numeroatition*/
{
  int i;
  *Name= malloc(*nb*sizeof(tex));
  for (i=0;i<*nb;i++)
    {
      sprintf((*Name)[i].s,"%d",i+1);
    }
}




int fSize (char path[50])/*recupére la nombre d'ellement contenu dans un fichier*/
    { int res=0;
      char tampon[50];

      FILE* fichier = NULL;
      fichier = fopen(path, "r");

      while(fscanf(fichier,"%s",tampon)!=EOF)
	res++;
      fclose(fichier); 
      return res-1;
    }




void bwrite(tex *Name,int nb) /*ecrit la liste des binomes*/
{
  int i;
  for (i=0;i<nb;i++)
    printf("Binome %s\n ",Name[i].s);
}




void pwrite(tex *Name,int nb) /*ecrit la liste des projets*/
{
  int i;
  for (i=0;i<nb;i++)
    printf("Projet %s\n ",Name[i].s);
}

