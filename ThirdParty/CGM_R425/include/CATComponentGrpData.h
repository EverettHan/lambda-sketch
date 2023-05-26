//-------------------------------------------------------------------------
//
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
// CATComponentGrpData :
//    Classe stokant les donnees specifiques de la classe CATComponentGroup
//
//--------------------------------------------------------------------------

#ifndef CATCOMPONENTGRPDATA_H
#define CATCOMPONENTGRPDATA_H


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

class CATSiList;
//class CATTrace;

//===================================================================
//                          EXPORT
//===================================================================

class CATComponentGrpData;


/////////////////////////////////////////////////////////////////////
//
//                                CLASSE
//
/////////////////////////////////////////////////////////////////////


class ExportedByCOMPONENTV2 CATComponentGrpData
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
  //static int                     SetTrace      (CATTrace*             ipTrace_o);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------
 
    //-------------------------------
    // Construction/Destruction
    //-------------------------------
    CATComponentGrpData (void);
    //
    virtual ~CATComponentGrpData ();

    //-------------------------------
    // Lecture des attributs
    //-------------------------------
    virtual CATSiList&     GetListAggregatedComponent (void);

    //-------------------------------
    // Autres
    //-------------------------------
    virtual void           Display                  (const char*  ipTab_c, 
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
       // Liste des Composants Aggreges
       //
   CATSiList             _ListAggregatedComponent_o;

};

#endif



