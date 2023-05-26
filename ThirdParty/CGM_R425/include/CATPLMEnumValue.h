//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef CATPLMEnumValue_H
#define CATPLMEnumValue_H

#include "VPMIDicInterfaces.h"
#include "CATSysErrorDef.h" // $$$$ CP7 2011-01-05: HRESULT definition

class CATString;
class CATUnicodeString;
class VPMIDicEnumerator;

/*
 * The following functions allow you to convert enumeration values for roles & semantics from string or
 * integer value to the actual VPMIDicEnumerator representing the enum value.
 *
 * These services expect the metadata that contains the enumeration values to be already present
 * in memory.
 */

/**
 *
 * Get the enumerator object representing the specified role enum value.
 *
 * @param iEnumValue
 *    the literal enum value
 *
 * @param oEnumValue [out, CATBaseUnknown#Release]
 *    the symbolic enumerator object representing the specified enum value
 *
 *
 *   @return
 *   An HRESULT value.
 *   <br><b>Legal values</b>:
 *   <dl>
 *     <dt>S_OK</dt>
 *     <dt>E_FAIL</dt>
 *   </dl>
 */
extern HRESULT ExportedByVPMIDicInterfaces CATPLMGetRoleEnumValue(const CATUnicodeString& iEnumValue,
                                                                  VPMIDicEnumerator *&oEnumValue);

/**
 *
 * Get the enumerator object representing the specified role enum value.
 *
 * @param iEnumValue
 *    the literal enum value
 *
 * @param oEnumValue [out, CATBaseUnknown#Release]
 *    the symbolic enumerator object representing the specified enum value
 *
 *
 *   @return
 *   An HRESULT value.
 *   <br><b>Legal values</b>:
 *   <dl>
 *     <dt>S_OK</dt>
 *     <dt>E_FAIL</dt>
 *   </dl>
 */
extern HRESULT ExportedByVPMIDicInterfaces CATPLMGetRoleEnumValue(int iEnumValue,
                                                                  VPMIDicEnumerator *&oEnumValue);

/**
 *
 * Get the enumerator object representing the specified semantics enum value.
 *
 * @param iEnumValue
 *    the literal enum value
 *
 * @param oEnumValue [out, CATBaseUnknown#Release]
 *    the symbolic enumerator object representing the specified enum value
 *
 *
 *   @return
 *   An HRESULT value.
 *   <br><b>Legal values</b>:
 *   <dl>
 *     <dt>S_OK</dt>
 *     <dt>E_FAIL</dt>
 *   </dl>
 */
extern HRESULT ExportedByVPMIDicInterfaces CATPLMGetSemanticsEnumValue(const CATUnicodeString& iEnumValue,
                                                                       VPMIDicEnumerator *&oEnumValue);

/**
 *
 * Get the enumerator object representing the specified semantics enum value.
 *
 * @param iEnumValue
 *    the literal enum value
 *
 * @param oEnumValue [out, CATBaseUnknown#Release]
 *    the symbolic enumerator object representing the specified enum value
 *
 *
 *   @return
 *   An HRESULT value.
 *   <br><b>Legal values</b>:
 *   <dl>
 *     <dt>S_OK</dt>
 *     <dd>Admin has been initialized. No release to be done</dd>
 *     <dt>E_FAIL</dt>
 *     <dd>Admin not initialized or a problem occurs during the process</dd>
 *   </dl>
 */
extern HRESULT ExportedByVPMIDicInterfaces CATPLMGetSemanticsEnumValue(int iEnumValue,
                                                                       VPMIDicEnumerator *&oEnumValue);

/**
 *
 * Check that an enumerator object really belongs to a given enum
 *
 * @param iEnumValue
 *    a symbolic enum value
 *
 * @param iEnumName
 *    the symbolic name of the enum the first parameter should be a member of.
 *
 *
 *   @return
 *   An HRESULT value.
 *   <br><b>Legal values</b>:
 *   <dl>
 *     <dt>S_OK</dt>
 *     <dt>E_FAIL</dt>
 *   </dl>
 */
extern HRESULT ExportedByVPMIDicInterfaces CATPLMCheckEnumValue(VPMIDicEnumerator *iEnumValue,
                                                                const CATString& iEnumName);

#endif /*CATPLMEnumValue_H*/
