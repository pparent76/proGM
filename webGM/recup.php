<?php
/*
  Copyright (c) 2009,2010 Pierre Parent
  Copyright (c) 2010 Josselin beisser
  Thanx to Leo letaro for his help.
  
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

/* Le systéme de vérification par mail se fait grace à la génération d'un code aléatoire transmis dans le mail.
Le code et constitué d'une entête et du reste du code.
L'entête suffit pour anuler les choix, alors qu'il faut le code complet pour les confirmer.
Cela permet d'annuler les choix directement à partir de cette page en cas de non-reception du mail sans pour antant permettre
à quelqu'un de valvaillant de valider ses choix directement à partir de cette page;
des fichiers portant le nom de l'entête et du code complet sont créer pour pouvoir verifier le code par la suite.
*/
				 
$binome=Trim($_POST['binome']);
$binomeValide=false;

//verification de la validité du binome envoyé-------------

$fichier="0biName.txt"; //On ouvre le fichier 0biname.txt
		   		$tabfich=file($fichier);

		   		for( $i = 0 ; $i < count($tabfich) ; $i++ )// Pour chacune des entrées
				      {
				      $tabfich[$i]=Trim($tabfich[$i]);// on surpime les espaces
				      if ($binome==$tabfich[$i]) // si il a pas deja fait ses choix.
					      	$binomeValide=true;
				      }
				      
//-------------------------------------------------

if (!$binomeValide) // Si le nom du binome ne correspond à rien.
	{
	echo "<b><u>Erreur:</u> vous n'avez pas choisi votre binome.</b>";
	echo "</br>Retourner à la page de confirmation des choix <a href=index.php>par là.</a>";
	echo "</br>En cas d'erreur merci de contacter le responsable.";
	exit;
	}

if (file_exists($binome)) // Si le fichier nomdubinome existe (c'est à dire qu'une demande lui a deja été envoyé)
	{
	echo "<b><u>Erreur:</u>  une demande de confirmation vous a deja été envoyé sur votre boite INSA.</b>";
	exit;
	}
	
$choix="\n";// variable qui cotiendra l'ensemble des choix en chaine de caractéres.

$code1= rand(1,100000000000000);//choisit le code de confirmation secret.
$code2= rand(1,100000000000000);
$code3= rand(1,100000000000000);

while (file_exists(((string)$code1).".txt")) // Si il s'agit d'un code deja pris on en reprend un autre.
	{
	$code1= rand(1,100000000000000);//choisit le code de confirmation secret.
	$code2= rand(1,100000000000000);
	$code3= rand(1,100000000000000);
	}
	
//caclul du chemin de la page de confirmation pour le mail.
$chemin=$_SERVER["HTTP_REFERER"];
$longeurChemin=strlen ($chemin);
while(substr($chemin, $longeurChemin-1, $longeurChemin-1)!="/")
	$longeurChemin--;
$chemin = substr($chemin, 0, $longeurChemin);


//ouvre le fichier secret de validation
if (!$fp = fopen(((string)$code1).((string)$code2).((string)$code3).".txt","w")) {echo "Echec de l'ouverture du fichier";exit;}
// ouvre le fichier secret d'anulation.
if (!$fp2 = fopen(((string)$code1).".txt","w")) {echo "Echec de l'ouverture du fichier";exit;}

fputs($fp,$_POST['binome']);//y ecrit le nom du binome
fputs($fp,"\n");//passe une ligne
fputs($fp2,$_POST['binome']);//y ecrit le nom du binome
fputs($fp2,"\n");//passe une ligne

echo "<b>Binome:</b>";
echo $_POST['binome'];

if(empty($_POST['liste']))
	{
	echo "ERROR";
	}	
else
	{
	echo "</br> <b>vos choix:</b> </br>";
		
	for( $i = 0 ; $i < count($_POST['liste']) ; $i++ )
		{
		echo ($i+1);//affiche sur la page web les choix
		echo "- ".$_POST['liste'][$i];
		echo "</br>";
	
		fputs($fp,$_POST['liste'][$i]);//ecrit les choix dans le fichier secret de confirmation.
		fputs($fp,"\n");
		fputs($fp2,$_POST['liste'][$i]);//ecrit les choix dans le fichier secret de confirmation.
		fputs($fp2,"\n");
	
		$choix=$choix.($i+1)."- ".$_POST['liste'][$i]."\n";//ajoute à la chaine de caractére des choix.
		}
	echo "<b>Important: Vous allez recevoir un mail de confirmation sur votre boite mail. Ne fermez pas cette page tant que vous ne l'avez pas reçu </b>";
fclose($fp);
fclose($fp2);

//ecrit le mail
mail($binome."@insa-rouen.fr", 'Confirmation des choix', "Vox choix:".$choix."Pour Confirmer vos choix cliquer ici:\n".$chemin."confirm.php?entete=".((string)$code1)."&code=".((string)$code2).((string)$code3)."\nPour Anuler vos choix cliquer ici:\n".$chemin."cancel.php?entete=".((string)$code1)) ; 

//Affiche les informations concernant le mail.
echo "</br>Le message vous à été envoyé à <b><FONT color=\"blue\">&#139;".$binome."@insa-rouen.fr"."&#155;</FONT></b>";
echo "</br><b><FONT color=\"red\">Si (et seulement si) vous n'avez pas recus le mail, merci de cliquer <a href=\"".$chemin."cancel.php?entete=".((string)$code1)."\">ici</a></FONT></b>";

//crée un fichier nomdubinome afin de savoir qu'une demande de confirmation lui a été envoyé
if (!$fp2 = fopen($binome,"w")) {echo "Echec de l'ouverture du fichier";}
fputs($fp2,"ok");
fclose($fp2);

}
?>
</br></br>En cas de probléme pesistant, merci de contacter le responsable avec une capture d'écran de cette page.
