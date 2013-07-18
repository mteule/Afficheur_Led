/*	AFFICHAGE DANS SHELL

Fonctions ayant pour but d'afficher dans le shell une matrice affichable, 
colonnes par colonnes.

(et non pas ligne par lignes, ce qui est le cas avec l'afficheur à led.)

_____________________
Liste des fonctions :
_____________________

	const char *byte_to_binary	( int x )

	void afficher_sur_l_ecran_la_matrice  (	uint8_t	Matrice_Colonne_de_Test[40]	,
						int	Longueur			)

	void afficher_sur_l_ecran_la_matrice_par_8    (	uint8_t Matrice_Colonne_de_Test[40]	,
							int	longueur			)

//_____________________________________________________________________________________________	*
*/

#include "affichage_dans_shell.h"

//******DECLARATION_VARIABLE_GLOBALES**********************************************************	*

//******INITIALISATION_VARIABLE_GLOBALES*******************************************************	*

//******DETAILS_FONCTIONS******************************************************************	*

const char *byte_to_binary
		 ( int x )
		// Fonction copiée du hack vue sur stackoverflow, voir à la fin 
{
	static char b[9]	;
	b[0] = '\0'		;

	int z			;
	for (z = 128; z > 0; z >>= 1)
	{
		strcat(b, ((x & z) == z) ? "§" : ".");
		// "strcat": http://www710.univ-lyon1.fr/~jciehl/Public/MAN/man3/strcat.3.html
	}

	return b;
}

void afficher_sur_l_ecran_la_matrice  
		     (	uint8_t	Matrice_Colonne_de_Test[40]	,
			int	Longueur			)

{
	uint8_t	Binary;

	for (int i=0; i<Longueur; i++)
	{
	Binary = Matrice_Colonne_de_Test[i];
	printf	("%s\n", byte_to_binary ( Binary ) );
	}
}

void afficher_sur_l_ecran_la_matrice_par_8  
		     (	uint8_t Matrice_Colonne_de_Test[40]	,
			int	longueur			)

{
	uint8_t *Curseur = Matrice_Colonne_de_Test		,
		*Limite  = (Matrice_Colonne_de_Test + 40)	;

	while (Curseur < Limite)
	{
		afficher_sur_l_ecran_la_matrice (Curseur, 8)	;
		printf("\n")					;
		Curseur += 8					;
	}
}

void afficher_sur_8_lignes_la_matrice
		     (	uint8_t  Matrice_de_Test_lignes[40]	,
			int	longueur			)
{
	uint8_t	Binary;

	for (int i=0; i<8; i++) {
		//afficher la ligne "i"
		for (int j=i; j<longueur; j +=8) {
		Binary =  Matrice_de_Test_lignes[j];
		printf	("%s", byte_to_binary ( Binary ) );
		};
		printf	("\n");
	}
	printf	("\n");
}


//*************	HACK DE STACK OVERFLOW ********************************************************	*

// http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format

// Pour imprimer avec printf au format binaire

//	#include <stdio.h>      // printf
//	#include <string.h>     // strcat



