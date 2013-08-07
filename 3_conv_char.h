#ifndef CONV_CHAR_H
#define CONV_CHAR_H

#define STRING_SIZE_MAX 8

#include <inttypes.h>	// uint8_t
#include <string.h>

void init_font5x7(uint8_t mtr_font5x7 [480]);

void transcrire_Char_to_LedMatrix_5x7
(
	char	Char		,
	uint8_t	LedMatrix[5],
	uint8_t font5x7 [480]
);

void transcrire_String_to_LedMatrix_n
//Cette fonction doit retranscrire dans une matrice d'octets correspondant aux leds qui doivent s'allumer dans une "LedMatrix" de 7 led de haut, pour que l'on reconnaisse les "n" premiers caractères de la "String_A_Transcrire"
(
	char	String_A_Transcrire	[STRING_SIZE_MAX]	,
	uint8_t	LedMatrix_COL		[STRING_SIZE_MAX *5]	,
	uint8_t	n,
	uint8_t font5x7 [480]
);

#endif
