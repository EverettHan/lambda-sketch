#ifndef _CATxPDMSessionCoordinator_H
#define _CATxPDMSessionCoordinator_H
/* -*-c++-*- */
/* 
* @COPYRIGHT DASSAULT SYSTEMES 2008
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
 * @level Private
 * @usage U1       
 */

#define AuthorizedModule                  999
#define CATxPDMLog      									AuthorizedModule
#define CATPLMItgXPDMLog                  AuthorizedModule
#define CATOxiPDMLog                      AuthorizedModule
#define CATPLMIntegration                 AuthorizedModule
#define CATPLMTos                         AuthorizedModule
#define CATOxiPDMLogNewVersion            AuthorizedModule
#define CATPLMIntegrationAccess           AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
	    #error Forbidden access to CATxPDMSessionCoordinator from a non-infrastructure module
        @error 
#endif
#undef CATxPDMLog   
#undef CATPLMItgXPDMLog 
#undef CATOxiPDMLog
#undef CATPLMIntegration
#undef CATPLMTos
#undef CATOxiPDMLogNewVersion
#undef CATPLMIntegrationAccess

#include "IUnknown.h"
#include "CATUnicodeString.h"
#include "ExportedByCATPLMIdentification.h"

class CATILockBytes2;

/** This class provides information about the ressources/directory/files that must be used to create
 *  a save log. It returns a path to the file where the save log must be created.
 *  This class is a singleton, please use GetxPDMChangeSessionCoordinator to obtain the object.
 */

class ExportedByCATPLMIdentification CATxPDMSessionCoordinator
{
public:
  /**
  * GetxPDMChangeSessionCoordinator
  *
  * @return
  *   A pointer to the single object of the class
  */
  static CATxPDMSessionCoordinator * GetxPDMChangeSessionCoordinator();

  /**
  * DeleteSessionCoordinator
  *   Deletes the single object of the class
  */
  static void DeleteSessionCoordinator();

  /**
  * Check if PDM Log is activated
  *
  * @return
  *   TRUE  : PDM is activated
  *   FALSE : PDM is not activated
  */
  static CATBoolean IsPDMLogActivated();

  /**
  * GetCurrentxPDMLogPath
  *
  * @param oLogPath
  *   The path to the file in which the save log will be put
  *
  * @return
  *   S_OK if the process succeeded
  *   E_FAIL otherwise
  */
  HRESULT GetCurrentxPDMLogPath(CATUnicodeString & oLogPath);

  /**
  * GetCurrentxPDMLogPath
  *
  * @param oLogBytes
  *   The stream representing the file in which the save log will be put
  *
  * @return
  *   S_OK if the initialization process succeeded
  *   E_FAIL otherwise
  */
  HRESULT GetCurrentxPDMLogPath(CATILockBytes2 * oLogBytes);



protected:
  friend class CATAdpXPDMLogSessionNavigator;
  friend class CATAdpXPDMLogSessionNavigatorImpl;
  friend class CATxPDMSessionDescription;
  friend class CATOxiPDMLog;
  CATUnicodeString & GetUserId() {return _User;}
  CATUnicodeString & GetMachineId() {return _Machine;}
  static HRESULT GetPathToxPDMLogs(CATUnicodeString & oPath);
  static HRESULT GetPathToxPDMLogs(CATUnicodeString & iPathToTMP, CATUnicodeString & oLogPath);
  CATUnicodeString & GetPathToSession() {return _SessionPath;}

private:
  CATxPDMSessionCoordinator();
  ~CATxPDMSessionCoordinator();

  HRESULT Init();

  CATUnicodeString _SessionPath;

  CATUnicodeString _User;
  CATUnicodeString _Machine;

  static CATxPDMSessionCoordinator * _Coordinator;

  static CATUnicodeString _xPDMLogDirectoryName;
};

#endif
