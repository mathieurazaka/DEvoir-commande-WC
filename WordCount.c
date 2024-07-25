#include <stdio.h>
#include <string.h>
#include "Prototype_WC.h"

int main (int argc,char *argv[])
{
	FILE *fichier;
	int ligne,mot,octet,caractere,nombre_caractere_par_ligne,max,nombre_de_mot;
	
	//Initialisation des variables
	ligne = 0;
	mot = 0;
	octet =0 ;
	caractere = 0;
	nombre_caractere_par_ligne = 0;
	max = 0;
	nombre_de_mot = 0;
	
	//Ouverture du fichier
	fichier = fopen (argv[argc - 1],"rw");
	if(fichier == NULL)
	{
		erreur_fopen(fichier,argc,argv);
	}
	else 
	{
		if (argc == 2)
		{
			//Affiche le resultat du commande wc sans option
			wc_sans_option(fichier , ligne , mot ,octet,argc,argv);
		}
		else
		{	
			//Affiche le nombre d'octet
			if ((strcmp(argv[1],"-c") == 0) || (strcmp(argv[1],"--bytes") == 0))
			{
				wc_option_c(fichier,octet,argc,argv);
			}
			
			//Affiche le nombre de caractere
			if ((strcmp(argv[1],"-m") == 0) || (strcmp(argv[1],"--chars") == 0))
			{
				wc_option_m(fichier,caractere,argc,argv);
			}
			
			//Afficher le nombre de sauts de lignes
			if ((strcmp(argv[1],"-l") == 0) || (strcmp(argv[1],"--lines") == 0))
			{
				wc_option_l(fichier,ligne,argc,argv);
			}
			
			//Afficher la largeur maximale d'affichage
			if ((strcmp(argv[1],"-L") == 0) || (strcmp(argv[1],"--max-line-length") == 0))
			{
				wc_option_L(fichier,nombre_caractere_par_ligne,max,argc,argv);
			}
			
			//Afficher le nombre de mots
			if 	((strcmp(argv[1],"-w") == 0) || (strcmp(argv[1],"--words") == 0))
			{
				wc_option_w(fichier,nombre_de_mot,argc,argv);
			}
		}
		
		//Fermeture du fichier		
		fclose (fichier);
	}
return (0);
}
