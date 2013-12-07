/* prodcons.c from class notes, edited to work in hw5 environment */
/* This uses semaphores in the normal way to share a buffer of
   As it runs, it records the sequence of producer "p" actions
   and consumer "c" actions in a global string "report".  When
   the consumer finishes, it writes out the string.  This way,
   the main run is not disturbed by i/o delays.
*/
#include <stdio.h>
#include <string.h>
#include "tunistd.h"
/* #include "semaphore.h" uncomment asap */
#include "intqueue/intqueue.h"
#include "prodcons.h"
static void printline(char *s);
static void consumer_delay(void);
int main3(void);

/* consumer */
int main3()
{
    int item = 0;
    char msg1[20];

    /* do some output to make sure main1 runs before consumer loop */
    printline("consumer-start"); /* make sure main1 runs first */

    while (item < NITEMS - 1) { /* consumer loop */
	/*	down(full); */
	/*	down(mutex); */
	item = i_dequeue(&buffer);
	sleep(CONSUMER_SLEEP);	/* make mutex hold a while */
	if (item >= 0)
	    sprintf(msg1,"[c%d]", item);
	else 
	    sprintf(msg1,"[cXXX]"); /* queue was empty */
	strcat(report, msg1);  /* under mutex */
	/*	up(mutex); */
	/*	up(empty); */
	consumer_delay();   /* consumer "consuming" */
    }
    /* output report of c's and p's */
    printline(report);
    return 0;
}

static void printline(char *s)
{
    write(TTY1, s, strlen(s)); 
    write(TTY1,"\r\n",2);
}

/* little delay to mimic work on item for consumer */
static void consumer_delay()
{
    int i;

    for (i=0;i<DELAYCOUNT_CONSUMER; i++)
	;
}



