/*********************************************************************
*
*       file:           tsystm.h
*       author:         betty o'neil
*
*       kernel header for internal prototypes and global constants
*
*/

#ifndef TSYSTM_H
#define TSYSTM_H

/* Record debug info in memory between program and stack */
/* 0x300000 = 3M, the start of the last M of user memory on the SAPC */
#define DEBUG_AREA ((char *)0x300000)
#define DEBUG_AREA_LENGTH 0x40000  /* up to 0x340000, 256KB */
#define DELAY_COUNT (40*1000*1000)

/* for saved esp register--stack bases for user programs */
/* could use enum here */
#define STACKBASE1 0x3f0000
#define STACKBASE2 0x3e0000
#define STACKBASE3 0x3d0000

/* initialize io package*/
void ioinit(void);
/* read nchar bytes into buf from dev */
int sysread(int dev, char *buf, int nchar);
/* write nchar bytes from buf to dev */
int syswrite(int dev, char *buf, int nchar);
/* misc. device functions */
int syscontrol(int dev, int fncode, int val);
/* sleep for argued ms */
int syssleep(int ms);
#endif
