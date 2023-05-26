// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIPLMFilterOrderBy.h
// Define the CATIPLMFilterOrderBy interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//  Apr 2004  Creation: Code generated by the CAA wizard  jvm
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMFilterOrderBy_H
#define CATIPLMFilterOrderBy_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATPLMTypeId.h"
#include "CATPLMOmxCollections.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMFilterOrderBy;
#else
extern "C" const IID IID_CATIPLMFilterOrderBy ;
#endif

class CATPLMType;
class CATString;

/**
 * The list returned by a query may be ordered by any attribute of a returned object Type
 */
class ExportedByCATPLMServicesItf CATIPLMFilterOrderBy: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * Returns the Object Id in which the criteria will be applied.
  * @param oObjectId
  *    The object plmId.
  */
  virtual HRESULT GetType( CATPLMType ** oObjectType) = 0;
  
  /**
  * Returns the attribute to order by
  * @param oAttrId
  *     The attributeId
  */
  virtual HRESULT GetAttributeId( CATString ** oAttrId) = 0;

  /**
  * if = 0 Ascending (A then B then C...), if = 1 descending (C then B then A...).
  * @return
  */
  virtual CATBoolean IsDescending () = 0;

  /**
  *@deprecated
  *@deprecated
  *@deprecated
  * CONTRACT OF THIS METHOD IS STUPID, PLEASE USE IsDescending!!!
  * Returns the order : Ascending or descending
  * @param oAsc
  *    if = 0 Ascending otherwise Descending
  *    if = 0 Ascending (A then B then C...), if = 1 descending (C then B then A...).
  */
  virtual HRESULT IsAscending( int * oDesc) = 0;

  /**
  * Retreives the types entered when an extension attribute is filtered.
  *
  * <br><b>Role</b>: Gets the types used.
  *
  * @param oRequestedBaseType
  *   The list of types.
  * @return
  * <dt> <code>S_OK</code>     <dd> Success.
  * <dt> <code>E_FAIL</code>   <dd> Failure. The creation type is not an extension.
  *
  */
  virtual HRESULT GetExtensionBaseTypes (CATLISTV(CATPLMTypeId)& oRequestedBaseType) = 0;

  virtual HRESULT GetExtensionBaseTypes(CATPLMTypeList& oRequestedBaseType) = 0;
};

#endif
