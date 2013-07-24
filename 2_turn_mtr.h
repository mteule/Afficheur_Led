#include <inttypes.h>	// uint8_t
#include <string.h>
#include "1_dim_afficheur.h"

uint8_t bit_n_is_set
( 
	uint8_t byte, 
	uint8_t n
);

uint8_t ligne
/**
 * Extraire la ligne 'n' d'une case horizontale affichable en lisant 
 * la colonne 'n' d'une case verticale 
 */
(
	uint8_t * case_,
	uint8_t n
);

void transcr_case
/**
 * Il s'agir de retranscrire dans une case horizontale de l'afficheur 
 * le contenu d'une matrice de 8 uint8_t (qui correspond à ce que l'on 
 * désigne par l'appellation case verticale. 
*/
(
	uint8_t case_vertcl[LARGEUR_CASE],
	uint8_t case_horiz[NB_LIGN]
);

void turn_mtr
(
	uint8_t matrice_affichable[NB_CASES][NB_LIGN],
	uint8_t mtr_vertcl[LARGEUR_CASE * NB_CASES]
);
