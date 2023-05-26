// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIPLMFilterFunction.h
// Define the CATIPLMFilterFunction interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Jan 2008  Creation: TBF
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMFilterFunction_H
#define CATIPLMFilterFunction_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATVariant.h"
#include "CATLISTV_CATPLMTypeId.h"
#include "AttrTypes.h"
#include "CATOmxAny.h"
#include "CATPLMOmxHelpers.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMFilterFunction;
#else
extern "C" const IID IID_CATIPLMFilterFunction ;
#endif

class CATUnicodeString;
class CATString;
class CATPLMType;
class CATBinary;
class CATTime;
class CATIPLMFunction;
class CATPLMFunction;

/**
* The attribute filter allows you to narrow the list of objects returned by attribute.
*/
class ExportedByCATPLMServicesItf CATIPLMFilterFunction: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Returns the operator applied to the attribute condition.
  * @param oFunction
  *     The Function. It is allocated on the heap by the callee.
  */
  virtual HRESULT GetFunction( CATIPLMFunction ** oFunction) = 0;

  /**
  * Returns the operator applied to the attribute condition.
  * @param oOperator
  *     The Operator. It is allocated on the heap by the callee.
  */
  virtual HRESULT GetOperator( CATUnicodeString ** oOperator) = 0;

  /**
  * @deprecated
  */
  virtual HRESULT SetValues( CATUnicodeString * iValue, CATUnicodeString * iEndValue=NULL ) = 0;

  /**
  * @deprecated
  */
  virtual HRESULT SetValues( CATBoolean *iValue, CATBoolean * iEndValue=NULL ) = 0;

  /**
  * Sets a value and an end value if required to match by the filter attribute.
  * Use CATPLMOmxHelpers to fill CATOmxAny
  * If returned type of CATIPLMFunction is a binary, use CATPLMOmxHelpers::SetBinary
  * If returned type of CATIPLMFunction is a Date, use CATPLMOmxHelpers::SetDate
  * 
  * @param iValue [in]
  * 
  * @param iEndValue [in]
  * 
  * @return
  * <dl>
  * <dt><code>S_OK</code> <dd>
  * <dt><code>E_FAIL</code> <dd>
  * </dl>
  */
  virtual HRESULT SetValues( const CATOmxAny &iValue, const CATOmxAny &iEndValue = CATOmxAny()) = 0;

  /**
  * Get value(s) to match by the filter function.
  *
  * Use CATPLMOmxHelpers to fill CATOmxAny
  * If oAttrType is a PLMTYPE_BINARY, use CATPLMOmxHelpers::GetBinary
  * If attribute is a PLMTYPE_DATE, use CATPLMOmxHelpers::GetDate
  *
  * @param oValue [out]
  *   The value of the filter attribute.
  * @param oTypes [out]
  *   
  * @param oIsAnyMulti [out]
  *   
  * @return
  * <dt> <code>S_OK</code>     <dd> Success.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  *
  */
  virtual HRESULT GetValue(CATOmxAny & oValue,AttrTypes& oTypes,CATBoolean& oIsAnyMulti) = 0;

  /**
  * @deprecated
  */
  virtual HRESULT GetValue(CATUnicodeString** opValue) = 0;

  /**
  * @deprecated
  */
  virtual HRESULT GetValues(CATUnicodeString* opValue) = 0;

  /**
  * Get value(s) to match by the filter function.
  *
  * Use CATPLMOmxHelpers to fill CATOmxAny
  * If oAttrType is a PLMTYPE_BINARY, use CATPLMOmxHelpers::GetBinary
  * If attribute is a PLMTYPE_DATE, use CATPLMOmxHelpers::GetDate
  *
  * @param oValue [out]
  *   The value of the filter attribute.
  * @param oAttrType [out]
  *   The type of the filter attribute.
  * @param oIsAnyMulti [out]
  *   oValue stores a list or not.
  *
  * @return
  * <dt> <code>S_OK</code>     <dd> Success.
  * <dt> <code>E_FAIL</code>   <dd> Failure.
  */
  virtual HRESULT GetEndValue(CATOmxAny & oValue,AttrTypes& oTypes,CATBoolean& oIsAnyMulti) = 0;

  /**
  * @deprecated
  */
  virtual HRESULT GetEndValue(CATUnicodeString** opValue) = 0;

};

#endif
