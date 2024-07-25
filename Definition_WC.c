#include <stdio.h>
#include <stdlib.h>

char c;

//Definition de la fonction pour verifier l erreur lors de l ouverture du fichier
void erreur_fopen(FILE *fichier,int argc,char *argv[])
{
	printf("%s: %s: Aucun fichier ou dossier de ce nom\n",argv[0],argv[argc - 1]);
	exit(1);
}

//Definition de la fonction pour compter les nombres de saut de ligne dans le fichier
int LineCount(FILE *fichier)
{
	int ligne;
	
	//Initialisation de variable
	ligne = 0;
	
	rewind(fichier);
	do 
	{
		c = fgetc (fichier);
		if (c == '\n')
			ligne++;
	}
	while(!feof(fichier));
	return ligne;
}

//Definition de la fonction pour compte les nombres de mot contenu dans le fichier
int WordCount(FILE *fichier)
{
	int mot;
	
	//Initialisation de variable
	mot = 0;
	
	rewind(fichier);
	do 
	{
		c = fgetc (fichier);
		if (c == ' ' || c == '\n')
			mot++;
	}
	while (!feof(fichier));
	return mot;
}

//Definition de la fonction pour compte les nombres d'octets contenu dans le fichier
int OctetCount (FILE *fichier)
{
	int octet;
	
	//Initialisation de variable
	octet = 0;
	
	rewind(fichier);
	do
	{
		c = fgetc (fichier);
		octet++;
	}
	while (!feof(fichier));
	return octet;
}

//Definition de la fonction pour afficher le resultat du commande wc sans option
void wc_sans_option(FILE *fichier , int ligne , int mot ,int octet,int argc,char *argv[])
{
	//Compte les nombres de saut de ligne dans le fichier
	ligne = LineCount(fichier); 
	
	//Compte les nombres de mot contenu dans le fichier
	mot = WordCount (fichier);
	
	//Compte les nombres d'octets contenu dans le fichier
	octet = OctetCount (fichier);
	printf("  %d  %d %d %s\n",ligne,mot,octet-1,argv[argc - 1]);
}

//Definition de la fonction pour afficher le resultat du commande wc avec un option -c
void wc_option_c(FILE *fichier,int octet,int argc,char *argv[])
{
	rewind(fichier);
	octet = OctetCount (fichier);
	printf("%d %s\n",octet-1,argv[argc - 1]);
}

//Definition de la fonction pour afficher le resultat du commande wc avec un option -m
void wc_option_m(FILE *fichier,int caractere,int argc,char *argv[])
{
	rewind(fichier);
	do
	{
		c = fgetc (fichier);
		if (((int)c >= 32 && (int)c <= 127) || c == '\n') 
		{							
			caractere++;
		}
	}
	while (!feof(fichier));
	printf("%d %s\n",caractere ,argv[argc - 1]);
}

//Definition de la fonction pour afficher le resultat du commande wc avec un option -l
void wc_option_l(FILE *fichier,int ligne,int argc,char *argv[])
{
	rewind(fichier);
	ligne = LineCount(fichier);
	printf("%d %s\n",ligne,argv[argc - 1]);
}

//Definition de la fonction pour afficher le resultat du commande wc avec un option -L
void wc_option_L(FILE *fichier,int nombre_caractere_par_ligne,int max,int argc,char *argv[])
{
	rewind(fichier);
	do
	{
		c = fgetc (fichier);
		nombre_caractere_par_ligne++;
		if (c == '\n')
		{
			nombre_caractere_par_ligne--;
			if (max < nombre_caractere_par_ligne)
				max = nombre_caractere_par_ligne;
			nombre_caractere_par_ligne = 0;
		}
	}
	while(!feof(fichier));
	printf("%d %s\n",max,argv[argc - 1]);
}

//Definition de la fonction pour afficher le resultat du commande wc avec un option -w
void wc_option_w(FILE *fichier,int nombre_de_mot,int argc,char *argv[])
{
	rewind(fichier);
	do 
	{
		c = fgetc (fichier);
		if(c == ' ' || c == '\n' || c == '\t')
			nombre_de_mot++;
	}
	while(!feof(fichier));
	printf("%d %s\n",nombre_de_mot,argv[argc - 1]);
}
