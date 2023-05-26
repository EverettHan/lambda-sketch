//-------------------------------------------------------------------------
//
// COMPOSANT : System
//
//-------------------------------------------------------------------------
//  HISTORIQUE :   
//     Creation  Sep 99                       EBN
//        Ajout de la donnee 'Gamme' et de la methode 
//        d acces en lecture de cette donnee
//-------------------------------------------------------------------------
// CATAuthorizedOption :
//
//--------------------------------------------------------------------------

#ifndef CATAUTHORIZEDOPTION_H
#define CATAUTHORIZEDOPTION_H

// COPYRIGHT DASSAULT SYSTEMES 2000

//===================================================================
//                          IMPORT
//===================================================================

//_____________________ constantes
#include "CATComponent.h"
#include "CATComponentPackaging.h"

#ifdef _CAT_ANSI_STREAMS
/** @c++ansi aew 2004-08-02.20:04:49 [Replace forward declaration of standard streams with iosfwd.h] **/
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

class ExportedByCOMPONENTV2 CATAuthorizedOption
{
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PUBLIC <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  public:

  //---------------------------------------------------------
  // -> METHODES DE CLASSE
  //---------------------------------------------------------
    static int        Find       (CATSiList*   ipListAuthorizedOption_o,
				  const char*  ipOptionName_c);

  //---------------------------------------------------------
  // -> METHODES
  //---------------------------------------------------------
    CATAuthorizedOption                (const char*                    ipOptionName_c,
					const int                      iScale_n);
    CATAuthorizedOption                (void);
    CATAuthorizedOption                (const CATAuthorizedOption&  iAuthorizedOption_o);
    //
    virtual ~CATAuthorizedOption       (void);

    virtual const char*   GetName      (void)                             const;
    virtual int           GetScale     (void)                             const;

    virtual void          Display      (const char*  ipTab_c,
					ostream&     oOStream_o)          const;
    
  //---------------------------------------------------------
  // -> OPERATEURS
  //---------------------------------------------------------
    virtual int           operator ==     (const CATAuthorizedOption&    iAuthorizedOption_o) const;
    virtual int           operator !=     (const CATAuthorizedOption&    iAuthorizedOption_o) const;

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> PRIVATE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

  private:

//---------------------------------------------------------
// -> DONNEES
//---------------------------------------------------------

    char                      _Name [CATOptionNameLength + 1];

    int                       _Scale;

	int						  _NameSize;

};

#endif



