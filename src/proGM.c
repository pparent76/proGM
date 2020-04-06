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
#include "kuhn.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{/*définition des varaibles générales*/
  char folder[50];
  char path[50];
  int i;
  int biName=1;/*variables des differents modes*/
  int proName=1;
  int matrix=0;
  int fNb=0;
  int detail=0;
  int  methode2=0;
  tex *bName;/*nom des binome et projet*/
  tex *pName;
  int nbb=-1;
  int nbp=-1;
  int *res;
  int n=0;
  int maxCout,totCout;
  double moyCout;
  int nbcheat=-1;/*variable de favorisation de binome.*/
  tex *cheatName;
 
  cheatName= malloc(argc*sizeof(tex));

  if (argc==1) {printf("Erreur: définissez le répertoire de donnés\n");exit(0);}
  char help[]="--help";
  if (strcmp(argv[1],help))/*gestion de l'aide*/
    {printf("pour obtenir de l'aide allez dans le dossier doc/ ou tapez man proGM \n");exit(0);}


  while (argv[1][n]!='\0' && argv[1][n]!=' ' ) /*copie du premier argument dans folder.(dossier de données)*/
    {folder[n]=argv[1][n];
      n++;} 
  folder[n]='\0';




  for (i=2;i<argc;i++)/*lecture des arguments du programme*/
    {
      if (argv[i][0]=='-' && argv[i][1]=='b' && biName==1) 
	biName=0; 
	  else if (argv[i][0]=='-' && argv[i][1]=='p'&& proName==1) 
	    proName=0;
	  else if (argv[i][0]=='-' && argv[i][1]=='m'&& !matrix && !methode2) 
	    matrix=1;  
	  else if (argv[i][0]=='-' && argv[i][1]=='d'&& !detail) 
	    {detail=1;
	      printf("Affichage des details.\n");}
	  else if (argv[i][0]=='-' && argv[i][1]=='a'&& !methode2 && !matrix)
	    { methode2=1;
	      printf("Les binomes doivent inscrire le n° des choix en face des projets\n");
	    }
	  else if (argv[i][0]=='-' && argv[i][1]=='n'&& fNb==0) 
	    {fNb=1;
	      printf("Lecture obligatoire du nombre de binomes:\n");}
	  else if (argv[i][0]=='-' && argv[i][1]=='f'&& i!=argc-1) 
	    {nbcheat++;i++;
	      sprintf((cheatName[nbcheat]).s,"%s",argv[i]); }
	  else
	    {printf("Le paramétre suivant n'as pas été reconnu: %s .Ignoré\n",argv[i]);}
    }

  if(!biName || fNb)/*si besoin demande le nombre de binomes et projets à gérer*/
    {
      printf("Nombre de binomes à gérer:");
      scanf("%d",&nbb);

      while (nbp<nbb)
	{printf("Nombre de projet à gérer:");
	  scanf("%d",&nbp);}
    }

  
  if (biName)/*si le nom des fichier est géré par fichier*/
    
    {/*lecture des nom de binome dans le fichier.*/
       printf("Nom des binomes lus dans le fichier:    %s/0biName.txt\n",folder);
      sprintf(path,"%s/0biName.txt",folder);
      if(!readName(path,&bName,&nbb))
      {printf("Erreur de lecture du fichier.\n"); exit(0);}
    }
  
  else{numName(&bName,&nbb);}/*sinon numérote simplement*/

  if (detail) {printf("--liste des binomes:\n ");bwrite(bName,nbb); }
     
  if (nbp==-1) nbp=nbb;/*(il doit y avoir au moins autant de projet que de binomes)*/
   




  if (proName)/*si le nom des projets est géré par fichier*/ 

    { /*lecture des nom de projet dans le fichier.*/
     printf("Nom des projets lus dans le fichier:    %s/0proName.txt\n",folder);
       sprintf(path,"%s/0proName.txt",folder);
       if(!readMinName(path,&pName,&nbp))
	 {printf("Erreur de lecture du fichier.\n"); exit(0);}
   }

  else{numName(&pName,&nbp);}/*sinon numérote simplement*/    


  if (detail) {printf("--liste des projets:\n ");pwrite(pName,nbp);
    printf("->Il y a %d binomes et %d projets\n",nbb,nbp);}
  


  int **mat=genMat(nbb,nbp);
  if (matrix)
    { /*lis le fichier matrix.txt si nessecaire (-m)*/
      printf("Matrice lue dans le fichier:    %s/matrix.txt\n",folder);
      sprintf(path,"%s/matrix.txt",folder);
      if(!readMat(mat,nbb,nbp,path))
	{printf("Erreur de lecture du fichier matrix. Ne peut continuer\n");exit(0);}
    }
   else if(methode2)
     { if(!fillMat2(mat,nbb,nbp,pName,bName,folder))
	{printf("Fichier de données de binomes manquant, ne peut continuer\n");exit(0);}
     }
  else
    { /*Sinon remplie la matrice grace aux fichier de spécification des binomes.*/
      if(!fillMat(mat,nbb,nbp,pName,bName,folder))
	{printf("Fichier de données de binomes manquant, ne peut continuer\n");exit(0);}
    }

  handleCheating(nbcheat,cheatName,bName,nbb,nbp,mat);/*gére la favoristaion d'un binome.*/
  if (detail){printf("%d binomes sont favorisés\n",nbcheat+1);
    printf("voici la matrice de coups:\n");affMat(mat,nbb,nbp,bName);}
  int **mat2=copyMat(mat,nbp);
  res=kuhn(mat2,nbp);
  
  for (i=0;i<nbb;i++)
    printf("\nLe Binome %20.20s   recois le projet %20.20s (choix %d)",(bName[i]).s,(pName[res[i]]).s,mat[i][res[i]]);
  printf("\n");

  maxCout=0;totCout=0;
 for (i=0;i<nbb;i++)
   {
     totCout+=mat[i][res[i]];
     if(mat[i][res[i]]>maxCout)maxCout=mat[i][res[i]];
   }
 moyCout=1.0*totCout/nbb;
   if (detail)
     printf("\nCout total:%d\nChoix maximal obtenu:%d\nMoyenne des Couts:%lf\n",totCout,maxCout,moyCout);
}
