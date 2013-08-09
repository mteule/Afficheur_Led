#ifndef AFF_TEMP_H
#define AFF_TEMP_H

#include <time.h>	
#include <stdio.h>

#include <unistd.h> //usleep()

// remonter de NB de Lignes lignes

// attendre un moment
// http://stackoverflow.com/questions/1157209/is-there-an-alternative-sleep-function-in-c-to-milliseconds
// http://www.siteduzero.com/informatique/tutoriels/apprenez-a-programmer-en-c/utilisation-d-une-structure
// http://man7.org/linux/man-pages/man2/nanosleep.2.html

// Afficher

struct timespec {
           time_t tv_sec;        /* seconds */
           long   tv_nsec;       /* nanoseconds */
       };
 
void remonter ();

void attendre();

#endif
