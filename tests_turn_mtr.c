#include "tests_turn_mtr.h"

void test_all_turn_mtr()
{
	test_bit_is_set();
	test_init_case_vert();
	test_ligne();
	test_init_mtr_vert();
	test_transcr_mtr();
};

void test_bit_is_set()
{
	printf( "Test de bit_is_set(byte, i) avec byte = 31\n\n");
	uint8_t byte = 31; // 0x1F
	printf( "byte: ");
	ecrire_byte(byte);
	printf( "\nfor i=0 -> 7: ecrire_byte:");
	printf( "\n(on commence donc par la droite)\n");
	for (uint8_t i=0; i<8; i++)
	{
		printf( "\n");
		ecrire_byte(bit_n_is_set(byte, i));
	}
	printf( "\nça passe!\n\n");
}
	
void test_init_case_vert()
{
	printf( "test_init_case_vert():\n");
	uint8_t mtr[LARGEUR_CASE]={0};
	init_case_vert(mtr);
	for (uint8_t i=0; i<8; i++)
	{
		printf( "\n");
		ecrire_byte(mtr[i]);
	}
	printf( "\nça passe!\n\n");
}

void test_ligne()
{
	printf( "test_ligne():\n");
	uint8_t mtr[LARGEUR_CASE]={0};
	init_case_vert(mtr);
	for (uint8_t i=0; i<NB_LIGN; i++)
	{
		printf( "\n");
		ecrire_byte(ligne(mtr, i));
	}
	printf( "\nça passe!\n\n");
}

void test_init_mtr_vert()
{
	printf( "test_init_mtr_vert():\n");
	uint8_t mtr[LARGEUR_CASE * NB_CASES]={0};
	init_mtr_labx_vert(mtr);
	for (uint8_t i=0; i<LARGEUR_CASE * NB_CASES; i++)
	{
		printf( "\n");
		ecrire_byte(mtr[i]);
	}
	printf( "\nça passe!\n\n");
}

void test_transcr_mtr()
{
	printf( "test_transcr_mtr():\n");
	uint8_t matrice_affichable[NB_LIGN][NB_CASES] = {0};
	uint8_t mtr_vertcl[LARGEUR_CASE * NB_CASES] = {0};
	init_mtr_labx_vert(mtr_vertcl);
	printf( "...init OK ...\n");
	turn_mtr
	(
		matrice_affichable,
		mtr_vertcl
	);
	affichage(matrice_affichable);	
	printf( "\nça passe!\n\n");
}

void init_case_vert
(
	uint8_t mtr[LARGEUR_CASE]
)
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

void init_mtr_labx_vert
(
	uint8_t mtr[LARGEUR_CASE * NB_CASES]
)
{
	uint8_t mtr_LA[LARGEUR_CASE * NB_CASES] = {
	0x7F,
	0x40,
	0x40,
	0x40,	
	0x7F,
	0x09,
	0x09,
	0x7F,
	
	0x7F,
	0x40,
	0x40,
	0x40,	
	0x7F,
	0x09,
	0x09,
	0x7F,

	0x7F,
	0x40,
	0x40,
	0x40,	
	0x7F,
	0x09,
	0x09,
	0x7F,

	0x00,
	0x00,
	0x00,
	
	0x7F,
	0x40,
	0x40,
	0x40,	
	0x7F,
	0x09,
	0x09,
	0x7F
	};
	memcpy(mtr, mtr_LA, LARGEUR_CASE * NB_CASES);
}
