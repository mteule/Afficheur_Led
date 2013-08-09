#include "tests_aff_temp.h"

void test_all_aff_temp()
{
	test_attendre();
}
void test_attendre()
{
	// Attendre 10 fois.
	for (uint8_t i=0; i<10; i++)
	{
		attendre();
	}
}
