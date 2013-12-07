/* number of spots in shared buffer */
#define N 5
/* number of fake items to process */
#define NITEMS 30
/* size of delay to mimic producer/consumer work */
#define PRODUCER_SLEEP 10
#define CONSUMER_SLEEP 30

/* these are small delays, under 2 ms */
/* For a preemptive scheduler, would be interesting to try 2000000 
   or so here to see a tick during a delay loop */
#define DELAYCOUNT_PRODUCER 100000
#define DELAYCOUNT_CONSUMER 100000

/* globals set up by main1, used by main1 and main2 */
extern int mutex, empty, full; 
/* for in-memory buffer of record of consumer/producer actions */
/* max report string length--need one [pxx] and one [cxx] per item */
#define MAXREPORT (100 + NITEMS*8)
extern char report[MAXREPORT];
extern IntQueue buffer;

/*char *strcat(char *s1, const char *s2);*/  /* no strings.h header */ 

