#ifndef TESTS_AFFICHAGE_H
#define TESTS_AFFICHAGE_H

#include "1_affichage.h"
#include "1_dim_afficheur.h"

#include <inttypes.h>

void test_all_affichage();

void test_convert_byte_to_str ();
void test_init_matrice();
void test_affichage();

void init_matrice
(
	uint8_t matrice_affichable[NB_CASES][NB_LIGN]
);

#endif
