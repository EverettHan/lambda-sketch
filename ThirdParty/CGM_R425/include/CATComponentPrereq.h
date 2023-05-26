//-------------------------------------------------------------------------
//
// COMPOSANT : COMPONENTV2
//
//-------------------------------------------------------------------------
// CATComponentPrereq :
//    Classe representant un composant prerequis
//--------------------------------------------------------------------------

#ifndef CATCOMPONENTPREREQ_H
#define CATCOMPONENTPREREQ_H


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
#include "CATIAV5Level.h"
//_____________________ constantes, enum
#include "CATComponent.h"

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:04:56 [Replace forward declaration of standard streams with iosfwd.h] **/
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


class ExportedByCOMPONENTV2 CATComponentPrereq
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:
  
//---------------------------------------------------------
// -> METHODES DE CLASSE
//---------------------------------------------------------
  static int        Find      (CATSiList*       ipListPrereqComponent_o,
			       const char*      ipComponentName_c);

//---------------------------------------------------------
// -> METHODES
//---------------------------------------------------------
  CATComponentPrereq          (const char*      ipComponentName_c,
			       ComponentAccess  iAccess_e,
			       ComponentExport  iExport_e,
				   ComponentExposePrereq iExpose_e);
  CATComponentPrereq          (void);
  //
  virtual ~CATComponentPrereq (void);

  virtual const char*       GetName   (void)                              const;
  virtual ComponentAccess   GetAccess (void)                              const;
  virtual ComponentExport   GetExport (int&         oDefaultValFlag_n)    const;
#ifdef CATIAR201
  virtual ComponentExport   GetAddToClientPrereqs(void)                   const;
  virtual ComponentExposePrereq   GetExposePrereqs(void)                        const;
#endif
  virtual void              Display   (const char*  ipTab_c,
				       ostream&     oOStream_o)           const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  private:

//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------
  char              _ComponentNamePrereq [CATComponentNameLength + 1];
  ComponentAccess   _ComponentAccess;
  ComponentExport   _ComponentExport;
  ComponentExposePrereq _ComponentExpose;
};


#endif



