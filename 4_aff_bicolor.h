#ifndef AFF_BICOLOR_H
#define AFF_BICOLOR_H


#include <inttypes.h>	// uint8_t
#include <stdio.h>		// printf()
#include <string.h>		// strcat()

#include "1_affichage.h"

#define NB_COLOR 2

const char *convert_2byte_to_str(uint8_t x[NB_COLOR]);

#endif
