#include "tests_affichage.h"

void test_all_affichage()
{
	test_convert_byte_to_str ();
	test_init_matrice();
	test_affichage();
};

void test_convert_byte_to_str ()
{
	printf("Test de la fonction convert_byte_to_str(unite <<i) \n");
	uint8_t  unite = 1;
	for (int i=0 ; i<8 ; i++)
	{
		printf("%s\n", convert_byte_to_str(unite <<i));
	}
	printf("\n\n\n");
}

void test_init_matrice()
{
	printf( "Test de init_matrice(matrice_affichable)");
	printf( "\n...\n\n");
	
	uint8_t matrice_affichable[NB_CASES][NB_LIGN] = {0};
	init_matrice(matrice_affichable);
	printf( "\nça passe!\n\n");
}

// TODOS: tests ecrire_byte et ecrire_ligne

void test_affichage()
{
	printf( "Test de affichage()");
	printf( "\n...\n\n");	
	uint8_t matrice_affichable[NB_CASES][NB_LIGN] = {0};
	init_matrice( matrice_affichable);
	affichage(matrice_affichable);
	printf( "\nça passe!\n\n");
}

