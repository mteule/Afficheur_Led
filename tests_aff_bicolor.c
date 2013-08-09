#include "tests_aff_bicolor.h"

void test_all_aff_bicolor()
{
	test_init_mtr_bicolor();
	test_ledsegment_color();
};

void test_init_mtr_bicolor()
{
	printf("Test de la fonction test_init_mtr_bicolor()\n");
	uint8_t mtr[NB_LIGN][NB_CASES][NB_COLOR] = {0};
	init_mtr_bicolor(mtr);
	aff_bicolor(mtr);
	printf( "\nça passe!\n\n");
}
void test_ledsegment_color()
{
	printf("Test de la fonction init_ledsegment_color()\n");
	uint8_t ledsegment[NB_COLOR] = {0};
	init_ledsegment_color(ledsegment);
	printf( "\n");
	ecrire_byte(ledsegment[0]);
	printf( "\n");
	ecrire_byte(ledsegment[1]);
	printf( "\n");
	
	printf("%s\n", convert_2byte_to_str(ledsegment));

	ecrire_ledsegment(ledsegment);
	printf( "\nça passe!\n\n");
}
void init_ledsegment_color(uint8_t ledsegment[NB_COLOR])
{
	ledsegment[0]= 240	;//	&&&&....
	ledsegment[1]= 230	;//	&&&..&&.
}
void init_mtr_bicolor
(
	uint8_t mtr_bicolor[NB_LIGN][NB_CASES][NB_COLOR]
)
{
	mtr_bicolor[0][0][0]= 128 	;//	&.......	128
	mtr_bicolor[1][0][0]= 128	;//	&.......	128
	mtr_bicolor[2][0][0]= 128	;//	&.......	128
	mtr_bicolor[3][0][0]= 128	;//	&.......	128
	mtr_bicolor[4][0][0]= 128	;//	&.......	128
	mtr_bicolor[5][0][0]= 128	;//	&.......	128
	mtr_bicolor[6][0][0]= 240	;//	&&&&....	240	=128 +64 +32 +16

	mtr_bicolor[0][0][1]= 15	;//	....&&&&	15
	mtr_bicolor[1][0][1]= 9		;//	....&..&	9
	mtr_bicolor[2][0][1]= 9		;//	....&..&	9
	mtr_bicolor[3][0][1]= 15	;//	....&&&&	15
	mtr_bicolor[4][0][1]= 9		;//	....&..&	9
	mtr_bicolor[5][0][1]= 9		;//	....&..&	9
	mtr_bicolor[6][0][1]= 9		;//	....&..&	9

	mtr_bicolor[0][1][0]= 233	;//	&&&.&..&	233	=128 +64 +32 +8 +1	=224 +8 +1
	mtr_bicolor[1][1][0]= 153	;//	&..&&..&	153	=128 +16 +8 +1		=144 +8 +1
	mtr_bicolor[2][1][0]= 150	;//	&..&.&&.	150	=128 +16 +4 +2
	mtr_bicolor[3][1][0]= 230	;//	&&&..&&.	230	=128 +64 +32 +4 +2
	mtr_bicolor[4][1][0]= 150	;//	&..&.&&.	150
	mtr_bicolor[5][1][0]= 153	;//	&..&&..&	153
	mtr_bicolor[6][1][0]= 233	;//	&&&.&..&	233
	
	mtr_bicolor[0][1][1]= 233	;//	&&&.&..&	233	=128 +64 +32 +8 +1	=224 +8 +1
	mtr_bicolor[1][1][1]= 153	;//	&..&&..&	153	=128 +16 +8 +1		=144 +8 +1
	mtr_bicolor[2][1][1]= 150	;//	&..&.&&.	150	=128 +16 +4 +2
	mtr_bicolor[3][1][1]= 230	;//	&&&..&&.	230	=128 +64 +32 +4 +2
	mtr_bicolor[4][1][1]= 150	;//	&..&.&&.	150
	mtr_bicolor[5][1][1]= 153	;//	&..&&..&	153
	mtr_bicolor[6][1][1]= 233	;//	&&&.&..&	233
}



