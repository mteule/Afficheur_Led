/*


envoyer_LABX_lignes(DATA_PIN, CLOCK_PIN) 

est la fonction qui va envoyer sur l'afficheur la matrice 
Matrice_Afficheur [2][NOMBRE_BLOCS][HAUTEUR_BLOC]
*/




      // Librairie	// Fonctions appelées:
#include "caracteristiques_afficheur_&_affichage.h"
#include "inttypes.h"			// uint8_t
#include "initialisation_de_matrices_affichables.h"	
#include "recopier_matrice_colonnes_vers_lignes.h"	

//****************VARIABLES GLOBALES*************************************************************************

uint8_t Matrice_Colonne		[LONGUEUR_AFFICHEUR]			;
 
uint8_t	Matrice_Afficheur 	[2] [NOMBRE_BLOCS] [HAUTEUR_BLOC]	;

				//Le premier chiffre est pour la couleur, 
			        //le deuxième pour le numéro du rectangle,
			        //le troisième pour la ligne.

//****************FONCTIONS PRINCIPALES**********************************************************************

void setup() {

	//Transfert données sur deux fil
	pinMode(CLOCK_PIN, OUTPUT);
	pinMode(DATA_PIN, OUTPUT);

	//Alimentation Darlingtons
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);

	initialiser_avec_LABX_ (Matrice_Colonne)		;

	//recopier pour le rouge ----> " [0] "
	recopier_matrice_colonnes_vers_lignes 
		      (	Matrice_Colonne		,
			Matrice_Afficheur[0]	)		;

	//recopier pour le vert  ----> " [1] "
	recopier_matrice_colonnes_vers_lignes 
		      (	Matrice_Colonne		,
			Matrice_Afficheur[1]	)		;

}

void loop() 
{
	envoyer_LABX_lignes();
}


//*****************FONCTIONS_ANNEXES*************************************************************************

void	envoyer_LABX_lignes   ()
{
	for (int Num_Ligne=0; Num_Ligne < NOMBRE_LIGNES_AFFICHEUR ; Num_Ligne ++)
	{
	puthigh(9);
	envoyer_ligne_R (Num_Ligne, Matrice_Afficheur);
	puthigh(Num_Ligne +2);	
	delayMicroseconds(DELAY_PUTHIGH_Darlington);	
	}
}

void	puthigh (int val)	
	// La fonction puthigh(int val) du code de départ, qui sert à allumer les Darlingtons.
	// Le Darlington est activé par mise à la masse du Pin qui le commande.
{
	// remettre les Darlingtons à 0
	for (int i=2;i<=8;i++)
	{
	digitalWrite(i, HIGH);
	}

	// Allumer le Darlington spécifié dans "val"
	digitalWrite(val, LOW);

}

void	envoyer_ligne_R       (	int NumLigne	,
				uint8_t Matrice [2][NOMBRE_BLOCS][HAUTEUR_BLOC] )

	// Cette fonction envoie les octets d'une ligne d'une matrice affichable.
	// Elle commence par un octet rouge, puis l'octet vert de la ligne du rectangle 7 x 8 lui correspondant.
	// du premier au 5 ème rectangle
{
	for (uint8_t i=0; i<NOMBRE_BLOCS; i++)
	{
	shiftOut_MSB (Matrice [0][i][NumLigne]); //Octet rouge
	shiftOut_MSB (Matrice [1][i][NumLigne]); //Octet Vert
	}	
}	


void	shiftOut_MSB (	uint8_t val	)	
	// Fonction obtenue par une petite modification de la fonction shift out de la librairie wiring, 
	// qui ne prend en compte que le cas MSB
{
	uint8_t i;


	for (i = 0; i < 8; i++)  
        {
		digitalWrite (DATA_PIN	, !!(val & (1 << (7 - i))   )	);
		digitalWrite (CLOCK_PIN	, HIGH);
		digitalWrite (CLOCK_PIN	, LOW);		
	}
}





// void	InitMatrice_LABX()

	//Initialisation de la matrice à 3 dimensions

	//L'afficheur est matériellement divisé en 5 rectangles de 7 lignes de 8 leds. 
	//Ce sont des Leds Red Green, il y a donc une série pour le rouge, et une série pour le vert.

	//Le premier indice correspond à l'ordre d'apparition du rectangle.
	//Le deuxième indice à la couleur qui est concernée, 0 pour le rouge et 1 pour le vert.
	//Le troisième indice correspond au numéro de la ligne.
	//L'octet qui est désigné correspond à une ligne de 8 leds.
 
	//Le nombre de lignes a été passé de 7 à 8, pour rendre la matrice compatible avec d'éventuels afficheurs à 8 lignes,

	//Et SURTOUT pour ULTÉRIEUREMENT initialiser la matrice à partir d'une matrice de COLONNES. 
{

