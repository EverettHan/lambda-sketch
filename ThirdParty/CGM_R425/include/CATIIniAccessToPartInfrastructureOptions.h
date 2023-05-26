/**
 * @level Protected
 * @usage U3
 */
//===================================================================
// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIIniAccessToPartInfrastructureOptions.h
// Define the CATIIniAccessToPartInfrastructureOptions interface
//
//===================================================================
//
// Usage notes:
//   This interface is used as a trick for low-level framework to 
//   access some PartInfrastructure settings, as defined in
//   MecModInterfaces/CATIMmiPartInfrastructureSettingAtt.
//
//===================================================================
//
//  June 2005  Creation: JAC
//===================================================================
#ifndef CATIIniAccessToPartInfrastructureOptions_H
#define CATIIniAccessToPartInfrastructureOptions_H

#include "CATInteractiveInterfaces.h"
#include "CATBaseUnknown.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATInteractiveInterfaces IID IID_CATIIniAccessToPartInfrastructureOptions;
#else
extern "C" const IID IID_CATIIniAccessToPartInfrastructureOptions ;
#endif

//------------------------------------------------------------------
/**
 * This interface only mimics services already provided by 
 * MecModInterfaces/CATIMmiPartInfrastructureSettingsAtt interface.
 * <b>Role:</b>Refer to the interface mentioned here above for more details on the services.
 * <br/>Here under is an example on how to retrieve a pointer to CATIIniAccessToPartInfrastructureOptions interface:
 * <code>
 * <br/>#include "CATInstantiateComponent.h" //System
 * <br/>#include "CATIIniAccessToPartInfrastructureOptions.h"  //MecModInterfaces
 * <br/>{ 
 * <br/> ...
 * <br/> HRESULT rc=E_FAIL;
 * <br/> if(CATFrmEditor::GetCurrentEditor())
 * <br/>   {
 * <br/>     CATPathElement uiActiveObjectPath=CATFrmEditor::GetCurrentEditor()->GetUIActiveObject();
 * <br/>     CATDocument* pDocument=NULL;
 * <br/>     if(&uiActiveObjectPath)
 * <br/>       {
 * <br/>         uiActiveObjectPath.InitToLeafElement();
 * <br/>         CATBaseUnknown* pObject = uiActiveObjectPath.NextFatherElement();
 * <br/>         
 * <br/>         if(pObject)
 * <br/>           {
 * <br/>             CATILinkableObject *pILinkable=NULL;
 * <br/>             rc = pObject->QueryInterface(IID_CATILinkableObject, (void**)&pILinkable);
 * <br/>             if(SUCCEEDED(rc))
 * <br/>               {
 * <br/>                 pDocument=pILinkable->GetDocument();
 * <br/>                 pILinkable->Release(); pILinkable=NULL;
 * <br/>               }
 * <br/>           }
 * <br/>        }
 * <br/>  }
 * <br/> CATIIniAccessToPartInfrastructureOptions *pIAccessToOptions=NULL;
 * <br/> if(pDocument && SUCCEEDED(rc=pDocument->QueryInterface(IID_CATIIniAccessToPartInfrastructureOptions, (void**)&pIAccessToOptions)) && pIAccessToOptions)
  * <br/>   {
 * <br/>     //insert your code here
 * <br/>     pIAccessToOptions->Release(); pIAccessToOptions=NULL;
 * <br/>    }
 * <br/>  ...
 * <br/> }
 * </code> 
*/
class ExportedByCATInteractiveInterfaces CATIIniAccessToPartInfrastructureOptions: public CATBaseUnknown
{
  /**
   * Macro for interface declaration.
   */
  CATDeclareInterface;

public:
  /**
   * Naming mode parameter's possible values.
   * <b>Role</b>: This enumeration describes what naming mode is used.
   * @param NoNamingCheck
   *   Naming is rule-free,
   * @param NamingCheckUnderSameNode
   *   Two elements cannot have the same name under the same node,
   * @param NamingCheckWithinUIActiveObject
   *   Two elements cannot have the same name within a defined UIActiveObject.
   */
  enum NamingMode {NoNamingCheck=0, NamingCheckUnderSameNode, NamingCheckWithinUIActiveObject};

  /**
   * Retrieves the "NamingMode" parameter's value.
   * <br/><b>Role:</b> This parameter determines how an element can be named through Edit/Properties or any operation creating a feature (Copy-Paste, etc.).
   * <br/>When this option is being changed, it only affects elements whose name is modified afterwards.
   * @param oNamingMode
   *   Current "NamingMode" parameter's value: <ul><li><tt>NoNamingCheck</tt> when naming is rule-free,</li><li><tt>NamingCheckUnderSameNode</tt> when 2 elements cannot have the same name under the same node,</li><li><tt>NamingCheckWithinUIActiveObject</tt> when 2 elements cannot have the same name within a defined UIActiveObject.</li></ul>
   * @return
   *   S_OK if the parameter is correctly retrieved, E_FAIL otherwise.
   */
  virtual HRESULT GetNamingMode(CATIIniAccessToPartInfrastructureOptions::NamingMode& oNamingMode) = 0;

  /**
   * Sets the "Naming mode" parameter's value.
   * @param iNamingMode
   *   Chosen naming mode
   * @return
   *   S_OK if the parameter is correctly retrieved, E_FAIL otherwise.
   */
  virtual HRESULT SetNamingMode(const CATIIniAccessToPartInfrastructureOptions::NamingMode iNamingMode) = 0 ;

  /****** Pas nécessaire
   **
   * Update mode setting parameter's possible values.
   * <b>Role</b>: This enumeration describes what mode is active for update.
   * @param ManualUpdate
   *   User has to manually launch update tasks.
   * @param AutomaticUpdate
   *   Update is automatically launched
   *
  enum PartUpdateMode {ManualUpdate, AutomaticUpdate};

  **
   * Retrieves the "UpdateMode" parameter's value.
   * <br/><b>Role:</b> This parameter determines how the update of a .CATPart document is conducted.
   * @param oUpdateMode 
   *   Current update mode: <ul><li><tt>AutomaticUpdate</tt> when update is automatically launched,</li><li><tt>ManualUpdate</tt> when update has to be launched manually.</li></ul>
   * @return
   *   S_OK if the parameter is correctly retrieved, E_FAIL otherwise.
   *
  virtual HRESULT GetUpdateMode(PartUpdateMode& oUpdateMode) = 0;

  **
   * Sets the "Update mode" parameter's value.
   * @param iUpdateMode 
   *   Update mode: <ul><li><tt>AutomaticUpdate</tt> when update is to be automatically launched,</li><li><tt>ManualUpdate</tt> when update is to be launched manually.</li></ul>
   * @return
   *   S_OK if the parameter is correctly retrieved, E_FAIL otherwise.
   *
  virtual HRESULT SetUpdateMode(const PartUpdateMode iUpdateMode) = 0;


  **
   * Retrieves the "UpdateStoppedOnError" parameter's value.
   * <br/><b>Role:</b> This parameter determines if update tasks stop on the first detected error.
   * @param oStoppedOnError 
   *   Current "UpdateStoppedOnError" parameter's value:
   *      <ul><li>TRUE or 1 if update tasks stop,</li>
   *      <li>FALSE or 0 otherwise.</li></ul>
   * @return
   *   S_OK if the parameter is correctly retrieved, E_FAIL otherwise.
   *
  virtual HRESULT GetUpdateStoppedOnError(CATBoolean& oStoppedOnError) = 0;

  **
   * Sets the "Update stop" parameter's value.
   * @param iStoppedOnError 
   *   "Update stop" parameter's value:
   *      <ul><li>TRUE or 1 if update tasks have to stop,</li>
   *      <li>FALSE or 0 otherwise.</li></ul>
   * @return
   *   S_OK if the parameter is correctly retrieved, E_FAIL otherwise.
   *
  virtual HRESULT SetUpdateStoppedOnError(const CATBoolean iStoppedOnError) = 0;

  **
   * Retrieves the "UpdateElementsRefreshed" parameter's value.
   * <br/><b>Role:</b> This parameter determines if elements visualization has to be refreshed individually during update tasks.
   * @param oElementsRefreshed 
   *   Current "UpdateElementsRefreshed" parameter's value:
   *      <ul><li>TRUE or 1 if elements visualization is refreshed,</li>
   *      <li>FALSE or 0 otherwise.</li></ul>
   * @return
   *   S_OK if the parameter is correctly retrieved, E_FAIL otherwise.
   *
  virtual HRESULT GetUpdateElementsRefreshed(CATBoolean& oElementsRefreshed) = 0;

  **
   * Sets the "Elements refreshed at update" parameter's value.
   * @param iElementsRefreshed 
   *   "Elements refresh at update" parameter's value:
   *      <ul><li>TRUE or 1 if elements visualization is to be refreshed,</li>
   *      <li>FALSE or 0 otherwise.</li></ul>
   * @return
   *   S_OK if the parameter is correctly retrieved, E_FAIL otherwise.
   *
  virtual HRESULT SetUpdateElementsRefreshed(const CATBoolean iElementsRefreshed) = 0;
  ****/

  /**
   * Retrieves the "LinkedExternalReferences" parameter's value.
   * <br/><b>Role:</b> This parameter enables creation of external references with links.
   * @param oWithLink
   *   "LinkedExternalReferences" parameter's value:
   *      <ul><li>TRUE or 1 if external references are created with links,</li>
   *      <li>FALSE or 0 otherwise.</li></ul>
   * @return
   *   S_OK if the parameter is correctly retrieved, E_FAIL otherwise.
   */
  virtual HRESULT GetLinkedExternalReferences(CATBoolean& oWithLink) = 0;

  /**
   * Retrieves the "LinkedExternalReferencesWarningAtCreation" parameter's value.
   * <br/><b>Role:</b> This parameter defines if a warning panel is displayed each time an external reference with llink is created. The panel enables the user to decide whether the link will be kept or not.
   * <br/>This option is only used when external references are created with link.
   * @param oWarningAtCreation
   *   Current "LinkedExternalReferencesWarningAtCreation" parameter's value:
   *      <ul><li>TRUE or 1 if a panel is displayed upon external references with link creation,</li>
   *      <li>FALSE or 0 otherwise.</li></ul>
   * @return
   *   S_OK if the parameter is correctly retrieved, E_FAIL otherwise.
   */
  virtual HRESULT GetLinkedExternalReferencesWarningAtCreation(CATBoolean& oWarningAtCreation) = 0;
};

CATDeclareHandler(CATIIniAccessToPartInfrastructureOptions,CATBaseUnknown);

#endif
