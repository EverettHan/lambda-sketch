//-------------------------------------------------------------------------
//
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
// CATComponentAttach :
//    Classe representant un composant attache
//--------------------------------------------------------------------------

#ifndef CATCOMPONENTATTACH_H
#define CATCOMPONENTATTACH_H


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
//                          IMPORTATION
//===================================================================

//_____________________ constantes
#include "CATComponent.h"

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:04:53 [Replace forward declaration of standard streams with iosfwd.h] **/
 #include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class ostream;
#endif //_CAT_ANSI_STREAMS

class CATSiList;

//===================================================================
//                          EXPORTATION
//===================================================================


/////////////////////////////////////////////////////////////////////
//
//                                CLASSES
//
/////////////////////////////////////////////////////////////////////


class ExportedByCOMPONENTV2 CATComponentAttach
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  public:
  
//---------------------------------------------------------
// -> METHODES DE CLASSE
//---------------------------------------------------------
  static int        Find      (CATSiList*   ipListAttachedComponent_o,
			       const char*  ipComponentName_c);

//---------------------------------------------------------
// -> METHODES
//---------------------------------------------------------
    CATComponentAttach (const char*      ipComponentName_c);
    CATComponentAttach (void);
    //
    virtual ~CATComponentAttach (void);

    virtual const char*     GetName   (void)         const;
    virtual void            Display   (const char*   ipTab_c,
				       ostream&      oOStream_o)           const;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  private:

//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------
  char              _ComponentNameAttach [CATComponentNameLength + 1];

};

#endif



