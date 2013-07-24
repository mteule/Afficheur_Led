#include "tests.h"

void test_all()
{
	//afficher dans le shell:
	test_convert_byte_to_str ();
	test_init_matrice();
	test_affichage();
	// tourner une case:
	test_bit_is_set();
	test_init_case_vert();
	test_ligne();
	test_transcr();
};

void test_convert_byte_to_str ()
{
	uint8_t  unite = 1;

	printf(
		"Test de la fonction convert_byte_to_str(unite <<i) \n"
		)		;
	for (int i=0 ; i<8 ; i++)
	{
		printf("%s\n", convert_byte_to_str(unite <<i));
	}
	printf("\n\n\n");
}

void test_init_matrice()
{
	printf( "Test de init_matrice( matrice_affichable)");
	printf( "\n...\n\n");
	
	uint8_t matrice_affichable[NB_CASES][NB_LIGN] = {0};
	init_matrice( matrice_affichable);
	printf( "ça passe!\n\n");
}

// TODOS: ecrire_byte et ecrire_ligne

void test_affichage()
{
	printf( "Test de affichage()");
	printf( "\n...\n\n");	
	uint8_t matrice_affichable[NB_CASES][NB_LIGN] = {0};
	init_matrice( matrice_affichable);
	affichage(matrice_affichable);
	printf( "\nça passe!\n\n");
}

void test_bit_is_set()
{
	printf( "Test de bit_is_set(byte, i) avec byte = 31\n\n");
	uint8_t byte = 31; // 0x1F
	printf( "byte: ");
	ecrire_byte(byte);
	printf( "\nfor i=0 -> 7: ecrire_byte:");
	printf( "\n(on commence donc par la droite)");
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

void test_transcr()
{
	printf( "test_transcr():\n");
	uint8_t mtr[LARGEUR_CASE]={0};
	init_case_vert(mtr);
	uint8_t case_[NB_LIGN];
	*case_ = transcr(mtr);
	
	for (uint8_t i=0; i<NB_LIGN; i++)
	{
		printf( "\n");
		ecrire_byte(case_[i]);
	}
	printf( "\nça passe plus!\n\n");
}

