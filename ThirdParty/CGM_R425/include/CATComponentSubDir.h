//-------------------------------------------------------------------------
//
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
// CATComponentSubDir :
//    Classe representant un composant prerequis
//--------------------------------------------------------------------------

#ifndef CATCOMPONENTSUBDIR_H
#define CATCOMPONENTSUBDIR_H


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

//_____________________ constantes, enum
#include "CATComponent.h"
#include "CATString.h"
#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:04:57 [Replace forward declaration of standard streams with iosfwd.h] **/
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


class ExportedByCOMPONENTV2 CATComponentSubDir
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:
  
//---------------------------------------------------------
// -> METHODES DE CLASSE
//---------------------------------------------------------
  static int        Find (CATSiList*   ipListSubDirComponent_o,const CATComponentSubDir* iComponent);

//---------------------------------------------------------
// -> METHODES
//---------------------------------------------------------

  CATComponentSubDir          (const CATString      ipComponentName_c,
			                   ComponentAccess  iAccess_e);
  CATComponentSubDir          (void);
  
  //
  virtual ~CATComponentSubDir (void);

  virtual const CATString   GetSubDir   (void)                              const;
  virtual const ComponentAccess   GetAccessLevel (void)                              const;
  virtual void              Display   (const char*  ipTab_c,
				       ostream&     oOStream_o)           const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  private:

//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------
  CATString         _SubDir;
  ComponentAccess   _ComponentAccess;

};


#endif



