/*


envoyer_LABX_lignes(dataPin, clockPin) 

est la fonction qui va envoyer sur l'afficheur la matrice 
Matrice_Afficheur [2][NOMBRE_BLOCS][HAUTEUR_BLOC]
*/


//****************DEFINE*************************************************************************************

#define DELAY_PUTHIGH_Darlington 400	//Durée de l'alimentation d'une ligne commandée par un Darlington

#define NOMBRE_BLOCS 5
#define HAUTEUR_BLOC 8
#define NOMBRE_LIGNES_AFFICHEUR 7

      // Librairie	// Fonctions appelées:
#include <inttypes.h>	// uint8_t

//****************VARIABLES GLOBALES*************************************************************************

int	clockPin = 13;	//Clock
int	dataPin = 12;	//Data
 
uint8_t	Matrice_Afficheur [2][NOMBRE_BLOCS][HAUTEUR_BLOC];
						//Le premier chiffre est pour la couleur, 
					        //le deuxième pour le numéro du rectangle,
					        //le troisième pour la ligne.

//****************FONCTIONS PRINCIPALES**********************************************************************

void setup() {

	//Transfert données sur deux fil
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);

	//Alimentation Darlingtons
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);

	InitMatrice_LABX();
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
	for (int i=2;i<=8;i++)
	{
	digitalWrite(i, HIGH);
	}

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
		digitalWrite (dataPin	, !!(val & (1 << (7 - i))   )	);
		digitalWrite (clockPin	, HIGH);
		digitalWrite (clockPin	, LOW);		
	}
}





void	InitMatrice_LABX()

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
//MATRICE A AFFICHER LIGNES, SECTION EN ROUGE
	// Lx
	Matrice_Afficheur [0][0][0]= 0b10000000;
	Matrice_Afficheur [0][0][1]= 0b10000000;
	Matrice_Afficheur [0][0][2]= 0b10000000;
	Matrice_Afficheur [0][0][3]= 0b10000000;
	Matrice_Afficheur [0][0][4]= 0b10000000;
	Matrice_Afficheur [0][0][5]= 0b10000000;
	Matrice_Afficheur [0][0][6]= 0b11110000;
	Matrice_Afficheur [0][0][7]= 0b00000000;
	// BX
	Matrice_Afficheur [0][1][0]= 0b11101001;
	Matrice_Afficheur [0][1][1]= 0b10011001;
	Matrice_Afficheur [0][1][2]= 0b10010110;
	Matrice_Afficheur [0][1][3]= 0b11100110;
	Matrice_Afficheur [0][1][4]= 0b10010110;
	Matrice_Afficheur [0][1][5]= 0b10011001;
	Matrice_Afficheur [0][1][6]= 0b11101001;
	Matrice_Afficheur [0][1][7]= 0b00000000;
	// xx
	Matrice_Afficheur [0][2][0]= 0b00000000;
	Matrice_Afficheur [0][2][1]= 0b00000000;
	Matrice_Afficheur [0][2][2]= 0b00000000;
	Matrice_Afficheur [0][2][3]= 0b00000000;
	Matrice_Afficheur [0][2][4]= 0b00000000;
	Matrice_Afficheur [0][2][5]= 0b00000000;
	Matrice_Afficheur [0][2][6]= 0b00000000;
	Matrice_Afficheur [0][2][7]= 0b00000000;
	// xx
	Matrice_Afficheur [0][3][0]= 0b00000000;
	Matrice_Afficheur [0][3][1]= 0b00000000;
	Matrice_Afficheur [0][3][2]= 0b00000000;
	Matrice_Afficheur [0][3][3]= 0b00000000;
	Matrice_Afficheur [0][3][4]= 0b00000000;
	Matrice_Afficheur [0][3][5]= 0b00000000;
	Matrice_Afficheur [0][3][6]= 0b00000000;
	Matrice_Afficheur [0][3][7]= 0b00000000;
 	// xx	
	Matrice_Afficheur [4][0][0]= 0b00000000;
	Matrice_Afficheur [0][4][1]= 0b00000000;
	Matrice_Afficheur [0][4][2]= 0b00000000;
	Matrice_Afficheur [0][4][3]= 0b00000000;
	Matrice_Afficheur [0][4][4]= 0b00000000;
	Matrice_Afficheur [0][4][5]= 0b00000000;
	Matrice_Afficheur [0][4][6]= 0b00000000;
	Matrice_Afficheur [0][4][7]= 0b00000000;

//MATRICE A AFFICHER LIGNES, SECTION EN VERT
	// xA
	Matrice_Afficheur [1][0][0]= 0b00001111;
	Matrice_Afficheur [1][0][1]= 0b00001001;
	Matrice_Afficheur [1][0][2]= 0b00001001;
	Matrice_Afficheur [1][0][3]= 0b00001111;
	Matrice_Afficheur [1][0][4]= 0b00001001;
	Matrice_Afficheur [1][0][5]= 0b00001001;
	Matrice_Afficheur [1][0][6]= 0b00001001;
	Matrice_Afficheur [1][0][7]= 0b00000000;
	// BX
	Matrice_Afficheur [1][1][0]= 0b11101001;
	Matrice_Afficheur [1][1][1]= 0b10011001;
	Matrice_Afficheur [1][1][2]= 0b10010110;
	Matrice_Afficheur [1][1][3]= 0b11100110;
	Matrice_Afficheur [1][1][4]= 0b10010110;
	Matrice_Afficheur [1][1][5]= 0b10011001;
	Matrice_Afficheur [1][1][6]= 0b11101001;
	Matrice_Afficheur [1][1][7]= 0b00000000;
	// xx
	Matrice_Afficheur [1][2][0]= 0b00000000;
	Matrice_Afficheur [1][2][1]= 0b00000000;
	Matrice_Afficheur [1][2][2]= 0b00000000;
	Matrice_Afficheur [1][2][3]= 0b00000000;
	Matrice_Afficheur [1][2][4]= 0b00000000;
	Matrice_Afficheur [1][2][5]= 0b00000000;
	Matrice_Afficheur [1][2][6]= 0b00000000;
	Matrice_Afficheur [1][2][7]= 0b00000000;
	// xx
	Matrice_Afficheur [1][3][0]= 0b00000000;
	Matrice_Afficheur [1][3][1]= 0b00000000;
	Matrice_Afficheur [1][3][2]= 0b00000000;
	Matrice_Afficheur [1][3][3]= 0b00000000;
	Matrice_Afficheur [1][3][4]= 0b00000000;
	Matrice_Afficheur [1][3][5]= 0b00000000;
	Matrice_Afficheur [1][3][6]= 0b00000000;
	Matrice_Afficheur [1][3][7]= 0b00000000;
 	// xx
	Matrice_Afficheur [1][4][0]= 0b00000000;
	Matrice_Afficheur [1][4][1]= 0b00000000;
	Matrice_Afficheur [1][4][2]= 0b00000000;
	Matrice_Afficheur [1][4][3]= 0b00000000;
	Matrice_Afficheur [1][4][4]= 0b00000000;
	Matrice_Afficheur [1][4][5]= 0b00000000;
	Matrice_Afficheur [1][4][6]= 0b00000000;
	Matrice_Afficheur [1][4][7]= 0b00000000;
}
