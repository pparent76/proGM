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


#include "etape1.h"
#include <stdlib.h>

void initTabTemp (int **symbol,int **v,int taille, int *nbzero) /*Initialise le tableau de symbole avec la matrice*/
{
  int i,j;
  nbzero=0;
  for(i=0;i<taille;i++)
  {
    for(j=0;j<taille;j++)
    {
      if(v[i][j]==0) { symbol[i][j]=1; nbzero++;}
      else symbol[i][j]=0;
    }
  }
 
}


int searchLine(int **symbol, int taille)/*recherche la ligne ayant le moins de zero.*/
{
  int i;
  int min,j,temp,bi;
  bi=-1;/*si ne trouve aucune ligne avec un zero renvois -1*/
  min=taille;
  for(i=0;i<taille;i++)
  {
    temp=nbZero(symbol,taille,i,1);
    if( min>temp && temp != 0)
    {
      min=temp;
      bi=i;
    }
  }
  return bi;
}

void handleZero(int i, int j, int **symbol, int taille, int *nbzero)/*permet d'encadre un zero et barer ceux sur la meme colone ou ligne*/
{
int k;
if (symbol[i][j]==1)
    {
      *nbzero=*nbzero-1;
      symbol[i][j]=-1;
      for(k=0;k<taille;k++)
	{
	  if(symbol[i][k]>=1 && k!=j) 
	    {
	      symbol[i][k]++;
	      if(symbol[i][k]==2) *nbzero=*nbzero-1;
	    }
	}
      for(k=0;k<taille;k++)
	{
	  if(symbol[k][j]>=1 && k!=i) 
	    {  
	      symbol[k][j]++;
	      if(symbol[k][j]==2)*nbzero=*nbzero-1;
	    }
	}
    }
}

int nbZero(int **symbol,int taille,int i,int ligne) /*calcul le nombre de zero sur une ligne ou une colone. (variable ligne: 1 si ligne 0 si colone)*/
{
 int j;
 int  res=0;
  for (j=0;j<taille;j++)
    {
      if (ligne && symbol[i][j]==1) res++;
      if (!ligne && symbol[j][i]==1) res++;
    }
 return res;
}



int getRownZero(int **symbol,int taille,int n, int i,int ligne)/*récupére la ligne ou collone qui est la iéme a avoir n zero. (variable ligne: 1 si ligne 0 si colone)*/

{
  int res=-1;
  int nb=0;
  while (nb!=i)
    {res++; 
      if(res==taille) break;
      if (nbZero(symbol,taille,res,ligne)==n) nb++;
     
    }
  if (res==taille)return -1; /*n'as pas put trouver assez de zero*/
  else return res;
}

int findnZero(int **symbol,int taille,int i,int n,int ligne)/*trouve la position du nieme zero d'une ligne ou colone i  (variable ligne: 1 si ligne 0 si colone)*/
{
  int res=-1;
  int nb=0;
  while (nb!=n)
    {res++;
      if(res==taille) break;
      if (ligne && symbol[i][res]==1)nb++;
      if (!ligne && symbol[res][i]==1)nb++;
     }
  if (res==taille) return -1;/*n'as pas trouvé assez de zero*/
  else return res;

}

int zeroSamePlace(int **symbol,int taille,int i, int j,int nbZero, int ligne)/*regarde si deux ligne ou colone i j on leur nbZero zero à la même place  (variable ligne: 1 si ligne 0 si colone).*/
{ 
  int k;
  for (k=1;k<=nbZero;k++)
      if(findnZero(symbol,taille,i,k,ligne)!=findnZero(symbol,taille,j,k,ligne))
	return 0;
  return 1;
}

int nbSameRow(int **symbol,int taille, int i, int ligne)/*calcul le nombre de ligne ou colone ayant les même zero que i  (variable ligne: 1 si ligne 0 si colone)*/
{
  int k;
  int res=0;
  int nbZ=nbZero(symbol,taille,i,ligne);
  for (k=0;k<taille;k++)
    if(nbZero(symbol,taille,k,ligne)==nbZ && zeroSamePlace(symbol,taille,i,k,nbZ,ligne))
      res++;
  return res;
}

void markRow(int **symbol,int taille, int i,int ligne)/*encadre arbitrairement un zero d'une ligne ou colone i  (variable ligne: 1 si ligne 0 si colone)*/
{if (i==-1) return;
 int nbZ=nbZero(symbol,taille,i,ligne);  
 int j=1+(int)(nbZ*((1.*rand())/RAND_MAX));
  if (ligne)
    handleZero(i,findnZero(symbol,taille,i,j,ligne),symbol,taille,&nbZ);
  else
    handleZero(findnZero(symbol,taille,i,j,ligne),i,symbol,taille,&nbZ);
  
}

int * markSameRow(int **symbol,int taille,int i,int ligne)/*marque toutes les lignes/colone pareils que i  (variable ligne: 1 si ligne 0 si colone)*/
{
  int k;
  int nbZ=nbZero(symbol,taille,i,ligne);
  int *tab;
  tab=malloc(taille*sizeof(int));
  
  for (k=0;k<taille;k++) 
    if(nbZero(symbol,taille,k,ligne)==nbZ && zeroSamePlace(symbol,taille,i,k,nbZ,ligne))
      {tab[k]=1;}
    else
      tab[k]=0;

  for (k=0;k<taille;k++)
    if(tab[k])
      markRow(symbol,taille,k,ligne);
}

int checkSol(int *sol,int taille) /*verifie si la solution est compléte et cohérente*/
{
  int i,j;
  int ok;
  for (i=0;i<taille;i++)
    {ok=0;
    for (j=0;j<taille;j++)
      if (sol[j]==i) ok=1;
    if (ok==0) {return 0;}
    }
  return 1;
}

int etape1(int **symbol, int taille,int **res)/*l'étape 1 encadre des zeros (cf. au dessus).*/
{
  int ligne=1;
  int nbMark=0;/*nb de zero marqué*/
  int n=1;
  int i,j,k;
  int l;
  int incremente;

  while (nbMark!=taille) /*tant qu'on a pas encadré un zero par ligne au par collone (ou essayé en vain)*/
    { while (n!=taille+1-nbMark && nbMark!=taille) /*tant que n n'as pas depassé le nb de zero maximal trouvable sur une ligne.*/
      {incremente=1;
	  i=1;    
	  for (k=1;k<=2;k++)/*pour lignes et colonnes*/
	    {ligne=(k==1);/*on tente de trouver n ligne ou colones, à n zero, identique au niveau des zeros*/
	      while ((l=getRownZero(symbol,taille,n, i,ligne))!=-1)
		{
		  if( nbSameRow(symbol,taille,l,ligne)==n)
		    { markSameRow(symbol,taille,l,ligne); /*si on a trouvé ces n lignes/colones à n zero non baré identiquement placés*/
		      incremente=0;             /*on peut alors encadrer  arbitrairement sur ces lignes/colones, n retombe à 1*/
		      nbMark+=n;                /*on augmente le nb de marquages*/
		      n=1;
		      i=0; 
		    }
		  i++;
		}
	    }
	  if (incremente){n++;}
	}
      if(nbMark!=taille)/*si on ne peut plus trouver n lignes/colones à n zero non baré identiquement placés*/
	{int s;
	    do{s=searchLine(symbol,taille);
	      markRow(symbol,taille,s,1);n=0;nbMark++;}while(s==-1 && nbMark!=taille);}
      /*on marque aléatoirement (si on peut) un zero, on augmente le nb de marquage (meme si on peut pas marquer)*/
    }
    
 
  *res=malloc(taille*sizeof(int));/*définie le resultat*/
  for(i=0;i<taille;i++)
    {(*res)[i]=-1;
      for(j=0;j<taille;j++)
	if(symbol[i][j]==-1) (*res)[i]=j;}

  
  if(checkSol(*res,taille))/*verifie la solution est la renvois si necessaire.*/
    { return 1;}
  else
    {free(*res); return 0;}


}
