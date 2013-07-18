/*

LES CONSTANTES QUI DECRIVENT LES DIMENSIONS DE :

		- L'AFFICHEUR,  
		- LA MATRICE PAR LIGNES
		- LA MATRICE PAR COLONNES





La MATRICE PAR LIGNES est celle qui contient les valeurs des bits qui seront envoyées lors du rafraichissement de l'afficheur


*/

#ifndef CARAC_AFF_H
#define CARAC_AFF_H

//**************** #DEFINE ********************************************************************	*
//_____________________________________________________________________	*
//Durée de l'alimentation d'une ligne commandée par un Darlington
#define DELAY_PUTHIGH_Darlington 400	

//_____________________________________________________________________	*
// Pins de l'arduino controlant l'affichage
#define CLOCK_PIN	13;	//Clock
#define	DATA_PIN	12;	//Data
		//NB Les pins des darlingtons sont 2 -> 9

//_____________________________________________________________________	*
// La matrice en mémoire pour le rafraichissement de l'afficheur 
#define NOMBRE_BLOCS	5
#define HAUTEUR_BLOC	8

//_____________________________________________________________________	*
// Les dimensions de l'afficheur
#define LONGUEUR_AFFICHEUR	40
#define NOMBRE_LIGNES_AFFICHEUR	7




//*********************************************************************************************	*

#endif
