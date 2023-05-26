/*===========================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1998                                          */
/*===========================================================================*/
/*                                                                           */
/*  soft for V4 Files                                                        */ 
/*                                                                           */
/*  Usage Notes: Fm Services Definition                                      */
/*===========================================================================*/
/*  Creation janvier 1998                                 adt                */
/*  portage depuis la V4                  remerciements a MRY                */
/*===========================================================================*/
#ifndef __FMPROCSH
#define __FMPROCSH
/*Ia64+ */ 
#include "CATDataType.h"
/*Ia64- */ 
#include <stdio.h>
#include <sys/types.h>

#include "JS0FILE.h"
#include "CATSysMultiBuffer.h"
#include "CATWTypes.h"

/* et cela se pretend  un OS.......  */
#ifdef  _WINDOWS_SOURCE
#include <Windows.h>

typedef struct flock { 
  short   l_type;
  short   l_whence;
  long    l_start;
  long    l_len;          /* len == 0 means until end of file */
  long    l_sysid;
  long    l_pid;
  long    pad[4];         /* reserve area */
} flock_t;

#define F_UNLCK  03
#define F_WRLCK  01
#define F_RDLCK  00
#define F_SETLK  06

#define fsync(fd) 		_commit(fd)
#define link( name, NewName) 	MoveFile( name, NewName)
#define ftruncate(fd,size) 	_chsize(fd, size)
#define unlink(fd)		_unlink(fd)
#endif




#ifdef _WINDOWS_SOURCE
/*Ia64C #define GETPID    ((unsigned long)( GetCurrentProcess ())) */ 
/*Ia64+ */ 
#define GETPID    ((size_t)( GetCurrentProcess ()))
/*Ia64- */ 
#define LINKFALSE	FALSE
#define LCKEXT          ".ulk"
#else
#define GETPID		getpid ()
#define LINKFALSE	-1	
#endif


/* Pour la creation a la volee des fichiers temporaires */
#ifdef _WINDOWS_SOURCE
#define MODE_CREATE	      O_CREAT|O_EXCL|O_RDWR|O_BINARY
#else
#define MODE_CREATE	      O_CREAT|O_EXCL|O_RDWR
#endif



/*--------------------------------------------------------------------*/
#define   FM_LONG_PATH_MAX      1024
#define   FM_LONG_NAME_MAX      255

#define   FM_BUFSIZ             4096
#define   FM_BUFFER_IO_SIZE     64*1024
#define   FM_DISCLAIM_SIZE      1024*128



/*--------------------------------------------------------------------*/
#define   FM_LECTURE_INTERDITE    0
#define   FM_LECTURE_AUTORISEE    1
#define   FM_ECRITURE_INTERDITE   0
#define   FM_ECRITURE_DIFFEREE    1
#define   FM_ECRITURE_REPLACE     2
#define   FM_ECRITURE_ORDINAIRE   3

/*--------------------------------------------------------------------*/
#define   FM_RENAME_NON_DEMANDE   0
#define   FM_RENAME_DEMANDE       1
#define   FM_RENAME_VALIDE        2

/*--------------------------------------------------------------------*/
#define   FM_CNTRL_ECRITURE_INACTIF  0
#define   FM_CNTRL_ECRITURE_ACTIF    1
#define   FM_CNTRL_ECRITURE_VALIDE   2


/*--------------------------------------------------------------------*/
#ifdef _WINDOWS_SOURCE
#define SEPAR ";"
#define DIR_DELIMITER "\\"
#define DROIT_W 	_S_IWRITE
#define DROIT_X 	_S_IEXEC
#define DROIT_R 	_S_IREAD
#define DROIT_RW 	_S_IREAD | _S_IWRITE
#else
#define DIR_DELIMITER "/"
#define SEPAR ":"
#define DROIT_W 	S_IWUSR
#define DROIT_R 	S_IRUSR
#define DROIT_RW 	S_IRUSR | S_IWUSR
#define DROIT_X  	S_IXUSR
#endif

#ifdef _WINDOWS_SOURCE
#define READ 		GENERIC_READ
#define WRITE		GENERIC_WRITE
#define READWRITE	(GENERIC_WRITE | GENERIC_READ)
#define OPENNEW 	CREATE_NEW
#define CREATE		CREATE_ALWAYS
#define OPEN		OPEN_EXISTING
#define SHAREWRITE	0
#define SHAREREAD	FILE_SHARE_READ
#define SEEKSET		FILE_BEGIN
#define SEEKCUR		FILE_CURRENT
#define SEEKEND		FILE_END

#define ERRNO		GetLastError()

#else
#define READ 		O_RDONLY
#define WRITE		O_WRONLY 
#define READWRITE	O_RDWR
#define OPENNEW		(O_CREAT | O_EXCL )
#define CREATE		(O_CREAT | O_TRUNC) 
#define OPEN		0
#define SHAREWRITE	F_WRLCK
#define SHAREREAD	F_RDLCK
#define SEEKSET		SEEK_SET
#define SEEKCUR		SEEK_CUR
#define SEEKEND		SEEK_END

#define ERRNO		errno

#endif
/*--------------------------------------------------------------------*/
#define   FM_POSITION_COURANTE       SEEKCUR
#define   FM_POSITION_DEBUT          SEEKSET
#define   FM_POSITION_FIN            SEEKEND

#define TODELETE 1

#define RELEASE_FM_STRUCT(f)     close( f->file_descr ) ;	\
			         if(f->_Buff) delete ( f->_Buff ) ;		\
					 if(f->path) delete [] ( f->path ) ; \
			         free( f ) ;			\
				 f = NULL ;	
/*--------------------------------------------------------------------*/
/* Definition d'une structure File */

typedef struct fm_file {
               char           * path ;
               char           name[ FM_LONG_NAME_MAX + 1] ;
               char           new_name[ FM_LONG_NAME_MAX + 1] ;
               char           copy_name[ FM_LONG_NAME_MAX + 8+ 1] ;
#ifdef _WINDOWS_SOURCE
  /*HANDLE         WFd ;*/
#endif
               int            file_descr ;
               int            copy_descr ;

               int            status_rename ;
               int            status_read ;
               int            status_write ;
               int            permission ;
               int            write_control ;
               int            Delete_On_Close;
               off_t          begin_write_offset ;
               off_t          last_write_offset ;
              

               CATSysMultiBuffer*	_Buff;
	       ULARGE_INTEGER		_Off;
	       size_t			_BOff;
	       size_t			_BSize;
       
        } T_FM_FILE ;

/*--------------------------------------------------------------------*/

/* Definition d'une structure Directory */
typedef struct fm_directory {
               char           path[ FM_LONG_PATH_MAX + 1] ;
               int            status_read ;
               int            status_write ;
               int            permission ;
        } T_FM_DIR ;

/*--------------------------------------------------------------------*/




#ifdef __cplusplus
extern "C" {
#endif
/*--------------------------------------------------------------------*/
/* OPEN d'un fichier */
ExportedByJS0FILE T_FM_FILE *  fmopen( const char *   path,
				       const char *   name,
				       const int      mode,
				       const int      permission,
				       const int      DeleteOnClose  ) ;

/*--------------------------------------------------------------------*/
/* CLOSE d'un fichier */
ExportedByJS0FILE int fmclose(  T_FM_FILE *   fm_struct_file ) ;

ExportedByJS0FILE int fmclos1(  T_FM_FILE *   fm_struct_file ,
				const int           maj_header,
				const int           long_header,
				const char *        header,
				const int           cntrl_marqueur_fin,
				const int           long_marqueur_fin,
				const char *        marqueur_fin           ) ;

/*--------------------------------------------------------------------*/
/* READ d'un fichier */
ExportedByJS0FILE int  fmread( T_FM_FILE *   fm_struct_file,
			       const char *        buffer_read,
			       const unsigned int  nb_bytes           ) ;

/*--------------------------------------------------------------------*/
/* WRITE d'un fichier */
ExportedByJS0FILE int  fmwrite( T_FM_FILE *   fm_struct_file,
				const char *        buffer_write,
				const unsigned int  nb_bytes            ) ;

/*--------------------------------------------------------------------*/
/* LSEEK sur un fichier */
ExportedByJS0FILE off_t fmlseek(  T_FM_FILE *   fm_struct_file,
				  const off_t         offset,
				  const int           whence              ) ;

/*--------------------------------------------------------------------*/
/* Mise en place du controle d'ecriture sur un fichier */
ExportedByJS0FILE int fmsetwc( T_FM_FILE *   fm_struct_file ) ;
/* not implemented */

/*--------------------------------------------------------------------*/
/* Validation du controle d'ecriture sur un fichier */
ExportedByJS0FILE int fmvalwc( T_FM_FILE *   fm_struct_file ) ;
/* not implemented */

/*--------------------------------------------------------------------*/
/* Destruction d'un fichier */
ExportedByJS0FILE int fmunlnk( const T_FM_FILE *   fm_struct_file ) ;

/*--------------------------------------------------------------------*/
/* Demande de rename d'un fichier */
ExportedByJS0FILE int   fmrname(  T_FM_FILE *   fm_struct_file,
				  const char *        new_name	 ) ;
/* not implemented */

/*--------------------------------------------------------------------*/
/* Changement du mode d'ecriture d'un fichier ouvert */
ExportedByJS0FILE int fmchgwm( T_FM_FILE *   fm_struct_file ) ;
/* not implemented */

/*--------------------------------------------------------------------*/
/* FTRUNCATE d'un fichier ouvert */
ExportedByJS0FILE int fmtrunc(  T_FM_FILE *   fm_struct_file,
				  const off_t         nb_bytes  ) ;
/* not implemented */

/*--------------------------------------------------------------------*/
ExportedByJS0FILE int fmerror( );

#ifdef __cplusplus
};
#endif

#endif
