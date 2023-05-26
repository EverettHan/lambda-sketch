/* 1ere ligne pour monocode */


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
/* Liste des constantes d'erreurs                                     */
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

/*--------------------------------------------------------------------*/

#define FM_MODE_INCORRECT                          1
/*           Le mode demande n'est pas reconnu     */
/*           par le service                        */

#define FM_PROBLEME_ALLOCATION                     2
/*           Probleme allocation memoire rencontr{ */

#define FM_FICHIER_INEXISTANT                      3
/*           Mode ouverture non compatible avec inexistence */

#define FM_FICHIER_EXISTE_DEJA                     4
/*           Mode ouverture non compatible avec existence */

#define FM_FICTEMP_EXISTE_DEJA                     5
/*           Fichier temporaire existe deja alors qu'on veut le creer */

#define FM_DROIT_LECTURE_NON_OK                    6
/*           Mode ouverture non compatible avec inexistence */

#define FM_DROIT_ECRITURE_NON_OK                   7
/*           Mode ouverture non compatible avec inexistence */

#define FM_PROBLEME_OUVERTURE                      8
/*           Probleme ouverture par system call open */

#define FM_FICTEMP_PROBLEME_OUVERTURE              9
/*           Probleme ouverture fichier travail par system call open */

#define FM_PROBLEME_LOCK                          10
/*           Probleme sur lock fichier apres ouverture */

#define FM_FICTEMP_PROBLEME_LOCK                  11
/*           Probleme sur lock fichier travail apres ouverture */

#define FM_PROBLEME_FERMETURE                     12
/*           Probleme fermeture par system call close */

#define FM_FICTEMP_PROBLEME_FERMETURE             13
/*           Probleme fermeture fichier travail par system call close */

#define FM_PROBLEME_UNLINK                        14
/*           Probleme destruction par system call unlink */

#define FM_FICTEMP_PROBLEME_UNLINK                15
/*        Probleme destruction fichier travail par system call unlink */

#define FM_PROBLEME_LINK                          16
/*           Probleme mise a jour par system call link */

#define FM_NON_OUVERT_EN_LECTURE                  17
/*           Mode ouverture fichier non coherent avec lecture */

#define FM_NON_OUVERT_EN_ECRITURE                 18
/*           Mode ouverture fichier non coherent avec ecriture */

#define FM_PROBLEME_LECTURE                       19
/*           Probleme lecture fichier rencontre par system call read */

#define FM_FICTEMP_PROBLEME_LECTURE               20
/*   Probleme lecture fichier travail rencontre par system call read */

#define FM_PROBLEME_ECRITURE                      21
/*           Probleme ecriture fichier rencontre par system call write*/

#define FM_FICTEMP_PROBLEME_ECRITURE              22
/*   Probleme ecriture fichier travail rencontre par system call write*/

#define FM_PROBLEME_DEVICE_FULL                   23
/*         Probleme ecriture fichier rencontre - device full par fsync*/

#define FM_PROBLEME_LSEEK                         24
/*           Probleme deplacement dans fichier par system call lseek */

#define FM_PROBLEME_FSTAT                         25
/*          Probleme acces informations fichier par system call fstat*/

#define FM_PROBLEME_FTRUNCATE                     26
/*   Probleme troncature fichier de travail par system call ftruncate*/

#define FM_FICTEMP_PROBLEME_FTRUNCATE             27
/*   Probleme troncature fichier de travail par system call ftruncate*/

#define FM_WCNTRL_NON_AUTORISE                    28
/*          Controle d'ecriture non compatible avec mode ecriture    */

#define FM_RENAME_NON_AUTORISE                    29
/*          Rename du fichier non compatible avec mode ecriture      */

#define FM_UNLINK_NON_AUTORISE                    30
/*          Unlink du fichier non compatible avec mode ecriture      */

#define FM_WCNTRL_EN_COURS                        31
/*         Unlink du fichier non compatible avec controle d'ecriture */

#define FM_CHGWM_NON_AUTORISE                     32
/*   Changement du mode d'ecriture non compatible avec mode ecriture */

#define FM_FIN_DE_FICHIER                         33
/*   Lecture impossible - fin de fichier atteinte  */


/*--------------------------------------------------------------------*/

#define FM_LONG_ROUTINE   32  /* Longueur chaine caracteres fm_errfct */

