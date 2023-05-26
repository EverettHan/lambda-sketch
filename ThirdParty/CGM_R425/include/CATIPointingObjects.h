/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIPointingObjects_h
#define CATIPointingObjects_h

/**
 * @level Private
 * @usage U3
 */

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"

class CATListValCATBaseUnknown_var;

extern ExportedByCATObjectModelerBase IID IID_CATIPointingObjects ;

class ExportedByCATObjectModelerBase CATIPointingObjects : public CATBaseUnknown
{
  CATDeclareInterface;

public:

    virtual HRESULT ListPointingObjects ( CATListValCATBaseUnknown_var& liste ) = 0; 

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIPointingObjects, CATBaseUnknown ) ;


#endif
