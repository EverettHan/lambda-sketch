/**
 * @level Protected
 * @usage U1
 */
 /* DataModelerBase.h : COPYRIGHT DASSAULT SYSTEMES 1996 */
#ifndef  DataModelerBaseExt_h
#define  DataModelerBaseExt_h
//------------------------------------------------------------------------
//
//  Attention afin permettre l'operation PR4 "JELE = CATIAEntity*",
// il convient des a present de separarer le bon grain de l'ivraie
//
//   "DataModelerBase.h" sous sa forme actuelle va etre mis au placard
//  dans CATIADataMacFortran pour vous laisser le temps de migrer
//  adequatement les interfaces.
//
//--------------------------------------------------------------------------
//  Definition du Vieux Soft de Base CATIA,
//   Dont on evitera d'etendre l'usage, aucune promotion n'en sera faite
//   les seuls usagers autorises sonts les frameworks CATV4 de la geometrie
//-------------------------------------------------------------------------
//  L'acces aux structures de donnees en CATIA en CXR1 sera privilegiee par
//     les methodes des classes CATIAEntity et eventuellement de CATIAModel
//     ou a defaut on pourra se retourner contre les pseudo CATGEO CXR1
//    definis dans le module CATGEOBasic
//---------------------------------------------------------------------

#include "ExportedByCATIAEntity.h"
#include<swapHeader.h>

class CATIAModel;
class CATIAEntity;

#include "CATDataType.h"

 /*-----------------------------*/
 /* un petit Dump/Verification  */
 /*-----------------------------*/

extern "C" ExportedByCATIAEntity void datachk();


//********////////////////////////////////////////////////********
//
//           Manipulation des descriptions CATIA      
//
//********////////////////////////////////////////////////********

extern "C" 
{

ExportedByCATIAEntity void dumind(const int &igra);

     /*---------------------------------------------------*/
     /* Services d'adressage/acces aux descriptions CATIA */
     /*---------------------------------------------------*/

ExportedByCATIAEntity  int adresc(const int jele, const int type,
                     double *&adress, int &longueur );

ExportedByCATIAEntity void lecnbd(const int &igra, int &nbdes);

ExportedByCATIAEntity void lecila(const int &igra, int &isto, 
			int &ldesc, int &iadat);

ExportedByCATIAEntity  int adres1(const int &igra,const int &itides,
                   int &idescr, int &ilodes );

ExportedByCATIAEntity  int adress(const int &igra,const int &itides,
                   int &idescr, int &ilodes, int &icode );

typedef struct { int itides; int longueur; int idescr; } TabDes;

ExportedByCATIAEntity  int adres2(const int &igra, 
                               int &nbdres, TabDes tabdes[] );

     /*------------------------------------------------*/
     /* Services de changements des Descriptions CATIA */
     /*       (ajout,modification,supression)          */ 
     /*------------------------------------------------*/

ExportedByCATIAEntity int ajodes(const int &igra, const int &itydes, 
      const int &lgrdes,  const double xdes[], const unsigned char &lvisu,
      int &iadnew, int &ier);

ExportedByCATIAEntity int moddes(const int &igra, const int &itydes,
    const int &lgrdes, const double xdes[], const unsigned char &lvisu,
    int &iadnew, int &ier);

ExportedByCATIAEntity int supdes(const int &igra, const int &itydes, 
	   const unsigned char &lvisu, int &ier);


ExportedByCATIAEntity int ajodat(const int &igra, const int &itydes, 
      const int &lgrdes,  const double xdes[], const unsigned char &lvisu, 
      int &iadnew, int &ier);

ExportedByCATIAEntity int moddat(const int &igra, const int &itydes,
      const int &lgrdes,  const double xdes[], const unsigned char &lvisu,
      int &iadnew, int &ier);

ExportedByCATIAEntity int supdat(const int &igra, const int &itydes, 
    const unsigned char &lvisu, int &ier);


ExportedByCATIAEntity int defdes(const int &igra, const int &itydes,
    const int &lgrdes,   const double xdes[], int &ier);


ExportedByCATIAEntity int ajods2(const int &igra, const int &itydes, 
    const int &lgrdes,  const double xdes[], const unsigned char &lvisu, 
    int &iadnew, int &ier);

ExportedByCATIAEntity int modds2(const int &igra, const int &itydes, 
    const int &lgrdes,  const double xdes[], const unsigned char &lvisu,
    int &iadnew, int &ier);

ExportedByCATIAEntity int dftdes(const int &igra, const int &itydes,
    const int &lgrdes,   const double xdes[], int &ier);

ExportedByCATIAEntity int modtmd(const int &igra, const int &itydes, const int &lgrdes,
    const double xdes[], const unsigned char &lvisu, int &iadnew, int &ier);

 /*-----------------------------------------------------*/
 /* Ajout/Recherche des Descriptions Temporaires CATIA  */
 /*-----------------------------------------------------*/

ExportedByCATIAEntity int dftdec(const int &igra,
           const int &itydes1, const int &lgrdes1, const double xdes1[],
           const int &itydes2, const int &lgrdes2, const double xdes2[],
           int &iadnew1, int &iadnew2, int &ier);

ExportedByCATIAEntity int recdt2(const int &igra, const int &itydes, 
           int &iaddat, int &lgrdes);
       
ExportedByCATIAEntity int recdt1(const int &igra, const int &itydes, 
           int &iaddat, int &lgrdes);

ExportedByCATIAEntity int supdst(const int &igra, const int &itydes);       
}



//********////////////////////////////////////////////////********
//
//            Manipulation des chainages CATIA      
//
//********////////////////////////////////////////////////********

extern "C" 
{

ExportedByCATIAEntity    int lecchn(const int &indice, const int &igrecc, 
                                   const int &igrprev, int &igrnext);
ExportedByCATIAEntity    int lecchi(const int &indice, const int &igrecc, 
                                   const int &igrprev, int &igrnext);

ExportedByCATIAEntity   int recchn(const int &igra,const int &indice,int &position);

ExportedByCATIAEntity  void reccic(const int &indice, 
	 const int &igra1, const int &igra2, unsigned char &lchaine);

ExportedByCATIAEntity  void ajochn(const int &indice, const int &igra,
                                   const int &igrecc);

ExportedByCATIAEntity  int ajoci(const int &igra, const int &indice, 
                                 int &igrdeb, int &ier);

ExportedByCATIAEntity  void modchn(const int &indice, const int &igra,
                                   const int &igrecc);

ExportedByCATIAEntity  void supchn(const int &indice, const int &igra);

ExportedByCATIAEntity  void nomeci(const int &igra, const int &indice, int &nombre);
}

//********////////////////////////////////////////////////********
//
//            Manipulation tables parentales CATIA      
//
//********////////////////////////////////////////////////********

extern "C" 
{

     /*-----------------------*/
     /*  Services d'analyses  */
     /*-----------------------*/

ExportedByCATIAEntity  void lecnfi(const int &igra, int &nfils);
ExportedByCATIAEntity  void lecnbp(const int &igra, int &inbparent);

ExportedByCATIAEntity   void lecdpa(const int &igra, 
                	  int &numpar, int &indice, int &igrpar);

ExportedByCATIAEntity   void lecnpa(const int &igra, int &nbrpar );
ExportedByCATIAEntity   void lectp0(const int &igra, int &nbrpar );

ExportedByCATIAEntity   void lectp1(const int &igra, int &nbrpar, int igrpar[] );
ExportedByCATIAEntity   void lectp2(const int &igra, 
                                    int &nbrpar, int indice[], int igrpar[]);

ExportedByCATIAEntity   int lecnup(const int &igra, 
                               const int &igrpar, const int &indice, int &numpar);

ExportedByCATIAEntity   int lecnu2(const int &igra, const int &igrpar, 
                                   int &indice, int &numpar);
ExportedByCATIAEntity   int lecpex(const int &igra, const int &igrpar, 
                                   int &numpar, int &indice);

ExportedByCATIAEntity   int lecpsu(const int &igra, const int &nume, 
                                   int &numpar, int &indice, int &igrpar);
ExportedByCATIAEntity   int lecpas(const int &igra, const int &pos0,
                                   int &position, int &indice, int &igrpar);

ExportedByCATIAEntity   void lecpa2(const int &igra, const int &numpar, int &igrpar);

ExportedByCATIAEntity   void lecpa1(const int &igra, const int &itp, int &igrpar);
ExportedByCATIAEntity   void lecpa3(const int &igra, 
                                    const int &nitp, const int itp[], 
                                    int &igrpar, int &itppar);

ExportedByCATIAEntity   int lectpi(const int &igra, const int &indice,
                                   int  &nbrpar, int *igrpar);

ExportedByCATIAEntity   void lecpar(const int &igra, const int &numparIC, 
                                    int &igrpar, const int &indice);

     /*------------------------------------------*/
     /*  Soft de modification de table parentale */
     /*------------------------------------------*/

ExportedByCATIAEntity void suppar(const int &igra, const int &numpar);
ExportedByCATIAEntity void supall(const int &igra);

ExportedByCATIAEntity int ajolpa(const int &igra, const int &nbrpar,
        const int indice[], int igrpar[], int &ltra, int &igrdeb, int &ier);

ExportedByCATIAEntity int ajopla(const int &igra, const int &numpar,
        const int &indice, int &igrpar, int &ltra, int &igrdeb, int &ier);

ExportedByCATIAEntity int ajopl2(const int &igra, const int &numpar, const int &nbpar,
        const int indice[], int igrpar[], int &ltra, int &igrdeb, int &ier);

ExportedByCATIAEntity int ajopar(const int &igra, const int &nbrpar,
      const int indice[], int igrpar[], int &ltra, int &igrdeb, int &ier);



ExportedByCATIAEntity int ajopl3(const int &igra, 
                                 const int &nbrpar, int &ier);

ExportedByCATIAEntity int ajopli(const int nbelt, int igra[], int nbrpar[],
				 const int nbtrav, int igrtrav[], int &ier);

ExportedByCATIAEntity void modpar(const int &igra, 
                           const int &numpar, const int &igrnew);

ExportedByCATIAEntity void modpa1(const int &igra, 
	  const int &numpar, const int &igrnew, const int &icnew);

ExportedByCATIAEntity int modpa3(const int &igra, const int &numpar, 
	 int &igrpar, int &ltra, int &igrdeb, int &ier );

ExportedByCATIAEntity int modpa2(const int &igra, const int &numpar,
	 int &igrpar, unsigned char &ligne, int &ier );

ExportedByCATIAEntity int modpa4(const int &igra, const int &nbrpar,
     const int numpar[], int igrpar[], int &ltra, int &igrdeb, int &ier);

ExportedByCATIAEntity int modpa5(const int &igra, const int &nbrpar,
     const int numpar[], int igrpar[], int &ltra, int &igrdeb, int &ier);


     /*------------------------------------*/
     /*  Gestion des familles d'elements   */
     /*------------------------------------*/

ExportedByCATIAEntity void nomedf(const int &igra, int &nbdef);
ExportedByCATIAEntity void nomedu(const int &igra, int &nbdef);

ExportedByCATIAEntity int famcmp(const int &igra1, const int &igra2 );

ExportedByCATIAEntity void nettoy();
ExportedByCATIAEntity void ntzsol( const int &igra );
ExportedByCATIAEntity int isole( const int &igra );
ExportedByCATIAEntity int isotra( const int &igra, const int &nbtypk,
    int itypok[], unsigned char logtyp[], int &ier );

ExportedByCATIAEntity int familt( int &ier );
ExportedByCATIAEntity int familp( int &ier );
ExportedByCATIAEntity int famile( int &ier );

ExportedByCATIAEntity void fampar(const int &igra, const int &nbdef,        
     const unsigned char &lhoriz, const unsigned char &ltass,             
    int &nbpar, int igrpar[], int itp[], int pospar[], unsigned char &lisole);

ExportedByCATIAEntity void fampa2(const int &igra, const int &nbdef,       
  const unsigned char &lhoriz, const unsigned char &ltass,           
  int &nbpar, int igrpar[], int itp[], int pospar[], unsigned char &lisole);

ExportedByCATIAEntity int tabfam( const int &igra, int &nbrelt, int itrav[] );
ExportedByCATIAEntity int tabfa2( const int &igra, int &nbrelt, int itrav[] );
ExportedByCATIAEntity int tabfa3( const int &igra, int &nbrelt, int &nsor, int itrav[] );

ExportedByCATIAEntity int tabnp2(const int &igrwsp, const int &nbpln,       
  const unsigned char &ldraw, const int &nbelt, int itab[],
  int &nbrp24, int &nfitot, int itrav[] );
}



//********////////////////////////////////////////////////********
//
//            Parcours dans le modele CATIA    
//
//********////////////////////////////////////////////////********

extern "C" 
{
     /*------------------------------------*/
     /*  Gestion des Ensembles/Workspaces  */
     /*------------------------------------*/

ExportedByCATIAEntity  void lecipr(const int &igra, int &iprec);
ExportedByCATIAEntity  void lecisu(const int &igra, int &isuiv);
ExportedByCATIAEntity  void rececc(const int &igra, int &igrset);
ExportedByCATIAEntity  void recwsp(const int &igra, int &igrwsp);
ExportedByCATIAEntity   int recepc(const int &igrset, const int &igrprev, 
                                         int &igrnext, const int &itp);
ExportedByCATIAEntity   int recesc(const int &igrset, const int &igrprev, 
                                         int &igrnext, const int &itp);
ExportedByCATIAEntity   int rectch(const int &igrset, int &igrnext );
ExportedByCATIAEntity   int recctd(const int &ityps, const int &igrset, 
                                          int &igrnext );
ExportedByCATIAEntity   int recctg(const int &ityps, const int &igrset, 
					 int &igrnext );

ExportedByCATIAEntity   void nomctd(const int &ityps, int &nombre);

ExportedByCATIAEntity   int recfan(const int &igrgeo, int &igrfan);
ExportedByCATIAEntity   int recgeo(const int &igrfan, int &igrgeo);

ExportedByCATIAEntity   int ScanBasic( CATIAEntity* const prev, const int &itpref, const int &itsref, CATIAEntity* &next );

     /*------------------------------------*/
     /*  Gestion des fils dans l'ensemble  */
     /*------------------------------------*/

ExportedByCATIAEntity int recfil(const int &igra, const int &igrprev, int &igrnext);

ExportedByCATIAEntity int recfit(const int &igra, const int &itp, 
                             const int &igrprev, int &igrnext);

ExportedByCATIAEntity int reclin(const int &itp, const int &igrent, 
                                 int &igrsor, int &its);

ExportedByCATIAEntity int recest(const int &itp, const int &igrent, 
                                 int &igrsor);

ExportedByCATIAEntity int reclsu(const int &igrent, 
                                 int &igrsor, int &itp, int &its);

ExportedByCATIAEntity int reclit(const int &igrent,
                                 int &igrsor, int &itp, int &its);

ExportedByCATIAEntity int recli1(const int &igrent, int &igrsor, int &itp);

ExportedByCATIAEntity int rechxx(const int &its, int &igrsor);

ExportedByCATIAEntity int recfuax(const int &igra, const int &igrset, 
                                  const int &igrprev, int &igrnext);
}


//********////////////////////////////////////////////////********
//
//            Manipulation code de VISU
//
//********////////////////////////////////////////////////********

extern "C" 
{
     /*---------------------------------------------------*/
     /* Manipulation du Code de Visu dans le modele CATIA */
     /*----------------------------------------------------*/

ExportedByCATIAEntity void lecivi(const int &igra,       struct CodeVisu &ivisu);
ExportedByCATIAEntity void modvis(const int &igra, const struct CodeVisu &ivisu);

     /*---------------------------*/
     /* Acces a la couleur modale */
     /*---------------------------*/

ExportedByCATIAEntity void collec(const int &type, const int &adresse, int &color);

     /*-----------------------------------------------*/
     /* Definition/Decodage complet du bloc CodeVisu  */
     /*-----------------------------------------------*/

ExportedByCATIAEntity void veevis( const int &color, const int &textsize, 
 const int &thickness, const unsigned char &showPerm, const unsigned char &showTemp,
 const unsigned char &pickPerm, const unsigned char &pickTemp,
 const unsigned char &planar, const unsigned char &opaque,
 const unsigned char &blink, const unsigned char &highlight,
 const unsigned char &temporary, const unsigned char &gagOne,
 const unsigned char &gagTwo, struct CodeVisu &codeVisu );

ExportedByCATIAEntity void velvis( const struct CodeVisu &codeVisu, int &color, 
  int &textsize, int &thickness,  unsigned char &showPerm,   unsigned char &showTemp,
  unsigned char &pickPerm,   unsigned char &pickTemp,   unsigned char &planar,
  unsigned char &opaque,     unsigned char &blink,      unsigned char &highlight,
  unsigned char &temporary,  unsigned char &gagOne,     unsigned char &gagTwo      );


ExportedByCATIAEntity void veestd(struct CodeVisu &codeVisu);

ExportedByCATIAEntity void veeagl( const int &color, const int &textsize,
 const int &thickness, const unsigned char &showPerm,  const unsigned char &pickPerm,
 const unsigned char &highlight, struct CodeVisu &codeVisu );

     /*-----------------------------------------------*/
     /* Definition/Decodage COULEUR su un CodeVisu    */
     /*-----------------------------------------------*/

ExportedByCATIAEntity void veecol(const int &color, struct CodeVisu &codeVisu);
ExportedByCATIAEntity void velcol(const struct CodeVisu &codeVisu, int &color);
ExportedByCATIAEntity void veegse(const int &color, struct CodeVisu &codeVisu);

     /*--------------------------------------------------------*/
     /* Definition/Decodage Texture/Thickness sur un CodeVisu  */
     /*--------------------------------------------------------*/

ExportedByCATIAEntity void veeatt(const int &textsize, struct CodeVisu &codeVisu);
ExportedByCATIAEntity void veeatl(const int &textsize, struct CodeVisu &codeVisu);
ExportedByCATIAEntity void veeatp(const int &textsize, struct CodeVisu &codeVisu);
ExportedByCATIAEntity void velatt(const struct CodeVisu &codeVisu, int &textsize);
ExportedByCATIAEntity void velatl(const struct CodeVisu &codeVisu, int &textsize);
ExportedByCATIAEntity void velatp(const struct CodeVisu &codeVisu, int &textsize);

ExportedByCATIAEntity void veeaet(const int &thickness, struct CodeVisu &codeVisu);
ExportedByCATIAEntity void veeael(const int &thickness, struct CodeVisu &codeVisu);
ExportedByCATIAEntity void veeaep(const int &thickness, struct CodeVisu &codeVisu); 
ExportedByCATIAEntity void velaet(const struct CodeVisu &codeVisu, int &thickness);
ExportedByCATIAEntity void velael(const struct CodeVisu &codeVisu, int &thickness);
ExportedByCATIAEntity void velaep(const struct CodeVisu &codeVisu, int &thickness);

     /*-----------------------------------------------*/
     /* Definition/Decodage OPACITE sur un CodeVisu   */
     /*-----------------------------------------------*/

ExportedByCATIAEntity void veeopq(const unsigned char &opaque,
                                    struct CodeVisu &codeVisu);   
ExportedByCATIAEntity void velopq(const struct CodeVisu &codeVisu,
                                    unsigned char &opaque);


     /*---------------------------------------------------*/
     /* Definition/Decodage TEMPORALITE sur un CodeVisu   */
     /*---------------------------------------------------*/

ExportedByCATIAEntity void veetem(const unsigned char &temporary,
                                   struct CodeVisu &codeVisu);
ExportedByCATIAEntity void veltem(const struct CodeVisu &codeVisu,
                                   unsigned char &temporary);

     /*-------------------------------------------------*/
     /* Definition/Decodage HIGHLIGHT sur un CodeVisu   */
     /*-------------------------------------------------*/

ExportedByCATIAEntity void veesel(const unsigned char &highlight,
                                   struct CodeVisu &codeVisu);
ExportedByCATIAEntity void velsel(const struct CodeVisu &codeVisu, 
                                   unsigned char &highlight);

     /*-------------------------------------------------*/
     /* Definition/Decodage Show Permanent/Temporaire   */
     /*-------------------------------------------------*/

ExportedByCATIAEntity void veesht(const unsigned char &showTemp,
                                   struct CodeVisu &codeVisu);
ExportedByCATIAEntity void velsht(const struct CodeVisu &codeVisu,
                                   unsigned char &showTemp);
ExportedByCATIAEntity void veeshp(const unsigned char &showPerm,
                                   struct CodeVisu &codeVisu);   
ExportedByCATIAEntity void velshp(const struct CodeVisu &codeVisu,
                                   unsigned char &showPerm);

     /*-------------------------------------------------*/
     /* Definition/Decodage Pick Permanent/Temporaire   */
     /*-------------------------------------------------*/

ExportedByCATIAEntity void veedtt(const unsigned char &pickTemp,
                                   struct CodeVisu &codeVisu);
ExportedByCATIAEntity void veldtt(const struct CodeVisu &codeVisu, 
                                   unsigned char &pickTemp);
ExportedByCATIAEntity void veedtp(const unsigned char &pickPerm,
                                   struct CodeVisu &codeVisu);
ExportedByCATIAEntity void veldtp(const struct CodeVisu &codeVisu,
                                   unsigned char &pickPerm);

     /*-------------------------------------------------*/
     /* Definition/Decodage Plan2D sur un CodeVisu      */
     /*-------------------------------------------------*/

ExportedByCATIAEntity void veespl(const unsigned char &planar, 
                                   struct CodeVisu &codeVisu);
ExportedByCATIAEntity void velspl(const struct CodeVisu &codeVisu,
                                   unsigned char &planar);

     /*--------------------------------------*/
     /* Definition/Decodage Clignotement     */
     /*--------------------------------------*/

ExportedByCATIAEntity void veecli(const unsigned char &blink, 
                                   struct CodeVisu &codeVisu);
ExportedByCATIAEntity void velcli(const struct CodeVisu &codeVisu,
                                   unsigned char &blink);

     /*---------------------------------------------*/
     /* Definition/Decodage Show/No Show Applicatif */
     /*---------------------------------------------*/

ExportedByCATIAEntity void veesha(const unsigned char &showApply,
                                   struct CodeVisu &codeVisu);
ExportedByCATIAEntity void velsha(const struct CodeVisu &codeVisu,
                                   unsigned char &showApply);

     /*-------------------------------------*/
     /* Definition/Decodage bit de groupes  */
     /*-------------------------------------*/

ExportedByCATIAEntity void velswd(const struct CodeVisu &codeVisu,
                                  unsigned char &group);
ExportedByCATIAEntity void velsws(const struct CodeVisu &codeVisu, 
                                  unsigned char &group);

ExportedByCATIAEntity void veegac();
ExportedByCATIAEntity void velagl();
ExportedByCATIAEntity void velgac();
ExportedByCATIAEntity void velgse();

     /*-----------------------------------------------*/
     /* Definition du code de Visu par defaut         */
     /*-----------------------------------------------*/

ExportedByCATIAEntity void defvis(const int &itypp, const int &ityps, 
   const unsigned char &highlight, const unsigned char &showTemp, 
   const unsigned char &temporary, struct CodeVisu &codeVisu );


ExportedByCATIAEntity void veeres(struct CodeVisu &codeVisu);
}


//********////////////////////////////////////////////////********
//
//            Manipulation extended DATA 
//
//********////////////////////////////////////////////////********

extern "C" 
{

ExportedByCATIAEntity  int ajodtb(const int &jele, const int &itydes, 
                                  const int &longueur,  
				  const double valeur [], int &offset, int &ier );

ExportedByCATIAEntity  int adresb(const int &jele, const int &itydes, 
				  int &offset, int &longueur, int &ier );

ExportedByCATIAEntity  int eradtb(const int &jele, const int &itydes, int &ier );

ExportedByCATIAEntity  void supdtb(const int &jele);

ExportedByCATIAEntity  void tasdtb();

ExportedByCATIAEntity  void valdtb(int &used_kb, double &taux);

ExportedByCATIAEntity  void datbevt(const int &ifvir8, const char event[3]);
}


//********////////////////////////////////////////////////********
//
//            Manipulations diverses
//
//********////////////////////////////////////////////////********

extern "C" 
{
     /*------------------------------------------------*/
     /*    Creation d'une entite permanente CATIA      */
     /*------------------------------------------------*/


ExportedByCATIAEntity int defele(const int &igrset, 
             const int &itp, const int &its,
	     const int &nbpar,    const int ic[],    const int igrpar[],
	     const int &lgrIdent, const char Ident[],
	     const int &itydes,   const int &lgrdes, const double xdes[],
	     int &igra, int &ier );

ExportedByCATIAEntity int defel2(const int &igrset, const int &numbid,
             const int &itp, const int &its,
	     const int &nbpar,    const int ic[],    const int igrpar[],
	     const int &lgrIdent, const char Ident[],
	     const int &itydes,   const int &lgrdes, const double xdes[],
	     int &igra, int &ier );

ExportedByCATIAEntity int d2fele(const int &igrset, 
             const int &itp, const int &its,
	     const int &nbpar,    const int ic[],    const int igrpar[],
	     const int &lgrIdent, const char Ident[],
	     const int &itydes,   const int &lgrdes, const double xdes[],
	     int &igra, int &ier );



ExportedByCATIAEntity int defel1(const int &igrset, 
             const int &itp, const int &its,
	     const int &nbchain,  const int ichain[], 
	     const int &nbpar,    const int ic[],    const int igrpar[],
	     const int &lgrIdent, const char Ident[],
	     const int &itydes,   const int &lgrdes, const double xdes[],
	     int &igra, int &ier );


ExportedByCATIAEntity int d2fel1(const int &igrset, 
             const int &itp, const int &its,
	     const int &nbchain,  const int ichain[], 
	     const int &nbpar,    const int ic[],    const int igrpar[],
	     const int &lgrIdent, const char Ident[],
	     const int &itydes,   const int &lgrdes, const double xdes[],
	     int &igra, int &ier );

     /*------------------------------------------------*/
     /*    Creation d'une entite temporaire CATIA      */
     /*------------------------------------------------*/

ExportedByCATIAEntity int dftele( const int &igrset,   const int &itypp, const int &ityps,
            const unsigned char &highlight,  const unsigned char &showTemp,
            const int &nbpar,    const int indice[],    const int igrpar[],
            const int &itydes,   const int &lgrdes, const double xdes[],
            int &igra,           int &ier);


ExportedByCATIAEntity int d2tele( const int &igrset,   const int &itypp, const int &ityps,
            const unsigned char &highlight,  const unsigned char &showTemp,
            const int &nbpar,    const int indice[],    const int igrpar[],
            const int &itydes,   const int &lgrdes, const double xdes[],
            int &igra,           int &ier);

ExportedByCATIAEntity int dftel1( const int &igrset,   const int &itypp, const int &ityps,
            const unsigned char &highlight,  const unsigned char &showTemp,
            const int &nbchain,  const int ichain[],
            const int &nbpar,    const int indice[],    const int igrpar[],
            const int &itydes,   const int &lgrdes, const double xdes[],
            int &igra,           int &ier);

ExportedByCATIAEntity int dftel2( const int &igrset,   const int &numbid,
            const int &itypp, const int &ityps,
            const unsigned char &highlight,  const unsigned char &showTemp,
            const int &nbpar,    const int indice[],    const int igrpar[],
            const int &itydes,   const int &lgrdes, const double xdes[],
   		 int &igra,           int &ier);



     /*--------------------------------------*/
     /*    Creation d'une ecc CATIA          */
     /*--------------------------------------*/

ExportedByCATIAEntity int defen0(const int &ityps, const int &lgrIdent,
				 const char Ident[], int &igra, int &ier);

ExportedByCATIAEntity int defens(const int &ityps, const int &lgrIdent,
				 const char Ident[], int &igra, int &ier);

ExportedByCATIAEntity int defesp(const int &ityps, const int &lgrIdent,
				 const char Ident[], int &igra, int &ier);

ExportedByCATIAEntity int deffan(const int &igrset, int &igra, int &ier);


ExportedByCATIAEntity void supele(const int &igra);

ExportedByCATIAEntity void supelt(const int &igra);

ExportedByCATIAEntity void supens(const int &igra);


ExportedByCATIAEntity int autide(const int &itypp, const int &ityps,
      const int &itydes, const int &lgrdes, const double xdes[],
      int &liden, char chiden[24], int &ier);

ExportedByCATIAEntity int autele(const int &itypp, const int &ityps,
      int &liden, char chiden[24]);

ExportedByCATIAEntity int patele(const int &itypp, const int &ityps,
      int &liden, char chiden[24]);

ExportedByCATIAEntity void lecide(const int &igra, int &lgrIdent, 
      char Ident[72]);

ExportedByCATIAEntity int ajoide(const int &igra,  const int &lngIdent, 
       char ident[72], int &ier);

     /*-----------------------------------------*/
     /*   Gestion general d'une entite CATIA    */
     /*-----------------------------------------*/

ExportedByCATIAEntity void chkigra( const int &igra );
ExportedByCATIAEntity int  maxigra();

ExportedByCATIAEntity unsigned char lelacc( const int &igra );
ExportedByCATIAEntity unsigned char leltem( const int &igra );
ExportedByCATIAEntity unsigned char lelfan( const int &igra );
ExportedByCATIAEntity unsigned char lecefa( const int &igra );
ExportedByCATIAEntity unsigned char ladrok( const int &igra );
ExportedByCATIAEntity void jprjmdl(int &jprjmdl);
ExportedByCATIAEntity void jeccmao(int &jeccmao);
ExportedByCATIAEntity void modtys(const int &igra, const int& ityps);
ExportedByCATIAEntity void modtyp(const int &igra, const int& itypp);

ExportedByCATIAEntity unsigned char lelsel(const int &igra);

     /*-----------------------------------------*/
     /*  Soft de Numerotation sur entite CATIA  */
     /*-----------------------------------------*/

ExportedByCATIAEntity int inuver( const int &igra, int &numele, int &numver);
ExportedByCATIAEntity int numeco( const int &numovl, const int &numele, 
                              int &igra, int &its, int &numax);
ExportedByCATIAEntity int numigr( const int &igrecc, const int &numele, 
                              int &igra, int &numver);

ExportedByCATIAEntity void numflg( const int &igra, const int &itydes);

typedef struct { int numwsp; int numele; int jele; int status; } NUMJEL;

// ---------------------------------------------------------
//  Ajout OGM le 24/11/2000
//  pour operation perfo sur numigr chez DAIMLER
//  On offre a ceux qui vont realiser un grand nombre de
//  numigr, de generer la table de correspondance une seule
//  fois, via numjeles.
// ---------------------------------------------------------
ExportedByCATIAEntity void FastNumigrTransactionBegin() ;
ExportedByCATIAEntity void FastNumigrTransactionEnd() ;
static NUMJEL* FastNumigrTransactionTable ;
static int FastNumigrTransactionNbJele ;
static CATIAModel* FastNumigrTransactionModel ;

ExportedByCATIAEntity void nbjelmax(int &nbjeles);
ExportedByCATIAEntity int numjeles(const int &nbmax, int &nbjeles, NUMJEL table[]);

     /*-------------------------------------------------------*/
     /*   Offre applicative des Ultra-Weak-Link (UWLs)        */
     /*-------------------------------------------------------*/

ExportedByCATIAEntity int uwlmaj (const int &numovl);
ExportedByCATIAEntity int uwlcre (const int &icode, const int &igra_pointant,
                                  const int &igra_pointe,int &numlnk, int &ier) ;
ExportedByCATIAEntity int uwllen (const int &icode, const int &igra_pointant, 
                                  const int &numlnk, int &igra_pointe, int &ier) ;
ExportedByCATIAEntity int uwlrec (const int &icode,const int &igra_pointant,const int &igrawsp,
                        const int &numlnk,const int &igra_pointe,int &ipos,int &ier) ;
ExportedByCATIAEntity int uwluee (const int &icode,const int &igra_pointant,
                                  const int &numlnk,const int &igra_pointe,int &ier) ;
ExportedByCATIAEntity int uwluqr (const int &icode,const int &igra_pointant,
                        const int &numlnk,const int &igra_pointe,int &ilok,int &ier) ;

ExportedByCATIAEntity int uwldee (const int &icode,const int &igra_pointant,
                                  const int &numlnk,int &ier) ;
ExportedByCATIAEntity int uwllnb (const int &icode,const int &igra_pointant, int &nblink) ;
ExportedByCATIAEntity int uwlsca (const int &icode,const int &igra_pointant,const int &numlnk, 
                                  int &igra_pointe_suivant, int &numlink_suivant, int &ifin,int &ier) ;
ExportedByCATIAEntity int uwlxxx (const int &icode,const int &igra_pointant,const int &ioperate,                             const int &numlnk,const int &igra_pointe,int &ilok,int &ier)  ;
ExportedByCATIAEntity int uwldmp (const int &icode,const int &igra_pointant) ;


     /*-------------------------------------------------------*/
     /*   Offre applicative des PIMs                          */
     /*-------------------------------------------------------*/
// Permet de recuperer le RELAIS correspondant a un PIM
ExportedByCATIAEntity int GetRelayFromPim(const CATIAEntity &PimEntity, CATIAEntity* &RelayEntity, int &ier) ;


     /*-------------------------------------------------------*/
     /*   Offre applicative des SLUs                          */
     /*-------------------------------------------------------*/
// Analyse d'un lien SLU
ExportedByCATIAEntity int AnalyseSLU(const CATIAEntity &SluEntity, const int LinkId,
									 CATIAEntity* &ReferencedEntity, int &status, int &ier);

     /*-------------------------------------------------------*/
     /*   Offre applicative des PICUWLs                       */
     /*-------------------------------------------------------*/
// Analyse d'un lien PIC
ExportedByCATIAEntity int AnalysePIC(const CATIAEntity &PicEntity,
									 CATIAEntity* &ReferencedEntity, int &status, int &ier);

// Extraction du PSNPathway reference par un PIC
ExportedByCATIAEntity int ExtractPSNSeqFromPIC(CATIAEntity &PicEntity,
											   int &NumberOfStepsToCommonNode, int &ReferencedPSNLength,
											   char* &ReferencedPSNPathway, int &ier);

ExportedByCATIAEntity int decodePic(const int& jelpic, const int &sizeInput, void* keyInput, int &sizeOut);
     /*-------------------------------------------------------*/
     /*     Offre applicative des Multi Model Link (MMLs)     */
     /*-------------------------------------------------------*/

ExportedByCATIAEntity int mmslec (CATIAEntity * const C_symbol, int &type_user,int &type_system, char *&id, int &ietat, CATIAEntity *&C_component, CATIAEntity *&C_father ) ;
ExportedByCATIAEntity int mmslnk (CATIAEntity * const C_symbol, int &nbrelation ,CATIAEntity * tab_C_relation[] );
ExportedByCATIAEntity int mmsexp (CATIAEntity * const C_entity, int &nbsymbol, CATIAEntity * tab_C_symbol[] ) ;

ExportedByCATIAEntity int mmrlec (CATIAEntity * const C_relation, CATIAEntity *&C_symbol_pere, CATIAEntity *&C_symbol_pointe, int &synchro, int &type_user , int &orientation) ;
ExportedByCATIAEntity int mmrlnk (CATIAEntity * const C_symbol, int &nbrelation ,CATIAEntity * tab_C_relation[] ) ;
     /*-------------------------------------------------------*/
     /*   Offre applicative des User Graphic Element (UGEs)   */
     /*-------------------------------------------------------*/
ExportedByCATIAEntity int ugedmp (const int &igra_UGE) ;
ExportedByCATIAEntity int ugenbc (const int &igra_UGE, int &nb_constituant) ;
ExportedByCATIAEntity int ugescn (const int &igra_UGE, const int &num_constituant, 
                                  int &itpC, int &itsC , int &ilay , int &ivisu , int &nbdes ) ;
#ifdef PLATEFORME_DS64
   struct TabDesAdr
   {
     int     itides ;
     int     longueur ;
     double* adrDescr ;
   } ;
ExportedByCATIAEntity int ugedes(const int &igra_UGE, const int &num_constituant, 
                                  int &nbdres, TabDesAdr tabdes[] );
#else
ExportedByCATIAEntity int ugedes(const int &igra_UGE, const int &num_constituant, 
                                  int &nbdres, TabDes tabdes[] );
#endif
     /*-------------------------------------------------------*/
     /*      Dump applicatif & trace hors CATIADataBasics     */
     /*-------------------------------------------------------*/
ExportedByCATIAEntity int mdltra (const int &ientr, const int &ilevel , char ctext[] ) ;

     /*-------------------------------------------------------*/
     /*   Selectionnabilite dans les modeles passifs (V3,V4)  */
     /*-------------------------------------------------------*/

ExportedByCATIAEntity void ovlrac(unsigned char &lautor);
ExportedByCATIAEntity void ovlacc(const unsigned char &lautor);

     /*---------------------------------------------*/
     /*   Manipulation des modeles passifs (V3,V4)  */
     /*---------------------------------------------*/

// OGM le 13/08/2003 : migration 64 bits
ExportedByCATIAEntity  int lecnuj(const int &jele,int &numovl, CATINTPTR &ifges8,
             CATINTPTR &iftol8, CATINTPTR &ifind8, CATINTPTR &ifdat8, CATINTPTR &ifvir8 );
ExportedByCATIAEntity  int jelovl(const int &jele );
ExportedByCATIAEntity  void lecovs(unsigned char &lovly, int &nbrovly);
ExportedByCATIAEntity  void lecov2(unsigned char &lovly, int &nbrovly);
// OGM le 13/08/2003 : migration 64 bits
ExportedByCATIAEntity  int lecof7(const int &numovl, CATINTPTR &ifges8,
             CATINTPTR &iftol8, CATINTPTR &ifind8, CATINTPTR &ifdat8, CATINTPTR &ifvir8, int &ier);

  /*-----------------------------------------------------------------------*/
  /*     giucnz : JELE->IGRA  et giurec : IGRA->JELE                       */
  /* giucnv : decodage JELE->IGRA des entites Catgeo                       */
  /* giucn1 : decodage JELE->IGRA des entites CATGEO du modele actif       */
  /* giucn2 : decodage JELE->IGRA                                          */
  /* giucn3 : decodage JELE->IGRA des entites du modele actif              */
  /*                                                                       */
  /* giuuty : decodage type CATGEO                                         */
  /*-----------------------------------------------------------------------*/

ExportedByCATIAEntity  void igraplus(const int &igra, CATIAEntity* &entity);

ExportedByCATIAEntity  int giurec(const int &igra, int &jele, int &ier);
ExportedByCATIAEntity  int giucnz(const int & jele, int &igra, int &ier);
ExportedByCATIAEntity  int giucnv(const int & jele, int &igra, 
                  int &itypp, int &ityps, int &icur, int &ier);
ExportedByCATIAEntity  int giucn1(const int & jele, int &igra, 
                  int &itypp, int &ityps, int &icur, int &ier);
ExportedByCATIAEntity  int giucn2(const int & jele, int &igra, 
                  int &itypp, int &ityps, int &icur, int &ier);
ExportedByCATIAEntity  int giucn3(const int & jele, int &igra, 
                  int &itypp, int &ityps, int &icur, int &ier);

ExportedByCATIAEntity void giuuty(const int &igra, int &itypp, int &ityps);

ExportedByCATIAEntity void giutws( const int &iwsp, int &ityp, int &iext );

ExportedByCATIAEntity void giutwt( const int &iwsp, int &ityp, int &iext );

ExportedByCATIAEntity  int giuwst( const int &nbtyp, const int typwsp[], 
                                   const int &externe, int &ier);

ExportedByCATIAEntity  int giuprv( const int &jele, int &privated, int &ier);

     /*-----------------------------------------------------------*/
     /* Gestion permissive du mode fantome specifique soft GIUCN. */
     /*   laufan : lecture du mode en cours                       */
     /*   autfon : on autorise les elts fantomes au giucn.        */
     /*   autfof : on autorise les elts fantomes au giucn.        */
     /* Par defaut, les elts fantomes sont interdits              */
     /*-----------------------------------------------------------*/

ExportedByCATIAEntity  int  laufan();
ExportedByCATIAEntity  void autfon();
ExportedByCATIAEntity  void autfof();

     /*-----------------------------------------------*/
     /*   Acces au type CATIA d'un element            */
     /* Un type CATIA <ITP-ITS> est-il reconnu public */
     /*-----------------------------------------------*/

ExportedByCATIAEntity  void lectyp(const int &igra, int &itp, int &its);
ExportedByCATIAEntity  unsigned char giuvel(int const &itypp, int const &ityps);

     /*---------------------------------------------*/
     /*   Manipulation des modeles passifs (V3,V4)  */
     /*---------------------------------------------*/

ExportedByCATIAEntity  int lecnuo(const int &igra, int &numovl );
// OGM le 13/08/2003 : migration 64 bits
ExportedByCATIAEntity  int lecnum(const int &igra, int &numovl, CATINTPTR &ifges8,
           CATINTPTR &iftol8, CATINTPTR &ifind8, CATINTPTR &ifdat8, CATINTPTR &ifvir8 );
// OGM le 13/08/2003 : migration 64 bits
ExportedByCATIAEntity  int lecifg(const int & igra, CATINTPTR &ifges8);
ExportedByCATIAEntity  unsigned char lelovl(const int &igra );

     /*------------------------------------*/
     /*  Gestion des elements flagges      */
     /*------------------------------------*/

ExportedByCATIAEntity    void recfla(const int &igrecc,const int &itp,int &igra);
ExportedByCATIAEntity    void modfla(const int &igra,const unsigned char &status);
ExportedByCATIAEntity unsigned char lelfla(const int &igra);


     /*--------------------------------------*/
     /*  Manipulation des numeros de LAYER   */
     /*--------------------------------------*/

ExportedByCATIAEntity  void lecniv(const int &igra,       int &layer);
ExportedByCATIAEntity  void modniv(const int &igra, const int &layer);

ExportedByCATIAEntity  int GetCurrentLayer();

     /*--------------------------------------*/
     /*  Services ecrites dans le cadre du   */
     /*  CATSiteNavigator                    */
     /*--------------------------------------*/

ExportedByCATIAEntity  int ScanLayFil( CATIAEntity* const, CATIAEntity*& );

ExportedByCATIAEntity  int ReadLayFil( CATIAEntity * const entity, unsigned char layer[255]);

ExportedByCATIAEntity  int ScanWindows( CATIAEntity* const, CATIAEntity*& );

     /*--------------------------------------*/
     /*  Manipulation des couleurs           */
     /*--------------------------------------*/

ExportedByCATIAEntity  int GetColorTable( CATIAModel * const mnum, unsigned short col[256]);

     /*-------------------------------------------------------------*/
     /*  Manipulation de la zone de TRAVAIL                         */
     /*      lecztr/modiztr correspondent a une manip brutale ZTRAV */
     /*-------------------------------------------------------------*/

ExportedByCATIAEntity  void lecztr(const int &igra, int &iztrav);
ExportedByCATIAEntity  void modztr(const int &igra,
                                   const unsigned char &ladr, const int &itrav);
ExportedByCATIAEntity  void modiztr(const int &igra, const int &itrav);

     /*----------------------------------------------------*/
     /*  Gestion de l'etat du Modele suite aux transitions */
     /*----------------------------------------------------*/

ExportedByCATIAEntity void refdco( unsigned char &iua,  unsigned char &vmd, 
               unsigned char &ima, unsigned char &tmp,  unsigned char &cre, 
               unsigned char &des, unsigned char &par,  unsigned char &eff );


     /*---------------------------------------------*/
     /*   Acces aux attributs de la table /INDEXE/  */
     /*---------------------------------------------*/

ExportedByCATIAEntity  void lecnpl(const int &igra, int &numplan);
ExportedByCATIAEntity  void leclib(const int &igra, int &izlib);
ExportedByCATIAEntity  void leczpr(const int &igra, int &izpr);
ExportedByCATIAEntity  void codlec(int &icode);

ExportedByCATIAEntity  void modnpl(const int &igra, const int &numplan);
ExportedByCATIAEntity  void modlib(const int &igra, const int &izlib);
ExportedByCATIAEntity  void modipr(const int &igra, const int &igrpre);
ExportedByCATIAEntity  void modisu(const int &igra, const int &igrsui);
ExportedByCATIAEntity  void modnbp(const int &igra, const int &npar);
ExportedByCATIAEntity  void modnfi(const int &igra, const int &nfil);

ExportedByCATIAEntity  void ecrvmd(const int &igra, const unsigned char &value);
ExportedByCATIAEntity  void lecvmd(const int &igra, unsigned char &value);

ExportedByCATIAEntity  void ecrtma(const int &igra, const unsigned char &value);
ExportedByCATIAEntity  void lectma(const int &igra, unsigned char &value);

ExportedByCATIAEntity  void ecrdst(const int &igra, const unsigned char &value);
ExportedByCATIAEntity  void lecdst(const int &igra, unsigned char &value);

ExportedByCATIAEntity  void ecrcot( const int &igra, const unsigned char &value);
ExportedByCATIAEntity  void leccotb(const int &igra, unsigned char &value);

ExportedByCATIAEntity  void ngtlec( const int &igra, const int &ngt, 
                                    unsigned char &value);

ExportedByCATIAEntity int modhea(const unsigned char &lvisu, const int &igra, int &ier);

     /*---------------------------------------------*/
     /* Pour compatibilite V4 uniquement            */
     /*---------------------------------------------*/

ExportedByCATIAEntity   void ldstart( struct DECALE *const decale,  
       struct INDEX  *const indexe, struct JELE   *const jele,  
       struct DATA   *const data,   struct MDL    *const vir,      
       struct GES    *const ges,    struct TOLER  *const toler ) ;

ExportedByCATIAEntity   void ldnulle();

     /*---------------------------------------------*/
     /*   Services internes de gestion des jeles    */
     /*---------------------------------------------*/

ExportedByCATIAEntity  void giuwsp(const int &bidon);

     /*---------------------------------------------*/
     /*                Gestion du Tass              */
     /*---------------------------------------------*/

ExportedByCATIAEntity  void tastda();
ExportedByCATIAEntity  void tasdat();
ExportedByCATIAEntity  void tasdatif(const int &facteur);
ExportedByCATIAEntity  void tasspa(const int &igra, int &nbfree, int &numfree);


     /*---------------------------------------------*/
     /*          Gestion de l'accept/refus          */
     /*---------------------------------------------*/

ExportedByCATIAEntity  void akkept();

ExportedByCATIAEntity  void suptem();

     /*---------------------------------------------*/
     /*            Soft de duplication              */
     /*---------------------------------------------*/

ExportedByCATIAEntity   int dupelt( const int &igrecc, const int &igrele,
   const int &itp, const int &its, const unsigned char &lstand,
   const int &nbpar, int &igra, int &ier );
ExportedByCATIAEntity   int dupels( const int &igrele,
   const unsigned char &lstand, int &igrdup, int &ier );

     /*--------------------------------------*/
     /*           Soft d'effacement          */
     /*--------------------------------------*/

ExportedByCATIAEntity  void proteg();
ExportedByCATIAEntity  int mbuef2(const int &igra, int &ier);
ExportedByCATIAEntity  int mbueff(const int &igra, int &ier);


     /*---------------------------------------------*/
     /* Pour Migration V5 -> V4 (Save_as_MODEL)     */
     /*---------------------------------------------*/

ExportedByCATIAEntity int CATIAModelMigre_en_ModelV4 (CATIAModel * mnum);
ExportedByCATIAEntity int CATIAMove_EltV4 (const int &iecc , const int &igra);
ExportedByCATIAEntity void samaut(const int &type_acces , int &autorisation);

}

//********////////////////////////////////////////////////********
//
//      Pseudo-CATGEO  du soft de base
//
//********////////////////////////////////////////////////********


#ifndef CATIAuuid_typedef_h
#define CATIAuuid_typedef_h
typedef unsigned char CATIAuuid[16];
#endif

extern "C" 
{
     /*---------------------------------------------*/
     /*    Le Modele en cours pour le soft de base  */
     /*---------------------------------------------*/

#ifndef gimcur_h
#define gimcur_h
  ExportedByCATIAEntity int gimcur(int &mnum, int &ier);
#endif

#ifndef giuswap_h
#define giuswap_h
  ExportedByCATIAEntity int giuswap(int &mnum, 
                                  int &good_model,
                                  int &old_model,  int &ier);
#endif

#ifndef gimswap_h
#define gimswap_h
  ExportedByCATIAEntity int gimswap(int &previous, 
                                  int &next, int &ier);
#endif

#ifndef giuchg_h
#define giuchg_h
  ExportedByCATIAEntity int giuchg(int &mnum, int &ier);
#endif

#ifndef giunum_h
#define giunum_h
  ExportedByCATIAEntity int giunum(int &mnum, int &ier);
#endif
  ExportedByCATIAEntity void gueloc(char sbname[8], int &mnum);


     /*---------------------------------*/
     /*   Rajout pour ObjectModeler V5  */
     /*---------------------------------*/


#ifndef gimsearch_h
#define gimsearch_h
 ExportedByCATIAEntity  int gimsearch(const char* name, int &mnum);
#endif


#ifndef gimpath_h
#define gimpath_h
 ExportedByCATIAEntity  int gimpath(int &mnum,const char* &pathname,
                                     int &ier);
#endif

#ifndef gimempty_h
#define gimempty_h
 ExportedByCATIAEntity  int gimempty(int &mnum, int &ier);
#endif

     /*---------------------------------*/
     /*   Rajout pour ObjectModeler V5  */
     /*---------------------------------*/

#ifndef g7usearch_h
#define g7usearch_h
 ExportedByCATIAEntity int g7usearch(const CATIAuuid key, int &model, 
                                     int &jele, int &ier);  
#endif
}

//********////////////////////////////////////////////////********
//
//      Services basique de la geometrie
//
//********////////////////////////////////////////////////********

extern "C" 
{

  ExportedByCATIAEntity  int recbpl(const int &igra, int &igrpoly);
  ExportedByCATIAEntity  int recsyn(const int &igra, int &igrsyn);
  ExportedByCATIAEntity void recfon(const int &igra, int &igrfon, int &itpfon);

  ExportedByCATIAEntity  int ylnln( const double droite_one[3],
                                    const double droite_two[3],
				    double point[2], int &ier);

  ExportedByCATIAEntity  int ypcadr(const int &jele, 
    int &jfond, int itp[2], int its[2], int iaddes[2], int &ier);

  ExportedByCATIAEntity  int iadpeq(const double xpln[9]); 
}

#endif   /* DataModelerBase_h */
