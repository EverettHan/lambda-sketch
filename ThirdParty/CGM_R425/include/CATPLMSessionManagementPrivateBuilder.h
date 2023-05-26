//===================================================================
// COPYRIGHT DASSAULT SYSTEMES 2010/12/17
//===================================================================
// CATPLMSessionManagementPrivateBuilder.cpp
// Header definition of class CATPLMSessionManagementPrivateBuilder
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2010/12/17 Creation: Code generated by the 3DS wizard
//===================================================================
/**
* @level Private
* @usage U1  
*/
#ifndef CATPLMSessionManagementPrivateBuilder_H
#define CATPLMSessionManagementPrivateBuilder_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATPLMGenericEngineBuilder.h"
class CATProxySpace;
class CATPLMCompletionParameters;
class CATIPLMOpenEngine;
class CATIPLMCompleteGraphWithFilter;
class CATIPLMCompleteGraph;
class CATIPLMLocalSaveTransactionManager;
class CATProxyTransaction;

// small checks
#if defined (private) || defined(friend) || defined (protected)
#error Forbidden re-define of 'private', 'friend' or 'protected'
@error
#endif

#define AuthorizedModule 999
#define CATPLMIntegrationAccess       AuthorizedModule
#define CATPLMIntegrationInterfaces   AuthorizedModule
#define CATPLMComponentChecker        AuthorizedModule
#define CATPLMOpenUI                  AuthorizedModule
#define CATPLMIdentification_PLM      AuthorizedModule
#define CATPLMModelBuilder            AuthorizedModule
#define CATPLMIntegrationInfra        AuthorizedModule
#define CATPLMIntegration             AuthorizedModule

#if _MK_MODNAME_ == AuthorizedModule
#else
#error This header is for internal use only
        // Fatal error on solaris
    @error
#endif

#undef CATPLMIntegrationAccess
#undef CATPLMIntegrationInterfaces
#undef CATPLMComponentChecker
#undef CATPLMOpenUI
#undef CATPLMIdentification_PLM
#undef CATPLMModelBuilder
#undef CATPLMIntegrationInfra
#undef CATPLMIntegration

//-----------------------------------------------------------------------

class ExportedByCATPLMIntegrationInterfaces CATPLMSessionManagementPrivateBuilder : public CATPLMGenericEngineBuilder
{
public:
// Standard constructors and destructors
// -------------------------------------
CATPLMSessionManagementPrivateBuilder ();
virtual ~CATPLMSessionManagementPrivateBuilder ();

/**
 * Get a Complete Graph.
 * <br><b>Role</b>: Creation of a Completion Graph Manager.
 * <ul>
 * <li>Error Monitor can be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetErrorMonitor.</li>
 * <li>Engine Listener must be provided to the Builder thanks to @href CATPLMGenericEngineBuilder#SetListener.</li>
 * </ul>
 *
 * @param oCompleteGraph [out, CATBaseUnknown#Release]
 *   The created Complete Graph.
 *
 * @return
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the complete graph to retrieve a pointer on the @href CATIPLMCompleteGraph interface.</tt>
 * </dl>
 */
  HRESULT GetCompleteGraphWithFilter( CATIPLMCompleteGraphWithFilter *& oCompleteGraph, CATPLMCompletionParameters &iCompletionParams );

  /*
  * For CATPLMItgDecoration
  */
  HRESULT GetCompleteGraphForRelevantCnxAndPorts( CATIPLMCompleteGraphWithFilter *& oCompleteGraph, CATProxySpace &iProxySpace);
	/*
  * For CATPLMItgDecoration
  */
  HRESULT GetCompleteGraphForRFLImplementLinks( CATIPLMCompleteGraph *& oCompleteGraph, CATProxySpace &iProxySpace);

   /*
  * For CATIPLMIterationsOpener  - Give an handle on the new open engine
  */
  HRESULT GetSessionOpenEngine( CATIPLMOpenEngine *& oEngine);

  /**
   * @brief GetLocalSaveTransactionManager
   * @details Get a handler on a new local save transaction manager
   * 
   * @param oManager The handler
   */
  HRESULT GetLocalSaveTransactionManager( CATIPLMLocalSaveTransactionManager *& oManager, const CATProxySpace & iProxySpace);

private:
// Copy constructor and equal operator
// -----------------------------------
CATPLMSessionManagementPrivateBuilder (CATPLMSessionManagementPrivateBuilder &);
CATPLMSessionManagementPrivateBuilder& operator=(CATPLMSessionManagementPrivateBuilder&);

};

//-----------------------------------------------------------------------

#endif