//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010
//=============================================================================
// Usage notes: used to introspect the different RelationClass, in particular, access to the subclauses of the RelationClass
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicRelationClass_h
#define _VPMIDicRelationClass_h

#include "VPMIDicInterfaces.h"
#include "CATString.h"
#include "CATBaseUnknown.h"

#include "VPMIDicElement.h"
#include "VPMIDicGenericClass.h"

#include "VPMDicCUSTOMEREXPOSITION.h"
#include "VPMDicCUSTOMEREXPOSITIONPURPOSE.h"
#include "VPMDicTYPE.h"

#include "CATLISTV_VPMIDicUniqueKey_var.h"
#include "CATLISTV_VPMIDicClass_var.h"
#include "CATLISTV_VPMIDicExtension_var.h"
#include "CATLISTV_VPMIDicElement_var.h"
#include "CATLISTV_VPMIDicRelationClass_var.h"
#include "CATLISTV_VPMIDicSubClause_var.h"
#include "VPMDicPROTECTION.h"

class VPMIDicMask;
class VPMIDicSimple_var;
class VPMIDicVolatile_var;
class VPMIDicSubRelationship;
class VPMIDicRelationship;
class VPMIDicRelationClass_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicRelationClass;
#else
extern "C" const IID IID_VPMIDicRelationClass;
#endif


/**
 * Interface to manage the RelationClass that are concepts of the dictionary.
 */

class ExportedByVPMIDicInterfaces VPMIDicRelationClass: public VPMIDicGenericClass
{
  CATDeclareInterface;

public:

  // ---------------------------------------------------------------------
  // Access to subclauses
  // ---------------------------------------------------------------------
  
 /**
  * Get the list of SubClauses defined in the current RelationClass.
  * Corresponds to the SubClause keyword
  * @param oSubClauseList
  * @return 
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSubClauses ( CATLISTV_VPMIDicSubClause_var & oSubClauseList, boolean iWithInherited = CATFalse ) const = 0;

  /**
  * Get the Names list of SubClauses defined in the current RelationClass.
  * @param oSubClauseNameList
  * @return 
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSubClauseNameList ( CATListOfCATUnicodeString & oSubClauseNameList, boolean iWithInherited = CATFalse ) const = 0;

  // ---------------------------------------------------------------------
  // Inheritance
  // ---------------------------------------------------------------------

  /**
  * Get the list of super RelationClasses of the current RelationClass.
  * The resulting list is ordered from base to top.
  * @param oRelationClasses 
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSuperRelationClasses (  CATLISTV_VPMIDicRelationClass_var & oSuperRelationClasses ) = 0;






  

  

  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to modify dictionary should never be user, except by providers
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
 /**
  * Set the super Class of the current RelationClass.
  * @param iSuperRelationClass The Class to become the super Class of the current Relation Class
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetSuperRelationClass ( const VPMIDicRelationClass * iSuperRelationClass) = 0;



  //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " Replace call to VPMIDicRelationClass::GetSuperRelationClass by VPMIDicWithAttributes::GetSuperElement .")

#else
   /** FIXME: not used. Should be moved to implementation
  
  * Create a SubRelationship element in the current Class.
  * @param iName Name ot the SubRelationship
  * @param iUuid Uuid of the SubRelationship
  * @param oSubRelationship the SubRelationship [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT CreateSubRelationship ( const CATString * iName, const CATDbBinary * iUuid, VPMIDicSubRelationship** oSubRelationship ) = 0;
#endif  
  


  //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " Replace call to VPMIDicRelationClass::GetSuperRelationClass by VPMIDicWithAttributes::GetSuperElement .")

#else
  /**
  * @deprecated
  */
  virtual HRESULT GetSuperRelationClass ( VPMIDicRelationClass ** oSuperRelationClass) const = 0;
#endif 

  
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " Replace call to VPMIDicRelationClass::GetSubClauseList by VPMIDicRelationClass::GetSubClauses .")

#else
  /**
  * @nodoc
  */
  virtual HRESULT GetSubClauseList ( CATLISTP(IUnknown) * oSubClauseList ) const = 0;
#endif

  #if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicRelationClass::GetMaturityAttributeName is meaningless. Please suppress it.")

#else
  virtual HRESULT GetMaturityAttributeName ( CATString & oAttributeName ) = 0;
#endif
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING"  " call to VPMIDicRelationClass::GetRevisionAttributeName is meaningless. Please suppress it.")

#else
  virtual HRESULT GetRevisionAttributeName ( CATString & oAttributeName ) = 0;
#endif
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " call to VPMIDicRelationClass::GetMajorRevisionAttributeName is meaningless. Please suppress it.")

#else
  virtual HRESULT GetMajorRevisionAttributeName ( CATString & oAttributeName ) = 0;
#endif
  
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " Replace call to VPMIDicRelationClass::GetSubRelationshipByName by VPMIDicGenericClass::GetSubRelationship .")

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
  virtual HRESULT GetSubRelationshipByName ( const CATUnicodeString &iName,VPMIDicSubRelationship **iDicRelationShip) =0;
#endif 

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " Replace call to VPMIDicRelationClass::GetAllSubRelationships by VPMIDicGenericClass::GetLocalSubRelationships .")

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
  virtual HRESULT GetAllSubRelationships   ( CATLISTP(IUnknown) * oListOfSubRelationships, boolean iWithInherited = CATTrue ) = 0;
#endif
  #if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING"   " Replace call to VPMIDicRelationClass::GetSuperRelationClass by VPMIDicWithAttributes::GetSuperElement .")

#else
  /**
  * Get the super RelationClass of the current RelationClass.
  * @param oSuperRelationClass 
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */

  virtual HRESULT GetSuperRelationClass ( VPMIDicRelationClass_var & oSuperRelationClass ) const = 0;
#endif

  #if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " Replace call to VPMIDicRelationClass::GetClassListBySubClause by VPMIDicRelationClass::GetSubClauses.")

#else
  /**
  * @deprecated Cannot be used anymore because subclause can reference RelationClass also !
  * Get the list of Class refered by SubClauses of the given name defined in the current RelationClass.
  * @param oClasses
  * @return 
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetClassListBySubClause ( const CATUnicodeString & iSubClauseName, CATLISTV_VPMIDicClass_var & oClasses ) = 0;
#endif 

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "  " Replace call to VPMIDicRelationClass::GetMaskList by VPMIDicGenericClass::GetMasks.")

#else

  virtual HRESULT GetMaskList ( CATLISTP(IUnknown) * oMaskItfList ) const = 0;
#endif

  // ---------------------------------------------------------------------
  // Access to subelements: FIXME should be moved to VPMIDicGenericClass
  // ---------------------------------------------------------------------
#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicRelationClass::GetElementList should be replaced by dedicated services to access sub elements of a given type.")

#else

  /**
  * FIXME: shouldn't we move these methods to VPMIDicWithAttributes or VPMIDicGenericClass
  */
  virtual HRESULT GetElementList ( CATLISTP(IUnknown) * oElemenList, boolean iWithInherited = CATFalse, const VPMDicTYPE iDicType = (VPMDicTYPE)0  ) const = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING" __FILE__ " VPMIDicRelationClass::GetPersistentName is useless.")

#else
    /**
  * FIXME: explain
  */
  virtual HRESULT GetPersistentName ( CATString & oPersistentName ) = 0;
#endif
};

CATDeclareHandler( VPMIDicRelationClass, VPMIDicGenericClass );

#endif
