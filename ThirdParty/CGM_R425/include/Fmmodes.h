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
/* Definition des modes d'ouverture                                   */
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
/*--------------------------------------------------------------------*/

/*--------------------------------------------------------------------*/

#define   ITMOPE_NEW                  0
#define   ITMOPE_DIFF                 1
#define   ITMOPE_MOD                  2
#define   ITMOPE_OLD                  3
#define   ITMOPE_SHR                  4
#define   ITMOPE_SAVE                 5
#define   ITMOPE_REPL                 6

#define   COMMON_WRITE                7

#define   FSOUVR_LECTURE              8
#define   FSOUVR_LECTURE_SUBSTITUEE   9
#define   FSOUVR_ECRITURE            10

#define   DACOPE_LECTURE             11
#define   DACOPE_LECTURE_SUBSTITUEE  12
#define   DACOPE_UPDATE              13
#define   DACOPE_UPDATE_SUBSTITUEE   14

/*--------------------------------------------------------------------*/


