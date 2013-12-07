
/* header for testmutex: shared variable */
/* Note that shared variables are *defined* in one of the C files,
   (i.e. "int mutex;", allocating memory, not "extern int mutex;")
   in this case testmutex1.c. Here they are just externed, so
   that they are documented as existing to the other files.
*/
extern int mutex;
