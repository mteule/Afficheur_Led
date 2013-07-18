/*

Fonctions ayant pour but d'initialiser une matrice affichable de uint8_t.
	NB : qui sera affichable colonnes par colonnes !!!

*/

#include "initialisation_de_matrices_affichables.h"

//******DECLARATION_VARIABLE_GLOBALES**********************************************************	*

//****** DECLARATION_VARIABLE_GLOBALES ********************************************************	*

//****** INITIALISATION_VARIABLE_GLOBALES *****************************************************	*

//******DETAILS_FONCTIONS******************************************************************	*


void	write_digit_L		
		( uint8_t digit[4] )

	//Ecrit un L dans un tableau digit
{
	uint8_t digit_L[4]=
	{
	0x7F,
	0x40,
	0x40,
	0x40
	};

	memcpy(digit, digit_L, 4);
	/* 
	!!! Il est INDISPENSABLE d'utiliser memcpy, 
	La simple invocation
	digit = digit_B;
	Ne marche pas!!!
	*/
}

void	write_digit_A		//Ecrit un A dans un tableau digit
(
	uint8_t digit[4]
)
{
	uint8_t digit_A[4]=
	{
	0x7F,
	0x09,
	0x09,
	0x7F
	};
	memcpy(digit, digit_A, 4);
}

void	write_digit_B		//Ecrit un B dans un tableau digit
(
	uint8_t digit[4]
)
{
	uint8_t digit_B[4]=
	{
	0x7F,
	0x49,
	0x49,
	0x36
	};

	memcpy(digit, digit_B, 4);
}

void	write_digit_X
(
	uint8_t digit[4]
)
{	
	uint8_t digit_X[4]=
	{
	0x63,
	0x1C,
	0x1C,
	0x63
	};
	memcpy(digit, digit_X, 4);
}

void	write_digit_NULL	//Ecrit un digit vide dans un tableau digit
(
	uint8_t digit[4]
)

{
	uint8_t digit_NULL[4]=
	{
	0x00,
	0x00,
	0x00,
	0x00
	};
	memcpy(digit, digit_NULL, 4);
}

void initialiser_avec_LABX_(uint8_t Matrice_Colonne[40])
{
	uint8_t	*Curseur_de_copie	, 
		*Limite_Matrice		;

	Curseur_de_copie = &Matrice_Colonne[0]	;
	Limite_Matrice = (Curseur_de_copie + 40)	;

	while ( Curseur_de_copie < Limite_Matrice )
	{
		write_digit_L	(Curseur_de_copie)	;
		Curseur_de_copie +=4		  	;

		write_digit_A	(Curseur_de_copie)	;
		Curseur_de_copie +=4			;

		write_digit_B	(Curseur_de_copie)	;
		Curseur_de_copie +=4			;

		write_digit_X	(Curseur_de_copie)	;
		Curseur_de_copie +=4			;

		write_digit_NULL(Curseur_de_copie)	;
		Curseur_de_copie +=4			;
	}	// Ici c'est plus facile sous cette forme de vérifier qu'il y a bien tous les " ; "
}

