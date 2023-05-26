
#ifndef __CATIOmxDebugServices_h__
#define __CATIOmxDebugServices_h__

/**
 * @level Protected
 * @usage U1
 */

#include "CATOmxKernel.h"
#include "CATOmxSharable.h"
#include "CATOmxSR.h"

class CATUnicodeString;

class CATIOmxDebugServices : public CATOmxSharable
{
public:
  virtual CATUnicodeString CatalogToFramework(const CATUnicodeString & iCatalogName) const = 0;
  virtual CATUnicodeString CatalogToResponsible(const CATUnicodeString & iCatalogName) const = 0;
  virtual CATUnicodeString FrameworkToResponsible(const CATUnicodeString & iFramworkName) const = 0;

  // Main access.
  // The data files will be parsed each time this method is called,
  // and the result will be kept in memory until the service class is released.
  // Beware of cpu vs. memory trade-off.
  static CATOmxSR<CATIOmxDebugServices> ExportedByCATOmxKernel GetDebugServices();
};


#endif // __CATIOmxDebugServices_h__
