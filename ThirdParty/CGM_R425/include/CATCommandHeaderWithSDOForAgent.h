#ifndef CATCommandHeaderWithSDOForAgent_H
#define CATCommandHeaderWithSDOForAgent_H
#include "CATDialogEngine.h"

// COPYRIGHT DASSAULT SYSTEMES 2000
// protected CATCmdDialogAgents.m

#include "CATCommandHeaderWithSDO.h"

#include "CATEventSubscriberTypedefs.h"

class CATString;
class CATCommandHeader;
class CATListPtrCATBaseUnknown;
class CATCommandHeaderWithSDORep;
class CATNotification;
class CATDialogAgent;

/**
 * Class for command headers to represent Dialog Agents in a toolbar. 
 * <b>Role</b>: This header allows you to see a @href CATDialogAgent in a toolbar. The
 * agents are set in the Set of Dialog Objects (SDO) by the CATStateCommand thanks to the
 * @href CATStateCommand#AddSDOElement method. 
 * <br>
 * An object in the SDO is visualized thanks this class under these three conditions:
 * <ol>
 *  <li>it's a component which OM derives from the @href CATDialogAgent component</li>
 *  <li>it implements an interface, which derives from @href CATIAfrDialog ,
 *      to give its representation</li>
 *  <li>it is activated.</li>
 * </ol>
 * 
 * <p>
 * <b>Example of usage</b>: You are in a workshop, workbench or in an Add-in
 * <ol> 
 *  <li>Create an instance of the class</li>
 *  <pre>
 *    new CATCommandHeaderWithSDOForAgent("HeaderID", IID_CATIMyVisuForMyToolbar);
 *  </pre>
 *  
 *  <li>Associate this instance with a starter</li>
 *  <pre>
 *    // The container which represents the toolbar
 *    NewAccess(CATCmdContainer,pCATMySDOTlb,CATMySDOTlb);
 *      ......
 *      // Starter to visualize all objects in the SDO
 *      NewAccess(CATCmdStarter,pCATMySDOStr,CATMySDOStr);
 *       .....
 *      // Associate the command header with the starter
 *      SetAccessCommand(pCATMySDOStr,"HeaderID")
 *  </pre>
 * </ol>  
 * <ul>
 *  <li><b>HeaderID</b>:Identificator of the header</li>
 *  <li><b>IID_CATIMyVisuForMyToolbar</b>: IID of an interface which derives from @href CATIAfrDialog </li>
 *  <li><b>CATMySDOTlb</b>:Identificator of the toolbar where dialog agent will be set</li>
 *  <li><b>CATMySDOStr</b>:Identificator of the starter dedicated to the header</li>
 * </ul>
 * 
 */

class ExportedByCATDialogEngine CATCommandHeaderWithSDOForAgent : public CATCommandHeaderWithSDO
{
  
  /** @nodoc */
  CATDeclareClass;
  CATDeclareHeaderResources;
  
public:
  
  /**
  * Constructs a header to represent Dialog Agent in a toolbar.
  * @param iHeaderID
  *    Identificator of the header. You must follow the nomenclature :
  *    <br><b>ZZZxxx</b>HeaderName<b>Hdr</b> where
  *    <ol>
  *     <li>ZZZ: The trigram of the enterprise</li>
  *     <li>xxx: The trigram of FW or the product</li>
  *     <li>Hdr: For <b>H</b>ea<b>d</b>e<b>r</b> </b>
  *    </ol>
  *    <br>This identificator is not used for any Nls or Rsc Resources. 
  * @param iVisuIID
  *    Interface deriving from @href CATIAfrDialog.
  *    <br>Agent must implement this interface to be visualized.
  */
  CATCommandHeaderWithSDOForAgent (const CATString & iHeaderID, const IID & iVisuIID);
  
  virtual ~CATCommandHeaderWithSDOForAgent ();
  
  /**
  * @nodoc
  */
  virtual CATCommandHeader * Clone ();
  
  /**
  * @nodoc
  * Agent are visualized when they are activated. 
  * see @href CATCommandHeaderWithSDO#BuildRep
  * Call @href #ConnectToAgent
  */
  virtual void BuildRep (CATListPtrCATBaseUnknown & iElems);
  
  /**
  * @nodoc
  * see @href CATCommandHeaderWithSDO#DestroyRep
  * Call @href #DeconnectFromAgent
  */
  virtual void DestroyRep (CATListPtrCATBaseUnknown & iElems);
  
  
protected:

  /** @nodoc */
  CATCommandHeaderWithSDOForAgent(CATCommandHeaderWithSDOForAgent * header);

  
/**
* @nodoc
* see @href CATCommandHeaderWithSDO#BuildSDORep
  */
  void BuildSDORep (CATCommandHeaderWithSDORep & iRep);

  
private:

  /**
  * @nodoc
  * Copy constructor. Not Implemented.
  */
  CATCommandHeaderWithSDOForAgent (const CATCommandHeaderWithSDOForAgent & iHeaderToCopy);
  
  // Callback when an agent change of state
  // agent cancel,
  void OnSDOAgentChangeCB (CATCallbackEvent iPublishedEvent,
                           void * iPublishingObject,
                           CATNotification * iNotification,
                           CATSubscriberData iClientData,
                           CATCallback iCallback);
  
  // To set the OnSDOAgentChangeCB callback
  // this method is called in the ..
  void ConnectToAgent (CATDialogAgent & iAgent);
  
  // To remove callback
  void DeconnectFromAgent (CATDialogAgent & iAgent);
  
  // NOT implemented, only declared to prevent unexpected call to default ctors created by the compiler
  CATCommandHeaderWithSDOForAgent ();
  CATCommandHeaderWithSDOForAgent & operator= (const CATCommandHeaderWithSDOForAgent &);

};

#endif

