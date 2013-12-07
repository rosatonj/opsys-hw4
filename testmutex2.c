/*
 * file: testmutex2.c  First semaphore test, process 2:
 * uses one semaphore, used as mutex
 * NOTE: Uncomment the semaphore calls for the real test.
 */

#include <stdio.h>
#include "tunistd.h"
/* #include "semaphore.h"  uncomment this when you have this API file */
/* for shared variable mutex-- */
#include "testmutex.h"
static void printline(char *s);
int main2(void);

int main2()
{
    /* make sure main1 runs first and creates mutex */
    sleep(50);

    printline("A requests mutex...");
    /*    down(mutex); */
    printline("...A has mutex");
    sleep(500);  /* make sure it can hold over time */
    printline("After .5 sec sleep, A is releasing mutex");
    /* up(mutex); */
    return 0;
}


static void printline(char *s)
{
    write(TTY1, s, strlen(s)); 
    write(TTY1,"\r\n",2);
}
