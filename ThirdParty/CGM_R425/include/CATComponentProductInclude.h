//-------------------------------------------------------------------------
//
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
// CATComponentProductInclude :
//   Classe dont derive les cartes d'identite des ProductInclude
//--------------------------------------------------------------------------

#ifndef CATCOMPONENTPRODUCTINCLUDE_H
#define CATCOMPONENTPRODUCTINCLUDE_H


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

//_____________________ macro GenerateIdentityCardProductInclude
#include "CATIdentityMacroProductInclude.h"

#include "CATComponent.h"
#include "CATIncludedComponent.h"

class CATSiList;
class CATTrace;

//===================================================================
//                          EXPORT
//===================================================================


/////////////////////////////////////////////////////////////////////
//
//                                CLASSE
//
/////////////////////////////////////////////////////////////////////


class ExportedByCOMPONENTV2 CATComponentProductInclude: public CATComponent
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------

      //
      // CONVERSION DE POINTEUR
      // ======================
      // 
  static CATComponentProductInclude*  CastPtr  (CATComponent*         ipIdCardObject_o);

      //
      // TRACE de mise au point
      // =====
      // 
//  static int                          SetTrace (CATTrace*             ipTrace_o);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------
 
    //-------------------------------
    // Affectation des attributs
    //-------------------------------
    int                     IncludeComponent   (const char*                   ipComponentName_c,
						const ComponentAccess         iAccess_e = Public,
						const ComponentExport         iExport_e = ComponentExport_NIL);

    //-------------------------------
    // Lecture des attributs
    //-------------------------------
    CATSiList*             GetListIncludedComponent (void);

    //-------------------------------
    // Autres
    //-------------------------------
    virtual void           Display (const char*  ipTab_c, 
				     ostream&     oOStream_o)         const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PROTECTED <<<<<<<<<<<<<<<<<<<<<<<<<<<<

 protected:
  
    //-------------------------------
    // Construction/Destruction
    //-------------------------------
    CATComponentProductInclude (const char* ipComponentProductIncludeName_c);  
    //
    virtual ~CATComponentProductInclude ();

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<

 private:

    //-------------------------------
    // Construction/Destruction
    //-------------------------------
//    CATComponentProductInclude (void);
//    CATComponentProductInclude (const CATComponentProductInclude& iComponentProductInclude_o);

    //-------------------------------
    // Operateur
    //-------------------------------
//    CATComponentProductInclude& operator = (const CATComponentProductInclude& iComponentProductInclude_o);

//---------------------------------------------------------
// -> DONNEES DE CLASSE
//---------------------------------------------------------

       //
       // Liste des Composants Inclus
       //
   CATSiList*            _pListIncludedComponent_o;

       //
       // Trace de mise au point
       //
       //      - par defaut, trace non active
       //
   //static CATTrace*      s_pTrace_o;  
};

#endif



