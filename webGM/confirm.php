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
 
 $fichier=((string)$_GET['entete']).((string)$_GET['code']).".txt";
if (((int)$_GET['code'])==0 or !file_exists($fichier))//test si le code est bien un entier et si il correspond à un fichier temporaire.
		{
		echo "<b> adresse invalide </b>".fichier;
		exit;
		}


$donnes=file($fichier);
$binome=(string)$donnes[0];
$binome=Trim($binome);
$fichier=$binome.".txt";


if (!$fichierFinal = fopen($fichier,"w")) {echo "Echec de l'ouverture du fichier";exit;}//ouvre le fichier final (nomdubinome.txt)

 for( $i = 1 ; $i < count($donnes) ; $i++ )//pour chaque choix contenue dans les donnés
		    {
		    $donnes[$i]=Trim($donnes[$i]);
		    fputs($fichierFinal,$donnes[$i]);// le met dans le fichier final.
		    fputs($fichierFinal,"\n");
		    }
fclose($fichierFinal);

 $fichier=((string)$_GET['entete']).((string)$_GET['code']).".txt";
unlink($fichier);
unlink(((string)$_GET['entete']).".txt");//suprime les fichier temporaires
unlink($binome);
echo "<b> Vos choix ont correctement été enregistrés, vous pouvez fermer cette page. </b>"
?>

