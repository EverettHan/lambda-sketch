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
// CATPartner :
//
//--------------------------------------------------------------------------

#ifndef CATPartner_H
#define CATPartner_H


// COPYRIGHT DASSAULT SYSTEMES 2000

//
// --> Parametres de WINDOWS_NT
//

#ifdef __COMPONENTV2 

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
/** @c++ansi aew 2004-08-02.20:05:05 [Replace forward declaration of standard streams with iosfwd.h] **/
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

class ExportedByCOMPONENTV2 CATPartner
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------
    static int        Find       (CATSiList*   ipListPartner_o,
				  const char*  ipComponentName_c);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------
    CATPartner                (const char*  ipComponentName_c);
    CATPartner                (void);
    CATPartner                (const CATPartner&  iPartner_o);
    //
    virtual ~CATPartner       (void);

    virtual const char*   GetPartnerName         (void)                             const;
    virtual void          Display         (const char*  ipTab_c,
					   ostream&     oOStream_o)          const;
    
  //---------------------------------------------------------
  // -> OPERATEURS
  //---------------------------------------------------------
    virtual int           operator ==     (const CATPartner&    iPartner_o) const;
    virtual int           operator !=     (const CATPartner&    iPartner_o) const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  private:

//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------

    char                      _Type [CATComponentNameLength + 1];


};

#endif



