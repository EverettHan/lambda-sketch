// (C) Copyright Dassault Systemes - 2006
// -----------------------------------------------------------------------
// Interface declaration: PLMISecMaskAttributeAccess
// -----------------------------------------------------------------------
// Creation: 2006-01-23
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMISecMaskAttributeAccess_H_
#define _PLMISecMaskAttributeAccess_H_

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMISecMaskAttributeAccess;
#else
extern "C" const IID IID_PLMISecMaskAttributeAccess;
#endif



/** @nodoc */
class ExportedByGUIDPLMPosBaseInterfaces PLMISecMaskAttributeAccess : public CATBaseUnknown
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
     * Get attribute order number.
     * @param oOrderNumber
     *    order number.
     * @return
     *   S_OK    if an order number exists.
     *   S_FALSE if no order number exists.
     *   E_FAIL  in case of error.
     */
    virtual HRESULT GetOrder(int &oOrderNumber) = 0;
    /**
     * Check whether attribute is visible.
     * Normally, when attributes have an attribute access, they are considered
     * as visible. This method should always return 1. It is there for future
     * evolution in attribute access.
     * @return
     *   1    if attribute is visible.
     *   0    otherwise.
     */
    virtual int IsVisible() = 0;
    /**
     * Check whether attribute is modifiable.
     * @return
     *   1    if modifiable.
     *   0    otherwise.
     */
    virtual int IsEditable() = 0;
};

CATDeclareHandler(PLMISecMaskAttributeAccess,CATBaseUnknown);

#endif
