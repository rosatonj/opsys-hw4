/* Debug logging API */

/* initialize debug log using memory starting at address DEBUG_AREA */
void init_debuglog(void);

/* append msg to memory log */
void debuglog(char *msg);

/* for access to filled-in log: return start point of log area */
char * get_debuglog_string(void);

/* to find out if debuglog had to wrap around in its memory */
int get_debuglog_wrapcount(void);


