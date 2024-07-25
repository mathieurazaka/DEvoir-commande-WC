//Prototype du fonction pour verifier l erreur lors de l ouverture du fichier
void erreur_fopen(FILE *fichier,int argc,char *argv[]);

//Prototype du fonction pour compter les nombres de saut de ligne dans le fichier
int LineCount(FILE *fichier);
//Prototype du fonction pour compter les nombres de mot contenu dans le fichier
int WordCount(FILE *fichier);
//Prototype du fonction pour compter les nombres d'octets contenu dans le fichier
int OctetCount (FILE *fichier);

//Prototype du fonction pour afficher le resultat du commande wc sans option
void wc_sans_option(FILE *fichier , int ligne , int mot ,int octet,int argc,char *argv[]);

//Prototype du fonction pour afficher le resultat du commande wc avec un option -c
void wc_option_c(FILE *fichier,int octet,int argc,char *argv[]);
//Prototype du fonction pour afficher le resultat du commande wc avec un option -m
void wc_option_m(FILE *fichier,int caractere,int argc,char *argv[]);
//Prototype du fonction pour afficher le resultat du commande wc avec un option -l
void wc_option_l(FILE *fichier,int ligne,int argc,char *argv[]);
//Prototype du fonction pour afficher le resultat du commande wc avec un option -L
void wc_option_L(FILE *fichier,int nombre_caractere_par_ligne,int max,int argc,char *argv[]);
//Prototype du fonction pour afficher le resultat du commande wc avec un option -W
void wc_option_w(FILE *fichier,int nombre_de_mot,int argc,char *argv[]);
