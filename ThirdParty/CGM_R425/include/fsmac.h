#ifndef FSMAC_INCLUDE
#define FSMAC_INCLUDE
/*   rel :      damoso: 89269      hemoso: 1700     */
/*   tgt :      damoso: 89248      hemoso: 1112     */
/*   tgt :      damoso: 89003      hemoso: 0535     */
struct TAB_INDEX {
  int  No_Enr;
  int  Adr_Exac;
} ;
#ifdef LUT /* %IF (LUT) THEN */
struct fsdac {
                         char   ddname[9]  ;
                         char   dsname[45] ;
                         char   member[15] ;
                         char   path[257]  ;
                         char   save[257]  ;
                         char   *image     ;
                         char   *adrcour   ;
                         int    dac        ;
                         int    desc       ;
                         int    mode       ;
                         int    existe     ;
                         int    nbenr      ;
                         int    courant    ;
                         int    lgenr      ;
                  struct fsdac  *next      ;
                        int     data_mode  ; /* Mode Preprocesse ou non        */
                        int     taille     ; /* taille du fichier physique     */
                        char    *BufPhys   ; /* Pointeur sur buffer physique   */
                        int     PhDebBuf   ; /* Pointeur sur fichier physique  */
                                             /* correspondant au debut buffer  */
                        int     PhFinBuf   ; /* 1ere Adr.fic.phys. apres buffer*/
                        int     PremEnrg   ; /* Premier enregristrement buffer */
                        int     DernEnrg   ; /* Premier enrg apres le buffer   */
                  struct fsdac  *ouvert2x  ; /* Si ouvert 2 fois, pointe sur   */
                                             /* l'autre structure              */
              struct TAB_INDEX *IndexTb    ; /* Table Index                    */
                        int    Max_Index   ; /* Nb max.actu. du nombre d'elts  */
             }  ;
#else /* %ELSE */
struct fsdac {
                         char   ddname[9]  ;
                         char   dsname[45] ;
                         char   member[9]  ;
                         char   path[257]  ;
                         char   save[257]  ;
                         char   *image     ;
                         char   *adrcour   ;
                         int    dac        ;
                         int    desc       ;
                         int    mode       ;
                         int    existe     ;
                         int    nbenr      ;
                         int    courant    ;
                         int    lgenr      ;
                  struct fsdac  *next      ;
                        int     data_mode  ; /* Mode Preprocesse ou non        */
                        int     taille     ; /* taille du fichier physique     */
                        char    *BufPhys   ; /* Pointeur sur buffer physique   */
                        int     PhDebBuf   ; /* Pointeur sur fichier physique  */
                                             /* correspondant au debut buffer  */
                        int     PhFinBuf   ; /* 1ere Adr.fic.phys. apres buffer*/
                        int     PremEnrg   ; /* Premier enregristrement buffer */
                        int     DernEnrg   ; /* Premier enrg apres le buffer   */
                  struct fsdac  *ouvert2x  ; /* Si ouvert 2 fois, pointe sur   */
                                             /* l'autre structure              */
              struct TAB_INDEX *IndexTb    ; /* Table Index                    */
                        int    Max_Index   ; /* Nb max.actu. du nombre d'elts  */
             }  ;
#endif /* %ENDIF */

#define  LECTURE   0
#define  LECTSUB   1
#define  ECRITUR   2
#define  ECRISUB   3

#define  LONG_ENR  80

#define  FORMAT_TEXTE        1
#define  FORMAT_BINAIRE_OLD  2
#define  FORMAT_BINAIRE_NEW  3
#define  FORMAT_TXT_IMP      4

#define  PRECISION_INDEX     100

#define  TRACEOUT      stdout

/* ----------------- PROTOTYPES ------------------------------------------- */
ExportedByJT0FIL struct GESFON  *adgesfon();

ExportedByJT0FIL int fs_prepro(struct fsdac *,int,int,int,int );
ExportedByJT0FIL int fd2_nbenr(struct fsdac *);
ExportedByJT0FIL int fd2_recale(struct fsdac *,int);

#endif
