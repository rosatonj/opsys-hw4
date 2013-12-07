/* Record debug info in memory */
/* Nov, '13: Reimplemented to use constants, not variables, for 
   limits of debug area, so that even if the kernel variables are
   corrupted, the debuglog output will stay in its proper area
*/ 

#include "debuglog.h"
#include "tsystm.h"
#include <stdio.h>
#include <string.h>
#define MAX_LOG_MSG 200

static char *debug_log_cursor;  /* current pointer into log area */ 
static int debug_log_wrapcount;
extern void finale(void);

void init_debuglog()
{
    debug_log_cursor = DEBUG_AREA; /* initialize log's end pointer */
    debug_log_wrapcount = 0;
}

/* append msg to memory log */
void debuglog(char *msg)
{
    int length;
    static int count = 0;
    length = strlen(msg);
    if (length > MAX_LOG_MSG) {
	length = MAX_LOG_MSG;	/* truncate overly long message */
    }
    if (debug_log_cursor < DEBUG_AREA ||
	debug_log_cursor >= DEBUG_AREA + DEBUG_AREA_LENGTH) {
	kprintf("debuglog detected memory corruption, exiting to Tutor\n");
	kprintf(" --use md %x to see debuglog\n", DEBUG_AREA); 
	finale();
    }
    if (debug_log_cursor + length >= DEBUG_AREA + DEBUG_AREA_LENGTH) {
	debug_log_cursor = DEBUG_AREA; /* wrap around in provided memory */
	debug_log_wrapcount++;
    }
    strncpy(debug_log_cursor, msg, length);  /* append msg to end of log */
    debug_log_cursor += length;  /* advance cursor */
}

/* for access to filled-in log: return start point of log area */
char * get_debuglog_string()
{
    return DEBUG_AREA;
}
int get_debuglog_wrapcount()
{
    return debug_log_wrapcount;
}
