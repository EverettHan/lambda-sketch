/**
* @level Private
* @usage U1
*/
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2002

#ifndef CATRestrictedServicesForCleaner_H
#define CATRestrictedServicesForCleaner_H

// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                               999
#define CATPLMComponentChecker                         AuthorizedModule
#define CATOmbLinkTrader                               AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATOxBaseDumpServices from a non-infrastructure module
@error 
#endif
#undef CATPLMComponentChecker
#undef CATOmbLinkTrader
// ----------------------------------------------------------------------------------------------------------------------

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

class ExportedByAC0XXLNK CATRestrictedServicesForCleaner
{
public:

  /**
  * Service to know if a document is a V5 document or not from a type
  * If you have the document, it's better to use IsV5Document(CATDocument * iDocument)
  * 
  * @return
  *    S_OK    : a document is a V5 document
  *    S_FALSE : a document is not a V5 document
  *    E_FAIL  : failure
  */
  static HRESULT IsV5Document (const CATUnicodeString& iDocType);
};

#endif
