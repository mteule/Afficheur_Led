#ifndef TESTS_TURN_MTR_H
#define TESTS_TURN_MTR_H

#include "1_affichage.h"
#include "2_turn_mtr.h"
#include "1_dim_afficheur.h"

#include <inttypes.h>
#include <string.h>

void init_case_vert(uint8_t mtr[LARGEUR_CASE]);
void init_mtr_labx_vert(uint8_t mtr[LARGEUR_CASE * NB_CASES]);

void test_all_turn_mtr();

void test_bit_is_set();
void test_init_case_vert();
void test_ligne();
void test_transcr_case();
void test_transcr_mtr();

#endif
