#include "init_mtr_labx.h"

void init_matrice
(
	uint8_t matrice_affichable[NB_CASES][NB_LIGN]
)
{
	matrice_affichable[0][0]= 128 	;//	&.......	128
	matrice_affichable[0][1]= 128	;//	&.......	128
	matrice_affichable[0][2]= 128	;//	&.......	128
	matrice_affichable[0][3]= 128	;//	&.......	128
	matrice_affichable[0][4]= 128	;//	&.......	128
	matrice_affichable[0][5]= 128	;//	&.......	128
	matrice_affichable[0][6]= 240	;//	&&&&....	240	=128 +64 +32 +16

	matrice_affichable[1][0]= 15	;//	....&&&&	15
	matrice_affichable[1][1]= 9		;//	....&..&	9
	matrice_affichable[1][2]= 9		;//	....&..&	9
	matrice_affichable[1][3]= 15	;//	....&&&&	15
	matrice_affichable[1][4]= 9		;//	....&..&	9
	matrice_affichable[1][5]= 9		;//	....&..&	9
	matrice_affichable[1][6]= 9		;//	....&..&	9

	matrice_affichable[3][0]= 233	;//	&&&.&..&	233	=128 +64 +32 +8 +1	=224 +8 +1
	matrice_affichable[3][1]= 153	;//	&..&&..&	153	=128 +16 +8 +1		=144 +8 +1
	matrice_affichable[3][2]= 150	;//	&..&.&&.	150	=128 +16 +4 +2
	matrice_affichable[3][3]= 230	;//	&&&..&&.	230	=128 +64 +32 +4 +2
	matrice_affichable[3][4]= 150	;//	&..&.&&.	150
	matrice_affichable[3][5]= 153	;//	&..&&..&	153
	matrice_affichable[3][6]= 233	;//	&&&.&..&	233
}
