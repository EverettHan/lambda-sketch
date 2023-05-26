#ifndef __Dscandir
#define __Dscandir

// COPYRIGHT DASSAULT SYSTEMES 2000

/* ODX and PLE for LME */		  

#include "JS0CORBA.h"

#if defined(_SUNOS_SOURCE) || defined(_WINDOWS_SOURCE)
ExportedByJS0CORBA int alphasort(struct dirent **, struct dirent **);
#endif

#ifdef _SUNOS_SOURCE
/* to use scandir under SUNOS */
int dscandir(const char *,struct dirent **[],int (*)(struct dirent*),
	     int (*)(struct dirent **, struct dirent **));
#endif

#ifdef _WINDOWS_SOURCE
/* PLE */
/* to use scandir under WINDOWS */
struct dirent {                         /* data from readdir() */
        unsigned int    d_ino;          /* inode number of entry */
        unsigned int    d_off;          /* offset of disk direntory entry */
        unsigned short  d_reclen;       /* length of this record */
        char            d_name[1];      /* name of file */
};

typedef struct
        {
        int             dd_fd;          /* file descriptor */
        int             dd_loc;         /* offset in block */
        int             dd_size;        /* amount of valid data */
        char            *dd_buf;        /* directory block */
        }       DIR;                    /* stream data from opendir() */

ExportedByJS0CORBA extern int   scandir(const char *, struct dirent **[],
                                int (*)(struct dirent *),
                                int (*)(struct dirent **, struct dirent **));
#endif
#endif
