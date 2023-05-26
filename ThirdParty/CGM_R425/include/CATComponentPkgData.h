//-------------------------------------------------------------------------
//
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
// CATComponentPkgData :
//    Classe stokant les donnees specifiques de la classe CATComponentPackaging
//
//--------------------------------------------------------------------------

#ifndef CATCOMPONENTPKGDATA_H
#define CATCOMPONENTPKGDATA_H


// COPYRIGHT DASSAULT SYSTEMES 2000

//
// --> Parametres de WINDOWS_NT
//

#if defined(__COMPONENTV2)
#define ExportedByCOMPONENTV2 DSYExport
#else
#define ExportedByCOMPONENTV2 DSYImport
#endif
#include "DSYExport.h"

//===================================================================
//                          IMPORT
//===================================================================

class CATTrace;

// Numero de license (entier 32 bits)
typedef int  CATComponentLicense;

extern ExportedByCOMPONENTV2 const CATComponentLicense  CATComponentLicense_NIL;

#define                                                 CATComponentShortIdLength   3

#undef P1
#undef P2
#undef P3

  // Gamme de Produit/Solution
enum CATComponentScale
{
  CATComponentScale_NIL = 0
  , P1
  , P2
  , P3
};

#undef StandAlone
#undef AddOn

  // Sous-type de solution
enum CATComponentSltType
{
  CATComponentSltType_NIL = 0
  , StandAlone
  , AddOn
};

//_________________ definition de ComponentLicense
#include "CATSiList.h"
#include "CATListOfCATUnicodeString.h"
//===================================================================
//                          EXPORT
//===================================================================

class CATComponentPkgData;

#define MAXLNGDESCRIPTION 4096
/////////////////////////////////////////////////////////////////////
//
//                                CLASSE
//
/////////////////////////////////////////////////////////////////////


class ExportedByCOMPONENTV2 CATComponentPkgData
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------

      //
      // TRACE de mise au point
      // =====
      // 
//  static int                     SetTrace      (CATTrace*             ipTrace_o);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------
 
    //-------------------------------
    // Construction/Destruction
    //-------------------------------
    CATComponentPkgData (void);
    //
    virtual ~CATComponentPkgData ();

    //-------------------------------
    // Acces aux attributs
    //-------------------------------

    virtual CATSiList&             GetListIncludedComponent      (void);
	virtual CATSiList&             GetListExtraIncludedComponent (void);
    virtual CATSiList&             GetListAuthorizedComponent    (void);
    virtual CATSiList&             GetListAuthorizedOption       (void);
    virtual CATSiList&             GetListAllowedWorkbench       (void);
    virtual char*                  GetDescription                (void);
	virtual char*                  GetCAADescription             (void);
    virtual CATComponentLicense&   GetLicense                    (void);
	virtual int&				   GetVersion                    (void);
    virtual char*                  GetShortId                    (void);                  
    virtual CATComponentScale&     GetScale                      (void);                  
    virtual CATComponentSltType&   GetSolutionType               (void); 
	virtual CATSiList&             GetListMarketingType          (void); 
    virtual CATSiList&             GetListPartner                (void); 
	virtual	CATSiList&             GetListIncludedHeaders	     (void);
    virtual	CATSiList&             GetListIncludedProgDoc        (void);
	virtual	CATSiList&             GetListIncludedDoc            (void);
	virtual	CATSiList&             GetListIncludedRefDoc         (void);
    virtual	CATSiList&             GetListIncludedUseCaseCode    (void);
	virtual	CATSiList&			   GetListIncludedL0Headers		 (void);

	virtual CATListOfCATUnicodeString&  GetListLicenseType       (void); 
	//-------------------------------
    // Debug
    //-------------------------------

    virtual void                Display                  (const char*  ipTab_c, 
							  ostream&     oOStream_o)  const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<

 private:


//---------------------------------------------------------
// -> DONNEES DE CLASSE
//---------------------------------------------------------

       //
       // Trace de mise au point
       //
       //      - par defaut, trace non active
       //
   //static CATTrace*      s_pTrace_o;  

//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------

       //
       // - Liste des Composants Inclus
       // - Liste des Composants Authorises
       // - Liste des Options Authorises
       // - Description
       // - Numero de license
       // - Identificateur court
       // - Gamme de produits/solutions
       // - Type de solution
       //
   CATSiList            _ListIncludedComponent_o;
   CATSiList            _ListExtraIncludedComponent_o;
   CATSiList            _ListAuthorizedComponent_o;
   CATSiList            _ListAuthorizedOption_o;
   CATSiList            _ListAllowedWorkbench_o;
   CATSiList            _ListIncludedHeaders_o;
   CATSiList            _ListIncludedL0Headers_o;
   CATSiList            _ListIncludedProgDoc_o;
   CATSiList            _ListIncludedDoc_o;
   CATSiList            _ListIncludedUseCaseCode_o;
   CATSiList            _ListIncludedRefDoc_o;
   char                 _pDescriptionText_c[MAXLNGDESCRIPTION];
   char                 _pCAADescriptionText_c[MAXLNGDESCRIPTION];
   CATSiList            _ListMarketingType_o;
   CATSiList            _ListPartner_o;
   CATComponentLicense  _License_n;
   char                 _aShortId_c [CATComponentShortIdLength + 1];
   CATComponentScale    _Scale_e;
   CATComponentSltType  _SolutionType_e;
   int					_Version_n;

   CATListOfCATUnicodeString _ListLicenseType_o;

};

#endif



