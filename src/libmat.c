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

#include "libmat.h"
#include <stdlib.h>

int** genMat(int nbb,int nbp)
{
 int **res;
 int i,j;
 res=malloc(nbp*sizeof(int *));/*allocation dynamique.*/
  for (i=0;i<nbp;i++)
	res[i]= malloc(nbp*sizeof(int));

  for (i=0;i<nbp;i++)/*initialisation*/
    for (j=0;j<nbp;j++)
      res[i][j]=1;

  return res;
}



void affMat(int **mat,int nbb,int nbp,tex *bName)
{
  int i,j;
  for (i=0;i<nbb;i++)
    {printf("Binome %9.9s|        ",(bName[i]).s);
      for(j=0;j<nbp;j++)
	printf("%5.1d ",mat[i][j]);
      printf("\n");
    }
}



int readMat(int **mat,int nbb,int nbp,char path[50])/*lis la matrice dans le fichier matrix.txt*/
{
  int i,j;
  FILE* fichier = NULL;
  fichier = fopen(path, "r");
  if (fichier==NULL)return 0;
    for (i=0;i<nbb;i++)
      for (j=0;j<nbp;j++)
	fscanf(fichier,"%d",&mat[i][j]);
  fclose(fichier);
  return 1;
}


int fillMat(int **mat,int nbb,int nbp,tex *pName,tex *bName, char folder[50])/*rempli la matrice grace au fichier de spécification de chaque binome*/
{
  int max;
  int i,j;
  for (i=0;i<nbb;i++)/*pour tous les binomes*/
    { 

      /*recupére le maximum des choix qu'il a donné afin de ne pas lui donner de choix superieur à ce max si il n'as pas tout classé (ce qui l'avantagerais).*/
      if ((max=maxCout(folder,bName[i],pName,nbb,nbp))==-1)return 0;
     
      for(j=0;j<nbp;j++)
	{/*calcul le coup de chacun des projet pour ce binome*/
	  mat[i][j]=sCout(folder,bName[i],pName[j],max+1);
	}
    }
  return 1;
}

int fillMat2(int **mat,int nbb,int nbp,tex *pName,tex *bName, char folder[50])/*rempli la matrice lorseque les binome donne le n° de leur choix.*/
{
  int i,j;
 char path [50];
 char tampon[50]="";
 /*ouverture du fichier de choix du binome donné*/
  FILE* fichier = NULL;
 
  
  for (i=0;i<nbb;i++)
	{sprintf(path,"%s/%s.txt",folder,(bName[i]).s);
	 fichier = fopen(path, "r");
	 if (fichier==NULL) {printf("%s\n",path);return 0;}
	      for(j=0;j<nbp;j++)
		fscanf(fichier,"%s%d",tampon,&mat[i][j]);
	      fclose(fichier);
	}

  return 1;
}



int sCout(char folder[50],tex binome,tex projet,int max)/*recherche le classement d'un projet donné pour un binome.*/
{char path [50];
 char tampon[50]="";
 int n=0;
 sprintf(path,"%s/%s.txt",folder,binome.s); /*ouverture du fichier de choix du binome donné*/
  FILE* fichier = NULL;
  fichier = fopen(path, "r");
  if (fichier==NULL) {printf("%s\n",path);return -1;}

  while (!strcmp(projet.s,tampon) && n!=max) /*max est la valeur maximale que peut avoir le cout.*/
    {if(fscanf(fichier,"%s",tampon)==EOF)
	n=max;
      else
      n++;
    }
	
  fclose(fichier);
  return n;
}


int maxCout(char folder[50],tex binome,tex *pName,int nbb,int nbp) /*calcule le classement maximal donné par un binome*/
{
  int i;
  int res=0;
  int tmp;
  for (i=0;i<nbp;i++)
    {
      tmp=sCout(folder,binome,pName[i],nbp+1);
      if (tmp==-1)return -1;/*gére les erreurs.*/
      if (tmp>res && tmp!=nbp+1)res=tmp;
    }
  return res;
}



int strcmp(char s1[50],char s2[50])/*compare l'egalité de deux chaines*/
{
  int n=0;
    while(s1[n]!='\0')
      {
	if (s1[n]!=s2[n])
	  {return 0;}
	n++;
      }
    if (s1[n]!=s2[n])
      {return 0;}
    return 1;

}



int ** copyMat(int **m,int n)/*crée une copie d'un matrice*/
{
  int i,j;
  int ** res;
  res=genMat(n,n);
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
      res[i][j]=m[i][j];
  return res;
}


void handleCheating(int nbcheat,tex *cheatName,tex *bName,int nbb,int nbp, int **mat)/*gére la favoristaion d'un binome.*/
{
  int i,j,k;
  if (nbcheat==-1) return;
  for (j=0;j<=nbcheat;j++)
    for (i=0;i<nbb;i++)   
      if (strcmp(cheatName[j].s,bName[i].s))
		 for (k=0;k<nbp;k++)
		   if (mat[i][k]!=1)mat[i][k]+=nbp;
    

}
