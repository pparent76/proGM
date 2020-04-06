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

<?php
	
				$id=$_POST['id'];
				
				if ($id==001)
				{
					$binome="../0biName.txt";
					$fp = fopen($binome,"w");
	
					for( $i = 0 ; $i < count($_POST['liste']) ; $i++ )
					{
						fputs($fp,$_POST['liste'][$i]);
						fputs($fp,"\n");
					}
   
					fclose($fp);

				}
				
				if ($id==002)
				{
					$projet="../0proName.txt";
					$fp = fopen($projet,"w");
	
					for( $i = 0 ; $i < count($_POST['liste']) ; $i++ )
					{
						fputs($fp,$_POST['liste'][$i]);
						fputs($fp,"\n");
					}
						
					fclose($fp);
				}
				
				if ($id==003)
				{
					$nom=htmlentities($_POST['binome']);

					if(file_exists("../".$nom.".txt"))
					{
						unlink("../".$nom.".txt");
					}
				}
				
				if ($id==004)
				{
					$p2=$_POST['binome'];
					$p2=Trim($p2);
					$p2="../".$p2.".txt";

					if (file_exists($p2)) 
					{						
						echo "Erreur due probablement à un réenvois de données ou une tentative de piratage.";
						exit;
					}
					if (!$fp = fopen($p2,"w")) 
					{
						echo "Echec de l'ouverture du fichier";

						exit;

					}


					if(empty($_POST['liste']))
					{
						echo "ERROR";
					}				
					else				
					{
						echo "<b>Binome:</b>";
						echo $_POST['binome'];
						echo "</br> <b>vos choix:</b> </br>";
		
						for( $i = 0 ; $i < count($_POST['liste']) ; $i++ )
						{
							echo ($i+1);
							echo "- ".$_POST['liste'][$i];
							echo "</br>";
							fputs($fp,$_POST['liste'][$i]);
							fputs($fp,"\n");
						}
						echo "<b> Vos choix ont correctement été enregistrés, vous pouvez fermer cette page. </b>";
						fclose($fp);
					}
				}
				if ($id==005)
				{
					$nom=htmlentities($_POST['choix']);
 
					if ($nom=='oui')
					{
						if(!file_exists("../UpDown"))
						{
							touch("../UpDown");
						}
					}
					else
					{
						if(file_exists("../UpDown"))
						{
							unlink("../UpDown");
						}
					}
				}
				

				//header("Location: administration.php");





?>
