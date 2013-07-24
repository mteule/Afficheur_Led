#ifndef AFFICHAGE_H
#define AFFICHAGE_H

//****** #INCLUDES ************************************************	*
      // Librairie		// Fonctions appelées:
#include <inttypes.h>	// uint8_t
#include <stdio.h>		// printf()
#include <string.h>		// strcat()

#include "1_dim_afficheur.h"

//******DECLARATION_FONCTIONS**************************************	*
const char *convert_byte_to_str(uint8_t x);

void ecrire_byte
(
	uint8_t byte
);

void ecrire_ligne
(
	uint8_t numligne, 
	uint8_t matrice_affichable[NB_CASES][NB_LIGN]
);

void affichage
(
	uint8_t matrice_affichable[NB_CASES][NB_LIGN]
);

#endif
