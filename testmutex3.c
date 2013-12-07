/*
 * file: testmutex3.c  First semaphore test, process 3:
 * uses one semaphore, used as mutex
 * NOTE: Uncomment the semaphore calls for the real test.
 */

#include <stdio.h>
#include "tunistd.h"
/* #include "semaphore.h"  uncomment this when you have this API file */
#include "testmutex.h"
static void printline(char *s);
int main3(void);

int main3()
{
    /* make sure main1 runs first and creates mutex */
    sleep(50);

    printline("B requests mutex...");
    /* down(mutex); */
    printline("...B has mutex");
    sleep(500);  /* see if it holds */
    printline("B is releasing mutex");
    /* up(mutex); */
    return 0;
}

static void printline(char *s)
{
    write(TTY1, s, strlen(s)); 
    write(TTY1,"\r\n",2);
}
