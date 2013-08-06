#include "2_turn_mtr.h"

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
// TODO: rendre plus explicite
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
	
void transcr_ligne
(
	uint8_t mtr_vertcl[LARGEUR_CASE * NB_CASES],
	uint8_t lign_horiz[NB_CASES],
	uint8_t num_ligne
)
{
	uint8_t lign_horiz_tmp[NB_CASES]={0};
	uint8_t * curseur;
	for (uint8_t i=0; i<NB_CASES; i++)
	// On commence par la case de gauche
	{
		curseur = mtr_vertcl + i*LARGEUR_CASE;
		lign_horiz_tmp[i] = ligne(curseur, num_ligne);
	}
	memcpy(lign_horiz, lign_horiz_tmp, NB_CASES);
}

void turn_mtr
(
	uint8_t matrice_affichable[NB_LIGN][NB_CASES],
	uint8_t mtr_vertcl[LARGEUR_CASE * NB_CASES]
)
{
	for (uint8_t i=0; i<NB_LIGN; i++)
	{
		transcr_ligne
		(
		&mtr_vertcl[0],
		&matrice_affichable[i][0],
		i
		);
	}
}
