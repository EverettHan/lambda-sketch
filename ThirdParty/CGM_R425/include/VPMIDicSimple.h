//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
// Usage notes: used to introspect the attributes
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicSimple_h
#define _VPMIDicSimple_h

#include "VPMIDicInterfaces.h"

#include "CATCORBABoolean.h"
#include "VPMIDicAttribute.h"
#include "VPMIDicRange.h"
#include "VPMDicCOLLECTION.h"
#include "VPMDicACCESSMODE.h"
#include "VPMDicCUSTOMEREXPOSITION.h"
#include "VPMDicCUSTOMEREXPOSITIONPURPOSE.h"
#include "VPMDicPRIMITIVEType.h"
#include "VPMDicSETONLYONCE.h"

#include "VPMIDicClass.h" // Important a garder pour compatibilite ascendante du service
#define VPMIDicVolatileNlsAsGenericClass

class VPMIDicPrimitive;
class VPMIDicEnumerator;

#include "CATIAV5Level.h"
#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicSimple;
#else
extern "C" const IID IID_VPMIDicSimple;
#endif

/**
 * Interface to manage the Attributes (declared as Simple in metadata).
 */

class  ExportedByVPMIDicInterfaces VPMIDicSimple : public VPMIDicAttribute
{
  CATDeclareInterface;

public:

  /**
* Retrieves the PrimitiveType of the Simple.
* As of April'2011, possible values are : VPMDicUNDEFINED, VPMDicBOOLEAN, VPMDicINTEGER, VPMDicDOUBLE, VPMDicSTRING, VPMDicBINARY,VPMDicCLOB, VPMDicDATE, VPMDicLOGICAL, VPMDicURL, VPMDicANYOBJECT, VPMDicENUMERATION
* (cf. CATPLMDictionary\ProtectedInterfaces\VPMDicPRIMITIVEType.h)
*/
  virtual VPMDicPRIMITIVEType GetPrimitiveType() const = 0;



  /**
   * Gets the list of authorized values of the Simple.
   * Corresponds to the range
   * NB: the authorized values of the Simple are declared:
   * @param oAuthorizedValues : list of authorized values of the Simple
   * @param iNLS : states whether to process the actual persisted labels (CATFalse),
   *               or rather the NLS values for these labels (CATTrue)
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT GetAuthorizedValues(CATListOfCATUnicodeString & oAuthorizedValues, const boolean iNLS = CATFalse) = 0;

  /**
   * Get the magnitude of the Simple wgeb there is one
   * Corresponds to the Magnitude keyword in metadata
   * The Magnitude is the physical type of a quantity.
   * It is an equivalence class for units.
   * ex: LENGTH magnitude is a class for {meters, inches, parsec,...}
   * @param oMagnitude : the magnitude of the Simple. [out]
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT GetMagnitude(CATUnicodeString * oMagnitude) = 0;

  /**
    * Indicates if the modification of the attribute impacts the update stamp of the object that hold the attribute
   * Corresponds to the PLMImpacting keyword in metadata
    */
  virtual HRESULT GetPLMImpacting(boolean * oPLMImpacting) = 0;

  /**
   * States whether the Simple is an Enumeration.
   * Reminder: a Simple is assumed to be an Enumeration if it has a range
   * @param oIsEnumeration : is the Simple an Enumeration ? (either true or false) [out]
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT IsEnumeration(boolean * oIsEnumeration) = 0;

  /**
  * Gets the default value of the Simple.
  * Corresponds to the DefaultValue keyword
  * NB: if the default value is defined as a reference to an Enumerator, then Enumerator's Name is returned as the default value.
  * @param oValue : the default value of the Simple. [out]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a significant defaut value was returned.</li>
  *    <li>S_FALSE  Operation succeeded, but no default value was found to be returned.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetDefaultValue(CATUnicodeString & oValue, int * oIndex = NULL) = 0;


  /**
   * States whether the Simple has a Default value.
   * @return boolean either CATTrue or CATFalse
   */
  virtual boolean HasDefaultValue() = 0;



  /**
   * States whether the Simple is a "ExtendedEnterprise" attribute or not (opposite of "CollaborativeDesign").
   * Corresponds to ExtendedEnterprise keyword
   * NB: an attribute of a Custo modeler is necessarily "ExtendedEnterprise=True", therefore "CollaborativeDesign=False".
   * @return boolean either CATTrue or CATFalse
   */
  virtual boolean IsExtendedEnterprise() = 0;


  /**
   * States whether the Simple is a "CollaborativeDesign" attribute or not (opposite of "ExtendedEnterprise").
   * NB: an attribute of a Custo modeler is necessarily "ExtendedEnterprise=True", therefore "CollaborativeDesign=False".
   * @return boolean either CATTrue or CATFalse
   */
  virtual boolean IsCollaborativeDesign() = 0;

  /**
  * Check whether the current Attribute must be reset when a NewVersion proccess is being applied
  * Corresponds to ResetOnNewVersion keyword
  * @return either S_OK or S_FALSE, whether it must be reset or not
  */
  virtual HRESULT IsResetOnNewVersion() = 0;

  /**
   * Check whether the current Attribute must be reset when a Cloning proccess is being applied
   * Corresponds to ResetOnCloning keyword
   * @return either S_OK or S_FALSE, whether it must be reset or not
   */
  virtual HRESULT IsResetOnCloning() = 0;


  /**
   * Retrieves the Simple's NLSTag, possibly in the context of a given Class.
   * In that case, this given Class must be derived from the Class where the current Simple is actually defined.
   * @param iDicClass : the Class in which the Simple is to be considered
   * @param oNLSTag : NLSTag
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT GetNLSTag(CATUnicodeString & oNLSTag, const VPMIDicGenericClass * iDicClass = NULL) = 0;


  /**
   * Retrieves the Simple's NLSValue, possibly in the context of a given Class.
   * In that case, this given Class must be derived from the Class where the current Simple is actually defined.
   * @param iDicClass : the Class in which the Simple is to be considered
   * @param oNLSValue : NLSValue
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT GetNLSValue(CATUnicodeString & oNLSValue, const VPMIDicGenericClass * iDicClass = NULL) = 0;

  /**
  * Get the Range possibly defined for the Simple.
  * @param oDicRange the Range [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a Range has been found.</li>
  *    <li>E_FAIL   Operation failed, or no Range was found.</li>
  *    </ul>
  */
  virtual HRESULT GetRange(VPMIDicRange ** oDicRange) const = 0;


  /**
  * Indicates if this attribute is faceted (impacts indexation)
  * Corresponds to the Faceted keyword
  */
  virtual boolean IsFaceted() const = 0;

  /**
  * Retrieves the Simple's CustoUserAccess, depending on its Protection and its Property "CustoUserAccess" if any
  * Only applies to customisations
  * @return
  *    <ul>
  *    <li>VPMDicCUSTOUSERACCESS_NONE      if the Protection is INTERNAL|INTERNALRO|PRIVATE, or if the Protection is FREE|USER and the CustoUserAccess Property is None.</li>
  *    <li>VPMDicCUSTOUSERACCESS_READONLY  if the Protection is EXTERNAL|EXTERNALRO, or if the Protection is FREE|USER and the CustoUserAccess Property is ReadOnly.</li>
  *    <li>VPMDicCUSTOUSERACCESS_READWRITE if the Protection is EXTERNALIN, or if the Protection is FREE|USER and the CustoUserAccess Property is ReadWrite|unset.</li>
  *    </ul>
  */
  virtual VPMDicCUSTOUSERACCESS GetCustoUserAccess() const = 0;


  /**
   * Indicates if this attribute can be set only once. And can it happen at Creation only, or potentially later
   * Corresponds to SetOnlyOnce keyword
   */
  virtual VPMDicSETONLYONCE GetSetOnlyOnceStatus() const = 0;

  /**
   * indicates if the definition of the attribute is local to the generic class (major case) or shared between generic classes
   */
  virtual CATBoolean IsGlobal() const = 0;

  /**
   * MQL is the DML (data manipulation language) in which we need to adress attributes by their names.
   * This method returns the string to put in MQL. For global attribute, it returns the name of the attribute. For local attributes, it returns a concatenation of the type name and the attribute name separated by a "."
   */
  virtual CATUnicodeString AttributeNameForDML() const = 0;

  /**
   * PLMQL is the DML (data manipulation language) in which we need to adress attributes by their names, that is still used on the rich client.
   * This method returns the string to put in PLMQL. For global attribute, it returns the name of the attribute.
   * For local attributes ER based, it returns a concatenation of the type name and the attribute name separated by a "."
   * For local attributes IRPC based, it returns the name of the attribute.
   */
  virtual CATUnicodeString AttributeNameForDML_PLMQL() const = 0;


  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to modify dictionary should never be user, except by providers
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
        /**
         * Sets the list of authorized values for the Simple.
         * @param iAuthorizedValues : the list of authorized values
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */
  virtual HRESULT SetAuthorizedValues(const CATListOfCATUnicodeString & iAuthorizedValues) = 0;
  /**
   * Sets the ExtendedEnterprise property of the Simple attribute.
   * NB: an attribute of a Custo modeler is necessarily "ExtendedEnterprise=True", and therefore cannot be set to False with this method.
   * @param iExtendedEnterprise : either True or False, whether the attribute is "ExtendedEnterprise" or not. [in]
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT SetExtendedEnterprise(boolean iExtendedEnterprise) = 0;

  /**
   * Set the PLMImpacting characteristic of the Simple.
   * @param iPLMImpacting : the PLMImpacting characteristic (either true or false) of the Simple. [in]
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT SetPLMImpacting(boolean iPLMImpacting) = 0;
  /**
    * Sets the default value of the Simple.
    * @param iValue : the default value of the Simple. [in]
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
  virtual HRESULT SetDefaultValue(const CATUnicodeString & iValue) = 0;

  /**
   * Sets the Enumerator which name is to be the default value of the Simple.
   * @param iEnumerator : the Enumerator. [in]
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT SetDefaultValueEnumerator(const VPMIDicEnumerator * iEnumerator) = 0;


  /**
   * Sets the Primitive type of the Simple.
   * @param iPrimitive : the Simple's Primitive
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT SetPrimitive(const VPMIDicPrimitive *iPrimitive) = 0;



  //---------------------------------------------------------------------
 // Deprecated methods
 //---------------------------------------------------------------------


#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING"   " VPMIDicSimple::GetPrimitive should be replaced by VPMIDicSimple::GetPrimitiveType.")

#else
         /**
         * Retrieves the Primitive type of the Simple.
         * Corresponds to the Type keyword in metadata
         * @param oPrimitive : the Simple's Primitive [out, CATBaseUnknown#Release]
         * @return
         *    <ul>
         *    <li>S_OK     Operation succeeded.</li>
         *    <li>E_FAIL   Operation failed.</li>
         *    </ul>
         */

  virtual HRESULT GetPrimitive(VPMIDicPrimitive **oPrimitive) = 0;
#endif     

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING"   " VPMIDicSimple::GetResetValue is obsolete.")

#else
  /**
   * Gets the reset value of the Simple.
   * NB: if the reset value is defined as a reference to an Enumerator, then Enumerator's Name is returned as the reset value.
   * @param oValue : the default value of the Simple. [out]
   * @return
   *    <ul>
   *    <li>S_OK     Operation succeeded.</li>
   *    <li>E_FAIL   Operation failed.</li>
   *    </ul>
   */
  virtual HRESULT GetResetValue(CATUnicodeString & oValue) = 0;
#endif     

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING"   " VPMIDicSimple::HasResetValue is obsolete.")

#else
  /**
   * States whether the Simple has a reset value.
   * @return boolean either CATTrue or CATFalse
   */
  virtual boolean HasResetValue() = 0;
#endif     


  /**
  * States whether the Simple is to be displayed in a multi-line manner.
  * NB: valid only for String attribute.
  * @return boolean either CATTrue or CATFalse
  */
  virtual boolean IsMultiLine() = 0;


  /**
   * Indicates if the attribute's input format has to be kept in order to be re-applied when displaying the attribute's value 
  * @return boolean either CATTrue or CATFalse
   */
  virtual boolean IsKeepFormat() const = 0;

  /**
   * Indicates if the attribute has a default (default) value. If 'CATFalse', it means there will be no default value for this attribute when an object is created.
  * @return boolean either CATTrue or CATFalse
   */
  virtual boolean HasDefaultDefault() const = 0;

};

CATDeclareHandler(VPMIDicSimple, VPMIDicAttribute);

#endif
