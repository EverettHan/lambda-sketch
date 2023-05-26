/*
 * CATOmyAllInOneOffline.h
 *
 *  Created on: Nov 14, 2012
 *      Author: PJQ
 */

#ifndef CATADPALLINONEOFFLINE_H_
#define CATADPALLINONEOFFLINE_H_
#include "CATSysErrorDef.h"
#include "CATPLMIntegrationAccess.h"
class CATPLMBag;
class CATUnicodeString;

class ExportedByCATPLMIntegrationAccess CATAdpAllInOneOffline
{
public:
  static HRESULT Init(CATPLMBag & iBag,
      const CATUnicodeString & iRepository, // PLM1
      const CATUnicodeString & iUserID,
      const CATUnicodeString & iUserPasswd,
      const CATUnicodeString & iRole,
      const CATUnicodeString & iHost,       // server:port
      const CATUnicodeString & iUri,        // ematrix/enovia
      const CATUnicodeString & iProtocol);  // http/hpps
};

#endif
