// (C) Copyright Dassault Systemes - 2006
// -----------------------------------------------------------------------
// Interface declaration: PLMIPosSecurityEngineMask
// -----------------------------------------------------------------------
// Creation: 2006-01-23
// -----------------------------------------------------------------------
/**
 * @level Protected
 * @usage U3
 */

#ifndef _PLMIPosSecurityEngineMask_H_
#define _PLMIPosSecurityEngineMask_H_

#include "CATBaseUnknown.h"

#include "CATLISTV_CATBaseUnknown.h"
class CATUnicodeString;
#include "CATListOfCATUnicodeString.h"
#include "ExportedByGUIDPLMPosBaseInterfaces.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByGUIDPLMPosBaseInterfaces IID IID_PLMIPosSecurityEngineMask;
#else
extern "C" const IID IID_PLMIPosSecurityEngineMask;
#endif



/** @nodoc */
class ExportedByGUIDPLMPosBaseInterfaces PLMIPosSecurityEngineMask : public CATBaseUnknown
{
    CATDeclareInterface;
public:
    /**
     * Get available mask operations.
     * @param oOperationList
     *    list of operations
     * @return
     *   S_OK    if operations are retrieved
     *   E_FAIL  otherwise
     */
    virtual HRESULT GetAvailableOperations(CATListOfCATUnicodeString &oOperationList) = 0;
    /**
     * Get mask information of all masked attributes, whatever the operation is.
     * @param iEntityName
     *    entity name
     * @param oAttrACIList
     *    list of mask attribute information (PLMISecMaskAttributeInfo)
     * @return
     *   S_OK    if entity is masked (has some attributes masked)
     *   S_FALSE if entity is not masked
     *   E_FAIL  on error
     */
    virtual HRESULT GetAttributeList(const CATUnicodeString &iEntityName, CATLISTV(CATBaseUnknown_var) &oAttrList) = 0;
    /**
     * Get mask information of all masked attributes, whatever the operation is.
     * @param iEntityName
     *    entity name
     * @param iOperation
     *    operation name
     * @param oAttrACIList
     *    list of mask attribute access information (PLMISecMaskAttributeAccess).
     *    The list is ordered.
     * @return
     *   S_OK    if entity is masked (has some attributes masked)
     *   S_FALSE if entity is not masked
     *   E_FAIL  on error
     */
    virtual HRESULT GetAttributeACIList(const CATUnicodeString &iEntityName, const CATUnicodeString &iOperation, CATLISTV(CATBaseUnknown_var) &oAttrACIList) = 0;
};

CATDeclareHandler(PLMIPosSecurityEngineMask,CATBaseUnknown);

#endif
