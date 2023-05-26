#ifndef CFPROCSH_INCLUDE
#define CFPROCSH_INCLUDE


/*--------------------------------------------------------------------*/
/*SERVICE CIM OPERATING SYSTEM                                        */
/*VERSION 4                                                           */
/*COPYRIGHT DASSAULT SYSTEMES 1992                                    */
/*                                                                    */
/* IDENTIFICATION :                                                   */
/* --------------                                                     */
/*                                                                    */
/*    RESPONSABLE :  M.A. ROY                                         */
/*    COMPOSANT   :  SOFT DES FICHIERS AIX                            */
/*    USAGE       :  CATIA                                            */
/*                                                                    */
/*--------------------------------------------------------------------*/
/*                                                                    */
/* DESCRIPTION GENERALE DU SOURCE :                                   */
/* ------------------------------                                     */
/*                                                                    */
/* Definition des services offerts                                    */
/* Gestion des fichiers CATIA                                         */
/* FILxxx, ITMxxx                                                     */
/*                                                                    */
/*--------------------------------------------------------------------*/
/*                                                                    */
/* HISTORIQUE :                                                       */
/* -----------                                                        */
/*                                                                    */
/*    AUTEUR       : M.A. ROY                                         */
/*    DATE         : 08/92                                            */
/*    TYPE         : CREATION                                         */
/*                                                                    */
/*    NUMERO MODIF : 01                                               */
/*    AUTEUR       : M.A. ROY                                         */
/*    DATE         :                                                  */
/*    TYPE         :                                                  */
/*    BUT          :                                                  */
/*                                                                    */
/*--------------------------------------------------------------------*/

#include "JT0FIL.h"

/* Fermeture d'un fichier CATIA */

ExportedByJT0FIL void  cflclo( const char *   ddname,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Mise en place du parcours des membres d'un fichier CATIA  */

ExportedByJT0FIL void  cflinf( const char *   ddname,
                    int *    nb_membres_max,  /* pas de sens sous AIX */
                    int *    nb_membres,
                    int *    place_max,       /* pas de sens sous AIX */
                    int *    place_occupee,
                    char *   enqueue,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Ouverture d'un fichier CATIA */

ExportedByJT0FIL void  cflope( const char *   ddname,
              const int *    mode,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Mise en place du parcours des membres d'un fichier CATIA  */

ExportedByJT0FIL void  cflrep( const char *   ddname,
                    int *    mode,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Fermeture d'un membre de fichier CATIA */

ExportedByJT0FIL void  cmbclo( const char *   ddname,
              const char *   member_name,
              const int *    close_mode,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Modification du commentaire d'un membre de fichier CATIA */

ExportedByJT0FIL void  cmbcom( const char *   ddname,
              const char *   member_name,
                    char *   new_comment,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Destruction d'un membre de fichier CATIA */

ExportedByJT0FIL void  cmbdel( const char *   ddname,
              const char *   member_name,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Ecriture d'un membre de fichier CATIA */

ExportedByJT0FIL void  cmbecr( const char *   ddname,
              const char *   member_name,
                    char *   buffer_data,
              const int *    long_data,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Recuperation des informations sur un membre de fichier CATIA */

ExportedByJT0FIL void  cmbinf( const char *   ddname,
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
                    int *    num_member,    /* Mis a 0 - Pas de sens    */
                                            /* dans la version sans map */
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Recuperation d'informations sur un membre de fichier CATIA */

ExportedByJT0FIL void  cmbin2( const char *   ddname,
              const char *   member_name,
                    char *   comment,
                    char *   date_last_modif,
                    char *   heure_last_modif,
                    int *    size_member,
                    int *    num_member,    /* Mis a 0 - Pas de sens    */
                                            /* dans la version sans map */
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Lecture d'un membre de fichier CATIA */

ExportedByJT0FIL void  cmblec( const char *   ddname,
              const char *   member_name,
                    char *   buffer_data,
                    int *    long_data,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Mise en controle d'ecriture d'un membre de fichier CATIA */

ExportedByJT0FIL void  cmbmce( const char *   ddname,
              const char *   member_name,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Ouverture d'un membre de fichier CATIA */

ExportedByJT0FIL void  cmbope( const char *   ddname,
              const char *   member_name,
                    char *   member_comment,
              const char *   open_mode,
              const int *    wait_mode,        /* not used */
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Ouverture d'un membre de fichier CATIA */

ExportedByJT0FIL void  cmbop3( const char *   ddname,
              const char *   member_name,
                    char *   member_comment,
              const char *   open_mode,
              const int *    wait_mode,        /* not used */
                    int *    status,
                    int *    ebcasc,
                    int *    codpage
            ) ;

/*--------------------------------------------------------------------*/

/* Parcours des membres d'un fichier CATIA */

ExportedByJT0FIL void  cmbrep( const char *   ddname,
                    char *   member_name,
                    int *    num_member,    /* Mis a 0 - Pas de sens    */
                                            /* dans la version sans map */
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Parcours des membres d'un fichier CATIA */

ExportedByJT0FIL void  cmbre1( const char *   ddname,
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
                    int *    num_member,    /* Mis a 0 - Pas de sens    */
                                            /* dans la version sans map */
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/


ExportedByJT0FIL void  cmbre2( const char *   ddname,
                    char *   member_name,
                    char *   date_last_modif,
                    char *   heure_last_modif,
                    int *    size_member,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

ExportedByJT0FIL void  cmbre3( const char *   ddname,
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
                    int *    num_member,    /* Mis a 0 - Pas de sens    */
                                            /* dans la version sans map */
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/


ExportedByJT0FIL void  cmbre4( const char *   ddname,
              const char *   member_name,
                    char *   date_last_modif,
                    char *   heure_last_modif,
                    int *    size_member,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Rename d'un membre de fichier CATIA */

ExportedByJT0FIL void  cmbrnm( const char *   ddname,
              const char *   member_name,
                    char *   new_member_name,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Validation du controle d'ecriture d'un membre de fichier CATIA */

ExportedByJT0FIL void  cmbvde( const char *   ddname,
              const char *   member_name,
                    int *    status
            ) ;

/*--------------------------------------------------------------------*/

/* Selection des membres de la directory ayant la bonne enqueue */

ExportedByJT0FIL int cmbsnm( struct dirent *   p_entry ) ;

/*--------------------------------------------------------------------*/


/* Filtrage du nom des membres */

ExportedByJT0FIL int  cflrcp() ;

ExportedByJT0FIL int  cmbflm( char *   member_name, char *   member_substitute ) ;

ExportedByJT0FIL int  cmbrcm( char *   member_substitute, char *   member_name ) ;


/*--------------------------------------------------------------------*/

/* Recuperation du dsname et de l'enqueue */

ExportedByJT0FIL int cfldec( const char *   ddname,
                  char *   dsname,
                  char *   enqueue
          ) ;

/*--------------------------------------------------------------------*/

#endif
