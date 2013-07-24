#include "turn_mtr.h"

uint8_t bit_n_is_set
( 
	uint8_t byte, 
	uint8_t n
)
{
	// On compte à partir du bit de poids faible
	uint8_t filtre = 1;
	filtre = filtre << n;
	
	return (byte & filtre)>0;
}

uint8_t ligne
(
	uint8_t * case_vertcl,
	uint8_t n
)
{	
	uint8_t ligne = 0;
	for (uint8_t i=0; i<LARGEUR_CASE; i++)
	{
		ligne += (bit_n_is_set(case_vertcl[LARGEUR_CASE-1-i], n) << i);
	}
	return ligne;
}
	
void transcr_case
(
	uint8_t case_vertcl[LARGEUR_CASE],
	uint8_t case_horiz[NB_LIGN]
)
{
	uint8_t case_ligne[NB_LIGN]={0};
	for (uint8_t i=0; i<NB_LIGN; i++)
	{
		case_ligne[i]=(ligne(case_vertcl, i));
	}
	memcpy(case_horiz, case_ligne, NB_LIGN);
}

void turn_mtr
(
	uint8_t matrice_affichable[NB_CASES][NB_LIGN],
	uint8_t mtr_vertcl[LARGEUR_CASE * NB_CASES]
)
{
	for (uint8_t i=0; i<NB_CASES; i++)
	{
		transcr_case
		(
		&mtr_vertcl[LARGEUR_CASE * i],
		&matrice_affichable[i][0]
		);
	}
}
