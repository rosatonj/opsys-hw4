/*  file :tsyscall.h 
    name : joseph tam
    date : 3-2-97
    */

#ifndef TSYSCALL_H
#define	TSYSCALL_H

#define	TEXIT	1
#define	TREAD 	2
#define	TWRITE	3
#define	TIOCTL	5   /* not the real number, but keep things small */
#define TSLEEP  6
/* be sure to increase MAX_CALL when you add a system call */
#define MAX_CALL 7
#endif

