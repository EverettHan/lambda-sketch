#ifndef CATIPLMVersionInput_H
#define CATIPLMVersionInput_H

#include "CATBaseUnknown.h"
#include "CATPLMIntegrationInterfaces.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxCollecManager.h"
#include "CATPLMVersionOptions.h"

class CATPLMID;
class CATUnicodeString;
class CATOmxKeyValueBlock;
class CATPLMTypeH;
class CATIPLMAttributeSet;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMVersionInput;
#else
extern "C" const IID IID_CATIPLMVersionInput;
#endif

/**
* This interface is dedicated to version graph process
*
* It is needed to provide input parameters to @href CATIPLMVersionGraph protocol.
* It enables the user to give information about a component which will be versioned such as identification, intent or overloaded attributes.
* Version Input should be unique for each PLMID/Intent couple.
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMVersionInput : public CATBaseUnknown
{
  CATDeclareInterface;
public:
/**
 * factory
 * @param iId: the identifier of the component which will be versioned.
 * @param iIntent: the intent needed to specialize the versioning operation.
 * @output oObj: the created object. Use @href CATBaseUnknown#Release when useless.
 */
  static HRESULT Create(const CATPLMID & iId, const CATUnicodeString & iIntent, CATIPLMVersionInput*& oObj);

/**
 * Add a set of attributes to be valuated on the new component which will be created by the server transaction.
 * @param iAttributes: the set of attributes to valuate on the created component.
 */
  virtual HRESULT AddAttributes(const CATOmxKeyValueBlock & iAttributes) = 0;


/**
 * Add a set of extension attributes to be valuated on the new component which will be created by the server transaction.
 * @param iExtensionType: the plm type of the extension on which the attributes must be valuated for this new component.
 * @param iExtensionAttributes: the set of attributes to valuate on the extension.
 */
  virtual HRESULT AddExtensionAttributes(const CATPLMTypeH & iExtensionType, const CATOmxKeyValueBlock & iExtensionAttributes) = 0;

  /*
  * It is preferred and more optimal to use CATOmxKeyValueBlock versions.
  */
  virtual HRESULT AddAttributes(const CATIPLMAttributeSet & iAttributes) = 0;

  /*
  * The new version will be created, initialized with the contents from the existing element specified.
  * It must be from the same PLM type as the versioned component.
  * It's the element the content is injected from. Versioning operation is done to the element specified in the Create method.
  * @param iContentFrom: the plmid from which to copy the content to the versioned item
  * Restrictions:
  * <ul>
  * <li>The element must exist</li>
  * <li>The element must be from the same type as the versioned component</li>
  * </ul>
  *
  */
  virtual void NewVersionFromContent(const CATPLMID &iContentFrom) = 0;

  /*
  * Add an intent from another element.
  * @param iIntent: the intent linking this id and the versioned id
  * @param iFrom: the element linked to the created element
  */
  virtual void NewIntentFrom(const CATUnicodeString & iIntent, const CATPLMID &iFrom) = 0;


  /*
  * Add options to change behavior on some attributes management.
  * If not called, or if called with DEFAULT value, it will use the default behaviour (keep or reset) as defined by each primary intent.
  * @param iAttrsToKeepMask : Preserve configuration information from source object (Keep). Use a mask with | (ex : ORGANIZATION | COLLABSPACE etc.)
  * @param iAttrsToResetMask  : Will generate new attribute (Reset) Use a mask with | (ex : ORGANIZATION | COLLABSPACE etc.)
  * @return E_* if you specified the same attribute on keep and reset, S_* else
  */
  //THIS IS NOT YET IMPLEMENTED, DO NOT EXCEPT ANYTHING YET PLEASE
  virtual HRESULT KeepOrReset(const CATPLMVersionOptions::KeepOrReset &iAttrsToKeepMask, const CATPLMVersionOptions::KeepOrReset &iAttrsToResetMask) = 0;
  
};

template<>
CATOmxCollecManager& CATOmxDefaultCollecManager<CATIPLMVersionInput*>::manager();


#endif
