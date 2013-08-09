#ifndef AFF_BICOLOR_H
#define AFF_BICOLOR_H


#include <inttypes.h>	// uint8_t
#include <stdio.h>		// printf()
#include <string.h>		// strcat()

#include "1_affichage.h"

#define NB_COLOR 2

const char *convert_2byte_to_str(uint8_t x[NB_COLOR]);
void ecrire_lettres_bicolor(char b[8]);
void ecrire_ledsegment(uint8_t x[NB_COLOR]);
void ecrire_ligne_bicolor
(
	uint8_t numligne, 
	uint8_t mtr_bicolor[NB_LIGN][NB_CASES][NB_COLOR]
);
void aff_bicolor
(
	uint8_t mtr_bicolor[NB_LIGN][NB_CASES][NB_COLOR]
);

#endif
