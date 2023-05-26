// (C) Copyright Dassault Systemes - 2006
// -----------------------------------------------------------------------
// Interface declaration: PLMISecMaskAttributeInfo
// -----------------------------------------------------------------------
// Creation: 2006-01-23
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMISecMaskAttributeInfo_H_
#define _PLMISecMaskAttributeInfo_H_

#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMISecMaskAttributeInfo;
#else
extern "C" const IID IID_PLMISecMaskAttributeInfo;
#endif



/** @nodoc */
class ExportedByGUIDPLMPosBaseInterfaces PLMISecMaskAttributeInfo : public CATBaseUnknown
{
    CATDeclareInterface;
public:
    /**
     * Get attribute name.
     * @param oValue
     *    attribute name
     * @return
     *   S_OK    if the name was retrieved
     *   E_FAIL  in case of error
     */
    virtual HRESULT GetName(CATUnicodeString &oValue) = 0;
    /**
     * Get default value.
     * @param oValue
     *    default value
     * @return
     *   S_OK    if a default value exists and was retrieved
     *   S_FALSE if no default value exists
     *   E_FAIL  in case of error
     */
    virtual HRESULT GetDefaultValue(CATUnicodeString &oValue) = 0;
    /**
     * Check whether attribute is mandatory or not.
     * @return
     *   1    if attribute is mandatory
     *   0 if attribute is optional
     */
    virtual int IsMandatory() = 0;
    /**
     * Check whether list of values are authorized or help values.
     * @return
     *   1    if authorized/help values are authorized values
     *   0    if authorized/help values are help values
     */
    virtual int HasAuthorizedValues() = 0;
    /**
     * Get authorized/help values.
     * @param oValues
     *    list of authorized/help values
     * @return
     *   S_OK    if authorized/help values exist and were retrieved
     *   S_FALSE if no authorized/help value exists
     *   E_FAIL  in case of error
     */
    virtual HRESULT GetAuthorizedValues(CATListOfCATUnicodeString &oValues) = 0;
};

CATDeclareHandler(PLMISecMaskAttributeInfo,CATBaseUnknown);

#endif
