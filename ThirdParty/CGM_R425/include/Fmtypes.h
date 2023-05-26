/*===========================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1998                                          */
/*===========================================================================*/
/*                                                                           */
/*  soft for V4 Files                                                        */ 
/*                                                                           */
/*  Usage Notes: Fm Specific Types Definitions                               */
/*===========================================================================*/
/*  Creation janvier 1998                                 adt                */
/*  portage depuis la V4                  remerciements a MRY                */
/*===========================================================================*/
#ifndef __FMTYPESH
#define __FMTYPESH
#include "JS0FILE.h"

#include <stdio.h>
#include <sys/types.h>

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




#endif
