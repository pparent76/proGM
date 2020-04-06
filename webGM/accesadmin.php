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
       	<title>ProGM - connexion administration</title>
       	<meta name="keywords" content=""/>
        <meta name="description" content="Logiciel de répartition de projets entre différents groupes"/>
        <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
   	
	
	<style type="text/css">

		
		
		body
		{
			font-weight: bold;
			background:white;
		}
	
		body
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

		a
		{
			text-align: center;
		}
	
	
	</style>
	
	<body>
		<?php
		
			echo '<p>Connexion à la page d\'administration de ProGM.</p>
		
			<form action="admin/administration.php" method="post">

				<input type="user" name="user" value="login" /><br />
				<input type="password" name="mdp" value="123456" /><br />
				<input type="submit" value="Connexion" /><br />
	
			</form>';
		    
			
	?>
	<br /><br />
	<a href="index.php"></h6>retour Accueil</h6></a>
	</body>
	
	</head>
</html>
