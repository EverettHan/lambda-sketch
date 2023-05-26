//-------------------------------------------------------------------------
//
// COMPOSANT : System
//
//-------------------------------------------------------------------------
// CATComponentMedia :
//    Classe dont derive chacun des objets Carte d'Identite des Composants 
//    Media
//--------------------------------------------------------------------------

#ifndef CATComponentMedia_H
#define CATComponentMedia_H


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

//_____________________ macro GenerateIdentityCardMedia
#include "CATIdentityMacroMedia.h"

#include "CATComponent.h"

class CATSiList;
//class CATTrace;

class CATComponentMedData;

//===================================================================
//                          EXPORT
//===================================================================



/////////////////////////////////////////////////////////////////////
//
//                                CLASSE
//
/////////////////////////////////////////////////////////////////////


class ExportedByCOMPONENTV2 CATComponentMedia: public CATComponent
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  //pour acceder au constructeur...
  friend class CATComponent;

  public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------

      //
      // CONVERSION DE POINTEUR
      // ======================
      // 
  static CATComponentMedia*  
  CastPtr       (CATComponent*         ipIdCardObject_o);

      //
      // TRACE de mise au point
      // =====
      // 
  //static int                     
  //SetTrace      (CATTrace*             ipTrace_o);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------
 
    //-------------------------------
    // Acces aux attributs
    //-------------------------------

      //
      // Ecriture
      //==========

    int                     
    SetProductLine     (const char*                 ipProductLineText_c);

    int                     
    SetMarketingVersion (const char*                ipMarketingVersionText_c);

    int                     
    SetDescription     (const char*                 ipDescriptionText_c);


   int SetOfficialCompanyName(const char* OfficialCompanyName);

   int SetOfficialProductLine(const char* OfficialProductLine);

   int SetOfficialProductItem(const char* OfficialProductItem);

   int SetOfficialVersionNumber(const char* OfficialVersionNumber);

   int SetProductItem(const char* ProductItem);

   int SetCommandLine(const char* CommandLine);



    int                     
    IncludeComponent   (const char*                 ipComponentName_c,
			const char*                 ipOSName_c);


      //
      // Lecture 
      //========

    const char*            
    GetProductLine             (void)                                                    const;

    const char*            
    GetMarketingVersion        (void)                                                    const;

    const char*            
    GetDescription             (void)                                                    const;

	const char*
    GetProductItem (void)  const;

	const char*
    GetOfficialCompanyName (void)  const;


    int
    GetListIncludedComponent   (const char*                  ipOSName_c,
				CATSiList&                   oIncludedCmpLstP_o)         const;

	const char*
    GetOfficialProductItem (void)  const;


	const char*
    GetOfficialProductLine (void)  const;


	const char*
    GetOfficialVersionNumber (void)  const;


    int            
    GetListOS                  (const char*                  ipComponentName_c,
				CATSiList&                   oOSNameLstP_o)              const;

    int             
    GetAllIncludedComponent    (CATSiList&                   oIncludedCmpLstP_o)         const;

    int             
    GetAllOS                   (CATSiList&                   oOSNameLstP_o)              const;


    //-------------------------------
    // Debug
    //-------------------------------

    virtual void           
    Display (const char*  ipTab_c, 
	     ostream&     oOStream_o)                                    const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PROTECTED <<<<<<<<<<<<<<<<<<<<<<<<<<<<

 protected:
  
    //-------------------------------
    // Construction/Destruction
    //-------------------------------
    CATComponentMedia (const char* ipComponentMediaName_c);  
    //
    virtual ~CATComponentMedia ();

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
       // Reference sur les donnees specifiques 
       //
    CATComponentMedData*   _pData_o;
};

#endif



