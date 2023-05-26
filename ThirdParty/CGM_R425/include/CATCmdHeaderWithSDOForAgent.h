#ifndef CATCmdHeaderWithSDOForAgent_H
#define CATCmdHeaderWithSDOForAgent_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#include "CATDialogEngine.h"
#include "CATString.h"

class CATCommandHeaderWithSDOForAgent;

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
 *    CATCommandHeaderWithSDOForAgent::CATCreateCmdHeaderWithSDOForAgent("HeaderID", IID_CATIMyVisuForMyToolbar);
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
class ExportedByCATDialogEngine CATCmdHeaderWithSDOForAgent
{
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

	static CATCommandHeaderWithSDOForAgent * CATCreateCmdHeaderWithSDOForAgent(const CATString & iHeaderID, const IID & iVisuIID);	
};

#endif
