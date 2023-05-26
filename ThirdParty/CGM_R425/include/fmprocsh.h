#ifndef FMPROCSH_INCLUDE
#define FMPROCSH_INCLUDE


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
/* Gestion de base des fichiers DS, independante du soft d'acces :    */
/* FILxxx, ITMxxx, FSxxxx, DACxxxx, ...                               */
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

/* OPEN d'un fichier */
ExportedByJT0FIL T_FM_FILE *   fmopen( const char *   path,
                      const char *   name,
                      const int      mode,
                      const int      permission
                    ) ;

/*--------------------------------------------------------------------*/

/* CLOSE d'un fichier */

ExportedByJT0FIL int    fmclose(       T_FM_FILE *   fm_struct_file ) ;

ExportedByJT0FIL int    fmclos1(       T_FM_FILE *   fm_struct_file ,
                const int           maj_header,
                const int           long_header,
                const char *        header,
                const int           cntrl_marqueur_fin,
                const int           long_marqueur_fin,
                const char *        marqueur_fin
              ) ;

/*--------------------------------------------------------------------*/

/* READ d'un fichier */
ExportedByJT0FIL int   fmread(       T_FM_FILE *   fm_struct_file,
              const char *        buffer_read,
              const unsigned int  nb_bytes
            ) ;

/*--------------------------------------------------------------------*/

/* WRITE d'un fichier */
ExportedByJT0FIL int   fmwrite(       T_FM_FILE *   fm_struct_file,
               const char *        buffer_write,
               const unsigned int  nb_bytes
             ) ;

/*--------------------------------------------------------------------*/

/* LSEEK sur un fichier */
ExportedByJT0FIL off_t   fmlseek(       T_FM_FILE *   fm_struct_file,
                 const off_t         offset,
                 const int           whence
               ) ;

/*--------------------------------------------------------------------*/

/* Mise en place du controle d'ecriture sur un fichier */
ExportedByJT0FIL int   fmsetwc( T_FM_FILE *   fm_struct_file ) ;

/*--------------------------------------------------------------------*/

/* Validation du controle d'ecriture sur un fichier */
ExportedByJT0FIL int   fmvalwc( T_FM_FILE *   fm_struct_file ) ;

/*--------------------------------------------------------------------*/

/* Destruction d'un fichier */
ExportedByJT0FIL int   fmunlnk( const T_FM_FILE *   fm_struct_file ) ;

/*--------------------------------------------------------------------*/

/* Demande de rename d'un fichier */

ExportedByJT0FIL int   fmrname(       T_FM_FILE *   fm_struct_file,
               const char *        new_name
             ) ;

/*--------------------------------------------------------------------*/

/* Changement du mode d'ecriture d'un fichier ouvert */
ExportedByJT0FIL int   fmchgwm( T_FM_FILE *   fm_struct_file ) ;

/*--------------------------------------------------------------------*/

/* FTRUNCATE d'un fichier ouvert */
ExportedByJT0FIL int   fmtrunc(       T_FM_FILE *   fm_struct_file,
               const off_t         nb_bytes
             ) ;

/*--------------------------------------------------------------------*/

#endif
