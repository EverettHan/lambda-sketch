#ifndef FMERRNOH_INCLUDE
#define FMERRNOH_INCLUDE


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
/* Definition des constantes d'erreurs                                */
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
#include "fmlsterh.h"

extern int  fm_errno ;                /* erreur systeme recuperee     */
extern int  fm_errfm ;                /* erreur interne               */
extern char fm_errfct[FM_LONG_ROUTINE] ;
                          /* fonction interne a l'origine de l'erreur */
ExportedByJT0FIL extern void dsfm_trace( const char * ) ;
                          /* trace erreur interne                     */

#endif
