//-------------------------------------------------------------------------
//
// COMPOSANT : System
//
//-------------------------------------------------------------------------
//  HISTORIQUE :   
//     Modification  Feb 98                       ADH
//        Ajout de la donnee 'Gamme' et de la methode 
//        d acces en lecture de cette donnee
//-------------------------------------------------------------------------
// CATAuthorizedComponent :
//
//--------------------------------------------------------------------------

#ifndef CATAUTHORIZEDCOMPONENT_H
#define CATAUTHORIZEDCOMPONENT_H

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

//_____________________ constantes
#include "CATComponent.h"
#include "CATComponentPackaging.h"

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:04:47 [Replace forward declaration of standard streams with iosfwd.h] **/
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
//                                CLASSE
//
/////////////////////////////////////////////////////////////////////

class ExportedByCOMPONENTV2 CATAuthorizedComponent
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------
    static int        Find       (CATSiList*   ipListAuthorizedComponent_o,
				  const char*  ipComponentName_c);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------
    CATAuthorizedComponent                (const char*                    ipComponentName_c,
					   const int                      iScale_n);
    CATAuthorizedComponent                (void);
    CATAuthorizedComponent                (const CATAuthorizedComponent&  iAuthorizedCmp_o);
    //
    virtual ~CATAuthorizedComponent       (void);

    virtual const char*   GetName         (void)                             const;
    virtual int           GetScale        (void)                             const;

    virtual void          Display         (const char*  ipTab_c,
					   ostream&     oOStream_o)          const;
    
  //---------------------------------------------------------
  // -> OPERATEURS
  //---------------------------------------------------------
    virtual int           operator ==     (const CATAuthorizedComponent&    iAuthorizedCmp_o) const;
    virtual int           operator !=     (const CATAuthorizedComponent&    iAuthorizedCmp_o) const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  private:

//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------

    char                      _Name [CATComponentNameLength + 1];

	int						  _NameSize;

    int                       _Scale;

};

#endif



