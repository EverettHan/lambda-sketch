//===================================================================
// COPYRIGHT Dassault Systemes 2013/05/23
//===================================================================
// PLMIExchangeExperienceSessionHandler.cpp
// Header definition of class PLMIExchangeExperienceSessionHandler
//===================================================================
//
// Usage notes: Allow the interaction with experience session.
//
//===================================================================
//  2013/05/23 Creation: Code generated by the 3DS wizard
//===================================================================
#ifndef PLMIExchangeExperienceSessionHandler_H
#define PLMIExchangeExperienceSessionHandler_H

#include "PLMExchangeInterfaces.h"
#include "PLMIExchangeExperienceOption.h"

#include "PLMExchangeExperienceDictionary.h"
#include "CATListPtrPLMIExchangeExperienceSessionObject.h"
#include "CATBaseUnknown.h"

#include "CATLISTV_CATPLMID.h"

extern ExportedByPLMExchangeInterfaces  IID IID_PLMIExchangeExperienceSessionHandler ;

class PLMExchangeExecution;
class ExportedByPLMExchangeInterfaces PLMIExchangeExperienceSessionHandler: public CATBaseUnknown
{
CATDeclareInterface;

public:   

   /**
   * <b> AddObjectByPLMId :</b> Add an object in the current session by its PLMID.   
   *
   * @param iPLMIdObjectToAdd (in)
   * input PLMID of the object to add.
   *
   * @param iPLMIdParent (in)
   * input PLMID of the parent of the object to add.
   * This refer to the object right on top of the object to add. 
   * i.e if iPLMIdObjectToAdd is an 'instance', then iPLMIdParent has to be equal to the plmid of the reference aggregating the instance.
   * i.e if iPLMIdObjectToAdd is a 'not root reference',  then iPLMIdParent has to be equal to the plmid of the its pointing instance.
   *
   * @param opCreatedObject [out, CATBaseUnknown#Release]
   * output on the created session object for the given PLMID;
   * 
   * @param inPrivate
   *  <p><u>Legal values:</u></p>
   *  <dl>
   *  <dt>0</dt>   <dd>Node is not considered as private data.</dd>
   *  <dt>1</dt>   <dd>Node is considered as private data.</dd>
   *  </dl>
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *                   E_FAIL 
   */ 
   virtual HRESULT AddObjectByPLMId(CATPLMID & iPLMIdObjectToAdd, CATPLMID iPLMIdParent, PLMIExchangeExperienceSessionObject * & opCreatedObject, int inPrivate = 0) =0;

   /**
   * <b>GetOption  :</b> Get the option associated with the option key.
   * The asked option must be accessible to the calling customization.
   * It means that the option :
   *  - must have been created by the calling customization.
   *  - or must have been shared to the calling customization.
   * Please release the pointer after use
   *
   * @param iStrOptionKey (in)
   * input NLS path string corresponding to identification key string used for the option creation.
   * i.e : "CatalogNameX.OptionName1"
   *
   * @param opOption [out, PLMIExchangeExperienceOption#Release] 
   * output pointer on the retrieved option.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if there's no associated option for the given key, or if the given key is not accessible.
   */ 
   virtual HRESULT GetOption(const CATUnicodeString & iStrOptionKey , PLMIExchangeExperienceOption * & opOption) = 0;
  
   /**
   * <b>SetGroupProperty  :</b> Set the property for the given group.
   * The asked group must be accessible to the calling customization.
   * It means that the group :
   *  - must have been created by the calling customization.
   *  - or must have been shared to the calling customization.   
   *
   * @param iStrGroupKey (in)
   * input NLS path string corresponding to identification key string used for the group creation.
   * i.e : "CatalogNameX.GroupName1"
   *
   * @param iObjProp (in)
   * input property to set for the group : Please to the type PLMExchangeExperienceObjectProperty defined in the PLMExchangeExperienceDictionary.h .   
   *
   * @param ibValue (in)
   * input value to set for the property.   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if there's no associated group for the given key, or if the given key is not accessible.
   */ 
   virtual HRESULT SetGroupProperty( const CATUnicodeString & iStrGroupKey , PLMExchangeExperienceObjectProperty iObjProp, CATBoolean & ibValue) = 0 ; 
  
   /**
   * <b>GetGroupProperty  :</b> Get the property for the given group.
   * The asked group must be accessible to the calling customization.
   * It means that the group :
   *  - must have been created by the calling customization.
   *  - or must have been shared to the calling customization.   
   *
   * @param iStrGroupKey (in)
   * input NLS path string corresponding to identification key string used for the group creation.
   * i.e : "CatalogNameX.GroupName1"
   *
   * @param iObjProp (in)
   * input property to get for the group : Please to the type PLMExchangeExperienceObjectProperty defined in the PLMExchangeExperienceDictionary.h .   
   *
   * @param obValue (in)
   * output value corresponding to the the property.   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if there's no associated group for the given key, or if the given key is not accessible.
   */ 
   virtual HRESULT GetGroupProperty( const CATUnicodeString & iStrGroupKey , PLMExchangeExperienceObjectProperty iObjProp, CATBoolean & obValue) = 0 ; 

   /**
   * <b>SetExperienceExecutionProperty  :</b> Set the property for the given experience exectuion.
   * The asked group must be accessible to the calling customization.
   * It means that the execution :
   *  - must have been created by the calling customization.
   *  - or must have been shared to the calling customization.   
   *
   * @param iStrExecutionKey (in)
   * input NLS path string corresponding to identification key string used for the execution creation.
   * i.e : "CatalogNameX.ExecutionName1"
   *
   * @param iObjProp (in)
   * input property to set for the execution : Please to the type PLMExchangeExperienceObjectProperty defined in the PLMExchangeExperienceDictionary.h .   
   *
   * @param ibValue (in)
   * input value to set for the property.   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if there's no associated execution for the given key, or if the given key is not accessible.
   */ 
   virtual HRESULT SetExperienceExecutionProperty(const CATUnicodeString & iStrExecutionKey, PLMExchangeExperienceObjectProperty iObjProp, CATBoolean ibValue ) =0 ;

   /**
   * <b>GetListOfExecution :</b> Get the list of execution for the current custo
   *
   * @param oExecutionList (out)
   * input list of string containing the name of the executions available for the current customization.    
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if there's no associated execution for the given key, or if the given key is not accessible.
   */ 
   virtual HRESULT GetListOfExecution(CATListOfCATUnicodeString & oExecutionList) = 0;

   /**
   * <b>GetObjects :</b> Get all session object if no search criterion are set.   
   * Otherwise, return the children depending on the given criterion.
   * If an object meet any of the defined criteria, it is then added to the output list. 
   * PLMIExchangeExperienceObjSearchCriterion can be created with the object PLMIExchangeExperienceCustoServices (accessible through PLMIExchangeExperienceCustomization).
   * Please release the pointers after use.

   * @param oListOfPtrSessionObj (out)
   * output list of PLMIExchangeExperienceSessionObject.
   *
   * @param ipSearchCriterion (in)
   * input pointer on PLMIExchangeExperienceObjSearchCriterion. The criteria will define the object type and depth level to search for.
   * Refer to PLMIExchangeExperienceObjSearchCriterion.h for addionnal informations.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds        
   *    Other,         E_FAIL.
   */ 
   virtual HRESULT GetObjects(CATListPtrPLMIExchangeExperienceSessionObject & oListOfPtrSessionObj, PLMIExchangeExperienceObjSearchCriterion * ipSearchCriterion = NULL) =0 ;

   /**
   * <b>GetObjectsPLMIDs :</b> Get all session object's PLMID if no search criterion are set.   
   * Otherwise, return the PLMIDs depending on the given criterion.
   * If an object meet any of the defined criteria, its PLMID is then added to the output list. 
   * PLMIExchangeExperienceObjSearchCriterion can be created with the object PLMIExchangeExperienceCustoServices (accessible through PLMIExchangeExperienceCustomization).
   * Please release the pointers after use.     
   *
   * @param oListOfPLMID (out)
   * output list of PLMID.
   *   
   * @return
   *    Legal values:  S_OK if the method succeeds        
   *    Other,         E_FAIL.
   */ 
   virtual HRESULT GetObjectsPLMIDs(CATPLMIDs & oListOfPLMID, PLMIExchangeExperienceObjSearchCriterion * ipSearchCriterion = NULL) = 0;
     
   /**
   * <b>GetObjectFromPLMID  :</b> Get the session object for the given PLMID.
   * Please release the pointer after use.
   *
   * @param iObjPLMID (in)
   * input PLMID.
   *
   * @param opSessionObj [out, CATBaseUnknown#Release] 
   * output PLMIExchangeExperienceSessionObject corresponding to the session object having the given PLMID. 
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL.
   */ 
   virtual HRESULT GetObjectFromPLMID(CATPLMID & iObjPLMID, PLMIExchangeExperienceSessionObject * & opSessionObj) = 0;

   /**
   * <b>SetStatusForPLMIDs  :</b>  For each PLMID, set the status for its corresponding session object.    
   *
   * @param iListOfPLMID (in)
   * input list of PLMID.
   *
   * @param iStrStatusKey (in)
   * input string corresponding to the status string key.
   *   
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if one of the PLMID is not associated with a session object.
   */ 
   virtual HRESULT SetStatusForPLMIDs(CATPLMIDs & iListOfPLMID, const CATUnicodeString &  iStrStatusKey) = 0;

   /**
   * <b>SetStatusForObjects  :</b>  For each object, set the status given as an input.    
   *
   * @param iListOfSessionObject (in)
   * input list of SessionObject.
   *
   * @param iStrStatusKey (in)
   * input string corresponding to the status string key.
   *   
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if one of the PLMID is not associated with a session object.
   */ 
   virtual HRESULT SetStatusForObjects(CATListPtrPLMIExchangeExperienceSessionObject & iListOfSessionObject, const CATUnicodeString & iStrStatusKey) = 0;

   /**
   * <b>GetLeafObjects  :</b> Get the leafs object of the session.   
   * From these leafs, a navigation throughout the structure is possible.   
   * Please release the pointer after use.
   *
   * @param oListOfPtrLeafObject (out)
   * output list of PLMIExchangeExperienceSessionObject corresponding to the leafs component of the session.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds        
   *    Other,         E_FAIL 
   */ 
    virtual HRESULT GetLeafObjects(CATListPtrPLMIExchangeExperienceSessionObject & oListOfPtrLeafObject) =0;

   /**
   * <b>GetRootObjects  :</b> Get the root object of the session.   
   * From these roots, a navigation throughout the structure is possible.   
   * Please release the pointer after use.
   *
   * @param oListOfPtrRootObject (out)
   * output list of PLMIExchangeExperienceSessionObject corresponding to the root component of the session.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds        
   *    Other,         E_FAIL 
   */ 
    virtual HRESULT GetRootObjects(CATListPtrPLMIExchangeExperienceSessionObject & oListOfPtrRootObject) =0;

   /**
   * <b> SetObjectsFilter :</b> Set the current filter for the session objects.    
   * This will mainly be used to set which filter is currently the active one.
   * If the filter (custo late type) set is not the same as the current one then this will trigger a design switch.
   * All design components of the new filter will be displayed whereas all the components related to the previous one will be hidden.
   *
   * @param iNewFilterName (in)
   * input string corresponding to the filter name. If the filter name is a customization late type then it must have been set in the CATRsc of the current operation.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *                   E_FAIL 
   */ 
   virtual HRESULT SetObjectsFilter(CATUnicodeString & iNewFilterName) = 0;
   
   /**
   * <b> GetObjectsFilter :</b> Get the current filter for the session objects.    
   *
   * @param oCurrentFilterName (in)
   * output string corresponding to the current filter name. This filter name or customization late type must have been set for the current operation (in the CATRsc).
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *                   E_FAIL 
   */ 
   virtual HRESULT GetObjectsFilter(CATUnicodeString & oCurrentFilterName) = 0 ;

   /**
   * Generate a report xml file from the current session information.
   *
   * <br><b>Role</b>: Generate a report xml file from the current session information.
   *
   * @param icReportPath [in]
   *   Directory path of the XML report file.
   *
   * @param icReportFileName [in]
   *   File name of the XML report file.
   *
   * @param oCreatedReportFilePath [out]
   *   Complete path to the created report (includes the report filename).
   *
   * @param icReportXslPath [in]
   *   File path of the XSL file to referenced in the generated XML.
   *   <p><u>NB:></u>In case of null string, the default XSL will be used in the generated XML.</p>
   * 
   * @return
   *   Returns error code.
   *    <p><b>Legal values</b>:</p>
   *    <dl>
   *    <dt>S_OK</dt>       <dd> XML report successfuly exported.</dd>
   *    <dt>S_FALSE</dt>    <dd> XML report opened.</dd>
   *    <dt>E_FAIL</dt>     <dd> XML report generation failed.</dd>
   *    </dl>
   */
   virtual HRESULT SaveReport( const CATUnicodeString & icReportPath ,  const CATUnicodeString & icReportFileName, CATUnicodeString & oCreatedReportFilePath,   CATUnicodeString  * icReportXslPath = NULL ) =0 ;   

  /**
   * <b> GetPLMExchangeExecution  :</b> (Internal use) Get PLMExchangeExecution associated with the current Session.
   * Please be aware that manipulating directly the PLMExchangeExecution node, might lead to some unwanted behavior.
   * This is because theses changes are done outside the control of the Session class object. 
   *
   * @param opExecNode (out)
   * output pointer on the session 's PLMExchangeExecution. (= to the root element of the current session in the PLMExchangeModel).   
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */ 
   virtual HRESULT GetPLMExchangeExecution(PLMExchangeExecution * & opExecNode) = 0 ;

   /**
   * <b> GetTemporaryPath  :</b> 
   * (Import Command) This function is used for the import command. If a custo needs to test the selected file/document
   * it can access the file using this command.
   *
   * @param ousPath (out)
   * the path where the imported file / document is located.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */
   virtual HRESULT GetTemporaryPath(CATUnicodeString & ousPath) = 0;

   /**
   * <b> SetTemporaryPath  :</b> 
   * (Import Command) This function is used to set the path to the file on the disk (downloaded or already on disk).
   * Usefull for the custo that needs to test the selected file/document.
   *
   * @param iusPath (in)
   * the path where the imported file / document is located.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */
   virtual HRESULT SetTemporaryPath(CATUnicodeString & iusPath) = 0;

   /**
   * <b> ClearNotificationNodes  :</b> 
   * Clear Notification Nodes from the PLMExperienceNodes.
   * For Example if we try to delete the following Notification node from tree
   *
   ***********  
   *  Before *
   ***********
   *  <Set Id="3" Name="ObjectSet">
   *   <Object Id="80" prop="Import Update " oper="Synchronize_Update">
   *    <Notification Id="81" Sev="Info"/>   <----  //Notification Node
   *   </Object>
   *  </Set>
   *  <DataSource Id="4" Name="DefaultDataSource" type="VPM"/>
   *  <Set Id="5" Name="GroupSet">
   *  ....
   *  </Set>
   ***********  
   *  After  *
   ***********
   *  <Set Id="3" Name="ObjectSet">
   *  
   *  </Set>
   *  <DataSource Id="4" Name="DefaultDataSource" type="VPM"/>
   *  <Set Id="5" Name="GroupSet">
   *  ....
   *  </Set>
   ***********
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL .
   */  
   virtual HRESULT ClearNotificationNodes() = 0;

   /**
   * <b> SetAsynchronousCommunicationIDs  :</b> 
   * This function can be used in both import and export command to set the Id used for asynchronous command
   * The customization called will have to pass this two parameter in order to establish the communication
   * between the two process.
   *
   * @param isMainProcessID (in)
   * string identifying the main process in the backbone.
   *
   * @param isExternalProcessID (in)
   * string identifying the external process / batch in the backbone.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if the value of the ID haven't been set.
   */
   virtual HRESULT SetAsynchronousCommunicationIDs(CATString & isMainProcessID, CATString & isExternalProcessID) = 0;

   /**
   * <b> GetAsynchronousCommunicationIDs  :</b> 
   * This function can be used by the customization in case of external process for both import and export
   * the IDs needs to be given to the process/batch to establish the communication
   * between the two process.
   *
   * @param osMainProcessID (out)
   * string identifying the main process in the backbone.
   *
   * @param osExternalProcessID (out)
   * string identifying the external process / batch in the backbone.
   *
   * @return
   *    Legal values:  S_OK if the method succeeds     
   *    Other,         E_FAIL if the value of the ID haven't been set.
   */
   virtual HRESULT GetAsynchronousCommunicationIDs(CATString & osMainProcessID, CATString & osExternalProcessID) = 0;

   /**
   * <b> SetSimulatePreviewObject  :</b>
   * This function is used to set list of preview object.
   *
   * @param iListPrevObject (in)
   * List of Preview objects.
   *
   *
   * @return
   *    Legal values:  S_OK if list is set successfully 
   *    Other,         E_FAIL If list is not set.
   */
   virtual HRESULT SetSimulatePreviewObject(CATListValCATBaseUnknown_var & iListPrevObject) = 0;

   /**
   * <b> GetSimulatePreviewObject  :</b>
   * This function is used to Get list of preview object.
   *
   * @param oListPrevObject (out)
   * List of Preview objects.
   *
   *
   * @return
   *    Legal values:  S_OK if list is retrieved successfully.
   *    Other,         E_FAIL If list is not retrieved.
   */
   virtual HRESULT GetSimulatePreviewObject(CATListValCATBaseUnknown_var & oListPrevObject) = 0;

};

//-----------------------------------------------------------------------

#endif