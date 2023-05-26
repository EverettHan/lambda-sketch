
#ifndef __CATOxExternalStreamDescriptorManager_H
#define __CATOxExternalStreamDescriptorManager_H


/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007

/*
* @COPYRIGHT DASSAULT SYSTEMES 2007
* ----------------------------------------------------------------------------------------------------------------------
*   Origin              : Local running (inside wintop) of remote persistency entity
*                            associative kernel change/data set of ... actors ...
*                            made as simple as possible to be affordable for enhanced infrastructure integration
*   Software's Category : Physical Layer (Middleware services) dedicated to client side
*                            (in a kind of software classification similar to the layered OSI Network
*                             upper (logical) Layer is mainly about two main axis  (
*                                  Modeler (domain) specialisation (for Data and Attributes ...)
*                                  Upper Levering Operand Integration exchange (QEOPS,
*   Premilinary         : Do not forget to contact your Database Administrators or any other representative
*                            (Authoring definition) for more convenient support
*                          (Just to be sure that appropriate schema (Table for Data , or Services) are supported
*                              when reference persistency occured when dealing with local work realized  )
*   Specification       : Simple genuine (re-usable) services about
*                            - associativity between local insulated implementation and shared remote repository
*                            - synthetic change set (persistency intents)
*   Limitations         : No attributes vocabulary provided to let this current functional component software
*                              be as comprehensible in specifications
*                         Status is slaved to Modelers deployement and Behaviors
*                             for more detailled specification (UML sequence diagram, statechart, ..)
*                             consult specialized specifications database relative to upper Logical Software layer
*                             it means Product Structure Legacy, PLM Client Core, Representation Model
*   Favorites entry-point for developpers :
*                         CATPLMRepositoryName : Repository classification
*                         CATProxySpace   : Instance of a domain resolution
*                         CATComponentId  : Handle on primary associativity between local and remote entity
* ------------------ ----------------------------------------------------------------------------------------------------
*/


/**
 * @level Protected
 * @usage U3
 */

#define AuthorizedModule                  999
#define CATPLMExternals                   AuthorizedModule
#define CATPLMClientCoreLinkTrader        AuthorizedModule
#define CATPLMTos                         AuthorizedModule
#define CATOmbTransientServices           AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to link services from a non-infrastructure module
@error
#endif
#undef CATPLMTos   
#undef CATPLMExternals
#undef CATPLMClientCoreLinkTrader
#undef CATOmbTransientServices


#include "CATBoolean.h"
#include "IUnknown.h"

#include "ExportedByCATPLMTos.h"

class CATComponentId;
class CATOxConnectionAndPortStreamDescriptor;
class CATPLMStreamDefinition;

/*
 * This class allows to manage the storage of stream descriptors associated to connections during
 * save transactions.
 *
 * It is used in CATPLMSpecsModeler/CAPTPLMExternals
 */
class ExportedByCATPLMTos CATOxExternalStreamDescriptorManager
{

public:
  /* Put
   *
   * Inputs :
   *  - iCID : The component to which the stream descriptor is associated
   *  - iStreamDescriptor : The stream descriptor
   *
   * Result :
   *  - S_OK if everything went right and the stream descriptor is stored
   *  - E_UNEXPECTED if iCID is NULL or if the transaction is not a save transaction
   *  - E_FAIL if the storage failed
   */
  static HRESULT Put(const CATComponentId &iCID, IUnknown * iStreamDescriptor);

  /* Put (for session manager)
  * Inputs :
  *
  *  - iCID : The component to which the stream descriptor is associated
  *  - iStreamDescriptor : The stream descriptor
  *
  * Result :
  * - S_OK if everything went right and the stream descriptor is stored
  * - E_FAIL if transaction is not a Session Manager transaction or if any failure
  * - S_OK otherwise
  */
  static HRESULT Put(const CATComponentId &iCID, const CATPLMStreamDefinition &iStreamDescriptor);

  /* Put (for session manager)
  * Inputs :
  *
  *  - iCID : The component with no Stream descriptor associated
  *  this is to have a registered object without stream definition, necessary for session manager
  *
  * Result :
  *  - S_OK if everything went right and the stream descriptor is stored
  * - E_FAIL if transaction is not a Session Manager transaction or if any failure
  */
  static HRESULT Put(const CATComponentId &iCID);


   /* Put
   *
   * Input :
   *  - iCID : The component for which the stream descriptor is being looked for
   *
   * Output :
   *  - oStreamDescriptor : The stream descriptor being looked for
   *
   * Result :
   *  - S_OK if everything went right and the stream descriptor is retrieved
   *  - E_UNEXPECTED if iCID is NULL or if the transaction is not a save transaction
   *  - E_FAIL if the retrieving failed
   */
  static HRESULT Get (const CATComponentId & iCID, IUnknown *& oStreamDescriptor);
  
   /* Get (for session manager)
  * Result : 
  * - S_OK if everything went right and the stream descriptor is retrieved
  * - S_FALSE if CID not found
  * - E_FAIL if no Session Manager transaction, or any kind of failure
  */
  
  static HRESULT Get(const CATComponentId &iCID, CATOxConnectionAndPortStreamDescriptor *& iStreamDescriptor);

};

#endif
