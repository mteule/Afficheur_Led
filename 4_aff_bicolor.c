#include "4_aff_bicolor.h"

const char *convert_2byte_to_str(uint8_t x[NB_COLOR])
{
	uint8_t z, jaune, vert, rouge;
	static char b[9];
	b[0] = '\0';

	for (z = 128; z > 0; z >>= 1)
	{
		rouge = x[0] & z;
		vert  = x[1] & z;
		jaune = rouge & vert;
		
		if (jaune == z)
		{
			strcat(b, "J");
		}
		else
		{
			if (vert == z)
			{
				strcat(b, "V");
			}
			else
			{
				if (rouge == z)
				{
					strcat(b, "R");
				}
				else
				{
					strcat(b, ".");
				}
			}
		}
	}
	return b;
}

void ecrire_lettres_bicolor(char b[8])
{
	char couleur;
	for (uint8_t i =0; i <8; i++)
	{
		couleur = b[i];
		if ('J' == couleur)
		{
			printf(ANSI_COLOR_YELLOW "&");
		}
		else
		{
			if ('V' == couleur)
			{
				printf(ANSI_COLOR_GREEN "&");
			}
			else
			{
				if ('R' == couleur)
				{
					printf(ANSI_COLOR_RED "&");
				}
				else
				{
					printf(ANSI_COLOR_CYAN ".");
				}
			}
		}		
	}
	printf(ANSI_COLOR_RESET);
}

void ecrire_ledsegment(uint8_t x[NB_COLOR])
{
	ecrire_lettres_bicolor
	(
		convert_2byte_to_str(x)
	);
}

void ecrire_ligne_bicolor
(
	uint8_t numligne, 
	uint8_t mtr_bicolor[NB_LIGN][NB_CASES][NB_COLOR]
)
{
	for (uint8_t i =0; i <NB_CASES; i++)
	{
		ecrire_ledsegment(mtr_bicolor[numligne][i]);
	}
}

void aff_bicolor
(
	uint8_t mtr_bicolor[NB_LIGN][NB_CASES][NB_COLOR]
)
{
	for (uint8_t i =0; i <NB_LIGN; i++)
	{
		ecrire_ligne_bicolor( 
			i, 
			mtr_bicolor
			);
		// retour à la ligne
		printf("\n");
	}
}



