#include "init_mtr_labx_vertcl.h"
#include <inttypes.h>

void init_case_vert(uint8_t mtr[LARGEUR_CASE]) 
{
	uint8_t mtr_LA[LARGEUR_CASE] = {
	0x7F,
	0x40,
	0x40,
	0x40,	
	0x7F,
	0x09,
	0x09,
	0x7F
	};
	memcpy(mtr, mtr_LA, 8);
}

