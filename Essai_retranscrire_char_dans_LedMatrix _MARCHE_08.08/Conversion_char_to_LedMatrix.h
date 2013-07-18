#ifndef CONVERSION_CHAR_TO_LEDMATRIX_H
#define CONVERSION_CHAR_TO_LEDMATRIX_H

#include "font5x7.h"
#include <inttypes.h>	
#include <string.h>	// memcpy

#define STRING_SIZE_MAX 8

   //	DECLARATION DES FONCTIONS

uint8_t transcrire_Char_to_LedMatrix_5x7			(
					char	Char		,
					uint8_t	LedMatrix[5]	);

void transcrire_String_to_LedMatrix_n						(
				char	String_A_Transcrire	[STRING_SIZE_MAX]	,
				uint8_t	LedMatrix_COL		[STRING_SIZE_MAX *5]	,
				uint8_t	n						);


#endif
