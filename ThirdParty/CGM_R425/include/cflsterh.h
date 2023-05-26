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
/* Gestion des fichiers CATIA : FILxxx et ITMxxx                      */
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

/*--------------------------------------------------------------------*/

#define CF_NO_PROBLEM                              0
/*           Pas de probleme rencontre             */

#define CF_MODE_INCORRECT                          1
/*           Le mode demande n'est pas reconnu     */
/*           par le service                        */

#define CF_PROBLEME_ALLOCATION                     2
/*           Probleme allocation memoire rencontr{ */

#define CF_DIRECTORY_INEXISTANTE                   3
/*           La directory n'a pas ete creee        */

#define CF_DROIT_LECTURE_NON_OK                    4
/*           Lecture non autorisee                 */

#define CF_DROIT_ECRITURE_NON_OK                   5
/*           Ecriture non autorisee                */

#define CF_FICHIER_DEJA_OUVERT                     6
/*           Fichier CATIA a deja ete ouvert       */

#define CF_FICHIER_NON_OUVERT                      7
/*           Fichier CATIA non ouvert              */

#define CF_PROBLEME_DDNAME                         8
/*          Probleme rencontre sur DDNAME : inconnu, ...  */

#define CF_PROBLEME_STAT                           9
/*          Probleme acces informations directory par system call stat*/

#define CF_FICHIER_NON_DIRECTORY                  10
/*          Un fichier CATIA doit etre une directory */

#define CF_MEMBRE_DEJA_OUVERT                     11
/*           Membre CATIA a deja ete ouvert       */

#define CF_MEMBRE_NON_OUVERT                      12
/*           Membre CATIA non ouvert              */

#define CF_MEMBRE_INEXISTANT                      13
/*           Le membre devrait deja exister       */

#define CF_MEMBRE_EXISTE_DEJA                     14
/*           Le membre ne existe deja et donc ne peut etre cree */

#define CF_PROBLEME_SUR_NOM                       15
/*           Nom de membre rejete par le filtre   */

#define CF_PROBLEME_LOCK_MEMBRE                   16
/*           Probleme rencontre sur le lock du membre */

#define CF_PROBLEME_OUVERTURE_MEMBRE              17
/*           Probleme divers rencontre a l'ouverture d'un membre */

#define CF_PROBLEME_FERMETURE_MEMBRE              18
/*          Un des membres du fichier ne peut etre ferme */

#define CF_MEMBRE_NON_OUVERT_EN_ECRITURE          19
/*          Le membre n'a pas ete ouvert en mode ecriture */

#define CF_PROBLEME_ECRITURE_MEMBRE               20
/*          Probleme divers detecte par le soft des FMXXXXX */

#define CF_PROBLEME_DEVICE_FULL                   21
/*          Probleme sur place disque        */

#define CF_PROBLEME_LECTURE_MEMBRE                22
/*          Probleme divers detecte par le soft des FMXXXXX */

#define CF_PROBLEME_FMLSEEK                       23
/*           Probleme detecte par fmlseek */

#define CF_PROBLEME_COHERENCE_DATA                24
/*           Incoherence entre info attendue et info obtenue */

#define CF_PROBLEME_CHANGEMENT_MODE               25
/* Probleme au cours du passage du mode replace a l'ecriture differee */

#define CF_WCNTRL_EN_COURS                        26
/*          Controle d'ecriture en cours : unlink impossible */

#define CF_PROBLEME_DESTRUCTION_MEMBRE            27
/*          Probleme divers detecte par le soft des FMXXXXX */

#define CF_PROBLEME_RENAME_MEMBRE                 28
/*          Probleme divers detecte par le soft des FMXXXXX */

#define CF_PROBLEME_SET_WRITE_CNTRL               29
/*          Probleme divers detecte par le soft des FMXXXXX */

#define CF_PROBLEME_VAL_WRITE_CNTRL               30
/*          Probleme divers detecte par le soft des FMXXXXX */

#define CF_PROBLEME_SCANDIR                       31
/*          Probleme divers detecte par scandir */

#define CF_FILREP_NON_FAIT                        32
/*          Un appel a FILREP doit preceder la boucle sur ITMREP */

#define CF_ITMREP_FIN_PARCOURS                    33
/*          Tous les membres du fichier ont ete parcourus */

#define CF_FILREP_PROBLEME_PARCOURS               34
/*          probleme sur detection enqueue du nom du membre */

#define CF_FIN_DE_MEMBRE                          35
/*          Fin de membre detectee a la lecture */

#define CF_MEMBRE_MODE_PERMISSIF                  36
/*          ITMRE2 : Membre est en mode permissif */

#define CF_RESTE_MEMBRES_OUVERTS                  37
/*          Un ou plusieurs membres du fichier sont encore ouverts */

#define CF_FILPUR_PROBLEME_FILREP                 38
/*          Probleme detecte par FILREP pour FILPUR */

#define CF_FILPUR_PROBLEME_ITMREP                 39
/*          Probleme detecte par ITMREP pour FILPUR */

#define CF_FILPUR_PROBLEME_ITMOPE                 40
/*          Probleme detecte par ITMOPE pour FILPUR */

#define CF_FILPUR_PROBLEME_ITMDEL                 41
/*          Probleme detecte par ITMDEL pour FILPUR */

#define CF_PROBLEME_DCINIT                        42
/*          Probleme detecte par soft des DC */

#define CF_PROBLEME_INIT_SOFT_DC                  43
/*          Probleme detecte par soft des DC */

#define CF_PROBLEME_DCDEFCRI                      44
/*          Probleme detecte par soft des DC */

#define CF_PROBLEME_DCQUERY                       45
/*          Probleme detecte par soft des DC */

#define CF_PROBLEME_DCTABADR                      46
/*          Probleme detecte par soft des DC */

#define CF_PROBLEME_DCLSUFDD                      47
/*          Probleme detecte par soft des DC */


#define CF_PB_CHARGEMENT_FILTRE                   48
/*          Probleme rencontre au chargement du filtre */

#define CF_FILTRE_INCORRECT                       49
/*          Le filtre n'est pas bijectif */

#define CF_MEMBRE_A_IGNORER                       50
/* Pour RECORD - ITMRE2 - on ignore les membres de longueur nulle */


#define CF_PROBLEME_REMOTE                        51
/*          Probleme de communication avec server remote */

#define CF_PB_REMOTE_LG_PACKET                    52
/*          Longueur du packet recu par remote est incorrecte */

#define CF_FICHIER_REMOTE                         53
/*          action interdite sur fichier remote  */

#define CF_PB_FILREP_DS_ITMREP                    54
/*          erreur du filrep remote dans un itmrep */

#define CF_ERREUR_CODE                            55
/*          erreur code ni ASCII, ni EBCDIC itmope */

/*--------------------------------------------------------------------*/

#define CF_LONG_ROUTINE   32  /* Longueur chaine caracteres CF_errfct */

