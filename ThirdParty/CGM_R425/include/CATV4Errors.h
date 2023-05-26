/*===========================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1998                                          */
/*===========================================================================*/
/*                                                                           */
/*  CATV4File                                                                */
/*                                                                           */
/*  Usage Notes: V4 File Management Routines                                 */
/*               Return Codes definition                                     */
/*===========================================================================*/
/*  Creation fevrier 1998                                        adt         */
/*                                                                           */
/*===========================================================================*/
#ifndef _CATV4ERRORS
#define _CATV4ERRORS

/*---------------------------------------------------------------------------*/
/* Generic  Return Codes                                                     */
#define   V4FILE_E_INSUFFICIENTMEMORY          23
#define   V4FILE_E_INVALIDMODE                 24
#define   V4FILE_E_INVALIDFILEHANDLE           25

/*---------------------------------------------------------------------------*/
/* CATV4Open Specific Return Codes                                           */
#define   V4FILE_OPENOK                        0

#define   V4FILE_E_FILEALREADYOPENED           1
#define   V4FILE_E_FILENOTFOUND                2
#define   V4FILE_E_FILEALREADYEXISTS           4
#define   V4FILE_E_FILELOCKED                  5

#define   V4FILE_E_HEADERREADFAULT             6
#define   V4FILE_E_HEADERWRITEFAULT            7

#define   V4FILE_E_WRITEDENIED                 8
#define   V4FILE_E_READDENIED                  9

#define   V4FILE_E_PATHNOTFOUD                 10
#define   V4FILE_E_STATERROR                   11
#define   V4FILE_E_INVALIDPATH                 12
#define   V4FILE_E_INVALIDNAME                 17


/*---------------------------------------------------------------------------*/
/* CATV4Read Return Codes                                                    */
#define   V4FILE_READOK                        0

#define   V4FILE_E_ENDOFFILE                   3
#define   V4FILE_E_INCOHERENTLENGTH            14
#define   V4FILE_E_READFAULT                   15

#define   V4FILE_E_FMREADFAULT                 16 

/*---------------------------------------------------------------------------*/
/* CATV4Close Specific Return Codes                                          */
#define   V4FILE_CLOSEOK                       0
#define   V4FILE_E_CLOSINGWRITEFAULT           18
#define   V4FILE_E_REWIND                      19
#define   V4FILE_E_UNLINK                      20



/*---------------------------------------------------------------------------*/
/* CATV4Write Specific Return Codes                                          */
#define   V4FILE_WRITEOK                        0
#define   V4FILE_E_NOWRITEREQUESTED             21
#define   V4FILE_E_WRITEFAULT                   22

/*---------------------------------------------------------------------------*/
/* CATV4Info Specific Return Codes                                          */
#define   V4FILE_INFOOK                         0
/*  V4FILE_E_STATERROR is used by CATV4Info too    */        
         

#endif 
