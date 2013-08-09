#ifndef AFF_TEMP_H
#define AFF_TEMP_H

#include <time.h>	
#include <stdio.h>

// remonter de NB de Lignes lignes
// http://stackoverflow.com/questions/1157209/is-there-an-alternative-sleep-function-in-c-to-milliseconds

// attendre un moment

// Afficher


void remonter
(
	uint8_t mtr_bicolor[NB_LIGN][NB_CASES][NB_COLOR],
	uint8_t mtr_vertcl_rouge[LARGEUR_CASE * NB_CASES],
	uint8_t mtr_vertcl_verte[LARGEUR_CASE * NB_CASES]
);

void attendre
(
	// todo: understand...
	time_t tv_sec = 0;        /* seconds */
    long   tv_nsec = 500000;  /* nanoseconds */ 
	const timespec req {
		tv_sec; 
		tv_nsec;	
	}
	time_t tv_sec_rem = 0;        /* seconds */
    long   tv_nsec_rem = 600000;  /* nanoseconds */ 
	timespec rem {
		tv_sec; 
		tv_nsec;	
	}
	nanosleep(*req, *rem);
);

#endif
