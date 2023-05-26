#ifndef CFERRNOH_INCLUDE
#define CFERRNOH_INCLUDE


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
/* Gestion des fichiers CATIA : FILxxx, ITMxxx                        */
/*                                                                    */
/*--------------------------------------------------------------------*/
/*                                                                    */
/* HISTORIQUE :                                                       */
/* -----------                                                        */
/*                                                                    */
/*    AUTEUR       : M.A. ROY                                         */
/*    DATE         : 10/92                                            */
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
#include "cflsterh.h"

extern int  cf_errno ;                /* erreur systeme recuperee     */
extern int  cf_errcf ;                /* erreur interne               */
extern char cf_errfct[CF_LONG_ROUTINE] ;
                          /* fonction interne a l'origine de l'erreur */
ExportedByJT0FIL extern void dscf_trace( const char * ) ;
                          /* trace erreur interne                     */

#endif
