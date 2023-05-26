// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIAdpEnvironment.h
// Define the CATIAdpEnvironment interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Apr 2005  Creation: Code generated by the CAA wizard  PMM
//===================================================================
/**
* @CAA2Level L1
* @CAA2Usage U3  
*/
#ifndef CATIAdpEnvironment_H
#define CATIAdpEnvironment_H

#include "CATPLMIntegrationAccess.h"
#include "CATPLMCoreType.h"
#include "CATBaseUnknown.h"

class CATString;
class CATListPtrCATBaseUnknown ;
class CATUnicodeString;
class CATIAdpType;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpEnvironment;
#else
extern "C" const IID IID_CATIAdpEnvironment ;
#endif

//------------------------------------------------------------------

/**
* Interface representing PLM Environment.
*
* <br><b>Role</b>: Components that implement this interface are PLM environment.
* You retrieves environment by using @href CATAdpDictionaryServices.
* @see CATAdpDictionaryServices
*/
class ExportedByCATPLMIntegrationAccess CATIAdpEnvironment: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  
  /**
  * @deprecated R213 Use @href CATCkePLMNavPublicServices#RetrieveKnowledgeType  <br>
  * Gets the PLMType which is being authorized to use in creation in this environment.
  *
  * <br><b>Role</b>: Informs the user about the type of component that can be created in this environment.
  *
  * @param iModeler [in]
  *   The modeler in which the user wants to known the authorized kind of -PLMCoreType- to be create.
  * @param iCoreType [in]
  *   The PLMCoreType required (PLM_Reference, PLM_Instance ...).
  * @param iIID [in]
  *   The iid of the interface expected as result.
  * @param oType [out, CATBaseUnknown#Release]
  *   The type of component that can be created in this environment. Release the returned object when useless.
  * @return
  * <dt> <code>S_OK</code>     <dd> A PLMType is an authoring type for the provided PLMCoreType in the provided modeler.
  * <dt> <code>S_FALSE</code>  <dd> No authoring type available for this PLMCoreType in the modeler.
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  * @see CATIAdpType
  *
  */
  virtual HRESULT GetAuthoringType( const CATString & iModeler, 
                                    const CATPLMCoreType & iCoreType, 
                                    const IID & iIID,
                                    void ** oType )=0;
  
  
/**
  * @deprecated R213 Use @href CATCkePLMNavPublicServices#RetrieveKnowledgeType  <br>
  * Gets the PLMTypes which can be examined by the user in this environment.
  *
  * <br><b>Role</b>: Informs the user about the types of components that can be examined in this environment. 
  *
  * @param iModeler [in]
  *   The modeler in which the user wants to known the authorized kind of -PLMCoreType- to be examined.
  * @param iCoreType [in]
  *   The PLMCoreType required (PLM_Reference, PLM_Instance ...).
  * @param oTypes [out, CATBaseUnknown#Release]
  *   The types of components that can be examined in this environment. Release the returned objects when useless.
  * @return
  * <dt> <code>S_OK</code>     <dd> At least one CATIPLMType is a usable type for the provided PLMCoreType in the provided modeler.
  * <dt> <code>S_FALSE</code>  <dd> No usable type available for this PLMCoreType in the modeler.
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  * @see CATIAdpType
  */
  virtual HRESULT GetUsableTypes( const CATString & iModeler, 
                                  const CATPLMCoreType & iCoreType, 
                                  CATListPtrCATBaseUnknown & oTypes ) = 0 ;

  /**
  * Gets the environment name as NLS name.
  *
  * <br><b>Role</b>: Allows the user to retrieve the environment NLS alias.
  *
  * @param oAlias [out]
  *   The environment alias.
  * @return
  * <dt> <code>S_OK</code>     <dd> an Alias was retrieved.
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  */
  virtual HRESULT GetAlias( CATUnicodeString & oAlias )=0;


  /**
  * @deprecated R213 Use @href CATCkePLMNavPublicServices#RetrieveKnowledgeType  <br>
  * Returns a type inside Usable list from Customisation / Modeler inputs.
  *
  * <br><b>Role</b>: Try to find a specific type from usable list.
  *
  * @param iModelerName [in]
  *   The modeler in which the user wants to get the Type to be examined.
  * @param iModelerTypeName [in]
  *   The metadata name of the base type in the modeler from which the type will be found.
  * @param iCustoName [in]
  *   The name of the customisation to search in. This string can be empty if <tt> iModelerTypeName </tt> is a concrete type (instantiable type).
  * @param oType [out, CATBaseUnknown#Release]
  *   The type found.
  * @return
  * <dt> <code>S_OK</code>     <dd> A type is found.
  * <dt> <code>E_FAIL</code>   <dd> Failure
  *
  * @see CATIAdpType
  */
  virtual HRESULT GetUsableTypeFromTypeIdentification (const CATString &  iModelerName , 
                                                            const CATString & iModelerTypeName, 
                                                            const CATString & iCustoName, 
                                                            CATIAdpType **oType ) = 0;

};

//------------------------------------------------------------------

#endif