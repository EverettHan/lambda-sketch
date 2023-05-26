/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2004
#ifndef CATIPLMOpenEngine_H
#define CATIPLMOpenEngine_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATIPLMVolatileDocumentFactory.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
class CATLISTV(CATPLMID); // Include CATLISTV_CATPLMID to access to that entities.
class CATLISTV(CATComponentId); // Include CATLISTV_CATComponentId to access to that entities.
class CATIPLMCompRecordReadSet;
class CATIPLMCompleteGraph;
class CATOmiLoadingModeRule;
class CATOmbLoadingModeRuleSet;
class CATIPLMOccurrencesBuilder;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMOpenEngine;
#else
extern "C" const IID IID_CATIPLMOpenEngine ;
#endif

/**
 * This interface defines the unique protocol of communication between the users and the open engine.
 * Use @href CATPLMEngineToolbox#GetOpenEngine to get a pointer on the open engine.
 * <br>Globally, the user can:
 * <ul>
 *   <li>Specify an opening mode to determine the context of opening in CATIA.</li>
 *   <li>Define loading mode rules used by the switch engine component to manage the catia documents (@href CATIOmiSwitchEngine ).</li>
 *   <li>Access thanks to @href CATPLMEngineToolbox#GetCompleteGraph to a CompleteGraph tool and use 
 * CompleteGraph to define a set of components to open.</li>
 *   <li>Ask the open engine to create in a CATIA session the components belonging to the complete graph area.</li>
 *   <li>Access to the components created during the open transaction.</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMOpenEngine: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * @deprecated V6R2009
 * Useless. Should not be used anymore.
 */
  virtual HRESULT SetOpeningMode( const CATIPLMVolatileDocumentFactory::PLMOpenMode iOpenMode ) = 0;
  
/** 
 * @deprecated V6R2009
 * @use CATIPLMOpenEngine#AddLoadingModeRules
 */
  virtual HRESULT AddLoadingModeRule(const CATOmiLoadingModeRule &iLoadingModeRule ) = 0;
 
/** 
 * Enables to add loading mode rules.
 *
 * <br><b>Role</b>: The loading mode rules have incidence only on the unstream. 
 * The number/nature of the streams loaded for a PLM component depend on the loading mode rule that applies on the component
 * (a loading mode rule doesn't have incidence on the set/number of PLM components to load).
 * Further information available in @href CATIOmiSwitchEngine#AddLoadingModeRules.
 *
 * @param iLoadingModeRules [in]
 *   The loading rules.
 *
 * @return
 *   <code>HRESULT</code> @href CATIOmiSwitchEngine#AddLoadingModeRules.
 *
 */
  virtual HRESULT AddLoadingModeRules(const CATOmbLoadingModeRuleSet& iLoadingRules)=0;
  
/** 
 * Enables to open a set of components defined though the complete graph component.
 *
 * <br><b>Role</b>: This method enables to trigger the load of a set of objects described thanks to the complete 
 * graph component.
 * <ul>
 * <li>Only the  elements listed by the CompleteGraph will be opened during the transaction.</li> 
 * <li>The open engine will be in charge of the retrieving in the database of the data needed by the factories
 * to instanciate in session the components.</li>
 * <li>If a component is already opened in the session, it is neither re-opened nor updated.</li>
 * <li>The open diagnostics could be retrieved through the @href CATIPLMEngineListener interface.</li>
 * <li> <code>ERR_01</code> error will be available on the provided @href CATIAdpErrorMonitor if the current authoring dataspace is not CATIA3D.</li>
 * </ul>
 *
 * @param iCompleteGraph [in]
 *   The input complete graph defining the set of elements to open.
 *
 * @return
 *   <code>S_OK</code> No major problem appeared during the transaction. The data could be opened in the session.
 *   <code>S_FALSE</code> The data could be opened in the session, but some open warnings were detected.
 *   <code>E_FAIL</code> A fatal error happened during the transaction. Nothing was done during the operation.
 *
 */
  virtual HRESULT Open( CATIPLMCompleteGraph * iCompleteGraph ) = 0;
  
/** 
 * @deprecated V5R203
 * @use CATIPLMOpenEngine#ListOpenedObjects
 *
 */
  virtual HRESULT ListOpenedObjects( CATLISTV(CATComponentId) & oOpenedObjects ) = 0;

/** 
 * Provide access to the components that are opened in the session following the open transactions.
 *
 * <br><b>Role</b>: Enables to retrieve the session object corresponding to each identifier that was asked 
 * to be opened. The session entity can be obtained thanks to @href CATComponentId#QueryInterface entry point on the @href CATComponentId.
 *
 * @param oOpenedInSession [out]
 *   The components which were opened in the session during this open transaction.
 * @param oAlreadyInSession [out]
 *   The component which were already available in the session. 
 *   <ul>
 *   <li> Nothing was done on those components.</li>
 *   <li> No refresh was performed through the open transaction.</li>
 *   </ul>
 *
 * @return
 *   <code>S_OK</code> Components are returned.
 *   <code>S_FALSE</code> No components available.
 *   <code>E_INVALIDARG</code> The input lists are not empty.
 *
 */
  virtual HRESULT ListOpenedObjects( CATLISTV(CATComponentId) & oOpenedInSession, CATLISTV(CATComponentId) & oAlreadyInSession ) = 0;

/** 
 * Gets a pointer on CATIPLMOccurrencesBuilder.
 *
 * <br><b>Role</b>: Returns an interface exposing service dedicated to build the filtered occurrence tree resulting from the open operation. 
 * 
 * @param oOccurrencesBuilder [out,CATBaseUnknown#Release] The out pointer.
 *
 * @return
 *   <code>S_OK</code> OK.
 *   <code>E_FAIL</code> failure.
 *   <code>E_NOTIMPL</code> not implemented.
 */
  virtual HRESULT GetOccurrencesBuilder (CATIPLMOccurrencesBuilder *& oOccurrencesBuilder ) = 0;
};
CATDeclareHandler( CATIPLMOpenEngine, CATBaseUnknown );
#endif
