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
// CATComponentBrand :
//
//--------------------------------------------------------------------------

#ifndef CATComponentBrand_H
#define CATComponentBrand_H


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
/** @c++ansi aew 2004-08-02.20:04:54 [Replace forward declaration of standard streams with iosfwd.h] **/
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

class ExportedByCOMPONENTV2 CATComponentBrand
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------
    static int        Find       (CATSiList*   ipListMarketingType_o,
				  const char*  ipComponentName_c);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------
    CATComponentBrand                (const char*                    ipComponentName_c);
    CATComponentBrand                (void);
    CATComponentBrand                (const CATComponentBrand&  iMarketingType_o);
    //
    virtual ~CATComponentBrand       (void);

    virtual const char*   GetBrand         (void)                             const;
    virtual void          Display         (const char*  ipTab_c,
					   ostream&     oOStream_o)          const;
    
  //---------------------------------------------------------
  // -> OPERATEURS
  //---------------------------------------------------------
    virtual int           operator ==     (const CATComponentBrand&    iMarketingType_o) const;
    virtual int           operator !=     (const CATComponentBrand&    iMarketingType_o) const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  private:

//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------

    char                      _Brand [CATComponentNameLength + 1];


};

#endif



