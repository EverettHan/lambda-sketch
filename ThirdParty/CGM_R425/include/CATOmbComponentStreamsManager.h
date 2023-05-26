/* -*-c++-*- */
//------------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2012
//------------------------------------------------------------------------------
//
// OMB wrapper: facade for all Streams access/management services
// 
//------------------------------------------------------------------------------
// 20/09/2012 Creation                                                       VCS
//------------------------------------------------------------------------------
#ifndef CATOmbComponentStreamsManager_H
#define CATOmbComponentStreamsManager_H
// System
#include "CATUnicodeString.h"
// SystemTS
#include "CATBoolean.h"
#include "IUnknown.h"
// ObjectModelerCollection
#include "CATOmxIter.h"
#include "CATOmxSR.h"
// CATPLMIdentification
#include "CATComponentId.h"
// ObjectModelerBase
#include "CATOmbSelectiveLoading.h"
#include "CATOmbStreamDescriptorAccess.h"
#include "CATOmbStreamDescriptorFormat.h"
#include "CATOmbSDSyncStatus.h"

class CATBaseUnknown;
class CATDocument;
class CATOmbLoadableDataUniqueKey;
class CATVVSUrl;

//=====================================================================================================================================

/**
* Manages Session LifeCycle of the streams attached to a PLM component
*<b>Role</b>: This wrapper class provides services to handle and manage in session the life cycle
*<br> of all streams attachable to a PLM component. 
* 
* Each stream is represented in session by its StreamDescriptor (SD), that stores all informations
* usable to access the stream, either in current memory Session, Vault or in Session cache.
* All the streamsDescriptors attached to the component are instanciated in session at component Open time.
* The streams referenced by their SDs may be then loaded/unloaded in/from session depending on the current applicative context.
* stream descriptors are categorized according to their function:
*  -Primary streams store the authoring data created and modified by applications (CATPart, CATData, NonCATIA documents, ..etc)
*  -Secondary streams store the resulting data relative to primary ones (visualisations, analysis results, ..etc)
* A given stream is mainly accessible through its identification key CATOmbLoadableDataUniqueKey, made up of following fields:
*  CATOmbStreamDescriptorFormat Format: the primary/secondary nature of the stream
*	 CATUnicodeString	              Role: the functional specialization of the stream
*	 CATUnicodeString    PersistencyName: the unique identification of the stream into its (Format/Role) family
* Format/Role are imposed by Infrastructure
* PersistencyName is choosen by application
* A given stream is accessible from its SD in a way depending on its nature/internal data formatting:
* -DS proprietary stream: Once loaded in session by switching APIs described hereunder, it can be handled through CATDocument 
*  exposed APIs that apply to.
* -Non DS stream: Once copied into a working directory by projection/export APIs, it can be handled through DS general file management
*  and external non DS applications APIs that may apply to.
*/


class ExportedByCATOmbSelectiveLoading CATOmbComponentStreamsManager
{
public:

  //-------------------------------------------------------------------------------------------------------------------
  //                                   Access to a PLM component streams                                       
  //-------------------------------------------------------------------------------------------------------------------

  /**
   * Initialize a CATOmbComponentStreamsManager from a pointer.
   * ipComponent must be a pointer to a representation reference or entity with stream.
   * If you already have the CATComponentId object, for performance reason prefer next constructor.
   */
  CATOmbComponentStreamsManager(CATBaseUnknown* ipComponent);

  /**
   * Initialize a CATOmbComponentStreamsManager from a CATComponentId.
   * iComponentID must be a refer to a representation reference or entity with stream.
   */
  CATOmbComponentStreamsManager(const CATComponentId& iComponentID);

  /** dtor*/
  ~CATOmbComponentStreamsManager();


  /**
   * Returns corresponding CATComponentId or NULL
   */
  CATComponentId GetComponentId();

  //-------------------------------------------------------------------------------------------------------------------
  //                                   Stream Life Cycle in session and repository                                        
  //-------------------------------------------------------------------------------------------------------------------

  // -> Streams ACCESS
  // -----------------

  // Following access methods all deal with stream descriptors aggregated on this current component opened in current session.

  /**
  * Gets a given stream descriptor by its access key.
  * @param iKey [in]
  *	 The (Format|Role|PersistencyName) key attributes selecting a given SD in a unique way
  * @return 
  *  The stream descriptor if found, NULL otherwise.
  *  Use CATOmxQIPtr to access interfaces implemented by the stream descriptor
  */
  CATOmxSR<CATBaseUnknown> GetSDByKey(const CATOmbLoadableDataUniqueKey& iKey);

  /**
   * Returns "first" stream descriptor matching (iFormat,iRole)
   */
  CATOmxSR<CATBaseUnknown> GetSDByFormatAndRole(const CATOmbStreamDescriptorFormat& iFormat,const CATUnicodeString& iRole);


  /**
  * Gets the session document associated to a given stream descriptor.
  * This document represents memory view of the stream described by this SD.
  * It is created/loaded by switching component to the appropriate loading mode.
  * @param iKey [in]
  *	 The (Format|Role|PersistencyName) key attributes selecting a given SD in a unique way
  * @return 
  *  The document if found, NULL otherwise.
  *  This pointer is returned without being AddRef'ed
  */
  CATDocument* GetDocumentByKey(const CATOmbLoadableDataUniqueKey& iKey);

  /**
  * Gets all stream descriptors from a given family type .
  * @param iFilter [in]
  *	A filter on Format and/or Role attributes of the SDs family to be retrieved 
  * @return 
  * An iterator on the retrieved SDs list.
  *  usage: 
  *    CATOmxIter<CATBaseUnknown> iter(ListSDs(ombSDAccess::AFormat/Role filter));
  *    CATBaseUnknown* pSD = NULL;
  *    while(pSD = iter.Next())
  *    { ... }
  */
  CATOmxIter<CATBaseUnknown> GetSDFamily(CATOmbSD::Family iFilter);

  // -> Streams CREATION
  // -------------------

  /**
  * Creates a stream descriptor on current component opened in current session.
  *  Only Archive SDs are authorized for creation here, as of now, using following key input:
  *	  - Format: The Format attribute of the stream, as to be stored in data base.
  *   - Role:   'Archive'
  *   - PersistencyName: the complete file name of the stream, as to be persisted in a data base store (FCS) at next Save.
  *   The Archive SD is dedicated to stream data creation in Database, from any DS or not DS stream NOT to be edited by DS
  *   wintop applications.
  *   The component can only aggregate Archive SDs, once a first SD typed as Archive has been created on empty component.
  *
  * @param iKey [in]
  *	 The (Format|Role|PersistencyName) key attributes defining a given SD in a unique way
  * @param iPersistencyType [in]
  *	The file extension of the stream
  * @param iURL [in]
  * The current location of the stream to be persisted in a database Store (FCS) at next Save.
  * @param iLatetype [in]
  * The latetype of document to add. Default method signature without this argument will use PeristencyType instead.
  * @return 
  * <ul>
  *   <li> S_OK :   Creation successful : The SD has been created in session and can be retrieved from its key  
  *   <li> E_INVALIDARG : No SD created. at least one input is invalid:
  *                       - component not in a usable state (under deletion ..etc)
  *                       - component should only aggregate Archive SDs
  *                       - empty iPersistencyName or iURL 
  *   <li> E_FAIL : Creation failed : No SD created
  * </ul>
  */
  HRESULT AddSD(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iPersistencyType, CATVVSUrl& iURL);

  HRESULT AddSD(const CATOmbLoadableDataUniqueKey& iKey, const CATUnicodeString& iPersistencyType, CATVVSUrl& iURL, CATUnicodeString iLatetype);


  // -> Streams DESTRUCTION
  // ----------------------
 /**
  * Deletes a given stream descriptor aggregated on current component opened in current session.
  * Marks a given SD as deleted and so no more accessible/usable in session, and propagates the
  * effective deletion to component in data base at next Save.
  * @param iKey [in]
  *	 The (Format|Role|PersistencyName) key attributes selecting a given SD in a unique way
  *   Deletion is only possible for the extended or derived non-core SD families:
  *      (Format:*|Role:Archive|PN:*) 
  *      (Format:Authoring|Role:Extended|PN:*) (Format:AuthoringVisu|Role:Extended|PN:*) (Format:AuthoringVisu|Role:Alternative|PN:*)
  *      (Format:Authoring|Role:Collaborative|PN:*) (Format:Authoring|Role:DerivedFromCollaborative|PN:*)  
  *      (Format:Authoring|Role:WebFormat|PT:zip) 
  *      (Format:AuthoringVisu|Role:CATIAV5INV6|PT:cgr) 
  *
  * When deleting a collaborative secondary SD (Format:Authoring|Role:*Collaborative|PN:*), eventual secondary SD (Format:AuthoringVisu|Role:DerivedFromCollaborative|PN:*) is also implicitely deleted 
  * When deleting a secondary SD (Format:AuthoringVisu|Role:Extended/Alternative|PN:*) or (Format:Authoring|Role:WebFormat|PT:zip) or (Format:AuthoringVisu|Role:CATIAV5INV6|PT:cgr),
  *  any (re)generation request eventually previously set by a call to RequestExtended/AlternativeSecondaryFormatGeneration is unset
  *
  * @return 
    * <ul>
  *   <li> S_OK      : Deletion successful : The SD has been deleted in session and cannot be retrieved anymore from its key
  *   <li> E_FAIL    : Deletion failed : The SD has not been deleted
  *   <li> E_NOTIMPL : SD is not typed (Format:Authoring|Role:Extended)
  * </ul>
  */
  HRESULT DeleteSD(const CATOmbLoadableDataUniqueKey& iKey);

  // -> Streams MOVE
  // -------------------

  /**
  * Moves a Stream Descriptor from this component to an other.
  *  Only Archive SDs are authorized for move here, as of now, using following key input:
  *	  - Format: The Format attribute of the stream, as to be stored in data base.
  *   - Role:   'Archive'
  *   - PersistencyName: the complete file name of the stream, as to be persisted in a data base store (FCS) at next Save.
  *   The Archive SD is dedicated to stream data creation in Database, from any DS or not DS stream NOT to be edited by DS
  *   wintop applications.
  *   The component can only aggregate Archive SDs, once a first SD typed as Archive has been created on empty component.
  *
  * @param iKey [in]
  *	 The (Format|Role|PersistencyName) key attributes defining a given SD in a unique way
  * @param iComponentID [in]
  *	 The SD will be moved to the component identified by iComponentID
  */
  HRESULT MoveSD(const CATOmbLoadableDataUniqueKey& iKey, const CATComponentId& iComponentID);

  //-> Selective STREAM LOADING in session : Switch operations
  //----------------------------------------------------------

  /**
   * Loads in memory the stream corresponding to input key.
   * Currently restricted to Archive documents.
   * on non CATIA documents it will actually not load anything into memory
   * but just download corresponding stream and create CATDocument allowing
   * manipulation of this stream though CATIOmbNonCATIAStreamDescriptor interface.
   * @param iKey [in]
   *	 The (Format|Role|PersistencyName) key attributes defining a given SD in a unique way
   * @param oLoadedDocument [out]
   *     oLoadedDocument is returned without being AddRef'ed
   */
  HRESULT LoadStream(const CATOmbLoadableDataUniqueKey& iKey,CATDocument*& oLoadedDocument);

  /**
  * Loads the targeted AuthoringVisu Alternative stream in current session.
  * All eventual other streams currently loaded are unloaded.
  *
  * @param iTargetPersistName [in]
  *	The unique PersistencyName locating a specific (Format:AuthoringVisu | Role:Alternative) SD into its component.
  * This name is the one passed to the input Key at SD creation time, using RequestAlternativeSecondaryFormatGeneration.
  */
  HRESULT SwitchToAlternativeVisu(const CATUnicodeString& iTargetPersistName);

  /**
   * Switch representation to iTargetLoadingMode.
   */
  HRESULT SwitchToLoadingMode(const CATUnicodeString& iTargetLoadingMode);

  /**
   * Returns representation current loading mode.
   * Notice that return code can be CATOmb_E_NOT_CONSISTENT_MODE.
   * This means that a switch has failed and that loading state of the SDs is not consistent
   * In this specific failure case, oMode will be nevertheless filled.
   */
  HRESULT GetLoadingMode(CATUnicodeString& oMode);

  /**
   * Returns the "main stream descriptor" in local context (local master). Note this could be not the same as global master SD (which is the original sd of the repRef).
   * It is either and by preference order the stream descriptor corresponding to (Format=Authoring,Role="") or (Format=Authoring,Role="CATIAV5INV6") or (Format=Authoring,Role="CATIAV5")
   * (Same as CATIOmbRepRefLoadingStatus::GetAuthoringStreamDescriptor)
   * @usage:
   *  CATOmbComponentStreamsManager hStreams( ... );
   *  CATOmxQIPtr<CATIOmbStreamDescriptor>  hMainSD(hStreams.GetMainAuthoringSD());
   *  if(hMainSD) 
   *  {
   *    ...
   *  }
   */
  CATOmxSR<CATBaseUnknown> GetMainAuthoringSD();

  /**
   * Returns the "main stream descriptor" key of a RepRef in local context (local master). Note this could be not the same as global master SD (which is the original sd of the repRef).
   * So that this key could be used to get the SD or Document after SwitchOperation
   * @usage:
   *  CATOmbComponentStreamsManager hStreams( ... );
   *  CATOmxSR<CATOmbLoadableDataUniqueKey>& mainkey = hStreams.GetMainAuthoringSDKey(); 
   *  {
   *    ...
   *    //Execute a SwitchOperation to load the required data
   *    ...
   *    //get the data with this key
   *    CATDocument* myWorjingDoc=hStreams.GetDocumentByKey(mainkey);
   *  }
   */
  const CATOmbLoadableDataUniqueKey& GetMainAuthoringSDKey();

  /**
   * Returns the late type of the document that the "main stream descriptor" can hold in local context (local master). Note this could be not the same as global master SD (which is the original sd of the repRef).
   * This is a shortcut for 
   *   CATOmxQIPtr<CATIOmbStreamDescriptor>(GetMainAuthoringSD())->GetDefinitionQualifiers().GetLateType();
   * (Same as CATIOmbRepRefLoadingStatus::GetMainStreamDescriptorType)
   */
  HRESULT GetMainAuthoringSDType(CATUnicodeString& oType);

  /**
  * Returns the global master SD of the repRef. It is the sd at the origin of all sd(s).
  */
  CATOmxSR<CATBaseUnknown> GetGlobalMasterSD();
  const CATOmbLoadableDataUniqueKey& GetGlobalMasterSDKey();

  /**
  * Give master status of sd described by given key
  */
  HRESULT GetSDMasterStatus(const CATOmbLoadableDataUniqueKey& iKey, CATBoolean& oIsMasterGlobal, CATBoolean& oIsMasterLocal, CATBoolean& oIsSlave);

  /**
  * Give status of given keys. If no key is provided the array will be filled with all sd keys present on rep reference. In that cas order won't be guarenteed.
  * return S_OK if everything ran ok, E_XXX else.
  */
  HRESULT GetSDsSyncStatus(CATOmxArray<CATOmbSDSyncStatus>& ioSDsStatus);

  /**
   * @return S_OK if a switch is running on this component
   */
  HRESULT GetCurrentLoadingModeTransition(CATUnicodeString& oCurrentLoadingMode,CATUnicodeString& oDestinationLoadingMode);

  /**
  * Creates an applicative container in the authoring document.
  * <br><b>Role:</b>This method creates an applicative container in the authoring document associated 
  * to the given PLM component.  
  * Note that inside this method , after the container creation , the followings steps are included :
  *  <ul>
  *  <li>The applicative container is initialized thanks to the <tt>CATInit</tt> interface, if it implements it. </li>
  *  <li>The undo/redo mechanism is also initialized 
  * @param oApplicativeContainer [out]
  *      the created applicative container.
  * @param iContainerType
  *      a string representing the type of the applicative container.
  * @param iContainerSuperType
  *      the supertype of the applicative container.
  *      <br> "": default value, the applicative container has no supertype.
  *      <br> otherwise must be set to the feature container type (CATFeatCont).
  * @param iIdentifier
  *      name of the applicative container, useful to get it later. Two applicative containers can not have the same name.
  * @return
  *      <tt>S_OK</tt>: the applicative container has been successfuly created.
  *	 <br><tt> E_FAIL</tt>: the operation has failed.
  *	 <br><tt> E_INVALIDARG </tt>: if the document associated to the stream authoring is not loaded
  */
  HRESULT CreateContainer(const CATUnicodeString& iIdentifier, const CATIdent iContainerType, const CATIdent iContainerSuperType, CATOmxSR<CATBaseUnknown>& oApplicativeContainer);

  /**  
* Gets an applicative container in the authoring document.
* <br><b>Role:</b>This method gets an applicative container in the authoring document associated 
* to the given PLM component.  

*  @param  oApplicativeContainer [out]
*            applicative  container.  
*  @param  iIdentifier  
*            name  of  the  applicative  container.  
*  @return  
*            <tt>S_OK</tt>:  the  applicative  container  has  been  successfuly  retrieved.  
*          <br><tt>  E_FAIL</tt>:  the  operation  has  failed.  
*/ 
  HRESULT GetContainer(const CATUnicodeString& iIdentifier, CATOmxSR<CATBaseUnknown>& oApplicativeContainer);

  // does take latetype of globalMasterSD for check
  // returns TRUE if RepRef main SD is a XCAD one, else FALSE
  CATBoolean IsXCAD();

private:

  void* m_data[4];

  // copy constructor is private
  CATOmbComponentStreamsManager (const CATOmbComponentStreamsManager& iCopy);

  // = operator is private
  CATOmbComponentStreamsManager operator=(CATOmbComponentStreamsManager& iCopy);
};

#endif
