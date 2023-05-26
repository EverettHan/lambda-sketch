/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIUntie_h
#define CATIUntie_h

/**
 * @level Private
 * @usage U3
 */

#include "CATObjectModelerBase.h"
#include "CATBaseUnknown.h"
class CATBaseUnknown_var;

extern ExportedByCATObjectModelerBase IID IID_CATIUntie ;

class ExportedByCATObjectModelerBase CATIUntie : public CATBaseUnknown
{
  CATDeclareInterface;

public:

    virtual HRESULT Untie ( const CATBaseUnknown_var& pointed ) = 0; 

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIUntie, CATBaseUnknown ) ;


#endif
