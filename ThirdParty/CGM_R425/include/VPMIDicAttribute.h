//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicAttribute_h
#define _VPMIDicAttribute_h

#include "VPMIDicInterfaces.h"

#include "CATCORBABoolean.h"
#include "VPMIDicElement.h"
#include "VPMDicCOLLECTION.h"
#include "VPMDicSEMANTICS.h"
#include "VPMDicACCESSMODE.h"
#include "VPMDicSCOPE.h"
#include "VPMDicPROTECTION.h"


class VPMIDicPackage;
class VPMIDicCollection;
class VPMIDicClass;
class CATString ;


#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicAttribute;
#else
extern "C" const IID IID_VPMIDicAttribute;
#endif
class  ExportedByVPMIDicInterfaces VPMIDicAttribute: public VPMIDicElement
{
  CATDeclareInterface;

public:


  /**
  * Gets the "MultiValuated" property of the Attribute.
  * @param oMultiValuated : CATTrue/CATFalse, "MultiValuated" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetMultiValuated ( boolean *oMultiValuated ) = 0;

   
  /**
  * Gets the "CollectionType" property of the Attribute (relevant only if the Attribute is MultiValuated).
  * Please refer to VPMDicCOLLECTION.h for the list of possible values.
  * @param oCollType : "CollectionType" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetCollectionType ( VPMDicCOLLECTION * oCollType ) = 0;


  /**
  * Gets the "Default" value of the Attribute (relevant only for VPMIDicSimple).
  * @param oDefaultValue : "Default" value of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetDefault ( CATUnicodeString * oDefaultValue ) = 0;



  /**
  * Gets the "MaxLength" property of the Attribute.
  * @param oMaxLength : "MaxLength" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetMaxLength ( int * oMax ) = 0;



  /**
  * Recovers the information whether the Attribute is, or is not, a system Attribute.
  * @param IsSystemAttr : CATTrue/CATFalse
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT IsSystemAttribute ( boolean * IsSystemAttr ) = 0;


  
  /**
  * Retrieves the Protection mode.
  * @param oProtection : the Protection mode
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetProtection ( VPMDicPROTECTION *oProtection ) = 0;

  /**
  * Retrieves the PLMVisibility according to the Protection mode.
  * @param oPLMVisibility : the PLM Visibility
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPLMVisibility ( VPMDicPLMVISIBILITY *oPLMVisibility ) = 0;


  /**
  * Retrieves the PLMExposition according to the Protection mode.
  * @param oPLMVisibility : the PLM Exposition
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPLMExposition ( VPMDicPLMEXPOSITION *oPLMExposition ) = 0;


  /**
  * Retrieves the PLMClientEditability according to the Protection mode.
  * @param oPLMClientEditability : the PLM Client Editability
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPLMClientEditability ( VPMDicPLMCLIENTEDITABILITY *oPLMClientEditability ) = 0;

  //---------------------------------------------------------------------
  // Reading characteristics of the Simple: old methods (still valid) that make sense in former typing mode only
  //---------------------------------------------------------------------

  /**
  * Retrieves the CAAExposition mode.
  * NB: CAAExposition mode is significant only for attributes which Protection mode is set to either User, Free, External or External_RO.
  * @param oCAAExposition : the CAAExposition mode
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetCAAExposition ( VPMDicCAAEXPOSITION * oCAAExposition ) = 0;

  /**
  * Recovers the information whether the Attribute is, or is not, part of the IdentifierSet defined for the Class or the Extension.
  * @param oBelongsToIdentifierSet : CATTrue/CATFalse
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetBelongsToIdentifierSet ( boolean *oBelongsToIdentifierSet ) = 0;



  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to modify dictionary should never be user, except by providers
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
 

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

  /**
  * Sets the CAAExposition mode.
  * NB: CAAExposition mode is significant only for attributes which Protection mode is set to either User, Free, External or External_RO.
  * @param iCAAExposition : the CAAExposition mode
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetCAAExposition ( const VPMDicCAAEXPOSITION iCAAExposition ) = 0;

  /**
  * Sets the "MaxLength" property of the Attribute.
  * @param iMaxLength : "MaxLength" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetMaxLength ( int Max ) = 0;

  /**
  * Sets the "Default" value of the Attribute (relevant only for VPMIDicSimple).
  * @param iDefaultValue : "Default" value of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetDefault ( const CATUnicodeString * iDefaultValue ) = 0;

  /**
  * Sets the "MultiValuated" property of the Attribute.
  * @param iMultiValuated : CATTrue/CATFalse, "MultiValuated" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetMultiValuated ( boolean iMultiValuated ) = 0;

  /**
  * Sets the "Mandatory" property of the Attribute.
  * @param iMandatory : CATTrue/CATFalse, "Mandatory" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetMandatory ( boolean iMandatory ) = 0;

   /**
  * Sets the "CollectionType" property of the Attribute (relevant only if the Attribute is MultiValuated).
  * Please refer to VPMDicCOLLECTION.h for the list of possible values.
  * @param iCollType : "CollectionType" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetCollectionType ( const VPMDicCOLLECTION iCollType ) = 0;


   //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------
#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ " VPMIDicAttribute::SetScope is useless. Its usage should be suppressed.")

#else
  /**
  * Sets the "Scope" property of the Attribute (relevant only for VPMIDicRelationship or VPMIDicInverse).
  * Please refer to VPMDicSCOPE.h for the list of possible values.
  * @param iScope : "Scope" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetScope ( const VPMDicSCOPE iScope ) = 0;
#endif 

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ " VPMIDicAttribute::AddScope is useless. Its usage should be suppressed.")

#else

    /**
  * @nodoc
  * (relevant only for VPMIDicRelationship)
  * @param iElement
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT AddScope ( const VPMIDicElement *iElement ) = 0;
#endif

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ " VPMIDicAttribute::RemoveScope is useless. Its usage should be suppressed.")

#else
 /**
  * @nodoc
  * (relevant only for VPMIDicRelationship)
  * @param iElement
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT RemoveScope ( const VPMIDicElement *iElement ) = 0;
#endif

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ " VPMIDicAttribute::GetScopes is useless. Its usage should be suppressed.")

#else
  /**
  * @nodoc
  * (relevant only for VPMIDicRelationship)
  * @param ioElements
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetScopes ( CATLISTP(IUnknown) * ioElements ) = 0;
#endif 


#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ " VPMIDicAttribute::GetScope is useless. Its usage should be suppressed.")

#else
  /**
  * Gets the "Scope" property of the Attribute (relevant only for VPMIDicRelationship or VPMIDicInverse).
  * Please refer to VPMDicSCOPE.h for the list of possible values.
  * @param oScope : "Scope" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetScope ( VPMDicSCOPE *oScope ) = 0;
#endif

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 141006 " __FILE__  " VPMIDicAttribute::SetAccessMode Obsolete methods, please suppress the usage. ")

#else

  /**
  * @deprecated
  * @nodoc
  */
  virtual HRESULT SetAccessMode ( const VPMDicACCESSMODE iAccessMode ) = 0;
#endif 


#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 141006 " __FILE__  " VPMIDicAttribute::GetAccessMode Obsolete methods, please suppress the usage. ")

#else
  /**
  * @deprecated
  * @nodoc
  */
  virtual HRESULT GetAccessMode ( VPMDicACCESSMODE *oAccessMode ) = 0;

#endif 

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ " VPMIDicAttribute::SetSemantics Obsolete methods, please suppress the usage. ")

#else
  /**
  * @deprecated
  * @nodoc
  */
  virtual HRESULT SetSemantics ( const VPMDicSEMANTICS iSemantics ) = 0;
#endif 

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ " VPMIDicAttribute::GetSemantics Obsolete methods, please suppress the usage. ")

#else
  /**
  * @deprecated
  * @nodoc
  */
  virtual HRESULT GetSemantics ( CATListOfInt & oSemantics ) = 0;
#endif

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ " VPMIDicAttribute::SetSemantics Obsolete methods, please suppress the usage. ")

#else
  /**
  * Sets the "Semantics" property of the Attribute (relevant only for VPMIDicRelationship or VPMIDicInverse).
  * @param iSemantics : "Semantics" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetSemantics ( const CATUnicodeString * iSemantics ) = 0;
#endif

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 140316 " __FILE__ " VPMIDicAttribute::SetSemantics Obsolete methods, please suppress the usage. ")

#else
  /**
  * Gets the "Semantics" property of the Attribute (relevant only for VPMIDicRelationship or VPMIDicInverse).
  * @param oSemantics : "Semantics" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSemantics ( CATUnicodeString * oSemantics ) = 0;
#endif



#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicAttribute::SetLower Obsolete methods, please suppress the usage. ")

#else
  /**
  * Sets the "Lower" property of the Attribute (relevant only if the Attribute is MultiValuated).
  * @param iLower : "Lower" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetLower ( int Lower ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicAttribute::GetLower Obsolete methods, please suppress the usage. ")

#else
  /**
  * Gets the "Lower" property of the Attribute (relevant only if the Attribute is MultiValuated).
  * @param oLower : "Lower" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetLower ( int * oLower ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicAttribute::SetUpper Obsolete methods, please suppress the usage. ")

#else
  /**
  * Sets the "Upper" property of the Attribute (relevant only if the Attribute is MultiValuated).
  * @param iUpper : "Upper" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetUpper ( int Upper ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " VPMIDicAttribute::GetUpper Obsolete methods, please suppress the usage. ")

#else
  /**
  * Gets the "Upper" property of the Attribute (relevant only if the Attribute is MultiValuated).
  * @param oUpper : "Upper" property of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetUpper ( int * oUpper ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " call to VPMIDicAttribute::GetOrigin should be replaced by  VPMIDicElement::GetOwnedBy. ")

#else
  /**
  * @deprecated
  * preferred method: VPMIDicElement::GetOwnedBy(VPMIDicElement_var&)
  */
  virtual HRESULT GetOrigin ( VPMIDicClass **oOClass ) = 0;
#endif 
  
#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " call to VPMIDicAttribute::SetType should be suppressed. ")

#else
  /**
  * Sets the target element of the Attribute.
  * @param iElement : the targeted Element of the Attribute
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT SetType ( const VPMIDicElement *iElement ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING "   " call to VPMIDicAttribute::GetType should be suppressed ")

#else
  /**
  * Gets the target element of the Attribute.
  * @param oElement : the targeted Element of the Attribute [out, CATBaseUnknown#Release]
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetType ( VPMIDicElement **oElement ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

#pragma message ("WARNING " __FILE__ " call to VPMIDicAttribute::GetMandatory should be suppressed ")

#else
  /**
  * @deprecated
  * @nodoc
  */
  virtual HRESULT GetMandatory ( boolean * oMandatory ) = 0;
#endif

};

CATDeclareHandler( VPMIDicAttribute, VPMIDicElement );

#endif




