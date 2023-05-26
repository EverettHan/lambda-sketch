// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMAttribute.h
// Header definition of CATPLMAttribute
//
//===================================================================
//
// Usage notes:
//    describes simple attribute of an object type
//
//===================================================================
//  May 2003  Creation: jvm
//===================================================================
/**
* @level Protected
* @usage U1
*/
#ifndef CATPLMAttribute_H
#define CATPLMAttribute_H

#include "CATPLMServicesItf.h"
#include "CATBaseUnknown.h"
#include "CATPLMBaseObject.h"
#include "CATListOfCATUnicodeString.h"
#include "CATVariant.h"
#include "CATPLMMask.h"
#include "CATOmxArray.h"
#include "AttrTypes.h"
#include "CATOmxOHMap.h"
#include "CATIAV5Level.h"

class CATUnicodeString;
class CATString;
class CATIPLMProviderDesc;
class VPMIDicUsingAttributeMask;
class CATPLMAttributeInternal;
class CATPLMType;


/** Visibility supported by CATPLMAttribute.
* @see GetVisibility ( CATPLMAttrVisibility * oVisibility);
*/
enum CATPLMAttrVisibility
{
  /** MODELER Only */
  CATPLMAttrVisibilityModeler = 0,
  /** USER */
  CATPLMAttrVisibilityUser = 1
};

/** Exposition supported by CATPLMAttribute.
* @see GetExposition ( CATPLMAttrExposition * oExposition);
*/
enum CATPLMAttrExposition
{
  /** FREE */
  CATPLMAttrExpositionFree = 0,
  /** EXTERNAL */
  CATPLMAttrExpositionExternal = 1,
  /** INTERNAL */
  CATPLMAttrExpositionInternal = 2
};

enum CATPLMAttrProtection
{
  CATPLMAttrUndefined = 0
  , CATPLMAttrUser = 1
  , CATPLMAttrFree = 2
  , CATPLMAttrExternal = 3
  , CATPLMAttrExternalIN = 4
  , CATPLMAttrExternalRO = 5
  , CATPLMAttrInternal = 6
  , CATPLMAttrInternalRO = 7
  , CATPLMAttrPrivate = 8
};

/** Client editability supported by CATPLMAttribute.
* @see GetClientEditability  ( CATPLMAttrClientEditability * oExposition);
*/
enum CATPLMAttrClientEditability
{
  /** READ WRITE */
  CATPLMAttrClientEditabilityRW = 0
  /** READ ONLY */
  , CATPLMAttrClientEditabilityRO = 1
};


/**
* CAAExposition mode (valid only for attributes which Exposition is set to either Free, External or External_RO).
*/
enum CATPLMAttrCAAExposition
{
  /**   The CAAEXPOSITION is "Undefined" because .....*/
  CATPLMAttrCAAExpositionUNDEFINED = 0
  /**   The CAAEXPOSITION of the attribute is "L0".*/
  , CATPLMAttrCAAExpositionL0 = 1
  /**   The CAAEXPOSITION of the attribute is "L1".*/
  , CATPLMAttrCAAExpositionL1 = 2
};

enum CATPLMAttrExchangeTag
{
  /** The ExchangeTag of the attribute is "CollaborativeDesign".*/
  CATPLMAttrExchangeTagCollaborativeDesign = 0
  /** The ExchangeTag of the attribute is "ExtendedEnterprise".*/
  , CATPLMAttrExchangeTagExtendedEnterprise = 1
};

enum CATPLMAttributeDefLevel
{
  eBasic = 1,
  eDefinedOnType = 2
};

/**
* CATPLMAttribute class describes simple attribute of an object type
*/
class ExportedByCATPLMServicesItf CATPLMAttribute : public CATPLMBaseObject//CATBaseUnknown
{
  friend class CATPLMType;
  friend class CATAdpProtectedDictionaryServices;
  friend class CATPLMxMetaData;
  friend class CATPLMxMetaDataTypesProcessor;
  friend class CATPLMTypeAttributesLoader;
  friend class TSTCATPLMStandardMaskTestPLMProductDS_V_Supplier_V_nature;

  CATDeclareClass;

public:

  // Standard constructors and destructors
  // -------------------------------------
  CATPLMAttribute(CATString *iAttributeId,
    CATUnicodeString *iAlias,
    CATIPLMProviderDesc * iProvider,
    CATListOfCATUnicodeString *iOperators = NULL,
    CATVariant *iAuthorizedValueArray = NULL,
    CATString * iAuthorizedValueIds = NULL,
    int iAuthorizedValSize = 0,
    CATVariant *iHelpValueArray = NULL,
    CATString * iHelpValueIds = NULL,
    int iHelpValSize = 0,
    CATVariant *iDefaultValue = NULL,
    CATUnicodeString *iUnit = NULL,
    int iMandatory = 0,
    int iWriteEnable = 1,
    int iVisible = 1,
    int iPLMImpacting = 1,
    int iMultiValuated = 0,
    AttrTypes iForcedType = PLMTYPE_STRING,
    short iMask = 0);

  CATPLMAttribute(VPMIDicUsingAttributeMask * iAttribute, CATIPLMProviderDesc * iProvider, CATListOfCATUnicodeString *iOperators = NULL);
  CATPLMAttribute(VPMIDicUsingAttributeMask * iAttribute, CATIPLMProviderDesc * iProvider, const CATOmxArray<CATUnicodeString> &iOperators);
  virtual ~CATPLMAttribute();

  /**
  * Name of attribute (IT IS NOT NLS VALUE)
  * eg: Here you retrieve V_Name. NLS value of V_Name is Title. You don't retrieve Title using this method
  * How can I retrieve Title?
  * I assume that you have
  * 1- A CATIType (use CATPLMTypeH to convert a CATPLMType into a CATIType).
  * 2- A string using CATPLMAttribute::GetId().
  * Here is what you have to do:
  * 1- Do a QueryInterface on CATIType to retrieve a CATIAttributesDescription.
  * 2- Call CATIAttributesDescription::FindByName using string (result of CATPLMAttribute::GetId()). You retrieve a CATAttributeInfos.
  * 3- Call static HRESULT CATAttributeInfos::GetNLSName(const CATIType_var &iType,const CATAttributeInfos &iAttribute,CATUnicodeString &oNLSName).
  */
  HRESULT GetId(CATString **oId);

  HRESULT GetId(CATString &oId);

  const CATOmxKeyString &GetId() const;

  /**
  * @DEPRECATED
  */
  HRESULT GetAlias(CATUnicodeString **oAlias);

  /**
  * Returns the Type and the instance Id of the provider
  * @param oProviderDesc [out, CATBaseUnknown#Release]
  *    provider descriptor.
  */
  HRESULT GetProviderDesc(CATIPLMProviderDesc ** oProviderDesc);

  /**
  * @DEPRECATED
  * Please use HRESULT GetAttributeType(AttrTypes& oType);
  *
  * Returns the type of this attribute
  * Enum are NOT NOT NOT managed correctly with current method, need to use IsEnumeration...
  * @param oType
  *   The type of this Attribute
  */
  HRESULT GetAttributeType(AttrTypes * oType);

  /**
  * Returns the type of this attribute
  * Enum are managed correctly with method
  * @param oType
  *   The type of this Attribute
  */
  HRESULT GetAttributeType(AttrTypes& oType);

  /**
  * Returns S_OK if the attribute is linked to an enumeration list, S_FALSE otherwise.
  */
  HRESULT IsEnumeration();

  /**
  * Gets enumeration informations.
  */
  HRESULT GetEnumerationInfo(CATListOfInt &oListOfIndexes, CATListOfCATString &oEnumKeys);

  /**
  * Returns the type this attribute
  * @param oTypeId
  *   The type of this Attribute
  */
  HRESULT GetTypeId(CATString ** oTypeId);

  /**
  * Returns the query operators available for this attribute
  * @param oOperators
  *   Query operators available
  */
  HRESULT GetOperators(CATListOfCATUnicodeString **  oOperators);

  /**
  * Method to check if an attribute is Range-like. That means the number of authorized values is restricted as Range or Enum/Range-as-Enum type
  * @return
  * TRUE if the attribute is a Range or an Enum
  * FALSE otherwise
  */
  CATBoolean IsRange();

  /**
  * Returns the Nls Value corresponding to the input authorized value.
  * If there are no Nls values the authorized key values are returned.
  * @param iKey
  *   Input Key Value.
  * @param oNls
  *   Nls Value if found, else Key Value
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_UNEXPECTED</code> if the attribute is not range-like
  *   <code>E_FAIL</code> if the computation of the authorized values has failed
  *   <code>S_ATTR_NOT_SET</code> if environment variable IS_PLM_ATTR_WITHOUT_DFLT_OF_DFLT_SUPPORTED is set and size of NLS is 0 - Please add #include "CATPLMHRESULT.h"
  */
  HRESULT GetNlsFromKey(const CATUnicodeString& iKey, CATUnicodeString& oNls);

  /**
 * Returns the Key Value corresponding to the input Nls.
 * If there are no Nls values the authorized key values are returned.
 * @param iNls
 *   Input Nls.
 * @param oKey
 *   Key Value
 * @return
 *   <code>S_OK</code> if everything ran ok.
 *   <code>E_UNEXPECTED</code> if the attribute is not range-like
 *   <code>E_FAIL</code> if the computation of the authorized values has failed
 *   <code>S_ATTR_NOT_SET</code> if environment variable IS_PLM_ATTR_WITHOUT_DFLT_OF_DFLT_SUPPORTED is set and size of NLS is 0 - Please add #include "CATPLMHRESULT.h"
 */
  HRESULT GetKeyFromNls(const CATUnicodeString& iNLS, CATUnicodeString& oKey);

  /**
  * Returns the authorized values CATOmxAny and  the list is restrictive.
  * Please, use CATPLMOmxHelpers API in order to manage CATOmxAny object
  * @param oValue
  *   authorized values are returned.
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_UNEXPECTED</code> if the attribute is not range-like
  *   <code>E_FAIL</code> if the computation of the authorized values has failed
  *   <code>S_ATTR_NOT_SET</code> if environment variable IS_PLM_ATTR_WITHOUT_DFLT_OF_DFLT_SUPPORTED is set and size of NLS is 0 - Please add #include "CATPLMHRESULT.h"
  */
  HRESULT GetAuthorizedValues(CATOmxAny & oValue);

  /**
  * Returns the authorized Nls values CATOmxAny and the list is restrictive.
  * Please, use CATPLMOmxHelpers API in order to manage CATOmxAny object
  * If there are no Nls values the authorized keys value are returned
  * @param oValue
  *   authorized values (NLS value if found else Key value) are returned.
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_UNEXPECTED</code> if the attribute is not range-like
  *   <code>E_FAIL</code> if the computation of the authorized values has failed
  *   <code>S_ATTR_NOT_SET</code> if environment variable IS_PLM_ATTR_WITHOUT_DFLT_OF_DFLT_SUPPORTED is set and size of NLS is 0 - Please add #include "CATPLMHRESULT.h"
  */
  HRESULT GetNlsAuthorizedValues(CATOmxAny & oValue);

  /**
  * Returns the help values array and its size. A help value is a possible value for this attribute. The list is not restrictive.
  * The internal names and external aliases can be returned.
  * @param oHelpValues
  *   The help values external aliases. If oHelpValueIds is null, the help values external aliases are used for identification too.
  * @param oHelpValueIds
  *   The help values indentifiers. If oHelpValueIds is null, the help values external aliases are used for identification too.
  * @param oHelpValuesSize
  *   the help values array size.
  */
  HRESULT GetHelpValues(CATVariant **  oHelpValues, int *oHelpValuesSize, CATString ** oHelpValueIds = NULL);

  /**
  * @DEPRECATED
  * Please use HRESULT GetDefaultValue(CATOmxAny& oValue, CATBoolean isDefaultOfDefaultReturned = TRUE);
  * 
  *	Returns the default value of this attribute. This method can be used to retrieve the attribute simple type (boolean, int, ...)
  *
  * detailed specification:
  * If default value is found on mask, then we return default value
  * else if default value found on metadata, then we return default value
  * else if HasDefaultDefault() == TRUE, then we return default value
  * else if HasDefaultDefault() == FALSE, then we return S_ATTR_NOT_SET
  * 
  * @param oValue
  *   the default value.
  * @param isDefaultOfDefaultReturned
  *   if isDefaultOfDefaultReturned=FALSE returns E_NOTIMPL.
  */
  HRESULT GetDefaultValue(CATVariant ** oValue, CATBoolean isDefaultOfDefaultReturned = TRUE);

  /**
  *	Returns the default value of this attribute. This method can be used to retrieve the attribute simple type (boolean, int, ...)
  *
  * detailed specification:
  * If default value is found on mask, then we return default value
  * else if default value found on metadata, then we return default value
  * else if HasDefaultDefault() == TRUE, then we return default value
  * else if HasDefaultDefault() == FALSE, then we return S_ATTR_NOT_SET
  *
  * @param oValue
  *   the default value.
  * @param isDefaultOfDefaultReturned
  *   if isDefaultOfDefaultReturned=FALSE returns E_NOTIMPL.
  */
  HRESULT GetDefaultValue(CATOmxAny& oValue, CATBoolean isDefaultOfDefaultReturned = TRUE);

  /**
  *	Returns the default value of this attribute. This method can be used to retrieve the attribute simple type (boolean, int, ...)
  *
  * detailed specification:
  * if default value found on metadata, then we return default value
  * else if HasDefaultDefault() == TRUE, then we return default value
  * else if HasDefaultDefault() == FALSE, then we return S_ATTR_NOT_SET
  *
  * @param oValue
  *   the default value.
  * @param isDefaultOfDefaultReturned
  *   if isDefaultOfDefaultReturned=FALSE returns E_NOTIMPL.
  */
  HRESULT GetDefaultValueDisregardingMasks(CATOmxAny& oValue, CATBoolean isDefaultOfDefaultReturned = TRUE);

  public:
  /**
  * Returns the unit of this attribute. May be NULL
  * @param Unit
  *   the unit of the attribute.
  */
  HRESULT GetUnit(CATUnicodeString **Unit);

  /**
  * Returns the magnitude of this attribute. May be NULL
  * @param oMagnitude
  *   the magnitude of the attribute.
  */
  HRESULT GetMagnitude(CATUnicodeString **oMagnitude);

  /**
  * Returns S_OK if the attribute is mandatory, S_FALSE otherwise.
  */
  HRESULT IsMandatory();

  /**
  * Returns S_OK if the attribute isn't read only, S_FALSE otherwise.
  */
  HRESULT IsWriteEnable();

  /**
  * Returns S_OK if the attribute is visible, S_FALSE otherwise.
  */
  HRESULT IsVisible();

  /**
  * Returns the PLMImpacting characteristic of the Attribute.
  * S_OK if the attribute is PLMImpacting, S_FALSE otherwise.
  *    <ul>
  *    <li>S_OK     the attribute is PLMImpacting.</li>
  *    <li>S_FALSE  the attribute isnot PLMImpacting.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  HRESULT IsPLMImpacting();

  /**
  * Returns S_OK if the attribute is Multi Valuated, S_FALSE otherwise.
  *    <ul>
  *    <li>S_OK     the attribute is MultiValuated.</li>
  *    <li>S_FALSE  the attribute is not MultiValuated.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  HRESULT IsMultiValuated();

  /**
  * Returns the max length for the attribute.
  * @param oMaxLength
  *   The max length for the attribute.
  */
  HRESULT GetMaxLength(int * oMaxLength);

  /**
  * Returns the PLM Visibility according to the Protection.
  * @param oVisibility :
  *    the PLM Visibility. Either CATPLMAttrVisibilityModeler or CATPLMAttrVisibilityUser
  */
  HRESULT GetVisibility(CATPLMAttrVisibility  * oVisibility);

  /**
  * Returns the PLM Exposition according to the Protection.
  * @param oExposition :
  *    the PLM Exposition. Either CATPLMAttrExpositionFree or CATPLMAttrExpositionInternal or CATPLMAttrExpositionExternal
  */
  HRESULT GetExposition(CATPLMAttrExposition * oExposition);

  /**
  * Returns the PLM CAA Exposition according to the Protection.
  * @param oExposition :
  *    the PLM CAAExposition. Either CATPLMAttrCAAExpositionL0 or CATPLMAttrCAAExpositionL1 or CATPLMAttrCAAExpositionUNDEFINED
  */
  HRESULT GetCAAExposition(CATPLMAttrCAAExposition * oExposition);

  /**
  * Returns the PLM Client Editability according to the Protection.
  * @param oClientEditability :
  *    the PLM Client Editability.
  */
  HRESULT GetClientEditability(CATPLMAttrClientEditability * oClientEditability);

  /**
  * Returns the PLM Exchange status.
  * @param oClientEditability :
  *    the PLM Client Editability.
  */
  HRESULT GetExchangeTag(CATPLMAttrExchangeTag * oExchangeTag);

  /**
  * Check whether the current Attribute must be reset when a NewVersion proccess is being applied
  * @return either S_OK or S_FALSE, whether it must be reset or not
  */
  HRESULT IsResetOnNewVersion();

  /**
  * Check whether the current Attribute must be reset when a Cloning proccess is being applied
  * @return either S_OK or S_FALSE, whether it must be reset or not
  */
  HRESULT IsResetOnCloning();

  /**
  * Returns the corresponding index of a enum value.
  * @return E_FAIL if it is not an enumerator or if value is not found.
  */
  HRESULT GetEnumIndexFromValue(const CATOmxKeyString &iEnumVal, int &oIndex);

  /**
  * Returns the corresponding enum from an index position.
  * @return E_FAIL if it is not an enumerator or if value is not found.
  */
  HRESULT GetEnumerationFromIndex(int iIndex, CATOmxKeyString &oEnumKey);

  /*
  * Checks the property with a specified value
  * @return
  *  <ul>
  *   <li>S_OK     The property exists and has the right value.</li>
  *   <li>E_FAIL   The property doesn't have the right value.</li>
  *  </ul>
  */
  HRESULT CheckPropertyValue(const char *iPropertyName, const char *iPropertyValueToCheck);

  /**
  * Clob cannot be used in where clause so FALSE
  */
  CATBoolean IsUsableInWhereClause();

  /**
  * For a PLMAttribute present in PLMType iWherePresent, retrieve at which parent level this PLMAttribute is effectively defined
  *
  * @return either S_OK or S_FALSE, whether it must be reset or not
  * @param oWhereDefined [out, CATBaseUnknown#Release] At which level of parent PLMType, this attibute is defined (may be iWherePresent)
  * @return
  *    E_INVALIDARG iWherePresent NULL or oWhereDefined not NULL
  *    E_FAIL   The attribute is not found in iWherePresent nor in its parents
  *    S_OK     Operation succeeded
  **/
  HRESULT GetPLMTypeOfDefinition(CATPLMType* iWherePresent, CATPLMType*& oWhereDefined);

  /**
  * Method implemented for Switch Security Context Project
  *
  * @return
  *  TRUE  if current attribute has been generated with current security context.
  *  FALSE if current attribute has been generated with a different security context.
  */
  CATBoolean IsValid();

  /**
  * @DEPRECATED
  * Please use HRESULT GetAuthorizedValues(CATOmxAny & oValue) and HRESULT GetNlsAuthorizedValues(CATOmxAny & oValue)
  * 
  * Returns the authorized values array and its size. the list is restrictive.
  * The internal names and external aliases can be returned.
  * @param oppAuthorizedValues
  *   If opAuthorizedValueIds is NOT null, array of authorized values (NLS value if found else Key value) is returned.
  *   If opAuthorizedValueIds is null, array of authorized values (Key value, no NLS) is returned.
  *                                   For deprecated enum, key value is returned.
  *                                   For range          , key value is returned.
  * @param opAuthorizedValueIds
  *   array of authorized values (Key value or Int value, no NLS) is returned.
  *   For deprecated enum, integer is returned as a string.
  *   For range          , key value is returned.
  * @param oAuthorizedValuesSize
  *   the authorized values array size.
  */
  HRESULT GetAuthorizedValues(CATVariant ** oppAuthorizedValues, int *opAuthorizedValuesSize, CATString ** opAuthorizedValueIds = NULL);

  // Attribute "originated" is defined when object is created and not later...
  // In metadata, we find:
  // <Simple Name="originated" ... SetOnlyOnce="AtCreation" ...>
  enum CATPLMSetValueOneTimeProperty { eUndefined = 1, eAtCreation = 2, eLater = 3 };

  // Specify how many times and when attribute can be valuated:
  // eUndefined: you can set attribute more than one time and when you want
  // eAtCreation: you can only set attribute one time and only at creation step
  CATPLMSetValueOneTimeProperty GetSetValueOneTimeProperty();

  // Specify if an attribute is internal, internalRO, external, externalRO...
  CATPLMAttrProtection GetProtection();

  // Release must be made
  CATPLMType* GetOwnedBy();

#ifdef CATIAR424
  /*
  * On metadata, we find property "HasDefault"
  * if HasDefault="No" , if property DefaultValue is not set, then it means that attribute is unset when it is initialized <=> attribute[<attribute name>].isset == FALSE
  * if HasDefault="Yes", if property DefaultValue is not set, then it means that attribute is set (with default of default value) when it is initialized <=> attribute[<attribute name>].isset == TRUE
  * 
  * HasDefaultDefault == TRUE  <=> HasDefault=="Yes"
  * HasDefaultDefault == FALSE <=> HasDefault=="No"
  */
  CATBoolean HasDefaultDefault();
#endif

  AttrTypes GetAttributeType();

  /************************
         PRIVATE
  *************************/
private:
  HRESULT GetOrder(CATPLMMask iMask, int& oOrder);

  /**
  * Returns the element's NLSTag.
  * @param oNLSTag : NLSTag
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  HRESULT GetNLSTag(CATUnicodeString & oNLSTag);

  HRESULT GetNLSValue(CATUnicodeString & oNLSVal);

  HRESULT GetEnumNLSValue(const CATString &iEnumKey, CATUnicodeString & oNLSVal);

  HRESULT _GetAuthorizedValues(CATVariant*& opAuthorizedValues, CATString*& opAuthorizedValueIds, int& oAuthorizedValuesSize,
    CATBoolean iIsAuthorizedValueIdsBuilt);

  // For its friends - Constructor
  CATPLMAttribute(CATPLMAttributeInternal * iAttribute, CATPLMMask iMask);

  // Copy constructor and equal operator
  // -----------------------------------
  CATPLMAttribute(CATPLMAttribute &);
  CATPLMAttribute& operator=(CATPLMAttribute&);

  /* For its friends - Returns The CATPLMAttributeInternal that this attribute aggregates.
  * @param oAttribute [out, CATBaseUnknown#Release]
  *        The CATPLMAttributeInternal.
  */
  HRESULT GetAttributeInternal(CATPLMAttributeInternal ** oAttribute);

  // For its friends - Returns its Mask
  short _Mask;

  CATPLMAttributeInternal * _pAttribute;

  static CATLONG32 _nb;

};

template<> ExportedByCATPLMServicesItf CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMAttribute*>::manager();

#endif
