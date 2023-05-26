#ifndef CATOmbFileMenuR14Service_H
#define CATOmbFileMenuR14Service_H

/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003

/**
 * @level Private
 * @usage U1
 */

#include "CATOmbSessionService.h"

#include <stddef.h> // for NULL

#include "CATBooleanDef.h"
#include "CATDocument.h"
#include "CATOmbCluster.h"

#undef __migr_omb_0404

struct CATOmbFileMenuR14Service
{
  inline HRESULT IsReferencingDoc( CATDocument &iDoc, CATDocument &iRefDoc ) {return E_NOTIMPL;}
  inline HRESULT ListReferencingDocs( CATDocument &iDoc, CATLISTP(CATDocument) &ioReferencingDocs ) {return E_NOTIMPL;} 
  inline HRESULT GetListDocumentToSave (CATDocument &iDoc, CATLISTP(CATDocument) &ioDocsToSave ) {return E_NOTIMPL;};
};


#endif
