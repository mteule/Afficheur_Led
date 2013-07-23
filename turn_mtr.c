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
	
const uint8_t * transcr
(
	uint8_t case_vertcl[LARGEUR_CASE]
)
{
	static uint8_t case_[NB_LIGN]={0};
	for (uint8_t i=0; i<NB_LIGN; i++)
	{
		case_[i]=(ligne(case_vertcl, i));
	}
	return case_;
}
