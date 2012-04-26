<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
	<body>
		<h1>Garage <em>Nom du garage</em></h1>
		<p>
			<strong>Propriétaire : nom prénom</strong><br />
			Ouvert depuis année
		</p>
		<h2>Voitures disponibles</h2>
		<table border="1">
			<tr bgcolor="#9acd32">
				<th>Marque</th>
				<th>Modele</th>
				<th>Couleur</th>
				<th>Motorisation</th>
				<th>Année</th>
				<th>Nombre de km</th>
				<th>Prix</th>
			</tr>
			<xsl:for-each select="garage/voiture">
			<tr>
				<td>une marque</td>
				<td>un modele</td>
				<td>une couleur</td>
				<td>une motorisation</td>
				<td>une année</td>
				<td>un kilométrage</td>
				<td>un prix</td>
			</tr>
			</xsl:for-each>
		</table>
	</body>
</html>
</xsl:template>
</xsl:stylesheet>