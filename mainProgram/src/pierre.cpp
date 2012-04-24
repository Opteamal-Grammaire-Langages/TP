
int result = 0;
analyse()
{
			if (args[1] == "-a") // toutes les analyses
			{ 
				if (args[2] == "-t") // analyse precise d'un fichier
				{
					if (args[3] == "dtd")
					{
						result = analyseDtd(args[4]);
					}
					else if (args[3] == "xml")
					{
						result = analyseXml(args[4]);
					}
					else if (args[3] == "xsl")
					{
						// a remplir
					}
				}
				else //analyse complete xml et dtd associee
				{
					result = analyseXml(args[2]);
				}
				
			}
}
