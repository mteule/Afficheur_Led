#include "tests_affichage.h"

void test_all_affichage()
{
	test_convert_byte_to_str ();
	test_init_matrice();
	test_affichage();
};


void init_matrice
(
	uint8_t matrice_affichable[NB_LIGN][NB_CASES]
)
{
	matrice_affichable[0][0]= 128 	;//	&.......	128
	matrice_affichable[1][0]= 128	;//	&.......	128
	matrice_affichable[2][0]= 128	;//	&.......	128
	matrice_affichable[3][0]= 128	;//	&.......	128
	matrice_affichable[4][0]= 128	;//	&.......	128
	matrice_affichable[5][0]= 128	;//	&.......	128
	matrice_affichable[6][0]= 240	;//	&&&&....	240	=128 +64 +32 +16

	matrice_affichable[0][1]= 15	;//	....&&&&	15
	matrice_affichable[1][1]= 9		;//	....&..&	9
	matrice_affichable[2][1]= 9		;//	....&..&	9
	matrice_affichable[3][1]= 15	;//	....&&&&	15
	matrice_affichable[4][1]= 9		;//	....&..&	9
	matrice_affichable[5][1]= 9		;//	....&..&	9
	matrice_affichable[6][1]= 9		;//	....&..&	9

	matrice_affichable[0][3]= 233	;//	&&&.&..&	233	=128 +64 +32 +8 +1	=224 +8 +1
	matrice_affichable[1][3]= 153	;//	&..&&..&	153	=128 +16 +8 +1		=144 +8 +1
	matrice_affichable[2][3]= 150	;//	&..&.&&.	150	=128 +16 +4 +2
	matrice_affichable[3][3]= 230	;//	&&&..&&.	230	=128 +64 +32 +4 +2
	matrice_affichable[4][3]= 150	;//	&..&.&&.	150
	matrice_affichable[5][3]= 153	;//	&..&&..&	153
	matrice_affichable[6][3]= 233	;//	&&&.&..&	233
}

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
	
	uint8_t matrice_affichable[NB_LIGN][NB_CASES] = {0};
	init_matrice(matrice_affichable);
	printf( "\nça passe!\n\n");
}

// TODOS: tests ecrire_byte et ecrire_ligne

void test_affichage()
{
	printf( "Test de affichage()");
	printf( "\n...\n\n");	
	uint8_t matrice_affichable[NB_LIGN][NB_CASES] = {0};
	init_matrice( matrice_affichable);
	affichage(matrice_affichable);
	printf( "\nça passe!\n\n");
}

