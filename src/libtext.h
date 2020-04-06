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

#include "stdio.h"

typedef struct tex { char s[50];}tex; 
int  readName(char  path[50],tex **Name,int *nb); /*lis une liste de noms dans un fichier*/
int  readMinName(char  path[50],tex **Name,int *nb); /*lis une liste de noms dans un fichier en forcant le nombre minimal uniquement*/
void  numName(tex **Name,int *nb);/*attribu au nom une numeroatition*/
int fSize (char path[50]);/*recupére la nombre d'ellement contenu dans un fichier*/
void bwrite(tex *Name,int nb);/*ecrit la liste des binomes*/
void pwrite(tex *Name,int nb);/*ecrit la liste des projets*/
