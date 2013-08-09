#include "6_aff_temp.h"	

void remonter ()
{
	
}

void attendre()
{
	// todo: understand...
//	time_t tv_sec = 0;        /* seconds */
//  long   tv_nsec = 500000;  /* nanoseconds */ 
	struct timespec req;
	req.tv_sec = 1; 
	req.tv_nsec = 500000000;	
	
	time_t tv_sec_rem = 0;        /* seconds */
    long   tv_nsec_rem = 600000000;  /* nanoseconds */ 
	struct timespec rem ;
	rem.tv_sec = 2; 
	rem.tv_nsec = 600000000;
	
	nanosleep(req, rem);
	usleep(900000); // avec usleep() ça a marché directement!
}

