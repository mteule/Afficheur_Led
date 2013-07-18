

#ifndef initialisation_de_matrice_affichables_H

#define initialisation_de_matrice_affichables_H

//****** #INCLUDES ****************************************************************************	*

#include "caracteristiques_afficheur_&_affichage.h"

#include <inttypes.h>	// Pour	uint8_t
#include <string.h>	// Pour	memcpy()

//	#include <stdio.h>	// Pour	printf()

//******* DECLARATION_FONCTIONS ***************************************************************	*


void initialiser_avec_LABX_(uint8_t Matrice_Colonne[40])	;
		// Recopie de manière récurrente le texte "LABX_" 
		// dans une matrice de colonnes, par exemple "Matrice_Colonne_de_Test"

void	write_digit_L	()	;
void	write_digit_A	()	;
void	write_digit_B	()	;
void	write_digit_X	()	;
void	write_digit_NULL()	;

//*********************************************************************************************	*

#endif
