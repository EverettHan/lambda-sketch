#ifndef CATIPLMTransitionIdentification_H
#define CATIPLMTransitionIdentification_H

// COPYRIGHT Dassault Systemes 2006
/* 
* @COPYRIGHT DASSAULT SYSTEMES 2004
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

//===================================================================
//
// Usage notes :
//
//===================================================================
//
//  November 2006 - Creation - pir
//===================================================================

#include "CATBaseUnknown.h"

#include "ExportedByCATPLMIdentification.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIdentification IID IID_CATIPLMTransitionIdentification;
#else
extern "C" const IID IID_CATIPLMTransitionIdentification ;
#endif

//------------------------------------------------------------------
#define AuthorizedModule 999
// List of authorized modules
#define CATPLMIdentification	                   AuthorizedModule
#define TransitionEngine                           AuthorizedModule
#define CATPLMXmlSpecsConverter                    AuthorizedModule
#define CAT3DXMLStreamEngine					   AuthorizedModule
#define CAT3DXMLEngine						       AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden Access To CATIPLMTransitionIdentification from a non-authorized module
// Fatal error on solaris
@error 
#endif

#undef CATPLMIdentification
#undef TransitionEngine
#undef CATPLMXmlSpecsConverter
#undef CAT3DXMLStreamEngine
#undef CAT3DXMLEngine

class CATPLMID;

/**
 * 
 * <br><b>Role</b>: This interface allows to get the destination Provider identification from source provider identification.
 * 
 */

class ExportedByCATPLMIdentification CATIPLMTransitionIdentification : public CATBaseUnknown
{
 CATDeclareInterface;

 public:

  /**
   * Get the target provider PLMID in the transaction.
   *
   * <br><b>Role</b>: This method is used to get the target Provider ID
   *
   * @param isourcePLMID
   * the PLMID of the object in the source Provider.
   *
   * @param otargetPLMID
   * the PLMID of the object in the target Provider.
   *
   * @return 
   * <tt>S_OK</tt> if ID has been successfully retrieved
   * <br><tt>E_FAIL</tt> for failure
   *
   */
   virtual HRESULT GetTargetIdentification(const CATPLMID& isourcePLMID, CATPLMID& otargetPLMID) = 0;

   /**
   * Get the target provider PLMID in the transaction.
   *
   * <br><b>Role</b>: This method is used to get the target Provider ID
   *
   * @param iTargetPLMID
   * the PLMID of the object in the target Provider.
   *
   * @param oSourcePLMID
   * the PLMID of the object in the source Provider.
   *
   * @return 
   * <tt>S_OK</tt> if ID has been successfully retrieved
   * <br><tt>E_FAIL</tt> for failure
   *
   */
   virtual HRESULT GetSourceIdentification(const CATPLMID& iTargetPLMID, CATPLMID& oSourcePLMID) = 0;
    
};

#endif
