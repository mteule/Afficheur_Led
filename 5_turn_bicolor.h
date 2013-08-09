#ifndef TURN_BICOLOR_H
#define TURN_BICOLOR_H

#include <inttypes.h>	// uint8_t
#include <string.h>
#include "2_turn_mtr.h"
#include "4_aff_bicolor.h" // NB_COLOR

void turn_mtr_bicolor
(
	uint8_t mtr_bicolor[NB_LIGN][NB_CASES][NB_COLOR],
	uint8_t mtr_vertcl_rouge[LARGEUR_CASE * NB_CASES],
	uint8_t mtr_vertcl_verte[LARGEUR_CASE * NB_CASES]
);

void transcr_ligne
(
	uint8_t mtr_vertcl_rouge[LARGEUR_CASE * NB_CASES],
	uint8_t mtr_vertcl_verte[LARGEUR_CASE * NB_CASES],
	uint8_t lign_horiz_bicolor[NB_CASES][NB_COLOR],
	uint8_t num_ligne
);

#endif
