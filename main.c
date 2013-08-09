/* Pour compiler afin de tester le programme:
 * 
 * gcc -std=c99 *.c -o /tmp/TEST
 * 
 * */
 
#include "tests_affichage.h"
#include "tests_turn_mtr.h"
#include "tests_conv_char.h"
#include "tests_aff_bicolor.h"
#include "tests_aff_temp.h"

void main()
{
	test_all_affichage();
	test_all_turn_mtr();
	test_all_conv_char();
	test_all_aff_bicolor();
	test_all_aff_temp();
}
