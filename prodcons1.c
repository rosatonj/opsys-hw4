/* prodcons.c from class notes, edited to work in hw5 environment */
/* This uses semaphores in the normal way to share a buffer of
   As it runs, it records the sequence of producer "p" actions
   and consumer "c" actions in a global string "report".  When
   the consumer finishes, it writes out the string.  This way,
   the main run is not disturbed by i/o delays.
*/
#include <stdio.h>
#include "tunistd.h"
/* #include "semaphore.h" uncomment asap */
#include "intqueue/intqueue.h"
#include "prodcons.h"

/* globals set up by main1, used by main2 and main3 */
/* something like a UNIX main1 which forks two child processes
   running main2 and main3, and has shared memory for the 
   queue and the report buffer.  The variables mutex, empty
   and full don't need shared memory under UNIX because they
   would be filled in before the forks and their values copied 
   to the child processes.
*/
static void printline(char *s);
int mutex, empty, full; 
/* for in-memory buffer of record of consumer/producer actions */
/* max report string length--need one [pxx] and one [cxx] per item */
char report[MAXREPORT];
IntQueue buffer;

int main1(void);

int main1()
{
    report[0] = 0;		/* start with empty string */
    if (!init_i_queue(&buffer, N)) {   /* set up shared queue of N ints */
	printline("Failed to init intqueue: N too large");
	return 1;		/* fail */
    }
    /* mutex = sem_create(1); */
    /* empty = sem_create(N); */
    /* full = sem_create(0); */
    return 0;
}

static void printline(char *s)
{
    write(TTY1, s, strlen(s)); 
    write(TTY1,"\r\n",2);
}
