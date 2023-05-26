
#ifndef CATCAfrComponentServices_H
#define CATCAfrComponentServices_H

// COPYRIGHT DASSAULT SYSTEMES 2012

#include "CATAfrItf.h"
#include "CATErrorDef.h"
#include "CATString.h"

class CATICAfrComponentController;
class CATSYPEventHandler;
class CATUnicodeString;
class CATICAfrComponent;
class CATISYPCollection;
/**
 * Class to manage C-Afr component life cycle
 * Please look at the documentation in http://codewiki/codewiki/index.php/C-Afr_programmer's_guide
 */
class ExportedByCATAfrItf CATCAfrComponentServices
{
  friend class CATAfrModelRoot;
  friend class CATCAfrSynchToControllerCmd; // for use of CATCAfrCurrentComponentIdForHeaders
  friend class CATEDeclarativeCmdContainer; // for use of RegisterComponent
  friend class CATCmdContainer;             // for use of RegisterComponent
  friend class CATCAfrMenu;                 // for use of RegisterComponent
  friend class CATApplicationDocument;      // for use of CleanComponents
  friend class UnitTestApplication;         // for use of CleanComponents
  friend class SYPUnitTestsRunnerSignatureApp; // for use of CleanComponents

  public:

   /**
    * Instantiate a C-Afrcomponent, respect the Naming convention
    * Respect the hierarchy component, the naming is generated with this format:
    * NameComp1.NameComp2.NameComp3....
    *
    * <br><b>Role</b>: This method instantiates a C-Afr component
    *
    *  @param iXMLFile
    *  The XML file to declare the Template
    *
    *  @param iTemplateName
    *  The Template name
    *
    *  @param iComponentInstanceName
    *  The Instance id, the id don't content special characters @ | .,...
    *
    *  @param opIAfrComponent
    *  The created C-Afr component [out, CATICAfrComponent#Release]
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>S_FALSE</b>The function has being retrieve the existing component.</li>
    *     <li><b>E_FAIL</b>An error occurred. The component was not created.</li>
    *     </ul>
    *
    */
    static HRESULT CATCAfrInstantiateComponent( CATICAfrComponent** opIAfrComponent, 
                                                const CATUnicodeString& iXMLFile, 
                                                const CATUnicodeString& iTemplateName, 
                                                const CATString& iComponentInstanceName );

   /**
    * Instantiate a C-Afrcomponent, respect the Naming convention
    * Respect the hierarchy component, the naming is generated with this format:
    * NameComp1.NameComp2.NameComp3....
    *
    * <br><b>Role</b>: This method instantiates a C-Afr component
    *
    *  @param iComponentType
    *  The component type
    *
    *  @param iComponentInstanceName
    *  The Instance id
    *
    *  @param opIAfrComponent
    *  The created C-Afr component [out, CATICAfrComponent#Release]
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>S_FALSE</b>The function has being retrieve the existing component.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    static HRESULT CATCAfrInstantiateComponent( const CATString& iComponentType, 
                                                const CATString& iComponentInstanceName, 
                                                CATICAfrComponent** opIAfrComponent );

   /**
    * Delete a C-Afrcomponent
    *
    * <br><b>Role</b>: This method deletes a C-Afr component
    *
    *  @param iComponentInstanceName
    *  The Instance id
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    static HRESULT CATCAfrDeleteComponent( const CATString& iComponentInstanceName );

    /**
    * Delete a C-Afrcomponent
    *
    * <br><b>Role</b>: This method deletes a C-Afr component
    *
    *  @param ipiAfrComponent
    *  The component to delete
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    static HRESULT CATCAfrDeleteComponent( CATICAfrComponent* ipiAfrComponent );

    /**
    * Search a C-Afrcomponent
    * Respect the hierarchy component, the naming is with this format:
    * NameComp1.NameComp2.NameComp3....

    * <br><b>Role</b>: This method searches a C-Afr component
    *
    *  @param iComponentInstanceName
    *  The Instance id
    *
    *  @param opiAfrComponent
    *  The C-Afr component [out, CATICAfrComponent#Release]
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    static HRESULT CATCAfrGetComponent( const CATString& iComponentInstanceName, 
                                        CATICAfrComponent** opiAfrComponent );

    
    /**
    * Trigger a change on a component with a specific value that you defined
    *
    * <br><b>Role</b>: This method triggers a component change
    *
    *  @param iComponentInstanceName
    *  The Instance id
    *
    *  @param iValue
    *  The specific value that you want to set on the ComponentChange property of your component.
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    static HRESULT CATCAfrComponentChange( const CATString& iComponentInstanceName, 
      const CATUnicodeString & iValue );    
   /**
    * Register a controller on a component even if it has not created yet.
    *
    * <br><b>Role</b>: This method register a controller on a component
    * When the component is instantiated and you call this service before, an event will sent to the controller
    * with the event id "ComponentRegistered".
    *
    * If a controller always exists for this component, it will be replaced.
    *
    *  @param iComponentInstanceName
    *  The Instance id of a component that you want to register.
    *  @param ipiController
    *  The controller to register on a component. You can release your controller after. If the component is not created yet, 
    *  the controller will be keeped until the component will be instantiated.
    *
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>E_FAIL</b> An error occurred during the execution of the function.</li>
    *     </ul>
    *
    */
    static HRESULT CATCAfrRegisterController( const CATString& iComponentInstanceName, 
      CATICAfrComponentController* ipiController );    
   /**
    * Add a callback when the view of a component is deleted. 
    * The notification is sent only if view parent is null (The component will create a panel box).
    *
    * @param iComponentInstanceName 
    *   The name of the component
    * @param iMethodToExecute
    *   The method to execute 
    * @param iUsefulData
    *   Data to pass to <tt>iMethodToExecute</tt> and that can be useful to this method
    * @return
    *   The added callback
    */
    static  HRESULT AddComponentViewDeletedCB (const CATString& iComponentInstanceName,CATSYPEventHandler * i_pHandler);

    
   /**
    * Include declarative elements in a component.
    *
    * <br><b>Role</b>: Includes elements in the component by declarative by providing the template name and the xml file.
    * @param ipiAfrComponent : the component that will host new elements generated by declarative
    * @param iTemplateName : the name of the template
    * @param iXmlFile : the XML file that contains this template
    * @return
    * <dl>
    * <dt><code>S_OK</code> <dd>
    * <dt><code>E_FAIL</code> <dd>
    * </dl>
    */
    static HRESULT IncludeElementsByDeclarative( CATICAfrComponent* ipiAfrComponent,  
                                                 const CATUnicodeString & iTemplateName, 
                                                 const CATUnicodeString & iXmlFile);

    /**
    * Instantiate a C-Afrcomponent, don't use anymore
    *
    * <br><b>Role</b>: This method instantiates a C-Afr component
    *
    *  @param iXMLFile
    *  The XML file to declare the Template
    *
    *  @param iTemplateName
    *  The Template name
    *
    *  @param iComponentInstanceName
    *  The Instance id
    *
    *  @param opIAfrComponent
    *  The created C-Afr component [out, CATICAfrComponent#Release]
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The function has being executed successfully.</li>
    *     <li><b>S_FALSE</b>The function has being retrieve the existing component.</li>
    *     <li><b>E_FAIL</b>An error occurred. The component was not created.</li>
    *     </ul>
    *
    */
    static HRESULT CATCAfrInstantiateComponent( const CATUnicodeString& iXMLFile, 
                                                const CATUnicodeString& iTemplateName, 
                                                const CATString& iComponentInstanceName, 
                                                CATICAfrComponent** opIAfrComponent );

    /**
    * Register the Component
    * NODOC Private Use.
    * @param ispAfrComponent 
    *   The component
    * @param iComponentInstanceName 
    *   The component name
    */
    static HRESULT RegisterComponent( CATBaseUnknown_var ispAfrComponent, 
                                      const CATString& iComponentInstanceName );
    
    /* Commun services for all CATISYPCollection
    *
    * <br><b>Role</b>: Check if the object is a CATCAfrInclude or a CATCAfrGroup to append new elements
    *
    *  @param i_spObject
    *  The object to check
    *
    *  @param ipCollection
    *  The collection to which the object children are appended if the object is  a CATCAfrInclude or a CATCAfrGroup
    *
    *  @return HRESULT
    *     Error code of function.
    *     <ul>
    *     <li><b>S_OK</b>The object is a CATCAfrInclude or a CATCAfrGroup, its children have been directly appended to ipCollection.</li>
    *     <li><b>E_FAIL</b>The object isn't a CATCAfrInclude or a CATCAfrGroup, neither i_spObject or its children have been appended to ipCollection.</li>
    *     </ul>
    */
    static HRESULT AppendIfIncludeOrGroup(const CATBaseUnknown_var  & i_spObject,  CATISYPCollection *ipCollection);

  private:
    static HRESULT CreateCATCAfrComponentServices( );

    /**
    * Allow to get the current component id when the component uses command header. **Internal Use ** 
    *
    * @return  the current Component id that supports command headers
    */
    static CATString CATCAfrCurrentComponentIdForHeaders();


    /**
    * Cleans all CAfr Component
    * NODOC Private Use.
    */
    static HRESULT CleanComponents( );

    static CATString      _currentComponentIdForHeaders;

};
#endif
