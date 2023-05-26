//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
// Usage notes: used to introspect the different PathTypes
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicSubRelationship_h
#define _VPMIDicSubRelationship_h

#include "VPMIDicInterfaces.h"

#include "CATString.h"
#include "CATBaseUnknown.h"
#include "VPMIDicWithAttributes.h"
#include "VPMDicPROTECTION.h"

#if defined(REMOVE_USELESS_INCLUDE)
#else
class VPMIDicRelationship;
#endif
class VPMIDicSRContextConstraint;
class VPMIDicSRPatternConstraint;
class VPMIDicElement_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicSubRelationship;
#else
extern "C" const IID IID_VPMIDicSubRelationship;
#endif

/**
* Interface to manage Path which is a concept of the dictionary. It is also refered as Local PathType.
* Previously the keyword in metadata was SubRelationship. We changed it to Path in R2016x
*/

class  ExportedByVPMIDicInterfaces VPMIDicSubRelationship: public VPMIDicWithAttributes
{
  CATDeclareInterface;

public:

  /**
  * Retrieves the MultiValuated property.
  * Corresponds to MultiValuated keyword
  * @param oMultiValuated
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetMultiValuated ( boolean * oMultiValuated ) = 0;



  /**
  * Retrieves the Protection mode.
  * Corresponds to Protection keyword
  * @param oProtection : the Protection mode
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetProtection ( VPMDicPROTECTION *oProtection ) = 0;

  /**
  * Generates the information for the persistence of the path that will be created from this path type
  * @param oPathTypeName : name of the path type
  * @param oRoleName : value to be put in the role attribute. May be empty, once it won't be mandatory anymore to declare role
  * @param oCategoryName : value to be put in the category attribute. May be empty, once it won't be mandatory anymore to declare category
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, the list is not empty.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT ProducePathCharacteristics ( CATUnicodeString &oPathTypeName, CATUnicodeString &oRoleName, CATUnicodeString &oCategoryName) const = 0;


  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to access integrity constraint: do not use them
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------

  /**
  * Get the ContextConstraint element of the current SubRelationship, if any.
  * @param iName : Name of the ContextConstraint
  * @param oDicSRContextConstraint : the ContextConstraint [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a ContextContraint was found.</li>
  *    <li>E_FAIL   Operation failed, or no ContextContraint was found.</li>
  *    </ul>
  */
  virtual HRESULT GetContextConstraint ( const CATString & iName, VPMIDicSRContextConstraint ** oDicSRContextConstraint ) = 0;

  /**
  * Get the PatternConstraint element of the current SubRelationship according to its Name.
  * @param iName : Name of the PatternConstraint
  * @param oDicSRPatternConstraint : the PatternConstraint [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, a PatternContraint was found.</li>
  *    <li>E_FAIL   Operation failed, or no PatternContraint was found.</li>
  *    </ul>
  */
  virtual HRESULT GetPatternConstraint ( const CATString & iName, VPMIDicSRPatternConstraint ** oDicSRPatternConstraint ) = 0;

  /**
  * Retrieve the list of ContextConstraint elements of the current SubRelationship.
  * @param oContextConstraintList : list of ContextConstraint elements
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, the list is not empty.</li>
  *    <li>S_FALSE  Operation succeeded, but the list is empty.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetContextConstraintList ( CATLISTP(IUnknown) * oContextConstraintList ) = 0;

  /**
  * Retrieve the list of PatternConstraint elements of the current SubRelationship.
  * @param oPatternConstraintList : list of PatternConstraint elements
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded, the list is not empty.</li>
  *    <li>S_FALSE  Operation succeeded, but the list is empty.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPatternConstraintList ( CATLISTP(IUnknown) * oPatternConstraintList ) = 0;


  
  

  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to modify dictionary should never be user, except by providers
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------


  /**
  * Sets the MultiValuated characteristic of a path, which indicates if we can create several paths of this type or only one.
  * Corresponds to MultiValuated keyword
  * @param iMultiValuated
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetMultiValuated ( boolean iMultiValuated ) = 0;
  
  /**
  * Sets the Protection mode.
  * @param iProtection : the Protection mode
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetProtection ( const VPMDicPROTECTION iProtection ) = 0;

  
  //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------

  
#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicSubRelationship SetTarget is deprecated. You must remove it ")

#else

  /**
  * @deprecated
  * mkchecksource UNIPAT1: please remove usage of this method.  
  * Sets the referred Relationship.
  * @param iDicRelationship
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetTarget ( const VPMIDicRelationship* iDicRelationship ) = 0;
#endif 
#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicSubRelationship SetRole is deprecated. You must remove it ")

#else
  /**
  * Sets the Role property.
  * @param iRole
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetRole ( const CATUnicodeString *iRole ) = 0;
#endif 

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicSubRelationship SetSemantics is deprecated. You must remove it ")

#else
  /**
  * Sets the Semantics property.
  * @param iSemantics
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  //        virtual HRESULT SetSemantics  ( const VPMDicSEMANTICS iSemantics ) = 0;
  virtual HRESULT SetSemantics  ( const CATUnicodeString * iSemantics ) = 0;
#endif 

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING call to VPMIDicSubRelationship::SetUpper is deprecated. You must remove it.")

#else
  /**
  * Sets the Upper property.
  * @param iUpper
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetUpper ( int Upper ) = 0;
#endif

  
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING:  Call to VPMIDicSubRelationship SetLower is deprecated. You must remove it ")

#else
  /**
  * Sets the Lower property.
  * @param iLower
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetLower ( int Lower ) = 0;
#endif
  
#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ "  Call to VPMIDicSubRelationship GetTarget is deprecated. You must remove it ")

#else
  /**
  * @deprecated
  * mkchecksource UNIPAT1: please remove usage of this method.  
  * Retrieves the referred Relationship.
  * @param oDicRelationship [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetTarget ( VPMIDicRelationship ** oDicRelationship ) = 0;
#endif 
  
  
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING Call to VPMIDicSubRelationship GetUpper is deprecated. You must remove it ")

#else
  /**  We may keep this one for the future... But today it is not used
  * Retrieves the Upper property.
  * @param oUpper
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetUpper ( int * oUpper ) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING Call to VPMIDicSubRelationship GetLower is deprecated. You must remove it ")

#else
  /**
  * Retrieves the Lower property.
  * @param oLower
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetLower ( int * oLower ) = 0;
#endif

  
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING  Call to VPMIDicSubRelationship GetSemantics is deprecated. You must remove it ")

#else
  /**
  * Retrieves the Semantics property.
  * @param oSemantics
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  //        virtual HRESULT GetSemantics ( VPMDicSEMANTICS * oSemantics ) = 0;
  virtual HRESULT GetSemantics ( CATUnicodeString * oSemantics ) = 0;
#endif 

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING Call to VPMIDicSubRelationship GetRole is deprecated. You must remove it ")

#else
  /**
  * Retrieves the Role property.
  * @param oRole
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetRole ( CATUnicodeString * oRole ) = 0;
#endif 


};

CATDeclareHandler( VPMIDicSubRelationship, VPMIDicWithAttributes );

#endif
