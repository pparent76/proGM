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
 ?>
 
<!DOCTYPE HTML SYSTEM>
<html lang="fr">
  <head>
<title>ProGM Choix des projets</title>   
<meta name="description" content="Répartition de projets entre différents groupes">
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
   	
	
<script type="text/javascript" language="Javascript">

function Transfert(liste1,liste2)//transphere un ellement de la liste1 à la liste2
{	
	var objListe1 = document.getElementById(liste1);
        var objListe2 = document.getElementById(liste2);
	if (objListe1.options.selectedIndex<0) return false;
	var iPositionAvant = objListe1.options.selectedIndex;
	
	if (objListe2[0].text=="Glissez vos choix ici")
	objListe2[0]=null;
	
	  nouvel_element = new Option(objListe1.options[iPositionAvant].value,objListe1.options[iPositionAvant].value,false,false);
	  objListe2[objListe2.length] = nouvel_element;

	objListe1.options[iPositionAvant]=null;
}

function PostSelect(id_liste)
	{//fonction nessecaire pour récupérer tous les ellements d'un select lors de l'envois des données.
  	obj=document.getElementById(id_liste);
  	NbOption=obj.length;
  	for(a=0; a < NbOption; a++)
  		obj.options[a].selected = true;
  
	obj.name="liste[]";
	}


function deplace(sens,liste)    // sens =-1 pour monter, 1 pour descendre
{
	var obj = document.getElementById(liste);
	var iPositionAvant = obj.options.selectedIndex;
 	 if  ( iPositionAvant+sens>=0 && iPositionAvant+sens<obj.length )
  	 	{   
  	 	var temp=obj[iPositionAvant+sens].text;
       		obj[iPositionAvant+sens].text=obj[iPositionAvant].text;
        	obj[iPositionAvant].text=temp;
        	iPositionAvant=iPositionAvant+sens; 
    		} 

}
</script>

        </head>
        
        
        
 <?php //----------------------------------BODY-----------------------------------?>       
        
<body>
<center>
<form action="recup.php" method="post" enctype="multipart/form-data">
Choisissez le nom de votre binome:
     <select  name="binome" onchange="fonction(this);">
        	<option value="faux"> Choissisez votre binôme </option>
			<?php 
		   		$fichier="0biName.txt"; //On ouvre le fichier 0biname.txt
		   		$tabfich=file($fichier);

		   		for( $i = 0 ; $i < count($tabfich) ; $i++ )// Pour chacune des entrées
				      {
				      $tabfich[$i]=Trim($tabfich[$i]);// on surpime les espaces
				      if (!file_exists($tabfich[$i].".txt")) // si il a pas deja fait ses choix.
					      	{echo "<option  value=\"$tabfich[$i]\">$tabfich[$i]</option>";}//ajoute l'option.
				      }
			?>
		
	</select>
<br>
<br>
<br>


Triez vos projets dans la liste de droite:
<br>
<TABLE>
 <TR>
 	<TD>
  	 <?php 
		 $fichier="0proName.txt"; // ouvre le fichier 0proName.txt
		 $tabfich=file($fichier);
      		if (count($tabfich)<20) // Met la taille de la liste au nombre de projet avec max 20.
			$taille=  count($tabfich);		
		else
       			$taille=20;
      	?>
 
	    <select id="projet_restant"  size=  <?php print "\"".$taille."\"" ?>>
     
	        <?php 
		 for( $i = 0 ; $i < count($tabfich) ; $i++ )		    
			echo "<option  value=\"$tabfich[$i]\">$tabfich[$i]</option>";//rajoute chaque projet dans la liste
				    
		?>
	 
	    </select>
	 </TD>
	 <TD>	    
	<TABLE>
    	 <TR><TD><input type="button" value="<-" onClick="Transfert('projet_trie','projet_restant')"></TD></TR>
    	 <TR><TD><input type="button" value="->" onClick="Transfert('projet_restant','projet_trie')"></TD></TR>
	</TABLE>
	</TD>
	<TD>
	  <select id="projet_trie" size=<?php print "\"".$taille."\"" ?> multiple><option>Glissez vos choix ici</option></select>	
	</TD>
	<TD>
	<?php
	if (file_exists("UpDown"))// si c'est congiguré ajoute les boutons haut-bas
	{
	echo " <TABLE>	<TR><TD><input type=\"button\" value=\"haut\" onClick=\"deplace(-1,'projet_trie')\"></TD></TR>";
     	echo "<TR><TD><input type=\"button\" value=\"bas\" onClick=\"deplace(1,'projet_trie')\"></TD></TR>";
     	echo "</TABLE>";
     	echo "</TD>";
     	}
     	?>
</TABLE>
	<h6>projets restants <- -> projets triés</h6>
	
<br>

<input type="submit" value="Valider choix" onClick="PostSelect('projet_trie')">
</form>
<p>
<a href="http://pi.parent.free.fr/logiciels.html"><b><img src="http://pi.parent.free.fr/images/proGM-mini.png" alt=""></b></a>
 
      <a href="http://validator.w3.org/check/referer"><img
          src="http://www.w3.org/Icons/valid-xhtml10-blue"
          alt="Valid XHTML 1.0!" height="31" width="88" ></a>
    </p>
</center>


</body>
</html>
