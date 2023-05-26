/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATIDuplicate_h
#define CATIDuplicate_h

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
#include "CATIContainer.h"

extern ExportedByAD0XXBAS IID IID_CATIDuplicate ;

class ExportedByAD0XXBAS CATIDuplicate : public CATBaseUnknown
{
  CATDeclareInterface;

public:

    virtual CATBaseUnknown_var Duplicate( CATIContainer_var  recept ) = 0; 

};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIDuplicate, CATBaseUnknown ) ;


#endif
