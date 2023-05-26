/* CATV4UserApplication.h : COPYRIGHT DASSAULT SYSTEMES 1997 */
/**
* @level Protected
* @usage U1
*/
#ifndef  CATV4UserApplication_h
#define  CATV4UserApplication_h

#include "ExportedByCATIAEntity.h"
#include "CATBoolean.h"

class CATIAModel;

  /*--------------------------------------*/
  /*  Gestion du Soft des UAX en CXR1     */
  /*--------------------------------------*/

	/* ----------------------- */
	/*  Creation de pointages  */
	/* ----------------------- */
	/* 
		numele : numero de parent derriere lequel on ajoute ( =0 pour ajouter en premier parent )
		nbToAdd : nombre de parents a ajouter
		jeleToAdd : tableau de jele des parents a jouter
		typeLnk : tableau des types de liaisons( de 1 a 12 )
	*/
	ExportedByCATIAEntity int CreateRelation( CATIAModel* const& mnum, const int jele,
														const int numele,	const int nbToAdd, const int *jeleToAdd,
														const int *typeLnk, int& ier ) ;

extern "C"
{

	struct application
	{
	  int lmode;       // =0 si appli publique ; =1 si appli privee
	  unsigned char c8appli[8];
	};

  /*----------------------------------------*/
  /* Gestion d'une transaction applicative  */
  /*----------------------------------------*/

ExportedByCATIAEntity int gmabegin(const char chapply[8], int &transaction, int &ier);
ExportedByCATIAEntity int gmubegin(const char chapply[8], int &transaction, int &ier);
ExportedByCATIAEntity int gmaended(const int &transaction, int &ier);

       /*--------------------------------------------*/
       /* Compatibilite KRADO avec la V4, a oublier  */
       /*--------------------------------------------*/

  ExportedByCATIAEntity  int  gmappl(const char chaine[8], int &ier);
  ExportedByCATIAEntity  int  gmuppl(const char chaine[8], int &ier);

	/* --------------------------------------- */
	/*  Gestion des chaines d'identifications  */
	/*			Ajout OGM le 24/10/2000						 */
	/*				pour SaveAs session							 */
	/* --------------------------------------- */
	union DecodeR8 
	{
		double R8 ;
		int I4[2] ;
		char C1[8] ;
	} ;

	ExportedByCATIAEntity int gmulid( const char chaineAppli[8], const CATBoolean &mode, 
																		const int &icode, const int &ityps, const int &iact,
																		char ident[4], int &compteur, int &ier ) ;
	ExportedByCATIAEntity int gmueid( const int & typDescro, const int & nbType,
																		const int *tabType, const char *tabChaine, int &ier ) ;

#ifdef PLATEFORME_DS64

	ExportedByCATIAEntity int gmasid( int &iMnum, const int &nbTyp,
									  const int *tabTyp, const char chaine[8], int &ier ) ;
	ExportedByCATIAEntity int gmaeid( int &iMnum, const int &nbTyp,
									  const int *tabTyp, const char chaine[8], int &ier ) ;

  /*-----------------------------------------------------------------------*/
  /* Services de scan des sets d'appli (UAS) et des elements d'appli (UAE) */
  /*-----------------------------------------------------------------------*/

  ExportedByCATIAEntity  int  gmasst( int &iMnum, const int &ityset,
									  const int &jsetp, int &jsetf, int &iend, int &ier);

  ExportedByCATIAEntity  int  gmasel( int &iMnum, const int &jset,
									  const int &ityps, const int &jelep, 
									  const int &istep, int &jelef, int &iend, int &ier);

  /*------------------------------------*/
  /* Services de scan des pointages UAX */
  /*------------------------------------*/

  ExportedByCATIAEntity  int  gmarln( int &iMnum, const int &jeleap, const int &numele, 
	                                  int &jrel, int &ityre, int &ier);

  ExportedByCATIAEntity  int  gmasln( int &iMnum, const int &jele, const int &jsetap, 
									  const int &jelapp, int &jelapf, int &ifin, 
									  int &ier);

/* Ajout YWE - 11.03.98 pour FD&T */
  ExportedByCATIAEntity  int  gmares( int &iMnum, const int &jeleap, int &jsetap, 
									  int &ier);

  /*-----------------------------------------------*/
  /* Liste des applis referencees dans un modele   */
  /*-----------------------------------------------*/

  ExportedByCATIAEntity  int uaplis( int &iMnum, const int &nbmax, int &nbfound,
									 struct application tab_appli[] );


  /*-----------------------------------------------*/
  /* Gestion des descriptions rudimentaires UDB V1 */
  /*-----------------------------------------------*/

         //---------------------------------------------------
         // Analyse du nombre de descriptions UDBV1 portees
         // Analyse des types de descriptions UDBV1 portees
         //---------------------------------------------------

  ExportedByCATIAEntity int gmdrnd( int &iMnum, const int &jele, \
				                    int &ndes, int &ier);

  ExportedByCATIAEntity int gmdrds( int &iMnum, const int &jele, \
								    int &ndes, int *itydes, int &ier);

         //------------------------------------------------------------
         // Analyse de la taille des valeurs d'une descriptions UDBV1 
         // Analyse des valeurs d'une descriptions UDBV1 
         //------------------------------------------------------------

  ExportedByCATIAEntity int gmdrdl( int &iMnum, \
									const int &jele, const int &itydes, int &iexist, \
									int &ni4, int &nr4, int &nr8, int &nc8, int &ier);

  ExportedByCATIAEntity int gmdrdv( int &iMnum,  \
									const int &jele, const int &itydes, int &iexist, \
									int &ni4,   int    *i4, \
									int &nr4,   float  *r4, \
									int &nr8,   double *r8, \
									int &nc8,   char   *c8, int &ier);
  
  ExportedByCATIAEntity int gmdrdt( int &iMnum,  \
									const int &jele, const int &itydes, int &iexist, \
									int &ni4,   int    *i4, \
									int &nr4,   float  *r4, \
									int &nr8,   double *r8, \
									int &nc8,   char   *c8, int &ier);
  
         //------------------------------------------------------------
         // Affection de valeurs a une description UDB V1
         // Suppression d une description UDB V1
         //------------------------------------------------------------

  ExportedByCATIAEntity int gmdwri( int &iMnum, \
									const int &jele, const int &itydes,\
									const int &ni4,  const int    *i4, \
									const int &nr4,  const float  *r4, \
									const int &nr8,  const double *r8, \
									const int &nc8,  const char   *c8, int &ier);
  
  ExportedByCATIAEntity int gmddel( int &iMnum, \
								    const int &jele, const int &itydes, int &ier);

#else /* PLATEFORME_DS64 */

	ExportedByCATIAEntity int gmasid( CATIAModel* const &iModel, const int &nbTyp,
																		const int *tabTyp, const char chaine[8], int &ier ) ;
	ExportedByCATIAEntity int gmaeid( CATIAModel* const &iModel, const int &nbTyp,
																		const int *tabTyp, const char chaine[8], int &ier ) ;

  /*-----------------------------------------------------------------------*/
  /* Services de scan des sets d'appli (UAS) et des elements d'appli (UAE) */
  /*-----------------------------------------------------------------------*/

  ExportedByCATIAEntity  int  gmasst(CATIAModel *const &iModel, const int &ityset,
          const int &jsetp, int &jsetf, int &iend, int &ier);

  ExportedByCATIAEntity  int  gmasel(CATIAModel *const &iModel, const int &jset,
            const int &ityps, const int &jelep, const int &istep, int &jelef,
            int &iend, int &ier);

  /*------------------------------------*/
  /* Services de scan des pointages UAX */
  /*------------------------------------*/

  ExportedByCATIAEntity  int  gmarln(CATIAModel *const &iModel, const int &jeleap, const int &numele, int &jrel, int &ityre, int &ier);

  ExportedByCATIAEntity  int  gmasln(CATIAModel *const &iModel, const int &jele, const int &jsetap, const int &jelapp, int &jelapf, int &ifin, int &ier);

/* Ajout YWE - 11.03.98 pour FD&T */
  ExportedByCATIAEntity  int  gmares(CATIAModel *const &iModel, const int &jeleap, int &jsetap, int &ier);

  /*-----------------------------------------------*/
  /* Liste des applis referencees dans un modele   */
  /*-----------------------------------------------*/

  ExportedByCATIAEntity  int uaplis( CATIAModel* const &iModel, const int &nbmax, int &nbfound,
	   struct application tab_appli[] );


  /*-----------------------------------------------*/
  /* Gestion des descriptions rudimentaires UDB V1 */
  /*-----------------------------------------------*/

         //---------------------------------------------------
         // Analyse du nombre de descriptions UDBV1 portees
         // Analyse des types de descriptions UDBV1 portees
         //---------------------------------------------------

  ExportedByCATIAEntity int gmdrnd(CATIAModel *const &iModel, const int &jele, \
				int &ndes, int &ier);

  ExportedByCATIAEntity int gmdrds(CATIAModel *const &iModel, const int &jele, \
		int &ndes, int *itydes, int &ier);

         //------------------------------------------------------------
         // Analyse de la taille des valeurs d'une descriptions UDBV1 
         // Analyse des valeurs d'une descriptions UDBV1 
         //------------------------------------------------------------

  ExportedByCATIAEntity int gmdrdl(CATIAModel *const &iModel, \
          const int &jele, const int &itydes, int &iexist, \
          int &ni4, int &nr4, int &nr8, int &nc8, int &ier);

  ExportedByCATIAEntity int gmdrdv(CATIAModel *const &iModel,  \
          const int &jele, const int &itydes, int &iexist, \
          int &ni4,   int    *i4, \
          int &nr4,   float  *r4, \
          int &nr8,   double *r8, \
          int &nc8,   char   *c8, int &ier);
  
  ExportedByCATIAEntity int gmdrdt(CATIAModel *const &iModel,  \
          const int &jele, const int &itydes, int &iexist, \
          int &ni4,   int    *i4, \
          int &nr4,   float  *r4, \
          int &nr8,   double *r8, \
          int &nc8,   char   *c8, int &ier);
  
         //------------------------------------------------------------
         // Affection de valeurs a une description UDB V1
         // Suppression d une description UDB V1
         //------------------------------------------------------------

  ExportedByCATIAEntity int gmdwri(CATIAModel *const &iModel, \
          const int &jele, const int &itydes,\
          const int &ni4,  const int    *i4, \
          const int &nr4,  const float  *r4, \
          const int &nr8,  const double *r8, \
          const int &nc8,  const char   *c8, int &ier);
  
  ExportedByCATIAEntity int gmddel(CATIAModel *const &iModel, \
          const int &jele, const int &itydes, int &ier);
  /*------------------------------------------------------*/
  /* Gestion des entites applicatives : le SET Applicatif */
  /*------------------------------------------------------*/

#endif /* PLATEFORME_DS64 */

}
#endif   /* CATV4UserApplication_h */
