//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2014/06/03
//===================================================================
// VPMIDicWithAttributes.cpp
// Header definition of class VPMIDicWithAttributes
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2014/06/03 Creation: Code generated by the 3DS wizard
//===================================================================



//===================================================================
//-- This interface regroups methods that are common for all these concepts in metadata
//-- Class, Extension, RelationClass, PathType, Path
//-- It provides
//-- The access to the list of attributes 
//-- The access to the visibility of this concept in UI and in programming toolkits (CustomerExposition)
//-- The type inheritance
//-- The fact that this concept is abstract or not
//===================================================================



#ifndef VPMIDicWithAttributes_H
#define VPMIDicWithAttributes_H

#include "VPMIDicInterfaces.h"
#include "VPMIDicElement.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATLISTV_VPMIDicSimple_var.h"
#include "CATLISTV_VPMIDicElement_var.h"
#include "CATUnicodeString.h"


extern ExportedByVPMIDicInterfaces  IID IID_VPMIDicWithAttributes ;


// This interface is available on an element of the dictionary (Class, Extension, RelationClass, PathType, Path)
class ExportedByVPMIDicInterfaces VPMIDicWithAttributes: public VPMIDicElement
{
  CATDeclareInterface;

public:

  //------------------------------------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------------------------------------
  // Accessing element hierarchy
  //------------------------------------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------------------------------------

  /**
  * Get the super element of the current element.
  * Corresponds to the "SuperName" keyword in most cases, and to the Type keyword for "Path"
  * @param oSuperElement 
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSuperElement ( VPMIDicElement_var & oSuperElement) const = 0;


  /**
  * Get the Name of the super element (if any) from which the current element inherits.
  * Corresponds to the "SuperName" keyword in most cases, and to the Type keyword for "Path"
  * @param oName Name of the super entity in output of the method
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSuperName ( CATUnicodeString & oName ) const = 0;

  /**
  * Tests if an element inherits from another one.
  */
   virtual CATBoolean  IsaSortOf (const VPMIDicElement_var &iElement) const =0;

   /**
  * Tests if an element inherits from another one.
  */
   virtual CATBoolean  IsaSortOfName (const CATUnicodeString &iElementName) const =0;

   /**
  * Get the list of sub-elements of the current element (in terms of hierarchy.
  * @param oElements
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
   virtual HRESULT GetSubElements( CATLISTV_VPMIDicElement_var & oElements ) = 0;

  //------------------------------------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------------------------------------
  // Accessing characteristics
  //------------------------------------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------------------------------------

  /**
  * Check whether the current element is abstract or not (can lead to the creation of real objects or not)
  * Corresponds to the "Abstract" keyword
  */
  virtual boolean IsAbstract () = 0;

  /**
  * Check whether the current element is public (ie. visible from EKL, UI) or private (ie. pure internal modeling).
  */
  virtual HRESULT IsExposedForPurpose ( const VPMDicCUSTOMEREXPOSITIONPURPOSE iPurpose, boolean & oIsExposed ) const = 0;

  //------------------------------------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------------------------------------
  // Accessing simples
  //------------------------------------------------------------------------------------------------------------------------
  //------------------------------------------------------------------------------------------------------------------------

  /**
  * Get a Simple attribute of the current element, by its name.
  * @oSimple the Simple in output, defined in the current element (or one of its super element)
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSimple ( const CATUnicodeString & iName, VPMIDicSimple_var & oSimple ) = 0;

  /**
  * Get the list of Simple elements of the current element (possibly restricted to those locally declared into the current element).
  * @param oSimples        List of Simple elements of the current element (local or inherited).
  * @param iWithInherited  with or without elements declared in super element.
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSimples ( CATLISTV_VPMIDicSimple_var & oSimples, boolean iWithInherited = CATFalse ) = 0;






  //---------------------------------------------------------------------
  // Deprecated methods
  //---------------------------------------------------------------------

#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "   " VPMIDicWithAttributes::GetSuperName(CATString) should be replaced by VPMIDicWithAttributes::GetSuperName(CATUnicodeString).")

#else
  /**
  * Get the Name of the super Class (if any).
  * @param oName Name of the super Class
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetSuperName ( CATString * oName ) = 0;
#endif
  
};

//-----------------------------------------------------------------------
CATDeclareHandler( VPMIDicWithAttributes, VPMIDicElement );

#endif
