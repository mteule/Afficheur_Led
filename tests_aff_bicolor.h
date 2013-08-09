#ifndef TESTS_AFF_BICOLOR_H
#define TESTS_AFF_BICOLOR_H

#include "1_affichage.h"
#include "1_dim_afficheur.h"
#include "4_aff_bicolor.h"

#include <inttypes.h>

void test_all_aff_bicolor();
void test_init_mtr_bicolor();
void test_ledsegment_color();

void init_ledsegment_color(uint8_t ledsegment[NB_COLOR]);
void init_mtr_bicolor
(
	uint8_t mtr_bicolor[NB_LIGN][NB_CASES][NB_COLOR]
);

#endif
