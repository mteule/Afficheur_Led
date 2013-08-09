#include "5_turn_bicolor.h"

void turn_mtr_bicolor
(
	uint8_t mtr_bicolor[NB_LIGN][NB_CASES][NB_COLOR],
	uint8_t mtr_vertcl_rouge[LARGEUR_CASE * NB_CASES],
	uint8_t mtr_vertcl_verte[LARGEUR_CASE * NB_CASES]
)
{
	for (uint8_t i=0; i<NB_LIGN; i++)
	{
		transcr_ligne_bicolor
		(
		&mtr_vertcl_rouge[0],
		&mtr_vertcl_verte[0],
		&mtr_bicolor[i][0],
		i
		);
	}
}

void transcr_ligne_bicolor
(
	uint8_t mtr_vertcl_rouge[LARGEUR_CASE * NB_CASES],
	uint8_t mtr_vertcl_verte[LARGEUR_CASE * NB_CASES],
	uint8_t lign_horiz_bicolor[NB_CASES][NB_COLOR],
	uint8_t num_ligne
)
{
	uint8_t lign_horiz_tmp[NB_CASES][NB_COLOR]={0};
	uint8_t * curseur;
	for (uint8_t i=0; i<NB_CASES; i++)
	// On commence par la case de gauche
	{
		// Le rouge
		curseur = mtr_vertcl_rouge + i*LARGEUR_CASE;
		lign_horiz_tmp[i][0] = ligne(curseur, num_ligne);
		
		// Le vert
		curseur = mtr_vertcl_verte + i*LARGEUR_CASE;
		lign_horiz_tmp[i][1] = ligne(curseur, num_ligne);		
	}
	memcpy(lign_horiz_bicolor, lign_horiz_tmp, NB_CASES * NB_COLOR);
}
