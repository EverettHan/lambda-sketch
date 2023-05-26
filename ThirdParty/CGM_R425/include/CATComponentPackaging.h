//-------------------------------------------------------------------------
//
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
// CATComponentPackaging :
//    Classe dont derive chacun des objets Carte d'Identite des Composants 
//    de Packaging (Produit,Solution)
//--------------------------------------------------------------------------

#ifndef CATCOMPONENTPACKAGING_H
#define CATCOMPONENTPACKAGING_H


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

//_____________________ macro GenerateIdentityCardPackaging
#include "CATIdentityMacroPackaging.h"

//===================================================================
//                          IMPORT
//===================================================================


#include "CATComponent.h"
#include "CATIncludedComponent.h"

class CATSiList;
class CATUnicodeString;

#include "CATComponentPkgData.h"

//===================================================================
//                          EXPORT
//===================================================================


/////////////////////////////////////////////////////////////////////
//
//                                TYPES
//
/////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
//
//                                CONSTANTES
//
/////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////
//
//                                CLASSE
//
/////////////////////////////////////////////////////////////////////


class ExportedByCOMPONENTV2 CATComponentPackaging: public CATComponent
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
  static CATComponentPackaging*  
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
    SetDescription     (const char*                 ipDescriptionText_c);

    int                     
    SetCAADescription  (const char*                 ipDescriptionText_c);


    int                     
    SetLicense         (const CATComponentLicense   iLicense_n);

    int                     
    SetShortId         (const char*                 ipShortId_c);

    int                     
    SetScale           (const CATComponentScale     iScale_e);

    int                     
    SetSolutionType    (const CATComponentSltType   iSolutionType_e);

    int                     
    IncludeComponent   (const char*                 ipComponentName_c,
			const ComponentAccess       iAccess_e = Public,
			const ComponentExport       iExport_e = ComponentExport_NIL);

	int
	IncludeExtraComponent (const char*                 ipComponentName_c,
			const ComponentAccess       iAccess_e = Public,
			const ComponentExport       iExport_e = ComponentExport_NIL);

	int                     
    IncludeHeaders   (const char*                 ipComponentName_c);

	int                     
    IncludeRefDoc  (const char*                 ipComponentName_c);

	int                     
    IncludeProgDoc  (const char*                 ipComponentName_c);

	int                     
    IncludeDoc  (const char*                 ipComponentName_c);

	int
	IncludeL0Headers (const char*                 ipComponentName_c);

	int                     
    IncludeUseCaseCode   (const char*                 ipComponentName_c);

    int                     
    AuthorizeComponent (const char*                 ipComponentName_c,
			const int                   iScale_n = 1);

    int                     
    AuthorizeOption(const char*                 ipComponentName_c,
		    const int                   iScale_n = 1);
    
	int                     
    AllowWorkbench(const char*                 ipComponentName_c);   
	


	int                               IsExtraAllowed           (void) { return _iAllowExtra; };
	void                              AllowExtra               (int i){ _iAllowExtra = i; };

      //
      // Lecture 
      //========

    const char*            
    GetDescription             (void);

    CATComponentLicense    
    GetLicense                 (void);

    const char*            
    GetShortId                 (void);

    CATComponentScale
    GetScale                   (void);

    CATComponentSltType
    GetSolutionType            (void);

    CATSiList*             
    GetListIncludedComponent   (void)              ;

	CATSiList*             
    GetListIncludedHeaders   (void)			   ;

	CATSiList*             
    GetListIncludedL0Headers   (void)			   ;

	CATSiList*             
    GetListIncludedRefDoc(void)            ;

	CATSiList*             
    GetListIncludedDoc(void)            ;


	CATSiList*             
    GetListIncludedProgDoc(void)            ;

	CATSiList*             
    GetListIncludedUseCaseCode   (void)             ;

    CATSiList*             
    GetListAuthorizedComponent (void)              ;

    CATSiList*             
    GetListAuthorizedOption    (void)              ;

	CATSiList*             
    GetListAllowedWorkbench    (void)              ;

	CATSiList*  
    GetListIncludedExtraComponent (void)           ;

	int SetMarketingType (const char*  ipMarketingType_c);
	CATSiList* GetListMarketingType (void);

	int SetLicenseType (const char*  ipLicenseType_c);
	CATListOfCATUnicodeString& GetListLicenseType (void);

    int SetPartner (const char*  ipPartner_c);

	int NOISCollect() {ISCollect=1; return 1;};

	int ISCollectStatus() { return ISCollect; };

	CATSiList* GetListPartner (void);

	int SetVersion (int  iVersion);
	int GetVersion (void);

	int isAddon();
	int isShareable();
	int isDelegation();
	int isRepresentation();

	static int IsAPackacgingComponent( ComponentType   ComponentType_e );
 

    //-------------------------------
    // Debug
    //-------------------------------

    virtual void           
    Display (const char*  ipTab_c, 
	     ostream&     oOStream_o)         const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PROTECTED <<<<<<<<<<<<<<<<<<<<<<<<<<<<

 protected:
  
    //-------------------------------
    // Construction/Destruction
    //-------------------------------
    CATComponentPackaging (const char* ipComponentPackagingName_c);  
    //
    virtual ~CATComponentPackaging ();

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
    CATComponentPkgData   _Data_o;
	int ISCollect;
	int _iAllowExtra;
};

#endif



