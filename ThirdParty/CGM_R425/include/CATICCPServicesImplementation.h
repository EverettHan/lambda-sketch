#ifndef __CATICCPServicesImplementation_h__
#define __CATICCPServicesImplementation_h__


/**
 * @level Private
 * @usage U3
 * COPYRIGHT DASSAULT SYSTEMES 2009
 */

class CATIUseEntity;
#include "CATLISTV_CATBaseUnknown.h"
#include "DataCommonProtocolUse.h" // ExportedByDataCommonProtocolUse

class CATPathElement;
class CATUnicodeString;
#include "CATCollec.h" // CATListOfCATUnicodeString
#include "CATSysErrorDef.h" // HRESULT

/**
 * Interface to implements DataCommonProtocolCCPServices services.
 * @see DataCommonProtocolCCPServices
 */
class CATICCPServicesImplementation
{
public:
  /**
   * Implements DataCommonProtocolCCPServices::CopyAndPasteTo.
   */
  virtual HRESULT CopyAndPasteTo(const CATListValCATBaseUnknown_var & iEntitiesToCopy, CATBaseUnknown * iPasteTarget, CATListValCATBaseUnknown_var & oNewEntities) = 0;

  /**
   * Implements DataCommonProtocolCCPServices::GetAvailableFormats.
   */
  virtual HRESULT GetAvailableFormats(const CATListValCATBaseUnknown_var & iEntitiesToCopy, CATBaseUnknown * iPasteTarget, CATListOfCATUnicodeString & oAvailableFormats) = 0;

  /**
   * Implements DataCommonProtocolCCPServices::CopyAndPasteSpecialTo.
   */
  virtual HRESULT CopyAndPasteSpecialTo(const CATListValCATBaseUnknown_var & iEntitiesToCopy, CATBaseUnknown * iPasteTarget, const CATUnicodeString & iFormat, CATListValCATBaseUnknown_var & oNewEntities) = 0;
};


#endif // __CATICCPServicesImplementation_h__
