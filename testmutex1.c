/*
 * file: testmutex1.c  First semaphore test, code for process 1
 * uses one semaphore, used as mutex
 * NOTE: Uncomment the semaphore calls for the real test.
 */

#include <stdio.h>
#include "tunistd.h"
/* #include "semaphore.h"  uncomment this when you have this API file */
#include "testmutex.h"
static void printline(char *s);
int main1(void);

/* Here is the definition of the variable shared between the
   three user processes. In UNIX, this would be the parent
   process, which would create the semaphore and then fork the 
   other two processes as two child processes--they would 
   be able access the value of this variable.
*/

int mutex;

int main1() 
{
  /* if ((mutex = sem_create(1))<0) 
        printline("sem_create failed"); */
  return 0;
}

static void printline(char *s)
{
    write(TTY1, s, strlen(s)); 
    write(TTY1,"\r\n",2);
}
