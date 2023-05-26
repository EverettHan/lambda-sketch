/*===========================================================================*/
/* COPYRIGHT DASSAULT SYSTEMES 1998                                          */
/*===========================================================================*/
/*                                                                           */
/*  CATV4File                                                                */
/*                                                                           */
/*  Usage Notes: V4 File Management Routines                                 */
/*===========================================================================*/
/*  Creation fevrier 1998                                        adt         */
/*  Portage depuis la V4                                                     */
/*                                                                           */
/*  Creation en V4 par mry                                                   */
/*                                                                           */
/*===========================================================================*/
#ifndef _CFPROCSH
#define _CFPROCSH
#include "JS0FILE.h"
#include "CATDataType.h"

#define   CF_LECTURE_INTERDITE    0
#define   CF_LECTURE_AUTORISEE    1
#define   CF_ECRITURE_INTERDITE   0
#define   CF_ECRITURE_AUTORISEE   1

#define   CF_FILREP_NON_DEMANDE   0
#define   CF_FILREP_OUVERTURE     1
#define   CF_FILREP_FERMETURE     2

#define   CF_MODE_NON_PERMISSIF   0
#define   CF_MODE_PERMISSIF       1

#define   CF_CHGT_MODE_REPLACE_INUTILE 0  /* Pour optimisation de la  */
#define   CF_CHGT_MODE_REPLACE_A_FAIRE 1  /* version disque -> se     */
#define   CF_CHGT_MODE_REPLACE_FAIT    2  /* reporter @ FMCHGWM       */

#define   CF_UPDATE_HEADER_INUTILE     0  /* Pour gestion du header   */
#define   CF_UPDATE_HEADER_DEMANDE     1  /* avec controle d'ecriture */
#define   CF_UPDATE_HEADER_VALIDE      2  /* traitement special       */
#define   CF_WCNTRL_INACTIF            0  /* Doublage du controle     */
#define   CF_WCNTRL_ACTIF              1  /* des FMxxxxx pour header  */

#define   CF_MARQUAGE_FIN_INUTILE      0  /* Pour format CATDATA      */
#define   CF_MARQUAGE_FIN_A_FAIRE      1
#define   CF_MARQUAGE_FIN_A_VERIFIER   2

/*--------------------------------------------------------------------*/
#define   CF_LONG_PATH_MAX        255
#define   CF_LONG_DDNAME          255

#define   CF_LONG_ENQUEUE          80
#define   CF_LONG_MEMBER           80

#define   CF_LONG_COMMENT          80
#define   CF_LONG_HEADER          240 /* -> CATDATA */
#define   CF_LONG_RECORD           80 /* -> CATDATA */
#define   CF_LONG_BLOC_LONG         8

/*--------------------------------------------------------------------*/
#define   CF_ITMOPE_MODE_DIFF         0
#define   CF_ITMOPE_MODE_NEW          1
#define   CF_ITMOPE_MODE_MOD          2
#define   CF_ITMOPE_MODE_SHR          3
#define   CF_ITMOPE_MODE_SAVE         4
#define   CF_ITMOPE_MODE_OLD          5
#define   CF_ITMOPE_MODE_REPL         6

#define   CF_ITMCLO_FERMETURE         0
#define   CF_ITMCLO_REWIND            1

#define   CF_FILREP_DEBUT_PARCOURS    0
#define   CF_FILREP_FIN_PARCOURS      1



/* Definition d'une structure Fichier Catia Mode V4*/
struct fm_file;

typedef struct  CATV4File {
public:
ExportedByJS0FILE  friend  CATLONG32  CATV4Open( const char *   iPath,
					    const char *   iOpenMode,
					    CATV4File *&   oFile,
					    char *         oMemberComment,
					    int *          ioEbcAsc,
					    int *          ioCodpage );

ExportedByJS0FILE  friend  CATLONG32  CATV4Open( const char *   iDirName,
					    const char *   iMemberName,
					    const char *   iEnqueue,
					    const char *   iOpenMode,
					    CATV4File *&   oFile,
					    char *         oMemberComment,
					    int *          ioEbcAsc,
					    int *          ioCodpage );
  
ExportedByJS0FILE friend CATLONG32  CATV4Close( CATV4File *&iFile, const int *iCloseMode ) ;

ExportedByJS0FILE  friend CATLONG32  CATV4Read( CATV4File *iFile, 
					   char *iBufferData, 
					   CATLONG32 *LongData );

ExportedByJS0FILE  friend CATLONG32  CATV4Write( CATV4File *iFile, 
					    char *iBufferData, 
					    const CATLONG32 *iLongData) ;

ExportedByJS0FILE  friend CATLONG32  CATV4Info( CATV4File *iFile,
					   char *&   oMemberName,
					   char *&   oComment,
					   char *&   oCreationDate,
					   char *&   oCreationTime,
					   char *&   oLastModifDate,
					   char *&   oLastModifTime,
					   char *&   oLastSaveDate,
					   char *&   oDlastUse,
					   int *     oMemberSize) ;

ExportedByJS0FILE  friend CATLONG32  CATV4Com ( CATV4File *iFile,
					   char *   new_comment);
  

private:
  friend void  cmbope( const char *   	iDirName,
		       const char *     iMemberName,
		       const char *     iEnqueue,
		       char *   	member_comment,
		       const char *   	open_mode,
		       const int        iDeleteOnClose,
		       CATV4File*&	oFile,
		       int *    	status  );

  friend void  cmbrep( CATV4File *iFile,
		       char *&   oMemberName,
		       char *&   oComment,
		       char *&   oCreationDate,
		       char *&   oCreationTime,
		       char *&   oLastModifDate,
		       char *&   oLastModifTime,
		       char *&   oLastSaveDate,
		       char *&   oLastUuseDate,
		       int *    size_member,
		       int * status) ;

  //char		_DirName [CF_LONG_DDNAME + 1] ;
  char		* _DirName;
  char		_Enqueue[CF_LONG_ENQUEUE + 1] ;
  char		_MemberName[CF_LONG_MEMBER + 1] ;
  
  struct fm_file *	_FmFile ;
  int		_OpenMode ;
  char		_Header[CF_LONG_HEADER] ;

  int 		_LgBloc;
  int		_EtatLecture;
  // pour rendre le write plus intelligent
  int 		_EtatEcriture;
  
  int		status_update_header ;
  int		status_marquage_fin ;
  int		status_wcntrl ;
  int		status_replace_change_mode ;
  
  int		_status_mode_permissif ;
  int		_status_filrep ;
  int		_status_write;
  int		_status_read;
  
  int		_ModCompress;
} V4_FILE ;



/*----------------------------------------------------------------------*/
ExportedByJS0FILE  char* CATV4NamingFilter( char *iMemberName);

#ifdef __cplusplus
extern "C" {
#endif








/*--------------------------------------------------------------------*/

/* Recuperation des informations sur un membre de fichier CATIA */
/*
void  cmbinf( const char *   ddname,
              const char *   member_name,
                    char *   comment,
                    char *   date_creation,
                    char *   heure_creation,
                    char *   date_last_modif,
                    char *   heure_last_modif,
                    int *    nb_modif,
                    char *   date_last_save,
                    char *   date_last_use,
                    int *    size_member,
                    int *    num_member,   
                    int *    status
            ) ;
*/

/*--------------------------------------------------------------------*/

/* Parcours des membres d'un fichier CATIA */
/*
void  cmbrep( const char *   ddname,
                    char *   member_name,
                    int *    num_member,    
                                           
                    int *    status
            ) ;
*/
/*--------------------------------------------------------------------*/

/* Parcours des membres d'un fichier CATIA */
/*
void  cmbre1( const char *   ddname,
                    char *   member_name,
                    char *   comment,
                    char *   date_creation,
                    char *   heure_creation,
                    char *   date_last_modif,
                    char *   heure_last_modif,
                    int *    nb_modif,
                    char *   date_last_save,
                    char *   date_last_use,
                    int *    size_member,
                    int *    num_member,    
                                            
                    int *    status
            ) ;
*/

/*--------------------------------------------------------------------*/


/* Filtrage du nom des membres */
/*
  int  cflrcp() ;
*/
/*int  cmbflm( char *   member_name, char *   member_substitute ) { return 1;};*/
#define cmbflm(a, b) 1
int CATV4Filter ( const char *iMemberName, char *oFiltredName); 

int  cmbrcm( char *   member_substitute, char *   member_name ) ;




#ifdef __cplusplus
};
#endif

#endif
