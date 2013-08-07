#include "tests_conv_char.h" 

void test_all_conv_char()
{
//	test_init_font5x7();
	test_transcrire_String_to_LedMatrix_n();
};

void test_init_font5x7()
{
	printf( "Test de init_font5x7(uint8_t mtr_font5x7 [480])");
	uint8_t mtr_font5x7 [480];
	init_font5x7(mtr_font5x7);
	
	for (uint8_t i=0; i<480; i++)
	{
		printf( "\n");
		ecrire_byte(mtr_font5x7[i]);
	}
	printf( "\nça passe!\n\n");
}

void test_transcrire_String_to_LedMatrix_n()
{
	printf( "Test de transcrire_String_to_LedMatrix_n(...)\n");
	
	// Initialise un tableau de conversion
	uint8_t mtr_font5x7 [480];
	init_font5x7(mtr_font5x7);
	
	// Initialise la chaîne de caractères
	char phrase[8]= {'l', 'a', 'b', 'x', '.', 'f', 'r', ' '};
	uint8_t n=8;
	
	// Déclaration ledmatrix_verticale et affichable
	uint8_t matrice_affichable[NB_LIGN][NB_CASES] = {0};
	uint8_t mtr_vertcl[LARGEUR_CASE * NB_CASES] = {0};
	
	// Test de la fonction
	transcrire_String_to_LedMatrix_n
	(
		phrase	,
		mtr_vertcl	,
		n,
		mtr_font5x7
	);
	
	// Affichage du résultat
	turn_mtr
	(
		matrice_affichable,
		mtr_vertcl
	);
	affichage(matrice_affichable);	
	
	printf( "\nça passe!\n\n");
}
