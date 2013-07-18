
#ifndef RECOPIER_MATRICE_H

#define RECOPIER_MATRICE_H



//****** #INCLUDES ****************************************************************************	*

#include "caracteristiques_afficheur_&_affichage.h"

#include "string.h" // memcpy	// l'explicatio de la syntaxe de memcpy se trouve dans: 
				// /usr/share/doc/avr-libc/avr-libc-user-manual/group__avr__string.html

#include "inttypes.h"	
		//Pour utiliser directement le compilateur  avr-gcc -c -std=c99 
		//il faut cet entête <inttypes.h> sinon le type unit_8 n'est pas reconnu
		//ça marche aussi avec gcc

//****** #DEFINE ******************************************************************************	*

//******* DECLARATION_FONCTIONS ***************************************************************	*

//	_____________________
//	Liste des fonctions :

void recopier_matrice_colonnes_vers_lignes 
		      (	uint8_t	Matrice_Colonne[LONGUEUR_AFFICHEUR]		,
			uint8_t	Matrice_Lignes[NOMBRE_BLOCS][HAUTEUR_BLOC]	)
	;

void tourner_les_Bloc_8x8_Matrice_vers_gauche
		      (	uint8_t Matrice_Blocs[NOMBRE_BLOCS][HAUTEUR_BLOC]	)
	;

void tourner_gauche_un_Bloc_8x8
		      (	uint8_t Bloc[HAUTEUR_BLOC]	)
	;

uint8_t extraire_de_Bloc__8x8_la_colonne_i_vers_Octet
		      (	uint8_t Bloc[HAUTEUR_BLOC]	,
			uint8_t i			)
	;

#endif



