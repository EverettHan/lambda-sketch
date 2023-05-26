// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATIPLMFilterAttribute.h
// Define the CATIPLMFilterAttribute interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//  Apr 2004  Creation: jsy
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMFilterAttribute_H
#define CATIPLMFilterAttribute_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATVariant.h"
#include "CATBoolean.h"
#include "CATLISTV_CATPLMTypeId.h"
#include "CATPLMOmxCollections.h"
#include "CATOmxAny.h"
#include "AttrTypes.h"
#include "CATPLMOmxHelpers.h"
#include "CATPLMQueryFilterEnum.h"
#include "CATPLMTypeHArray.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesItf IID IID_CATIPLMFilterAttribute;
#else
extern "C" const IID IID_CATIPLMFilterAttribute ;
#endif

class CATUnicodeString;
class CATString;
class CATPLMType;
#include "CATCollec.h"
class CATLISTP(CATPLMType);
class CATBinary;
class CATTime;

/**
 * The attribute filter narrows the list of objects returned on a query or expand.
 * The attribute filter is added to the QueryFilter by the APIs CATIPLMFilterCriteria/CATIPLMFilterCondition::(Create/Add)FilterAttributeWithPath
 * It defines on which attribute the filter applies, and the operator.
 * This interface is then used to associate values to the filter, or to query information.
 */
class ExportedByCATPLMServicesItf CATIPLMFilterAttribute: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Returns on which Object Type the filter attribute is defined
  * @param oObjectType [out, CATBaseUnknown#Release]
  *    The returned object Type
  */
  virtual HRESULT GetType( CATPLMType ** oObjectType) = 0;

  /**
  * Returns the attribute of your condition. 
  * @param oAttrId
  *     The attributeId. It is allocated on the heap by the callee.
  */
  virtual HRESULT GetAttributeId(CATString& oAttrId) = 0;

  /**
  * Returns the operator applied to the attribute filter.
  * @param oOperator
  *     The Operator.
  */
  virtual HRESULT GetOperator( RelationalOperator::Op &oOperator) = 0;

  /**
  * Sets the value and the end value (if required) of the attribute filter.
  * For CATTime signature, the provided date must be between 1970 and 2038.     
  *
  * @param iValue [in]
  *   The value.
  * @param iEndValue[in]
  *   The end value.
  * @return
  * S_OK               Success.
  * E_INVALIDARG       iValue is a NULL ptr.
  * E_INVALIDTYPE      Using a signature with a type that does not correspond to the type of the filtered attribute.
  * E_INVALIDENDVALUE  Specifying an iEndValue for operator other than BETWEEN NOT_BETWEEN.
  * E_FAIL             Other Not documented failure.
  *
  */
  virtual HRESULT SetValues( int * iValue, int * iEndValue=NULL ) = 0;
  virtual HRESULT SetValues( double * iValue, double * iEndValue=NULL ) = 0;
  virtual HRESULT SetValues( CATTime * iValue, CATTime * iEndValue=NULL ) = 0;
  virtual HRESULT SetValues( CATUnicodeString * iValue, CATUnicodeString * iEndValue=NULL ) = 0;
  virtual HRESULT SetValues( CATBinary * iValue, CATBinary * iEndValue=NULL ) = 0;
  virtual HRESULT SetValues( CATBoolean *iValue, CATBoolean * iEndValue=NULL ) = 0;
  virtual HRESULT SetValues( bool *iValue, bool *iEndValue = NULL) = 0;

  /**
  * Sets the value and the end value (if required) of the attribute filter.
  * This signature of the API can also be used to associate a list of values.
  *
  * Use CATPLMOmxHelpers to fill CATOmxAny
  * If attribute is a Binary, use CATPLMOmxHelpers::SetBinary
  * If attribute is a Date, use CATPLMOmxHelpers::SetDate
  * 
  * @param iValue [in]
  * 
  * @param iEndValue [in]
  *   iEndValue is filled only for operator BETWEEN or NOT_BETWEEN. It cannot contain a list of values.
  *
  * @return 
  * S_OK
  * E_INVALIDTYPE      The type of iValue (iEndValue) does not correspond to the type of the filtered attribute.
  * E_INVALIDENDVALUE  Specifying an iEndValue for operator other than BETWEEN NOT_BETWEEN.
  * E_INVALIDMULTIVAL  Specifying a multivalued value on an operator that does not support it
  *                    (the only operators supporting multivalued value are IN and CONTAINS_ONE_OF)
  * E_FAIL
  * 
  */
  virtual HRESULT SetValues( const CATOmxAny & iValue, const CATOmxAny & iEndValue=CATOmxAny() ) = 0;  

  /** 
  * Get value of the attribute filter.
  * Only applies to single value, use signature with CATOmxAny for list.
  *
  * @param oValue [out]
  *   The value of the filter attribute.
  *
  * @return
  * S_OK              Success.
  * E_FAIL            The value of the attribute filter has not been defined.
  * E_INVALIDTYPE     Using a signature of the non adequate type. 
  * E_INVALIDMULTIVAL The value is a list.
  */
  virtual HRESULT GetValue( int & oValue ) = 0;
  virtual HRESULT GetValue( double & oValue) = 0;
  virtual HRESULT GetValue( CATTime & oValue) = 0;
  virtual HRESULT GetValue( CATUnicodeString & oValue) = 0;
  virtual HRESULT GetValue( CATBinary & oValue) = 0;
  virtual HRESULT GetValue( CATBoolean & oValue) = 0;
  virtual HRESULT GetValue( bool& oValue) = 0;

  /** 
  * Get value(s) of the attribute filter.
  * Also applies to list of values.
  * Use CATPLMOmxHelpers::GetXXX to get a typed value from the returned CATOmxAny.
  * If oAttrType is a PLMTYPE_BINARY, use CATPLMOmxHelpers::GetBinary
  * If attribute is a PLMTYPE_DATE, use CATPLMOmxHelpers::GetDate
  * If value is not filled kind of oValue is omx_void
  *
  * @param oValue [out]
  *   The value of the filter attribute.
  * @param oAttrType [out]
  *   The type of the filter attribute.
  * @param oIsAnyMulti [out]
  *   oValue stores a list or not.
  *
  * @return
  * S_OK     Success.
  * E_FAIL   The value of the attribute filter has not been defined.
  */
  virtual HRESULT GetValue(CATOmxAny & oValue,AttrTypes& oAttrType,CATBoolean& oIsAnyMulti) = 0;
  
  /** 
  * Get end value of the attribute filter.
  *
  * @param oValue [out]
  *   The end value of the filter attribute.
  *
  * @return
  * S_OK          Success.
  * E_FAIL        The end value of the attribute filter has not been defined.
  * E_INVALIDTYPE Using a signature with a type that does not correspond to the type of the filtered attribute.
  */
  virtual HRESULT GetEndValue( int & oValue ) = 0;
  virtual HRESULT GetEndValue( double & oValue) = 0;
  virtual HRESULT GetEndValue( CATTime & oValue) = 0;
  virtual HRESULT GetEndValue( CATUnicodeString & oValue) = 0;
  virtual HRESULT GetEndValue( CATBinary & oValue) = 0;
  virtual HRESULT GetEndValue( CATBoolean & oValue) = 0;
  virtual HRESULT GetEndValue( bool & oValue) = 0;

  /**
  * Get end value of the attribute filter.
  * The only attributes filters with end values are for the operators BETWEEN, NOT_BETWEEN
  * Use CATPLMOmxHelpers::GetXXX to get a typed value from the CATOmxAny.
  * If oAttrType is a PLMTYPE_BINARY, use CATPLMOmxHelpers::GetBinary
  * If attribute is a PLMTYPE_DATE, use CATPLMOmxHelpers::GetDate
  * If attribute is not filled kind of oValue is omx_void
  *
  * @param oValue [out]
  *   The value of the filter attribute.
  * @param oAttrType [out]
  *   The type of the filter attribute.
  * @param oIsAnyMulti [out]
  *   Always FALSE since EndValue can not be a list.
  *
  * @return
  * S_OK     Success.
  * E_FAIL   The end value of the attribute filter has not been defined.
  */
  virtual HRESULT GetEndValue(CATOmxAny& oValue,AttrTypes& oAttrType,CATBoolean& oIsAnyMulti) = 0;

  /**
  * Use for attribute filter corresponding to an extension
  * Set (and restrict) on which extended types this attribute filter will apply
  *
  * @param iRequestedBaseType
  *   The list of extended types.
  * @return
  * S_OK   Success.
  * E_FAIL The filter type is not an extension.
  * E_INCOMPATIBLETYPES iRequestedBaseType contains type(s) that the extension is not declared extending in metadata
  */
  virtual HRESULT SetExtensionBaseTypes (const CATLISTV(CATPLMTypeId) &iRequestedBaseType) = 0;
  virtual HRESULT SetExtensionBaseTypes (const CATLISTP(CATPLMType) &iRequestedBaseType) = 0;
  virtual HRESULT SetExtensionBaseTypes (const CATPLMTypeList &iRequestedBaseType) = 0;

  /**
  * Retrieves the list of extended types that a filter attribute on extension is declared extending.
  *
  * NB This returns the extended types declared by a call to SetExtensionBaseTypes.
  *    Not the types that the extension is declared to extend in meta data, 
  *    types that you can get by a call to CATPLMType::ListExtendedType
  *
  * @param oRequestedBaseType
  *   The list of types.
  * @return
  * S_OK   Success.
  * E_FAIL Failure. This is not a filter attribute on extension.
  */
  virtual HRESULT GetExtensionBaseTypes (CATLISTV(CATPLMTypeId) &oRequestedBaseType) = 0;
  virtual HRESULT GetExtensionBaseTypes (CATPLMTypeList &oRequestedBaseType) = 0;

  /**
  * @see CATIPLMFilterAttribute#GetTypePath
  */
  virtual HRESULT GetTypePath(CATPLMTypeList& iRequestedTypePath) = 0;
  virtual HRESULT GetTypePath(CATPLMTypeHArray& iRequestedTypePath) = 0;
  virtual HRESULT GetTypePath(CATLISTV(CATPLMTypeId) &oRequestedTypePath) = 0;

  /**
  * Checks if a filter on attribute is always TRUE
  */
  virtual CATBoolean IsAlwaysTrue () = 0;

   /*******************************************************************************************************************************************
   *
   *  All the APIs below are deprecated, use instead as documented the non deprecated version
   *
   *******************************************************************************************************************************************/
  
  /**
  * @deprecated  R419
  * use instead the signature with CATString&
  * @param oAttrId. Allocated by the callee, the caller need to delete if not NULL
  */
  virtual HRESULT GetAttributeId( CATString ** oAttrId) = 0;

  /**
  * @deprecated R419
  * use instead the signature with RelationalOperator::Op
  * @param oOperator is allocated by the callee, the caller need to delete if not NULL
  */
  virtual HRESULT GetOperator( CATUnicodeString ** oOperator) = 0;

  /**
  * @deprecated R419
  * Not able to know if EndValue is filled or not.
  * Use instead GetValue and GetEndValue.
  */
  virtual HRESULT GetValues( int * oValue, int * oEndValue=NULL ) = 0;
  virtual HRESULT GetValues( double * oValue, double * oEndValue=NULL ) = 0;
  virtual HRESULT GetValues( CATTime * oValue, CATTime * oEndValue=NULL ) = 0;
  virtual HRESULT GetValues( CATUnicodeString * oValue, CATUnicodeString * oEndValue=NULL ) = 0;
  virtual HRESULT GetValues( CATBinary ** oValue, CATBinary ** oEndValue=NULL ) = 0;
  virtual HRESULT GetValues( CATBoolean * oValue, CATBoolean * oEndValue=NULL ) = 0;
  virtual HRESULT GetValues( bool* oValue, bool* oEndValue = NULL) = 0;
  virtual HRESULT GetValues( CATVariant ** oValue, CATVariant ** oEndValue=NULL ) = 0;

  /**
  * @deprecated V5R201
  * use instead the signature with CATUnicodeString&.
  * @param oValue is allocated by the callee, the caller need to delete if not NULL
  */
  virtual HRESULT GetValue( CATUnicodeString ** oValue) = 0;

  /**
  * @deprecated V5R201
  * use instead the signature with CATUnicodeString&.
  * @param oValue is allocated by the callee, the caller need to delete if not NULL
  */
  virtual HRESULT GetEndValue( CATUnicodeString ** oValue) = 0;

 /**
  * @deprecated R419
  * use instead the signature with CATOmxAny.
  */
  virtual HRESULT SetValues( CATVariant * iValue, CATVariant * iEndValue=NULL ) = 0;

  /**
  * @deprecated R419
  * Combined filter
  * Construct directly the FilterAttribute with path using API CATIPLMFilterCriteria/CATIPLMFilterCondition::(Create/Add)FilterAttributeWithPath
  */
  virtual HRESULT SetTypePath(const CATPLMTypeHArray& iRequestedTypePath) = 0;
  virtual HRESULT SetTypePath(const CATPLMTypeList& iRequestedTypePath) = 0;
  virtual HRESULT SetTypePath(const CATLISTV(CATPLMTypeId) &iRequestedTypePath) = 0;

  /**
  * <=> GetType( CATPLMType ** oObjectType) if oObjectType is a base type
  * <=> GetExtensionBaseTypes if oObjectType is an extension type
  */
  virtual HRESULT ListBaseType(CATPLMTypeList& olBaseType) = 0;
  virtual HRESULT ListBaseType(CATPLMTypeHArray& olBaseType) = 0;
  virtual HRESULT ListBaseType(CATLISTV(CATPLMTypeId)& olBaseTypeId) = 0;

  /**
  * <=> Suppose you have GetType( CATPLMType ** oObjectType) with oObjectType that is a base type, then oBaseTypeList contains one element oObjectType and opExtType==NULL.
  * <=> Suppose you have GetType( CATPLMType ** oObjectType) with oObjectType that is an extension type, then oBaseTypeList the list returned by GetExtensionBaseTypes and opExtType==oObjectType
  *
  * @param opExtType [out, CATBaseUnknown#Release]
  */
  virtual HRESULT ListType(CATPLMTypeList& oBaseTypeList, CATPLMType*& opExtType) = 0;

};

#endif
