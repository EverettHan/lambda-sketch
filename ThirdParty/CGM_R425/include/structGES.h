
/**
 * @level Private
 * @usage U1
 */

/* structGES.h : COPYRIGHT DASSAULT SYSTEMES 1995 */
#ifndef structGES_h
#define structGES_h
//----------------------------------------------------------------
//                     GES
//----------------------------------------------------------------

struct Proteg {
  unsigned short protg_type:8;
  unsigned short protg_bidon:6;
  unsigned short protg_insuf: 1; // =1: Un calcul de Protection est necessaire
  unsigned short protg_exces: 1; // =1: Les protections calcules excessives ?
} ;


struct Accept {
  unsigned char laccep_iua:1;   // Creation dans l'IUA             bit  7
  unsigned char laccep_vmd:1;   // Modification Visualisation      bit  6
  unsigned char laccep_ima:1;   // gestion Image                   bit  5
  unsigned char laccep_temp:1;  // Creation d'element temporaire   bit  4
  unsigned char laccep_perm:1;  // Creation d'element permanent    bit  3
  unsigned char laccep_desc:1;  // Modification Description        bit  2
  unsigned char laccep_par:1;   // Modification Table parentale    bit  1
  unsigned char laccep_erase:1; // Effacement Element/Ensemble     bit  0
} ;


struct LdtAcc {
  unsigned char ldtacc7 : 1; 
  unsigned char ldtacc6 : 1; 
  unsigned char ldtacc5 : 1; 
  unsigned char ldtacc4 : 1; 
  unsigned char ldtacc3 : 1; 
  unsigned char OvlAcc  : 1; 
  unsigned char ldtacc1 : 1; 
  unsigned char ldtacc0 : 1; 
} ;

struct GES {

  int   loncom;      // longueur GES+TOLER en octets 1568 ou ...
  int   icodhd;       /* code de header defini dans SYSLON    */

  double  echtrd;       /* echelle commune des triedres SPACE   */

  char    limage;       /*            ????                      */
  char    lv2cot;       /*            ????                      */
  char    lvmsup;       /*            ????                      */
  char    lriliz;       /*            ????                      */
  int     eccnum;       /* Compteur NUMELE des ECC maitres      */
  int     nuplma;       /* numero du PLF en cours de l'espace   ..
                        .. master                               */
  int     nugrma;       /* numero du groupe en cours dans       ..
                        .. l'espace master                      */
  int     ilibre[2];    /*            ????                      */
  int     ivituy;       /*            ????                      */
  int     ivistw;       /*            ????                      */
  int     ivishe;       /*            ????                      */
  int     iifree[3];    /*            ????                      */
  int     itabel[64];   /* tableau contenant les nombres        ..
                        .. d'elements deja crees (par types )   */
  int     itaben[32];   /* tableau contenant les nombres        ..
                        .. d'elements deja crees (par sous-type)*/
  char    lvisex;      /* logique concernant le ROLL de visu   */
  char    lztadr;       /* .true. si des adresses sont stockees ..
                        .. dans les zones de travail de index   */
  char    lnosho;       /* .true. en mode de visualisation      ..
                        ..  "NO SHOW"                           */
  char    ldtacc;       /*            ????                      */

  char    lresvi;       /* .true. pour valider la restitution   ..
                        .. de la visualisation permanente       */
  char    lshopa;       /* logique de SHOW/NO SHOW des patterns */
  char    lnopic;       /* .true. en mode de visu "NO PICK"     */
  char    lwspac;       /* .true. pour appliquer une selection  ..
                        .. generalisee a tout l'espace de travail */

  char   accept;        /* mais a manipuler par la struct Accept */

  char   lswv2d;       /*            ????                      */
  char   lfiltr;       /*            ????                      */
  char   lfanto;       /*            ????                      */

  char   ldrfon;       /*            ????                      */
  char   ltrspl;       /*            ????                      */

  short  proteg;       /* mais a manipuler par la struct proteg */
  
  int     indbid;       /*            ????                      */
  int     imsrep[3];    /*            ????                      */

  /* .................................................................. */

  int     igrrep[3],    /* @ de l'element en cours dans  le     ..
                        ..     G.T.No i (gere par REPGTi)       */
          ichera[3],    /* Gestion /ERASE/                      */
          ielmod,       /*            ????                      */
          ielera,       /* @ du dernier element EFFACE          */
          ibasic,       /* @ de l'ECC des ecrans                */
          ishdet,       /* @ de la feuille DETAIL (ECC  des     ..
                        .. vues draws                           */
          ielesa[10],   /* variables de sauvegardes des ICU&&&  ..
                        .. utilisees par ACCEPT/REFUS           */
          igrbid[2],    /*            ????                      */
          igr2td,       /* @ du triedre BIDIM                   */
          igr3td,       /* @ du triedre BIDIM en cours en 2D    */
          iespma[12],   /* variables de sauvegardes des ICU&&& ..
                        .. utilisees par la fonction DETAIL     */
          icuesp,       /* @ de travail de l'espace en cours    */
          icuscr,       /* @ de l'ecran en cours                */
          icusht,       /* @ de la feuille en cours             */
          icuele,       /* @ de l'elt geometrique en cours      */
          icutrd,       /* @ du triedre en cours                */
          icurep,       /* @ du repere en cours                 */
          igrfma,       /*            ????                      */
          icuv2d,       /* @ de la vue draw en cours            */
          icucot,       /*            ????                      */
          icuad1,       /*            ????                      */
          icuad2,       /*            ????                      */
          iengeo[32],   /* @ de l'ensemble en cours             */
          ioutil,       /* @ de l'outil de CN en cours          */
          igrcol,       /* @ des standards de couleurs          */
          igrpat;       /* @ de la chaine des patterns          */

  /* .................................................................. */

  int     nupcou,       /* numero du PLAN DE FOND en cours      */
          inumgr,       /* numero du GROUPE en cours            */
          levcou;       /* numero du NIVEAU en cours            */
  short   i2kost,       /* password des couleurs                */
          i2bido;       /* variable secrete                     */
  int     nbsp2d,       /* nombre de DETAIL 2D dans le modele   */
          nbsp3d,       /* nombre de DETAIL 3D dans le modele   */
          inuti1,       /*             ????                     */
          inuti2,       /*             ????                     */
          inuti3,       /*             ????                     */
          inuti4;       /*             ????                     */
  char    logbgs,       /*             ????                     */
          lradmp,       /*             ????                     */
          ldetv2,       /* .true. si la selection doit porter   ..
                        .. sur des vues draw                    */
          lcolor;       /* valeur modale du standard des        ..
                        .. couleurs : 0= ensemble               ..
                        ..            1= niveau                 ..
                        ..            2= type                   ..
                        ..            3= vue draw               */
  int     ivipol;       /* code de visu standard des POLYEDRES  */
  char    lvipol,       /* utile pour la visu des polyedres     */
          lfamil,       /* .true. on vient de creer les familles..
                        .. des elements (apres CALL FAMILLE)    */
          ldetai;       /* .true. si mode DETAIL                */
  unsigned char ldraw;  /* .true. si mode DRAW                  */
  char    lrepg1,       /* .true. si le groupe temporaire No i  */
          lrepg2,       /* est en cours d'utilisation           */
          lrepg3,
          lvistw,       /*             ????                     */
          lvmot,        /*             ????                     */
          lsur2d,       /* .true. si mode SURFACE - PLAN(U,V)   */
          ldetm2,       /* .true. si la selection doit porter   ..
                        .. sur des ensembles                    */
          lbidim;       /* .true. si mode BIDIM(2D geometrique) */
  int     ibidim;       /* 1,2,3 selon X=/Y=/Z= cte             */
  double  zbidim,       /* cote du plan 2D courant              */
          p1,           /* 9 coefficients du plan 2D courant    */
          a1,           /* origine-Pi, vecteur1-Ai, vecteur2-Bi */
          b1,
          p2,
          a2,
          b2,
          p3,
          a3,
          b3,
          xfilte[4],    /* tableau indiquant l'etat du filtre   ..
                        .. en cours                             */
          xges[6];      /*             ?????                    */

 };

#endif
