//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
// Usage notes: used to introspect the different Extension
//=============================================================================
/**
* @level Private
* @usage U3
*/
#ifndef _VPMIDicExtension_h
#define _VPMIDicExtension_h

#include "VPMIDicInterfaces.h"

#include "VPMIDicClass.h"
#include "CATLISTPIUnknown.h"
#include "CATListValCATAttributeInfos.h"
#include "CATLISTV_VPMIDicElement_var.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByVPMIDicInterfaces const IID IID_VPMIDicExtension;
#else
extern "C" const IID IID_VPMIDicExtension;
#endif

class VPMIDicProcedure; 

#ifdef VPMIDicClass_DoesNotSupportExtensionAnymore
class ExportedByVPMIDicInterfaces VPMIDicExtension: public VPMIDicGenericClass
#else
class ExportedByVPMIDicInterfaces VPMIDicExtension: public VPMIDicClass
#endif
{
  CATDeclareInterface;

public:
  
  /**
  * Get the list of Classes or RelationClasses (or Paths and path types) that can be extended by the current Extension.
  * @param oElements  Classes or RelationClasses or Path types or Paths that can be extended by the current Extension
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetScopes (  CATLISTV_VPMIDicElement_var & oElements  ) = 0;

  /**
  * Indicates if this extension is a customer extension (created with data model customization toolsà
  */
  virtual boolean IsCustomerExtension () const = 0;

  /**
  * Indicates if this extension is a deployment extension (created with data model customization toolsà
  */
  virtual boolean IsDeployment () const = 0;


  //---------------------------------------------------------------------
  // Reading characteristics of the Extensions: old methods (still valid) that make sense in former typing mode only
  //---------------------------------------------------------------------

  /**
  * FIXME: indicate the algorithm so that we understand the method
  */
  virtual boolean IsIRPC () const = 0;
  
  /**
  * FIXME: What should we do with this method 
  * @param oppProcedure [out, CATBaseUnknown#Release]
  */
  virtual HRESULT GetProcedure ( const CATString & iMethodTypeName, const CATString & iMethodUsageName, VPMIDicProcedure** oppProcedure ) = 0;

  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
  // Methods to modify dictionary should never be user, except by providers
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------
      /**
       * Enriches an existing extension with attributes in dictionary cache as it is done by catalog application for chapters 
       * @param iExtensionType
       *  the extension to enrich
       * @param iListFilteredAtt
       * list of attributes to be added on the extension 
       * @param iCreatedExtensionType
       * Extension type created
       * @return
	     *  <ol>
	     * 	 <li> S_OK	if the modification has succeeded
	     * 	 <li> E_FAIL if one of the attribute already exists 
	     *  </ol>
       */

  virtual HRESULT EnrichExtensionModelingAChapter (const CATListValCATAttributeInfos &iListAttributesToAdd) =0;

   /**
  * Add a Class in the scope of the current Extension.
  * @param iClass Class to be added in the scope of the current Extension
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>S_FALSE  Operation succeeded, however useless because the Class is already registered in the scope.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT AddScope ( const VPMIDicClass * iClass ) = 0;


  /**
  * Remove a Class from the scope of the current Extension.
  * @param iClass Class to be removed from the scope of the current Extension
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT RemoveScope ( const VPMIDicClass * iClass ) = 0;
 
#if defined(REMOVE_USELESS_CALLS)

  #pragma message ("WARNING "   " VPMIDicExtension::GetScopes should be replaced by VPMIDicExtension::GetScopes with precise type.")

#else

  /**
  * Get the list of Classes or RelationClasses that can be extended by the current Extension.
  * FIXME: provide an example of usage to understand what we must do with the pointers
  * @param ioClassList  Classes or RelationClasses that can be extended by the current Extension
  * @return
  *    <ul>
  *    <li>S_OK     Operation succeeded.</li>
  *    <li>E_FAIL   Operation failed.</li>
  *    </ul>
  */
  virtual HRESULT GetScopes ( CATLISTP(IUnknown) * ioClassList ) = 0;
#endif



};

CATDeclareHandler( VPMIDicExtension, VPMIDicClass );

#endif
