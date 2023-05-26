//-------------------------------------------------------------------------
//
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
// CATComponentGroup :
//    Classe representant un groupe de composant
//--------------------------------------------------------------------------

#ifndef CATCOMPONENTGROUP_H
#define CATCOMPONENTGROUP_H


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

//_____________________ macro GenerateIdentityCardGroup
#include "CATIdentityMacroGroup.h"

#include "CATComponent.h"

class CATSiList;
//class CATTrace;

class CATComponentGrpData;

//===================================================================
//                          EXPORT
//===================================================================



/////////////////////////////////////////////////////////////////////
//
//                                CLASSE
//
/////////////////////////////////////////////////////////////////////


class ExportedByCOMPONENTV2 CATComponentGroup : public CATComponent
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  //pour pouvoir utiliser le constructeur
  friend class CATComponent;

  public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------
      //
      // CONVERSION DE POINTEUR
      // ======================
      // 
  static CATComponentGroup*  CastPtr                (CATComponent*         ipIdCardObject_o);

      //
      // TRACE de mise au point
      // =====
      // 
  //static int                 SetTrace               (CATTrace*             ipTrace_o);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------
 
    //-------------------------------
    // Affectation des attributs
    //-------------------------------
    int                  AggregateComponent        (const char*            ipComponentName_c,
						    const ComponentAccess  iAccess_e = Public,
						    const ComponentExport  iExport_e = ComponentExport_NIL);

    //-------------------------------
    // Lecture des attributs
    //-------------------------------
    CATSiList*          GetListAggregatedComponent (void);

    //-------------------------------
    // Autres
    //-------------------------------
    virtual void        Display                    (const char*  ipTab_c, 
						    ostream&     oOStream_o)         const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PROTECTED <<<<<<<<<<<<<<<<<<<<<<<<<<<<

 protected:
  
    //-------------------------------
    // Construction/Destruction
    //-------------------------------
    CATComponentGroup (const char* ipComponentGroupName_c);  
    //
    virtual ~CATComponentGroup ();

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<

 private:

    //-------------------------------
    // Construction/Destruction
    //-------------------------------
//    CATComponentGroup (void);
//    CATComponentGroup (const CATComponentGroup& iComponentGroup_o);

    //-------------------------------
    // Operateur
    //-------------------------------
//    CATComponentGroup& operator = (const CATComponentGroup& iComponentGroup_o);

//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------

       //
       // Donnees specifiques 
       //

//   CATSiList*            _pListAggregatedComponent_o ;

     CATComponentGrpData*  _pData_o;

//---------------------------------------------------------
// -> DONNEES DE CLASSE
//---------------------------------------------------------

       //
       // Trace de mise au point
       //
       //      - par defaut, trace non active
       //
  // static CATTrace*      s_pTrace_o;

};

#endif



