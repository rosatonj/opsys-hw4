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
static void producer_delay(void);

int main2(void);

/* producer */
int main2()
{
    int item = 0;
    char msg1[20];

    /* do some output to make sure main1 runs before producer loop */
    printline("producer-start");

    while (item < NITEMS) {	/* producer loop */
	int stat;

	item++;			/* "produce" item */
	producer_delay();
	/*	down(empty); */  /* claim empty spot */
	/*	down(mutex); */
	stat = i_enqueue(&buffer, item);
	if (stat>=0)		
	    sprintf(msg1, "[p%d]", item); /* success report */
	else 
	    sprintf(msg1, "[pXXX]"); /* show failure of enqueue */
	sleep(PRODUCER_SLEEP);  /* slow it down, force sems to hold */
	strcat(report,msg1);	/* indicate producer action */
	/*	up(mutex);	 */
	/* up(full); */   /* signal filled-in spot */
    }
    return 2;
}

static void printline(char *s)
{
    write(TTY1, s, strlen(s)); 
    write(TTY1,"\r\n",2);
}

/* little delay to mimic work on item for producer */
static void producer_delay()
{
    int i;

    for (i=0;i<DELAYCOUNT_PRODUCER; i++)
	;
}
