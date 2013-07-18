/**************************************************************************************************************	*

A pour but d'afficher une matrice 

Pour faire ce TEST avec un résultat affiché dans un SHELL , 

Il faut compiler en ajoutant les fichiers :

	recopier_matrice_colonnes_vers_lignes.c

	initialisation_de matrice_affichables
	affichage_dans_shell.c		//NB !!! LA FONCTION byte-to-binary rajoute un 0 de trop


gcc -std=c99 	rev3_affichage_dans_shell.c  rev3_initialisation_de_matrice_affichables.c rev3_recopier_matrice_colonnes_vers_lignes.c rev3_TEST_GCC_recopier_matrice_colonnes_vers_lignes.c -o TEST

***************************************************************************************************************	*/

//****** #INCLUDES ********************************************************************************************	*


#include "affichage_dans_shell.h"
#include "initialisation_de_matrice_affichables.h"
#include "recopier_matrice_colonnes_vers_lignes.h"
#include "Conversion_char_to_LedMatrix.h"


#include <stdio.h>	// printf ()
#include <inttypes.h>	// uint8_t

//	#include <string.h>




//****** DECLARATION_VARIABLE_GLOBALES ************************************************************************	*

uint8_t	Matrice_Colonne_de_Test	[40]	={0}	;
uint8_t	Matrice_de_Test_lignes	[40]	={0}	;

uint8_t Octet;

char	String_A_Transcrire	[STRING_SIZE_MAX]	= {'c', 'o', 'u', 'c', 'o', 'u', '!', '_'}	;


//****** INITIALISATION_VARIABLE_GLOBALES *********************************************************************	*

//Matrice_Colonne_de_Test		={0}	;
//Matrice_de_Test_lignes		={0}	;

	// est ce qu'il vaut mieux combiner l'initialisation au moment de la déclaration, 
	// pour être sûr de mettre toutes les cases à 0?

	// De toutes façon il n'y a pas le choix, ces expressions sont considéres comme des erreurs par le compilateur!!


//******* DECLARATION_FONCTIONS *******************************************************************************	*

void main ()
{

// TEST de la fonction ********	* Byte to binary -> ça marche bien ************************************************************	*
	printf	(
		"Test de la fonction byte_to_binary(unite <<i) \n"
		)		;
	uint8_t unite = 1	;

	for (int i=0 ; i<8 ; i++)
	{
		printf("%s\n", byte_to_binary(unite <<i))	;
	}

	printf("\n\n\n");





// INITIALISATION *************	*Matrice_Colonne_de_Test_entiere **************************************************************	*

	initialiser_avec_LABX_(Matrice_Colonne_de_Test);





// TEST de la fonction ********	*" afficher_sur_l_ecran_la_matrice " ça marche bien aussi**************************************	*

	printf	(
		"Test de la fonction afficher_sur_l_ecran_la_matrice_par_8 (Matrice_Colonne_de_Test, 40) \n"
		)								;
	afficher_sur_l_ecran_la_matrice_par_8 (Matrice_Colonne_de_Test, 40)	;

	printf("\n\n\n");





// TEST de la fonction ********	*" extraire_de_Bloc__8x8_la_colonne_i_vers_Octet " -> ça marche *******************************	*

	printf	(
		"Test de la fonction extraire_de_Bloc__8x8_la_colonne_i_vers_Octet(Matrice_Colonne_de_Test, i) \n"
		);	
	for (int i=0 ; i<8 ; i++)
	{
		Octet = extraire_de_Bloc__8x8_la_colonne_i_vers_Octet(Matrice_Colonne_de_Test, i);
		printf("%s\n", byte_to_binary(Octet));
	}
	printf("\n\n\n");





// TEST de la fonction ********	*" tourner_gauche_un_Bloc_8x8(Bloc) " -> ça marche !!! ****************************************	*

	printf (
		"Test de la fonction tourner_gauche_un_Bloc_8x8(Bloc) \n"
		)	;	
	uint8_t Bloc[8]	;

	memcpy (Bloc, Matrice_Colonne_de_Test, 8)	;
	tourner_gauche_un_Bloc_8x8(Bloc)		;
	afficher_sur_l_ecran_la_matrice (Bloc, 8)	;

	printf("\n\n\n");





// TEST de la fonction ********	*" recopier_matrice_colonnes_vers_lignes() ****************************************************	*

	printf("Test de la fonction recopier_matrice_colonnes_vers_lignes( Matrice_Colonne_de_Test , Matrice_de_Test_lignes ) \n");	
	recopier_matrice_colonnes_vers_lignes( Matrice_Colonne_de_Test , Matrice_de_Test_lignes );
	afficher_sur_l_ecran_la_matrice_par_8 (Matrice_de_Test_lignes, 40);

//###########################################################################################


// TEST de la fonction ********	*" transcrire_Char_to_LedMatrix_5x7() ****************************************************	*

	printf("Test de la fonction transcrire_Char_to_LedMatrix_5x7 (,) \n");
	transcrire_Char_to_LedMatrix_5x7	('?'			,
						Matrice_Colonne_de_Test	) ;
	recopier_matrice_colonnes_vers_lignes( Matrice_Colonne_de_Test , Matrice_de_Test_lignes );
	afficher_sur_8_lignes_la_matrice ( Matrice_de_Test_lignes, 40);



// TEST de la fonction ********	*" transcrire_String_to_LedMatrix_n () ****************************************************	*


	transcrire_String_to_LedMatrix_n (
		String_A_Transcrire	, Matrice_Colonne_de_Test , 8 );

	recopier_matrice_colonnes_vers_lignes( Matrice_Colonne_de_Test , Matrice_de_Test_lignes );
	afficher_sur_8_lignes_la_matrice ( Matrice_de_Test_lignes, 40);


}	// ATTENTION "}" de la fin du "MAIN" !!! 




