/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003
#ifndef CATDocumentIntrospectionServices_H
#define CATDocumentIntrospectionServices_H

/**
 * @level Private
 * @usage U1
 */

#include <time.h>

#include "AC0XXLNK.h"
#include "CATUnicodeString.h"
#include "sequence_octet.h"

class CATIDocId;

class ExportedByAC0XXLNK CATDocumentIntrospectionServices
{
 public:

  static HRESULT GetPropertyByKeyAstime_t(CATIDocId* iDocId,const char* iKey,time_t& oTime);
  static HRESULT GetPropertyByKeyAstime_t(const SEQUENCE(octet) iSequence,const char* iKey,time_t& oTime);
  
};
#endif
