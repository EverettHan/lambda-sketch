// COPYRIGHT DASSAULT SYSTEMES 2011
//=============================================================================
//
// CATAfrDnDStyle
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// Sep. 2011                                                            T. Pech
//=============================================================================
#ifndef CATAfrDnDStyle_H
#define CATAfrDnDStyle_H

#include "CATAfrItf.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATCAfrEnum.h"

//-----------------------------------------------------------------------------
class ExportedByCATAfrItf CATAfrDnDStyle
{
  public:
    // Standard constructors
    // ---------------------
    CATAfrDnDStyle( );
    virtual ~CATAfrDnDStyle ();

    AfrDnDStyle& GetStyles( );
    void SetStyles( const AfrDnDStyle& iDnDStyle );

    // Copy constructor and equal operator
    // -----------------------------------
    CATAfrDnDStyle (const CATAfrDnDStyle &i_original);
    CATAfrDnDStyle& operator=(const CATAfrDnDStyle& i_original);

    CATBoolean operator==(const CATAfrDnDStyle& i_right) const;
    CATBoolean operator!=(const CATAfrDnDStyle& i_right) const;

  private:
    AfrDnDStyle       _Style;

};
//-----------------------------------------------------------------------
#include "CATSYPDeclareBoxing.h"
CATSYP_DECLARE_BOXING( ExportedByCATAfrItf, CATAfrDnDStyle );

#include <CATSYPFactoryResult.h>
extern "C" ExportedByCATAfrItf 
  CATSYPFactoryResult CATSYPCATAfrDnDStyleFactory(const CATUnicodeString& i_string);
#endif
