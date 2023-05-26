// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATCAfrUrlViewerSYPEventArgs
//
//=============================================================================
// Usage notes:
//
//=============================================================================
// Fev 2011  Creation                                                   T. Pech
//=============================================================================

#ifndef CATCAfrUrlViewerSYPEventArgs_H
#define CATCAfrUrlViewerSYPEventArgs_H

#include "CATAfrItf.h"
#include "CATSYPEventArgs.h"
#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATLISTV_CATBaseUnknown.h"

class CATCAfrComponentControllerArg;

//-----------------------------------------------------------------------
class ExportedByCATAfrItf CATCAfrUrlViewerSYPEventArgs: public CATSYPEventArgs
{
  CATDeclareClass;

  public:
    // Standard constructors and destructors
    // -------------------------------------
    CATCAfrUrlViewerSYPEventArgs ( CATSYPEvent * ipEvent, const CATUnicodeString& i_Url, 
                                   const CATString & i_typeEvent, 
                                   CATBaseUnknown_var ispBinary = NULL_var );
    CATCAfrUrlViewerSYPEventArgs ( CATSYPEvent * ipEvent, 
                                   const CATString & i_typeEvent, 
                                   const CATLISTV(CATBaseUnknown_var)& i_splist );
    virtual ~CATCAfrUrlViewerSYPEventArgs ();

    /** Get / Set the property Element */
    CATCAfrComponentControllerArg * GetElement() const {return _pElement;};
    const CATUnicodeString& GetUrl() const {return _Url;};

  private:
    // Copy constructor and equal operator
    // -----------------------------------
    CATCAfrUrlViewerSYPEventArgs (CATCAfrUrlViewerSYPEventArgs &);
    CATCAfrUrlViewerSYPEventArgs& operator=(CATCAfrUrlViewerSYPEventArgs&);

    CATCAfrComponentControllerArg *       _pElement;
    CATUnicodeString                      _Url;

};
#endif

