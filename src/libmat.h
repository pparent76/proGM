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

int** genMat(int nbb,int nbp);
void affMat(int **mat,int nbb,int nbp,tex *bname);
int readMat(int **mat,int nbb,int nbp,char path[50]);/*lis la matrice dans le fichier matrix.txt*/
int fillMat(int **mat,int nbb,int nbp,tex *pName,tex *bName, char folder[50]);/*rempli la matrice grace au fichier de spécification de chaque binome*/
int fillMat2(int **mat,int nbb,int nbp,tex *pName,tex *bName, char folder[50]);
int sCout(char folder[50],tex binome,tex projet,int nb);/*recherche le classement d'un projet donné pour un binome grace a son fichier.*/
int maxCout(char folder[50],tex binome,tex *pNmae,int nbb,int nbp); /*calcule le classement maximal donné par un binome*/
int strcmp(char s1[],char s2[]);/*compare l'egalité de deux chaines*/
int ** copyMat(int **m,int n);/*crée une copie d'un matrice*/
void handleCheating(int nbcheat,tex *cheatName,tex *bName,int nbb,int nbp, int **mat);/*gére la favoristaion d'un binome.*/
