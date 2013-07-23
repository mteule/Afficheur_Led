#include "init_mtr_labx_vertcl.h"
#include <inttypes.h>

const uint8_t * init_case_vert() 
{
	static uint8_t mtr[LARGEUR_CASE]=
	{
	0x7F,
	0x40,
	0x40,
	0x40,	
	0x7F,
	0x09,
	0x09,
	0x7F
	};
	return mtr;
}

