<?php
	//session_start();
?>

<?php
/*
  Copyright (c) 2010 Josselin beisser
  
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

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" >
	<head>
       	<title>ProGM - Administration</title>
       	<meta name="keywords" content=""/>
        <meta name="description" content="Logiciel de répartition de projets entre différents groupes"/>
        <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
   	
	
	<style type="text/css">

		
		
		body
		{
			font-weight: bold;
			background:white;
		}
	
		form, p
		{
			text-align: center;
		}
	
		a:link 
		{
			color: #066fd4;
			text-decoration: none;
		}

		a:visited 
		{
			color: #066fd4;
			text-decoration: none;
		}

		a:hover, a:active 
		{
			color: #000000;
		}
		
		.actionCache
		{
			display:none;
			clear:both;
		}

	
	
	</style>
	

			<script type="text/javascript">
			// Afficher par clique sur le lien d'un bout de code
			function MontrerAction(id) 
			{
				Classe='actionMontre';
			
				if (document.getElementById(id).className==Classe) 
				{
					Classe="actionCache";
				}
			
				document.getElementById(id).className=Classe;
			
			}
		</script>
			<!-- exemple d'utilisation :
					
			<script type="text/javascript">
                document.write("<a href=\"javascript:MontrerAction('ID')\">Titre</a>");
            </script>

            <noscript><h4 class='font3'>Le javascript ne marche pas sur votre navigateur. Veuillez contacter l'administrateur.</h4></noscript>

			<br />
			<div class="actionCache" id="ID">	
				
				//Ici on met le code de la page a afficher par clique sur le lien
					
			</div>
			--> 			

		<script language="Javascript">

			function PostSelect(id_liste)//fonction nessecaire pour récupérer tous les ellements d'un select
			{
				obj=document.getElementById(id_liste);
				NbOption=obj.length;
				for(a=0; a < NbOption; a++)
				{
					obj.options[a].selected = true;
				}
				obj.name="liste[]";
			}
		</script>
		<script language="Javascript">
		function Supprimer(liste1)//supprime un élément à la liste1
			{  
	            var objListe1 = document.getElementById(liste1);
				if (objListe1.options.selectedIndex<0) return false;
	            var iPositionAvant = objListe1.options.selectedIndex;
                objListe1.options[iPositionAvant]=null;
			}

            function ToutSupprimer(liste1)//supprime un élément à la liste1
			{  
	            var objListe1 = document.getElementById(liste1);
           	    objListe1.options.length=0;
			}

	        function AjouterBinome(nomForm)//Ajoute un élement à la liste1
       		{  
	            var t = new Option(nomForm.nombinome.value);
                nomForm.binome.options[nomForm.binome.options.length]=t;
			}
			
		 function AjouterProjet(nomForm)//Ajoute un élement à la liste1
       		{  
	            var t = new Option(nomForm.nomprojet.value);
                nomForm.projet.options[nomForm.projet.options.length]=t;
			}
		</script>
		
		<script language="Javascript">

		function Transfert(liste1,liste2)//transphere un ellement de la liste1 à la liste2
		{	
			var objListe1 = document.getElementById(liste1);
			var objListe2 = document.getElementById(liste2);
			if (objListe1.options.selectedIndex<0) return false;
			var iPositionAvant = objListe1.options.selectedIndex;

			nouvel_element =objListe1.options[iPositionAvant];
			objListe2[objListe2.length] = nouvel_element;
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
	<body>
	<?php
	
	if ((isset($_POST['user']) AND $_POST['user']=="Delegues" AND isset($_POST['mdp']) AND $_POST['mdp'] == "GestionProjet") OR (isset($_SESSION['user']) AND $_SESSION['user']=="Delegues" AND isset($_SESSION['mdp']) AND $_SESSION['mdp'] == "GestionProjet"))
		{ 
		
					if (isset($_POST['user']) AND $_POST['user']=="Delegues" AND isset($_POST['mdp']) AND $_POST['mdp'] == "GestionProjet")
					{
					
                        $_SESSION['user'] = "Delegues";
						$_SESSION['mdp'] = "GestionProjet";					
					}
		
			
	?>

	<center><h1>Page d'administration</h1></center>
		<center><a href="http://pi.parent.free.fr/logiciel.html"><b>webGM-proGM</b></a></center>
		<center><a href="../index.php"><b>Accueil proGM</b></a></center>
		<br /><br />
		<!-- Gestion des binôme (id : 001) -->
		
			<script type="text/javascript">
                document.write("<a href=\"javascript:MontrerAction('001')\">Gestion des binômes</a>");
            </script>

            <noscript><h4 class='font3'>Le javascript ne marche pas sur votre navigateur. Veuillez contacter l'administrateur.</h4></noscript>

			<br />
			<div class="actionCache" id="001">	
				
				<!-- On commence le formulaire : pour le résultat on invoquera la page "message.php" grâce à l'attribut action de la balise form -->
				<form id="general" action="traitement.php" method="post">
					<div>
						<fieldset><legend>binome</legend>
						<?php 
							$fichier="../0biName.txt";
							$tabfich=file($fichier); 
							$taille=10;
						?>
	    
						<select id="binome"  size=  <?php print "\"".$taille."\"" ?>multiple>
						<?php 
							for( $i = 0 ; $i < count($tabfich) ; $i++ )	
								echo "<option  value=\"$tabfich[$i]\">$tabfich[$i]</option>";//rajoute chaque binome dans la liste
						?>
						<TD>
							<TABLE>
								<TR><TD><input type="button" value="supprimer" onClick="Supprimer('binome')"/></TD></TR>
								<TR><TD><input type="button" value="tout supprimer" onClick="ToutSupprimer('binome')"/></TD></TR>
							</TABLE>
						</TD>

						<br />
						<p>
							<legend>
							adresse email sous la forme prenom.nom :     
							</legend>
						
							<input type="text" name="nombinome" id="nombinome" />
							<input type="button" value="ajouter" onClick="AjouterBinome(this.form)"/>
						</p>
						<br /><br />
							<input type="hidden" name="id" value="001"> 
							<input type="submit" onClick="PostSelect('binome')"/>
							</fieldset>
					</div>
				</form>
				<!-- Notre formulaire est fini, on ferme la balise form -->                
			<br />
					
			</div>
			<br /><br />
		
		
		
		<!-- Gestion des projets (id : 002) -->
		
					<script type="text/javascript">
                document.write("<a href=\"javascript:MontrerAction('002')\">Gestion des projets</a>");
            </script>

            <noscript><h4 class='font3'>Le javascript ne marche pas sur votre navigateur. Veuillez contacter l'administrateur.</h4></noscript>

			<br />
			<div class="actionCache" id="002">	
				
				<!-- On commence le formulaire : pour le résultat on invoquera la page "message.php" grâce à l'attribut action de la balise form -->
				<form name="general" action="traitement.php" method="post">
        	        <div>
						<fieldset>
						<legend>projet</legend>
                    
						<?php 
							$fichier="../0proName.txt";	 
       		        	    $tabfich=file($fichier);	
                            $taille=10;
						?>
 
	    		        <select id="projet"  size=  <?php print "\"".$taille."\"" ?>multiple>

						<?php 
		           			for( $i = 0 ; $i < count($tabfich) ; $i++ )	
								echo "<option  value=\"$tabfich[$i]\">$tabfich[$i]</option>";//rajoute chaque projet dans la liste
						?>
                
						<br />
						<TD>
							<TABLE>
								<TR><TD><input type="button" value="supprimer" onClick="Supprimer('projet')"/></TD></TR>
								<TR><TD><input type="button" value="tout supprimer" onClick="ToutSupprimer('projet')"/></TD></TR>
	                        </TABLE>
						</TD>
				          	
						<p>
							<legend>
								nom du projet :     
							</legend>
				
							<input type="text" name="nomprojet" />
							<input type="button" value="ajouter" onClick="AjouterProjet(this.form)"/>
						</p>
                        
						<br /><br />
                        <input type="hidden" name="id" value="002">
						<input type="submit" onClick="PostSelect('projet')"/>
						</fieldset>
	                </div>
                </form>
                <!-- Notre formulaire est fini, on ferme la balise form -->
					
			</div>
			
			<br /><br />
		<!-- Supprimer les choix d'un binôme (id : 003) -->
		
		
			<script type="text/javascript">
                document.write("<a href=\"javascript:MontrerAction('003')\">Supprimer les choix d'un binôme</a>");
            </script>

            <noscript><h4 class='font3'>Le javascript ne marche pas sur votre navigateur. Veuillez contacter l'administrateur.</h4></noscript>

			<br />
			<div class="actionCache" id="003">			
		
		<form action="traitement.php" method="post" enctype="multipart/form-data">
			<div>
			<fieldset><legend>Supprimer les choix d'un binome.</legend>
				Choisissez le nom de votre binome:
			
			<select  name="binome" defaultvalue="0" onchange="fonction(this);">
			<option value="faux"> Choissisez votre binôme </option>
			
			<?php 
		   		$fichier="../0biName.txt"; //On ouvre le fichier 0biname.txt
		   		$tabfich=file($fichier);

		   		for( $i = 0 ; $i < count($tabfich) ; $i++ )// Pour chacune des entrées
				      {
				      $tabfich[$i]=Trim($tabfich[$i]);// on surpime les espaces
				      if (file_exists("../".$tabfich[$i].".txt")) // si il a pas deja fait ses choix.
					      	{echo "<option  value=\"$tabfich[$i]\">$tabfich[$i]</option>";}//ajoute l'option.
				      }
			?>
		
			</select>
			<br />
			<input type="hidden" name="id" value="003">
			<input type="submit" value="Valider choix" />
			</fieldset>
	        
			</div></form>
			
			</div>
	 		
			
			<br /><br />
		<!-- Faire les choix d'un binôme (id : 004) -->
			<script type="text/javascript">
                document.write("<a href=\"javascript:MontrerAction('004')\">Faire les choix d'un binôme</a>");
            </script>

            <noscript><h4 class='font3'>Le javascript ne marche pas sur votre navigateur. Veuillez contacter l'administrateur.</h4></noscript>

			<br />
			<div class="actionCache" id="004">	
				<!-- On commence le formulaire : pour le résultat on invoquera la page "message.php" grâce à l'attribut action de la balise form -->
		        
				<form action="traitement.php" method="post" enctype="multipart/form-data">
									
					<div>
						<fieldset>
							<legend>Effectuer les choix d'un binome.</legend>
							
							<center>
							Choisissez le nom de votre binome:
							<select  name="binome" onchange="fonction(this);">
							<?php 
								$fichier="../0biName.txt"; 
								$tabfich=file($fichier); 

								for( $i = 0 ; $i < count($tabfich) ; $i++ )
								{
									$tabfich[$i]=Trim($tabfich[$i]);
									if (!file_exists("../".$tabfich[$i].".txt")) 
									{
										echo "<option  value=\"$tabfich[$i]\">$tabfich[$i]</option>";
									}
								}
							?>
							</select>
							<br /><br /><br />

							Triez vos projets dans la liste de droite:
							<br />
							
							<TABLE>
							<TR>
							<TD>
							<?php 
								$fichier="../0proName.txt"; 
								$tabfich=file($fichier);
								if (count($tabfich)<20)
								{
									$taille=  count($tabfich);		
								}
								else
								{
									$taille=20;
								}
							?>
							<select id="projet_restant"  size=  <?php print "\"".$taille."\"" ?>multiple>
							<?php 
								for( $i = 0 ; $i < count($tabfich) ; $i++ )
								{
									echo "<option  value=\"$tabfich[$i]\">$tabfich[$i]</option>";
								}
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

							<select id="projet_trie" size=<?php print "\"".$taille."\"" ?> multiple></select>
			
							</TD>
							<TD>
							<?php
								if (file_exists("../UpDown"))// si c'est congiguré ajoute les boutons haut-bas
								{
									echo " <TABLE>	<TR><TD><input type=\"button\" value=\"haut\" onClick=\"deplace(-1,'projet_trie')\"></TD></TR>";
									echo "<TR><TD><input type=\"button\" value=\"bas\" onClick=\"deplace(1,'projet_trie')\"></TD></TR>";
									echo "</TABLE>";
									echo "</TD>";
								}
							?>
							</TABLE>
							<br />

							<FONT SIZE=2> projet restants -> projet triés </FONT> 
							<br /><br /><br />
							<input type="hidden" name="id" value="004">
							<input type="submit" value="Valider" onClick="PostSelect('projet_trie')">
							</center>
						</fieldset>
	                </div>
				</form>
				<!-- Notre formulaire est fini, on ferme la balise form --> 
			
		</div>

	<br /><br />	
	<!-- Bouton UpDown (id : 005) -->
		<script type="text/javascript">
            document.write("<a href=\"javascript:MontrerAction('005')\">Bouton haut-bas</a>");
			</script>

			<noscript><h4 class='font3'>Le javascript ne marche pas sur votre navigateur. Veuillez contacter l'administrateur.</h4></noscript>

			<br />
			<div class="actionCache" id="005">

			<!-- On commence le formulaire : pour le résultat on invoquera la page "message.php" grâce à l'attribut action de la balise form -->
			<form name="general" id="form1" action="traitement.php" method="post">
				<div>
	          	Voulez vous les boutons Haut-Bas pour la liste 2 des choix de projets ?
                        <input type="radio" name="choix" value="oui" checked="checked" /> Oui
                        <input type="radio" name="choix" value="non" /> Non
	                <br />
                        <input type="hidden" name="id" value="005">
						<input type="submit" />
                        </div>
            </form>
                <!-- Notre formulaire est fini, on ferme la balise form -->    
	<br /><br />	
	<!-- Nom de Domaine (id : 006) -->				
		
		
	<?php
		}
		else
		{
			echo '<p>Veuillez passer par la page de connexion : </p>';
			echo '<p><a href="../accesadmin.php">Aller à la page de connexion.</a></p>';
		}
	?>
	
   	</body>
</html>
