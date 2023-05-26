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

extern int              scandir(const char *, struct dirent **[],
                                int (*)(struct dirent *),
                                int (*)(struct dirent **, struct dirent **));
