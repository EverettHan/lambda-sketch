//-------------------------------------------------------------------------
//
// COMPOSANT : System
//
//-------------------------------------------------------------------------
// CATComponentErr :
//
//--------------------------------------------------------------------------

#ifndef CATCOMPONENTERR_H
#define CATCOMPONENTERR_H


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

class CATSiList;
#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:04:55 [Replace forward declaration of standard streams with iosfwd.h] **/
 #include "iosfwd.h" 
#else //!_CAT_ANSI_STREAMS 
class ostream;
#endif //_CAT_ANSI_STREAMS
 

//===================================================================
//                          EXPORTATION
//===================================================================

class CATComponentErr;


/////////////////////////////////////////////////////////////////////
//
//                                CLASSE
//
/////////////////////////////////////////////////////////////////////


class ExportedByCOMPONENTV2 CATComponentErr
{

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:

//---------------------------------------------------------
// -> METHODES DE CLASSE
//---------------------------------------------------------

    //-------------------------------
    // Implementation
    //-------------------------------

      // appel du destructeur pour chaque element d'une liste d'objet CATComponentErr
    static int  ApplyDelete (CATSiList&  iCmpErrorLstP_o);


//---------------------------------------------------------
// -> METHODES
//---------------------------------------------------------

    //-------------------------------
    // Construction/Destruction
    //-------------------------------
    CATComponentErr (const char*  ipComponentName_c,
		     const int    iIdent_n);
    //
    virtual ~CATComponentErr ();

    //-------------------------------
    // Acces aux attributs
    //-------------------------------
    const char*     GetComponentName (void)                      const;
    const int       GetIdent         (void)                      const;

    //-------------------------------
    void            Display          (const char*  ipTab_c,
				      ostream&     oOStream_o)   const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  private:

//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------

    char*            _pComponentName_c;

    int              _Ident_n;

};

#endif


