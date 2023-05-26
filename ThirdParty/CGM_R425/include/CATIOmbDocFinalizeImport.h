//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2010
//-----------------------------------------------------------------------------
// This interface implemented by CATDocument modify the document to apply materials.
//-----------------------------------------------------------------------------
// Usage Notes:
// During the import of a 3DXMLFR (FR = For Review) in session,
// we need to apply materials on each CATDocument (type CGR) stored 
// into a Rep Reference (core2 modele). This interface implemented by CATDocument
// modify the document to apply materials. Implementation of this interface is
// delegated to team responsible for material.
//
//-----------------------------------------------------------------------------
// Creation : July 2010 EPB
//-----------------------------------------------------------------------------

#ifndef CATIOmbDocFinalizeImport_H
#define CATIOmbDocFinalizeImport_H

/**
 * @level Private
 * @usage U3
 */

#include "CATOmbSelectiveLoading.h"
#include "CATBaseUnknown.h"

class CATUuid;

extern ExportedByCATOmbSelectiveLoading IID IID_CATIOmbDocFinalizeImport;

class ExportedByCATOmbSelectiveLoading CATIOmbDocFinalizeImport : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  virtual HRESULT FinalizeImport() = 0 ;
};

CATDeclareHandler( CATIOmbDocFinalizeImport, CATBaseUnknown ) ;

#endif 

