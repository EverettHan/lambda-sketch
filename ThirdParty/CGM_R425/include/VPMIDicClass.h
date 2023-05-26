//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2007
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicClass_h
#define _VPMIDicClass_h

#include "EnoDicDELETE.h"
#include "VPMIDicInterfaces.h"

#include "VPMIDicElement.h"
#include "VPMIDicGenericClass.h"

#include "CATString.h"
#include "CATIAV5Level.h"

#include "VPMDicCAADERIVABLE.h"
#include "VPMDicPROTECTION.h"
#include "VPMDicCUSTOMEREXPOSITION.h"
#include "VPMDicCUSTOMEREXPOSITIONPURPOSE.h"

#include "CATListOfVPMIDicService.h"


class VPMIDicClass_var;
class VPMIDicVolatile_var;

class VPMIDicSimple;
#if defined(REMOVE_USELESS_INCLUDE)
#else
class VPMIDicRelationship;
#endif
class VPMIDicInverse;
class VPMIDicPackage;
class VPMIDicInterface;
class VPMIDicRelationClass_var;
class VPMIDicUnique;
class VPMIDicAttribute;
//class VPMIDicAttributeBlock;
class VPMIDicMask;
class VPMIDicIdentifierSet;
class VPMIDicInterfaceImplementation;
class VPMIDicVolatile;
//class VPMIDicContextKey;
class VPMIDicProcedure;

class VPMIDicSubRelationship;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicClass;
#else
extern "C" const IID IID_VPMIDicClass;
#endif


// When this define is set, extensions are no more VPMIDicClass
//#define VPMIDicClass_DoesNotSupportExtensionAnymore

//===================================================================
//-- This interface represents a Class as defined in the metadata
//-- It provides
//    - The access to the instance type to use when inserting an object of this class
//    - The access to identifier sets
//===================================================================


class ExportedByVPMIDicInterfaces VPMIDicClass : public VPMIDicGenericClass
{
  CATDeclareInterface;

public:

  //---------------------------------------------------------------------
  // Access to the default instance relation class to use when inserting an object of this particular class
  // Corresponds to the CreateInstName keyword (partially)
  //---------------------------------------------------------------------

  // It will be the only method when instance type mapping project will be activated
  virtual HRESULT GetCreateInstanceRelationClass(VPMIDicRelationClass_var & oInstanceClass) = 0;

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicClass GetCreateInstanceClass is deprecated. You must use GetCreateInstanceRelationClass instead ")


#else
  // Method obsolete when instance type mapping project will be finally activated
  virtual HRESULT GetCreateInstanceClass(VPMIDicClass_var & oInstanceClass) = 0;
#endif


  // FIXME: add a method to return the list of InstanceClass when instance type project will be finished



  //---------------------------------------------------------------------
  // Reading characteristics of the Class: old methods (still valid) that make sense in former typing mode only
  //---------------------------------------------------------------------
    /**
  * Get whether the current Class is of PLMCore type or not.
  * @param oIsPLMCoreType
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPLMCoreType(boolean *oIsPLMCoreType) = 0;

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicClass GetReference is deprecated. You must use VPMIDicRelationClass GetSubClauses instead ")

#else
  /**
  * @param oReferenceClass [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetReference(VPMIDicClass** oReferenceClass) = 0;
#endif

  /**
  * Get whether the current Class is derivable from a CAA standpoint.
  * @param oIsCAADerivable Either "No", "Yes" or "Multiple"
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetCAADerivable(VPMDicCAADERIVABLE * oIsCAADerivable) = 0;


#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicClass GetInstance is deprecated. You must use GetPLMCoreType instead ")

#else
  /**
  * @param oInstance
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetInstance(boolean * oInstance) = 0;
#endif

  /**
   * @nodoc
   */
  virtual HRESULT IsCBP(boolean & oIsCBP) const = 0;


  /**
  * Check whether the current Class has an IdentifierSet element.
  * @param oHasIdentifierSet
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT HasIdentifierSet(boolean * oHasIdentifierSet) = 0;

  /**
  * @deprecated
  * Get the list of Attributes elements defined in the IdentifierSet element of the current Class.
  * @param oListOfAttributes
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetIdentifierSetAttributes(CATLISTP(IUnknown) * oListOfAttributes) = 0;

  /**
  * Get the IdentifierSet element of the current Class, if any.
  * @param oIdentifierSet [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>S_FALSE  Current Class has no IdentifierSet.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetIdentifierSet(VPMIDicIdentifierSet** oIdentifierSet) const = 0;

  /**
  * Get the IdentifierSet elements of the current Class and super Classes, if any.
  * @param oListOfDicIdentifierSets
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>S_FALSE  Current Class has no IdentifierSet.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetIdentifierSets(CATLISTP(IUnknown) * oListOfDicIdentifierSets) = 0;


  /**
  * FIXME: should be replaced? If the Type is a Connection Type, returns if the Connection is Structured or not.
  * @return
  *    <ul>
  *    <li>TRUE    The Type is a Structured Connection.</li>
  *    <li>FALSE   The Type is not a Structured Connection.</li>
  *    </ul>
  */
  virtual boolean IsStructuredConnection() = 0;


  /**
  * Get the list of Attributes elements defined in the IdentifierSet element of the current Class.
  * @param oListOfAttributes
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetIdentifierSetAttributes(CATLISTV_VPMIDicSimple_var& oSimples) = 0;





  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to modify dictionary should never be user, except by providers
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicClass SetInstance is deprecated.")

#else
  /**
  * @nodoc
  * @param iInstance
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetInstance(boolean iInstance) = 0;
#endif

  /**
  * Remove an element (i.e. Simple, Relationship or Inverse) of the current Class.
  * @param iName Name of the element
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT RemoveElement(const CATString * iName) = 0;

  /**
   * @deprecated
   * @nodoc
   */
  virtual HRESULT SetPLMCoreType(boolean iIsPLMCoreType) = 0;
  /**
  * Set whether the current Class is derivable from a CAA standpoint.
  * @param iIsCAADerivable Either "No", "Yes" or "Multiple"
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetCAADerivable(const VPMDicCAADERIVABLE iIsCAADerivable) = 0;


  /**
  * Create a Volatile element in the current Class.
  * @param iName Name ot the Volatile
  * @param iUuid Uuid of the Volatile
  * @param oVolatile the Volatile [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateVolatile(const CATString * iName, const CATDbBinary * iUuid, VPMIDicVolatile** oVolatile) = 0;

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicClass CreateRelationship is deprecated. You must remove it ")

#else
  /**
  * Create a Relationship element in the current Class.
  * @param iName Name ot the Relationship
  * @param iUuid Uuid of the Relationship
  * @param oRelationship the Relatioinship [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateRelationship(const CATString * iName, const CATDbBinary * iUuid, VPMIDicRelationship** oRelationship) = 0;
#endif


  /**
  * Specify whether the current Class is of abstract or not.
  * @param iAbstract
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetAbstract(boolean iAbstract) = 0;
  /**
* Set the super Class of the current Class.
* @param iSuperClass The Class to become the super Class of the current Class
* @return
*    <ul>
*    <li>S_OK     Operation succeeded.</li>
*    <li>E_FAIL   Operation failed.</li>
*    </ul>
*/
  virtual HRESULT SetSuperClass(const VPMIDicClass * iSuperClass) = 0;

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicClass SetReference is deprecated. You must remove it ")

#else
  /**
  * @nodoc
  * @param iReferenceClass
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetReference(const VPMIDicClass * iReferenceClass) = 0;
#endif

  /**
  * @nodoc
  */
  virtual HRESULT SetCustomerExposition(const VPMDicCUSTOMEREXPOSITION iCustomerExposition) = 0;

  /**
 * Create the IdentifierSet element for the current Class.
 * Only one IdentifierSet element can be defined per Class.
 * @param iName Name ot the IdentifierSet
 * @param iUuid Uuid of the IdentifierSet
 * @param oIdentifierSet [out, CATBaseUnknown#Release]
 * @return
 *    <ul>
 *    <li>S_OK     Operation succeeded.</li>
 *    <li>E_FAIL   Operation failed.</li>
 *    </ul>
 */
  virtual HRESULT CreateIdentifierSet(const CATString * iName, const CATDbBinary * iUuid, VPMIDicIdentifierSet** oIdentifierSet) = 0;

  /**
  * Remove the IdentifierSet element of the current Class.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT RemoveIdentifierSet() = 0;



  //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------
#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING"   " VPMIDicGenericClass::GetMaturityAttributeName should be replaced by CATCkePLMDefinitions::Attribute_maturity.")

#else
  virtual HRESULT GetMaturityAttributeName(CATString & oAttributeName) = 0;
#endif
#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING"   " VPMIDicGenericClass::GetMajorRevisionAttributeName should be replaced by CATCkePLMDefinitions::Attribute_majorrevision.")

#else
  virtual HRESULT GetMajorRevisionAttributeName(CATString & oAttributeName) = 0;
#endif

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicClass GetSuperClassAsRelation should be replaced by VPMIDicAttributes::GetSuperElement ")

#else
  /**
  * Get the super RelationClass of the current class.
  * @param oSuperRelationClass
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */

  virtual HRESULT GetSuperClassAsRelation(VPMIDicRelationClass_var & oSuperRelationClass) const = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)
#pragma message ("WARNING "   " VPMIDicClass::GetSuperClass should be replaced by VPMIDicAttributes::GetSuperElement")
#else

  /**
  * @deprecated
  * Get the super Class of the current Class.
  * @param oSuperClass The super Class of the current Class [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, oSuperClass is valuated.</li>
  *    <li>S_FALSE  Operation succeeded, but there is no SuperClass (i.e. oSuperClass is NULL).</li>
  *    <li>E_FAIL   Operation failed. Use GetSuperRelationClass to be sure that this class doesn't inherit from a relation class</li>
  *    </ul>
  */
  virtual HRESULT GetSuperClass(VPMIDicClass** oSuperClass) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicClass::GetSuperClass should be replaced by VPMIDicWithAttributes::GetSuperElement.")

#else
  /**
  * Get the super Class of the current Class. User GetSuperRelationClass if fails...
  * @param oSuperClass The super Class of the current Class
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, oSuperClass is valuated.</li>
  *    <li>S_FALSE  Operation succeeded, but there is no SuperClass (i.e. oSuperClass is NULL).</li>
  *    <li>E_FAIL   Operation failed. Use GetSuperRelationClass to be sure that this class doesn't inherit from a relation class</li>
  *    </ul>
  */
  virtual HRESULT GetSuperClass(VPMIDicClass_var & oSuperClass) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicClass::GetSubRelationshipByName should be replaced by VPMIDicGenericClass::GetSubRelationship.")

#else
  /**
  * Get the subrelation ship by its name
  * @param iName name of subrelationship
  * @param iDicRelationShip sub relationship
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSubRelationshipByName(const CATUnicodeString &iName, VPMIDicSubRelationship **iDicRelationShip) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicClass::GetAllSubRelationships should be replaced by VPMIDicGenericClass::GetLocalSubRelationships.")

#else
  /**
    * @deprecated
    * Get the list of SubRelationship elements of the current Class, whatever Relationship they refer to.
    * @param oListOfSubRelationships List of SubRelationship of the current Class.
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
  virtual HRESULT GetAllSubRelationships(CATLISTP(IUnknown) * oListOfSubRelationships, boolean iWithInherited = CATTrue) = 0;
#endif



#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicClass::GetSubRelationships should be replaced by VPMIDicGenericClass::GetLocalSubRelationships.")

#else
  /**
 * @deprecated
 * mkchecksource UNIPAT1: this call is licit but raises a mkchecksource error.
 * You'd better use GetAllSubRelationships if you want to get rid the mcks
 * Get the list of SubRelationship elements of the current Class, whatever Relationship they refer to.
 * @param oListOfSubRelationships List of SubRelationship of the current Class.
 * @return
 *    <ul>
 *    <li>S_OK     Operation succeeded.</li>
 *    <li>E_FAIL   Operation failed.</li>
 *    </ul>
 */
  virtual HRESULT GetSubRelationships(CATLISTP(IUnknown) * oListOfSubRelationships, boolean iWithInherited = CATTrue) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicClass::GetSubRelationships should be replaced by VPMIDicGenericClass::GetLocalSubRelationships.")

#else
  /**
  * Get the list of SubRelationship elements of the current Class, whatever Relationship they refer to.
  * @param oListOfSubRelationships List of SubRelationship of the current Class.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSubRelationships(CATLISTV_VPMIDicSubRelationship_var & oSubRelationships, boolean iWithInherited = CATTrue) = 0;
#endif




#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicClass::GetAbstract should be replaced by VPMIDicWithAttributes::IsAbstract.")

#else
  /**
  * Get whether the current Class is of abstract or not.
  * @param oAbstract
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetAbstract(boolean * oAbstract) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicClass::IsDisciplineAuhtorized should be replaced by VPMIDicGenericClass::IsDisciplineAuthorized.")

#else
  /**
  * @deprecated
  * Refer to IsDisciplineAuthorized
  */
  virtual HRESULT IsDisciplineAuhtorized(const CATString & iDisciplineName, boolean iCreationMode, boolean &oAuth) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicClass::GetServices is obsolete.")

#else
  /**
  * Get the list of Services implemented by the current Class.
  * This method allows to directly get Services elements without navigating through InterfaceImplementations, and related Interfaces, and finally to Services elements.
  * @param iWithInherited taking into account Services possibly implemented in super Class
  * @param oDicServiceList (each element of the list should also be released by the caller)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetServices(CATListOfVPMIDicService & oDicServiceList, boolean iWithInherited = CATTrue) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicClass::GetListOfSecuredElement is obsolete.")

#else
  /**
    * Get the list of the Attribute elements (either Simple, Relationship or Inverse) that are actually secured.
    * @param ioListOfAttribute
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>S_FALSE  Current Class has no secured attribute.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
  virtual HRESULT GetListOfSecuredElement(CATLISTP(IUnknown) & ioListOfAttribute, boolean iWithInherited = CATTrue) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicClass::GetExtensible is obsolete.")

#else
  /**
  * Get whether the current Class is extensible or not.
  * If GetExtensible succeeded, return is : S_FALSE if oExtensible is a computed
  * default value ; S_OK if this field was explicitly defined on this Class
  * @param oIsExtensible
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetExtensible(boolean * oIsExtensible) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)
#pragma message ("WARNING"   " VPMIDicGenericClass::getProcedureForMethodType should be replaced by VPMIDicGenericClass::getProcedureForMethodUsage with 3 arguments.")


#else
  /**
* <dl>
* <dt>
* <pre>
*
     *   If the Method has only a single Usage, return for this Class the Procedure associated to this Usage.
     *   If the Method has more than one Usage, return for this Class the Procedure associated to the first Usage;
     *   @param iMethodTypeName
     *      The name of MethodType
     *   @param oppProcedure
     *      The Procedure
     *   @return
     *      E_FAILED if error
     *      S_OK else
*  HRESULT getProcedureForMethodType(const CATString & iMethodTypeName,VPMIDicProcedure** oppProcedure ) = 0;
* </pre>
* </dl>
*/
  virtual HRESULT getProcedureForMethodType(const CATString & iMethodTypeName, VPMIDicProcedure** oppProcedure) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicClass::GetRevisionAttributeName is useless.")

#else
  virtual HRESULT GetRevisionAttributeName(CATString & oAttributeName) = 0;
#endif


  //---------------------------------------------------------------------
  // FIXME: The following services should at least be moved to VPMIDicWithAttributes if we want to keep them
  //---------------------------------------------------------------------

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicClass::GetClassElements should be replaced by dedicated services to access sub elements of a given type.")

#else
  /**
  * Get the list of elements (ie Simple, Relationship and/or Inverse) of the current Class.
  * NB: only elements declared in the current Class are returned, not elements declared in a possible super Class.
  * @param oListOfElements List of the elements of the current Class.
  * @param iDicType the type of Element to filter (VPMDicSIMPLE, VPMDicRELATIONSHIP, or VPMDicINVERSE). If NULL, then no filter is applied.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetClassElements(CATLISTP(IUnknown) * oListOfElements, const VPMDicTYPE iDicType = (VPMDicTYPE)0) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicClass::GetAllElements should be replaced by dedicated services to access sub elements of a given type.")

#else
  /**
  * Get the list of elements (ie Simple, Relationship and Inverse) of the current Class, including elements inherited from a possible super Class.
  * @param oListOfElements List of all the elements (including inherited elements) of the current Class
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetAllElements(CATLISTP(IUnknown) * oListOfElements) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicClass::GetElement should be replaced by dedicated services to access sub elements of a given type.")

#else
  /**
  * Get an element of the current Class by its name.
  * Note that the element (ie a Simple, a Relationship or an Inverse) is searched in the current Class first, and recursiveley in possible super Class
  * @param iName Name of the element
  * @param oElement : Element [out, CATBaseUnknown#Release],
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetElement(const CATString * iName, VPMIDicElement** oElement) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicClass::GetClassElement should be replaced by dedicated services to access sub elements of a given type.")

#else
  /**
  * Get an element of the current Class by its name.
  * Note that the element (ie a Simple, a Relationship or an Inverse) is searched only in the current Class
  * @param iName Name of the element
  * @param oElement the Element that was found[out, CATBaseUnknown#Release]
  * @param oElement [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetClassElement(const CATString * iName, VPMIDicElement** oElement) = 0;
#endif


  /**
  * States whether the presumable number of objects of this given Class/Type
  * is foreseen to be low enough to allow “on all objects query”.
  * @return
  *    <ul>
  *    <li>true     </li>
  *    <li>false    </li>
  *    </ul>
  */
  virtual boolean IsLowObjectCount() = 0;


  /**
  * Get the PublicResourceURI (Unified Resource Identifier) of the current Class.
  * @param oURI the value of the PublicResourceURI tag, if any 
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPublicResourceURI(CATUnicodeString & oURI) const = 0;


};

CATDeclareHandler(VPMIDicClass, VPMIDicGenericClass);

#endif
