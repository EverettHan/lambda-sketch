//-------------------------------------------------------------------------
//
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
//  HISTORIQUE :   
//-------------------------------------------------------------------------
// CATAggregatedComponent :
//
//--------------------------------------------------------------------------

#ifndef CATAGGREGATEDCOMPONENT_H
#define CATAGGREGATEDCOMPONENT_H

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

//_____________________ constantes, enums
#include "CATComponent.h"

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:04:45 [Replace forward declaration of standard streams with iosfwd.h] **/
 #include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class ostream;
#endif //_CAT_ANSI_STREAMS

class CATSiList;


//===================================================================
//                          EXPORT
//===================================================================


/////////////////////////////////////////////////////////////////////
//
//                                TYPES
//
/////////////////////////////////////////////////////////////////////

class ExportedByCOMPONENTV2 CATAggregatedComponent
{

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------
    static int        Find       (CATSiList*   ipListAggregatedComponent_o,
				  const char*  ipComponentName_c);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------
    CATAggregatedComponent              (const char*      ipComponentName_c,
					 ComponentAccess  iAccess_e,
					 ComponentExport  iExport_e);
    CATAggregatedComponent              (void);
    //
    virtual ~CATAggregatedComponent     (void);

    virtual const char*       GetName   (void)                           const;
    virtual ComponentAccess   GetAccess (void)                           const;
    virtual ComponentExport   GetExport (int&         oDefaultValFlag_n) const;
    virtual void              Display   (const char*  ipTab_c,
					 ostream&     oOStream_o)        const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  private:
    
//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------

    char              _Name [CATComponentNameLength + 1];
    ComponentAccess   _ComponentAccess;
    ComponentExport   _ComponentExport;
  
};

#endif



