
<?php
/*
  Copyright (c) 2009,2010 Pierre Parent
  
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
 
 
 $fichier=((string)$_GET['entete']).".txt";
if ( ((int)$_GET['entete'])==0 or !file_exists($fichier))//test si le code est bien un entier et si il correspond à un fichier temporaire.
		{
		echo "<b> adresse invalide </b>";
		exit;
		}
		
$fich=file($fichier);
$binome=(string)$fich[0];
$binome=Trim($binome);

$handle = opendir('.');


    //Suprimer tous les fichiers dont le nom commence par l'entête (donc le fichier de code complet aussi)
while(false!=($file=readdir($handle))) {
        if (strlen($file)>strlen(((string)$_GET['entete']))
		   and substr($file,0,strlen(((string)$_GET['entete'])))==(string)$_GET['entete'])
	  {
	    unlink($file);
	    }
    }
  //suprime le fichier du nom de binome correspondant il peut donc recommencer ses choix.
unlink($binome);

echo "<b> Vos choix ont été éffacés vous pouvez les recommencer en retournant sur la page principale </b>";?>