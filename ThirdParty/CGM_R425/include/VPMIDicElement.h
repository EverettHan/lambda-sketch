//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
// Usage notes: this interface is shared by almost all dictionary elements
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMIDicElement_h
#define _VPMIDicElement_h

#include "VPMIDicInterfaces.h"

#include "CATCORBABoolean.h"

#include "VPMDicTYPE.h"
#include "VPMDicVISIBILITY.h"
#include "VPMDicCUSTOMEREXPOSITIONPURPOSE.h"
#include "CATBaseUnknown.h"
#include "CATLISTPIUnknown.h"
#include "CATListOfCATUnicodeString.h" 

class CATString;
class CATUnicodeString;

class VPMIDicPackage;
class VPMIDicComment;
class VPMIDicCAAComment;
class CATDbBinary;

class VPMIDicElement_var;

#ifndef LOCAL_DEFINITION_FOR_IID
extern  ExportedByVPMIDicInterfaces const IID IID_VPMIDicElement;
#else
extern "C" const IID IID_VPMIDicElement;
#endif

/**
 * Class managing all basic dictionary types.
 */
class  ExportedByVPMIDicInterfaces VPMIDicElement : public CATBaseUnknown
{
    CATDeclareInterface;

    public:
   
   /**
    * Retrieves the element type.
    */
    virtual VPMDicTYPE Type() const =0;

    /**
    * Retrieves the element's name.
    * @param oName : Dictionary element name
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetName( CATString * oName) = 0;

    /**
    * Retrieves the package containing the element.
    * @param oPackage : Package [out, CATBaseUnknown#Release]
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetPackage ( VPMIDicPackage ** oPackage) = 0;
     
  
/**  
    * Get the Name of the Package in which the current Element is defined.
    * @return oName Name of the Package
    */
    virtual CATUnicodeString GetPackageName ( ) const = 0;
     
    /**
    * Retrieves the element's NLSTag.
    * @param oNLSTag : NLSTag
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetNLSTag ( CATUnicodeString & oNLSTag) = 0;

    /**
    * Retrieves the element's NLSValue.
    * @param oNLSValue : NLSValue
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetNLSValue ( CATUnicodeString & oNLSValue) = 0;

  
    /**
    * Get the Element in which the current Element is defined.
    * @param oOwnedBy the Element in which the current Element is defined
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetOwnedBy ( VPMIDicElement_var & oOwnedBy ) const = 0;


    /**
    * Retrieves the list of all attributes names and values of the current element.
    * @param oAttrNames  : list of attributes names
    * @param oAttrValues : list of attributes values
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetAllAttributes ( CATListOfCATUnicodeString & oAttrNames, CATListOfCATUnicodeString & oAttrValues ) = 0;



    //---------------------------------------------------------------------
    // Properties
    //---------------------------------------------------------------------

    /**
    * Retrieves the Property value with the given Name, possibly taking into account Properties defined in super Classes
    * Corresponds to the Property keyword
    * @param iPropertyName : the name of the Property
    * @param oPropertyValue : the corresponding value of the Property
    * @return
    *    <ul>
    *    <li>S_OK    The Property was found, and returned value is not a "length=0 string".</li>
    *    <li>S_FALSE The Property was found, but the returned value is a "length=0 string".</li>
    *    <li>E_FAIL  The Property was not found.</li>
    *    </ul>
    */
    virtual HRESULT getPropertyValue ( const CATUnicodeString &iPropertyName, CATUnicodeString & oPropertyValue, const boolean iWithInheritance = CATFalse ) const = 0;

    /** 
    * Retrieves the names and the values of all Properties assigned to the current element, possibly taking into account Properties defined in super Classes.
    * Corresponds to the Property keyword
    * @param oNames : the list of Property names
    * @param oValues : the list of corresponding Property values
    * @return
    *    <ul>
    *    <li>S_OK    Operation succeeded.</li>
    *    <li>E_FAIL  No Property could be found.</li>
    *    </ul>
    */
    virtual HRESULT getPropertyNamesAndValues ( CATListOfCATUnicodeString & oNames, CATListOfCATUnicodeString & oValues, const boolean iWithInheritance = CATFalse ) const = 0;

    
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to modify dictionary should never be user, except by providers
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
 
  /**
    * Sets the object name.
    * @param oName : Dictionary object name
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT SetName ( const CATString *iNewName ) = 0;

    

   //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------
#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 141006 "  __FILE__  " VPMIDicElement::GetVisibilityis an obsolete method, please suppress the usage. ")

#else
     /**
     * @deprecated
     * @nodoc
     */
    virtual HRESULT GetVisibility ( VPMDicVISIBILITY *oVisibility) = 0;
#endif

#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 141006 "  __FILE__  " VPMIDicElement::SetVisibility is an obsolete method, please suppress the usage. ")

#else
    /**
    * Sets the visibility tag of the element.
    * @param oVisibility : Visibility
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT SetVisibility ( const VPMDicVISIBILITY inVISIBILITY) = 0;
#endif
#if defined(REMOVE_USELESS_INCLUDE)

#pragma message ("BADREM : FRH 141006 "  __FILE__  " VPMIDicElement::GetAlias is obsolete, please suppress the usage. ")

#else
  /**
    * @deprecated
    * Retrieves the element's alias.
    * @param oAlias : Alias
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetAlias ( CATUnicodeString * oAlias) = 0;
#endif
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "   " VPMIDicElement::GetPackageName should be replaced by VPMIDicElement::GetPackageName with no argument.")

#else
  /**
  * Get the Name of the Package in which the current Class is defined.
  * @param oName Name of the Package
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetPackageName ( CATString * oName ) = 0;

#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "   " VPMIDicElement::GetComment is useless.")

#else
/**
    * Retrieves the Comment for the current element.
    * @param oDicComment : Comment [out, CATBaseUnknown#Release]
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetComment        ( VPMIDicComment ** oDicComment ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "   " VPMIDicElement::GetCAAComment is useless.")

#else
    /**
    * Retrieves the CAAComment for the current element.
    * @param oDicCAAComment : CAAComment [out, CATBaseUnknown#Release]
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetCAAComment     ( VPMIDicCAAComment ** oDicCAAComment ) = 0;
#endif

    
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "   " VPMIDicElement::GetURL is useless.")

#else
    /**
    * Retrieves the object's URL.
    * @param oURL : Dictionary object's URL
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetURL ( CATDbBinary & oURL ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "   " VPMIDicElement::GetUuid is useless.")

#else
        /**
    * Retrieves the object UUID.
    * @param oUuid : Dictionary object UUID
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT GetUuid(CATDbBinary * oUuid) = 0;

#endif

#if defined(REMOVE_USELESS_CALLS)
 #pragma message ("WARNING "   " VPMIDicElement::CreateCAAComment is obsolete.")

#else
    /**
    * Creates a CAAComment for the current element.
    * @param oDicCAAComment : CAAComment [out, CATBaseUnknown#Release]
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT CreateCAAComment  ( VPMIDicCAAComment ** oDicCAAComment ) = 0;
#endif

#if defined(REMOVE_USELESS_CALLS)
 #pragma message ("WARNING "   " VPMIDicElement::CreateComment is obsolete.")

#else
    /**
    * Creates a Comment for the current element.
    * @param oDicComment : Comment [out, CATBaseUnknown#Release]
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT CreateComment     ( VPMIDicComment ** oDicComment ) = 0;
#endif


#if defined(REMOVE_USELESS_CALLS)
 #pragma message ("WARNING "   " VPMIDicElement::SetUuid is obsolete.")

#else
    /**
    * Sets the object UUID.
    * @param oUuid : Dictionary object UUID
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT SetUuid(const CATDbBinary * ioUuid) = 0;
#endif
    
    
    
#if defined(REMOVE_USELESS_CALLS)
 #pragma message ("WARNING "   " VPMIDicElement::SetAlias is obsolete.")

#else
/**
    * @deprecated
    * Sets the element's alias.
    * @param iAlias : Alias
    * @return
    *    <ul>
    *    <li>S_OK     Operation succeeded.</li>
    *    <li>E_FAIL   Operation failed.</li>
    *    </ul>
    */
    virtual HRESULT SetAlias ( const CATUnicodeString *iAlias) = 0;
#endif
};

CATDeclareHandler(  VPMIDicElement,  CATBaseUnknown  );

#endif
