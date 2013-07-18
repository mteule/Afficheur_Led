/*	RECOPIER_MATRICE_COLONNES_VERS_LIGNES

Fonctions constitutives de la fonction pricipales:
	void recopier_matrice_colonnes_vers_lignes 

Cette fonction a pour but de recopier une matrice affichable, lue colonnes par colonnes, 
	dans une matrice de lignes [N_BLOCS][HAUTEUR_BLOCS] (normalement [5][8])
	Il faudra tourner vers la gauche les blocs de 8x8.

Cette matrice de lignes peut correspondre à une des deux couleurs qui pourront être envoyée vers l'afficheur de type matrice à led d'Autobus.


*/

#include "recopier_matrice_colonnes_vers_lignes.h"


//****** DECLARATION_VARIABLE_GLOBALES ********************************************************	*

// uint8_t Matrice_Colonne	[LONGUEUR_AFFICHEUR]	;
//	Matrice_Lignes	[NOMBRE_BLOCS][HAUTEUR_BLOC]	;	//Présentes juste pour l'exemple

//****** INITIALISATION_VARIABLE_GLOBALES *****************************************************	*


//****** DETAILS_FONCTIONS ********************************************************************	*



//*****************FONCTIONS_RECOPIER_Matrice_ColonneS_VERS_LIGNES********************************************




uint8_t extraire_de_Bloc__8x8_la_colonne_i_vers_Octet ( uint8_t Bloc[HAUTEUR_BLOC]	,
							uint8_t i			)
{
	uint8_t	Resultat = 0	,
		RETENUE = 0	,
		FILTRE = 1	,
		h = 0		;

	//*********************************************************************************************
	FILTRE = FILTRE <<i;		//Débute par colonne de droite
	for (int8_t n= 7 ; n >=0 ; n--)	//n est la position du bit de la colonne i de Bloc concernée
	{				//on commence par le bas, n = 8, voir schéma suivant
					// rem: il a compilé sans vérifier n 
					// il faut faire attention à ce que n soit signé !!! 

		if( (Bloc[n] & FILTRE) > 0 )	//si le bit concerné = 1
		{
		RETENUE = 1;
		h = (7 - n) ;
		RETENUE =RETENUE << h ;	// C'est là qu'était le bug, avec seulement " RETENUE <<h ;"
		Resultat += RETENUE;	// au lieu de l'expression complète "RETENUE =RETENUE << h ;"
		} 
	}
	return Resultat;
}

/*	Schema du fonctionnement de " extraire_de_Bloc__8x8_la_colonne_i_vers_Octet(,) "
		      i			      i			      i

	0 0 0 0 0 0 0 i		0 0 0 0 0 0 0 i 	0 0 0 0 0 0 0 i
	0 0 0 0 0 0 0 i		0 0 0 0 0 0 0 i 	0 0 0 0 0 0 0 i
	0 0 0 0 0 0 0 i		0 0 0 0 0 0 0 i 	0 0 0 0 0 0 0 i
	0 0 0 0 0 0 0 i		0 0 0 0 0 0 0 i 	0 0 0 0 0 0 0 i
	0 0 0 0 0 0 0 i	  ->	0 0 0 0 0 0 0 i   ->	0 0 0 0 0 0 0 i
	0 0 0 0 0 0 0 i		0 0 0 0 0 0 0 i 	0 0 0 0 0 0 0 i
	0 0 0 0 0 0 0 i		0 0 0 0 0 0 0 i 	0 0 0 0 0 0 0 Z n
	0 0 0 0 0 0 0 i		0 0 0 0 0 0 0 Y n	0 0 0 0 0 0 0 i
	0 0 0 0 0 0 0 X n	0 0 0 0 0 0 0 i 	0 0 0 0 0 0 0 i

	i i i i i i i X		i i i i i i X Y		i i i i i X Y Z	    <-	Resultat

*/


void tourner_gauche_un_Bloc_8x8 ( uint8_t Bloc[HAUTEUR_BLOC] )
{
	uint8_t	Resultat[HAUTEUR_BLOC];
	
	for (uint8_t i = 0; i <8; i++)	//i est la ligne de Resultat que l'on calcule, 8 la largeur du Bloc en bit
	{
	Resultat[i] = extraire_de_Bloc__8x8_la_colonne_i_vers_Octet(Bloc, i);
					// printf("%s\n", byte_to_binary( Resultat[i] ) );
	}
	memcpy(Bloc, Resultat, 8);	
				// Attention ! memcpy copie un nombre n d'OCTETS,
				// il faudra se méfier avec des "int" qui font 2 octets,
				// ça ne marchera pas forcement.
				// Il semble aussi que memcpy préfèrerait une variable de type "char"
}		

/*	Schema du fonctionnement de " tourner_gauche_un_Bloc_8x8( Bloc[ 8 ] ) "
		      i			      i			      i

	0 0 0 0 0 0 0 0		0 0 0 0 X X X X 	
	0 0 0 0 0 0 0 0		0 0 0 0 X 0 0 X  	
	0 0 0 0 0 0 0 0		0 0 0 0 X 0 0 X 	
	0 0 0 0 0 0 0 0		0 0 0 0 X 0 0 X  
	0 0 0 0 0 0 0 0	  ->	0 0 0 0 X X X X   
	0 X X X X X X X		0 0 0 0 X 0 0 X  
	0 0 0 0 X 0 0 X		0 0 0 0 X 0 0 X  
	0 0 0 0 X 0 0 X		0 0 0 0 X 0 0 X  
	0 X X X X X X X 	0 0 0 0 0 0 0 0 

		Bloc	  ->	Resultat ;

(memcpy)	Resultat  ->	Bloc;

Le Bloc a été réécrit, ce qu'il y avait dedans avant est écrasé !!!
*/


void tourner_les_Bloc_8x8_Matrice_vers_gauche ( uint8_t Matrice_Blocs[NOMBRE_BLOCS][HAUTEUR_BLOC] )
{
	uint8_t	Resultat[HAUTEUR_BLOC];
        for (uint8_t i = 0; i < NOMBRE_BLOCS; i++)
	{
        memcpy(&Resultat, &Matrice_Blocs[i], 8)	; // Matrice_Blocs[i] est un pointeur sur un Bloc[HAUTEUR_BLOC]
	tourner_gauche_un_Bloc_8x8( Resultat )	; // il faut espérer que ce = envoie sur le pointeur "Resultat" la valeur du pointeur Matrice_Blocs[i]  
	memcpy(&Matrice_Blocs[i], &Resultat,8)	;
	}
	// Normalement toute la matrice a été réécrite
}


void recopier_matrice_colonnes_vers_lignes (	uint8_t	Matrice_Colonne[LONGUEUR_AFFICHEUR]		,
						uint8_t	Matrice_Lignes[NOMBRE_BLOCS][HAUTEUR_BLOC]	)
{
	uint8_t	Matrice_Blocs[NOMBRE_BLOCS][HAUTEUR_BLOC];

	memcpy		(Matrice_Blocs, Matrice_Colonne, LONGUEUR_AFFICHEUR);
	tourner_les_Bloc_8x8_Matrice_vers_gauche 	(Matrice_Blocs);
	memcpy		(Matrice_Lignes, Matrice_Blocs,	LONGUEUR_AFFICHEUR);
}




