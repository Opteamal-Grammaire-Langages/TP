<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
<html>
	<body>
		<h1>Garage <em><xsl:value-of select="garage/nomGarage"/></em></h1>
		<p>
			<strong>Propriétaire : </strong><xsl:value-of select="garage/proprietaire/prenom"/>&#160;<xsl:value-of select="garage/proprietaire/nom"/><br />
			Ouvert depuis <xsl:value-of select="garage/anneeOuverture"/>
		</p>
		<h2>Voitures disponibles</h2>
		<table border="1">
			<tr bgcolor="yellow">
				<th>Marque</th>
				<th>Modele</th>
				<th>Couleur</th>
				<th>Motorisation</th>
				<th>Année</th>
				<th>Nombre de km</th>
				<th>Prix</th>
			</tr>
			<xsl:apply-templates select="garage/voiture"/>
		</table>
	</body>
</html>
</xsl:template>

<xsl:template match="voiture">
<tr>
	<td><xsl:value-of select="marque"/></td>
	<td><xsl:value-of select="modele"/></td>
	<td><xsl:value-of select="couleur"/></td>
	<td><xsl:value-of select="moteur"/></td>
	<td><xsl:value-of select="annee"/></td>
	<td><xsl:value-of select="nbKm"/></td>
	<td><xsl:value-of select="prix"/>&#160;<xsl:value-of select="prix/@devise"/></td>
</tr>
</xsl:template>
</xsl:stylesheet>