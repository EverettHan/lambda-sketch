#ifndef CATIPC2Extensions_H
#define CATIPC2Extensions_H

#include "CATPLMComponentInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATPLMTypeH.h"
#include "CATUnicodeString.h"

class CATOmxAny;
class CATOmxKeyString;

extern ExportedByCATPLMComponentInterfaces const IID IID_CATIPC2Extensions;

class CATPC2Entity;

/**
 * access to the extensions held by a PLM component
 */
class ExportedByCATPLMComponentInterfaces CATIPC2Extensions : public CATBaseUnknown
{
  CATDeclareInterface;
public:
  /**
   * retrieve an existing extension
   *
   * @param iModelerPassword
   *   the password of the modeler that defines the extension, if one has been defined using CATPLMClientCoreKeyRegistration, empty string otherwise.
   * @param iExtensionType
   *   the extension type
   * @return
   *   the extension if it exists
   *
   */
  virtual CATOmxSR<CATPC2Entity> GetExtension(const CATUnicodeString& iModelerPassword, const CATPLMTypeH& iExtensionType) = 0;

  /**
   * create a new extension
   *
   * @param iModelerPassword
   *   see GetExtension
   * @param iExtensionType
   *   see GetExtension
   * @return
   *   the created extension or null if it already existed or in case of error
   */
  virtual CATOmxSR<CATPC2Entity> CreateExtension(const CATUnicodeString& iModelerPassword, const CATPLMTypeH& iExtensionType) = 0;

  /**
   * delete an extension
   *
   * @param iModelerPassword
   *   see GetExtension
   * @param iExtensionType
   *   see GetExtension
   * @return
   *   true if the extension has been deleted, false in case of error
   */
  virtual bool DeleteExtension(const CATUnicodeString& iModelerPassword, const CATPLMTypeH& iExtensionType) = 0;
};

/**
 * helper on top of CATIPC2Extensions
 * allows to easily retrieve an extension attribute value
 *
 * @param iPLMComponent
 *   a PLM component
 * @param iModelerPassword
 *   see CATIPC2Extensions::GetExtension
 * @param iExtensionType
 *   see CATIPC2Extensions::GetExtension
 * @param iAttributeName
 *   see CATIPC2Extensions::GetExtension
 * @return
 *   the attribute value or default CATOmxAny if an error occured
 *   see CATPC2Entity::GetValue for more details
 */
ExportedByCATPLMComponentInterfaces
CATOmxAny CATPC2GetExtensionAttributeValue(CATBaseUnknown* iPLMComponent, const CATUnicodeString& iModelerPassword, const CATPLMTypeH& iExtensionType, const CATOmxKeyString& iAttributeName);

/**
 * helper on top of CATIPC2Extensions
 * allows to easily set an extension attribute value
 * the extension is created if necessary
 *
 * @param iPLMComponent
 *   a PLM component
 * @param iModelerPassword
 *   see CATIPC2Extensions::GetExtension
 * @param iExtensionType
 *   see CATIPC2Extensions::GetExtension
 * @param iAttributeName
 *   see CATPC2Entity::GetValue
 * @param iValue
 *   see CATPC2Entity::SetValue
 * @return
 *   true in case of success, false in case of error
 */
ExportedByCATPLMComponentInterfaces
bool CATPC2SetExtensionAttributeValue(CATBaseUnknown* iPLMComponent, const CATUnicodeString& iModelerPassword, const CATPLMTypeH& iExtensionType, const CATOmxKeyString& iAttributeName, const CATOmxAny& iValue);

#endif
