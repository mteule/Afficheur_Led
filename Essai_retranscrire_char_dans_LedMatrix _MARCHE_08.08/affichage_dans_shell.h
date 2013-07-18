#ifndef AFFICHAGE_SHELL_H

#define AFFICHAGE_SHELL_H

//****** #INCLUDES ****************************************************************************	*

      // Librairie	// Fonctions appelées:

#include <stdio.h>	// printf()
#include <inttypes.h>	// uint8_t
#include <string.h>	// strcat()

//#include <stdlib.h>	// strtol() : 
			// pas besoin car on n'utilise qu'une partie du code de stackoverflow


//******DECLARATION_FONCTIONS******************************************************************	*

const char *byte_to_binary
		 ( int x );

void afficher_sur_l_ecran_la_matrice  
		     (	uint8_t	Matrice_Colonne_de_Test[40]	,
			int	Longueur			);

void afficher_sur_l_ecran_la_matrice_par_8  
		     (	uint8_t Matrice_Colonne_de_Test[40]	,
			int	longueur			);
void afficher_sur_8_lignes_la_matrice
		     (	uint8_t Matrice_Colonne_de_Test[40]	,
			int	longueur			);

//*********************************************************************************************	*

#endif
