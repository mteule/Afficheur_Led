#include "affg.h"

const char * convert_byte_to_str(uint8_t x) 
{
	uint8_t z;
	static char b[9];
	b[0] = '\0';

	for (z = 128; z > 0; z >>= 1)
	{
		strcat(b, ((x & z) == z) ? "&" : ".");
	}
	return b;
}

void ecrire_byte
(
	uint8_t byte
)
{
	printf
		(
			convert_byte_to_str(byte)
		);
}

void ecrire_ligne
(
	uint8_t numligne, 
	uint8_t matrice_affichable[NB_CASES][NB_LIGN]
)
{
	for (uint8_t i =0; i <NB_CASES; i++)
	{
		ecrire_byte(matrice_affichable[i][numligne]);
	}
}

void affichage
(
	uint8_t matrice_affichable[NB_CASES][NB_LIGN]
)
{
	for (uint8_t i =0; i <NB_LIGN; i++)
	{
		ecrire_ligne( 
			i, 
			matrice_affichable
			);
		// retour à la ligne
		printf("\n");
	}
}
