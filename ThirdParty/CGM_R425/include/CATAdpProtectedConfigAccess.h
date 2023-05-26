/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2013

/**
 * @level Protected
 * @usage U1  
 */

#ifndef CATAdpProtectedConfigAccess_H
#define CATAdpProtectedConfigAccess_H

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATBooleanDef.h"
#include "CATCollec.h"
class CATIPLMComponent;
class CATIAdpErrorMonitor;
class CATPLMID;
class CATIAdpPLMIdentificator;
class CATIPLMSpace;
class CATProxySpace;
class CATComponentId;
class CATPLMTypeH;
class CATUnicodeString;
class CATPLMIDSet;
class CATLISTP(CATIAdpPLMIdentificator);
class CATLISTV(CATPLMID);
class CATLISTV(CATBaseUnknown_var);
class CATOmbRelationSnapshot;

/**
 * Class enabling to access to Session Config information.
 * <br><b>Role</b>: <p>Provide basic functions to determine information on the Config in the Session.</p>
 *
 * <p>Use should be associated to @href CATAdpProtectedOpener in Config mode.</p>
 *
 * Example of usage :
 * <pre>
 * 
 * CATAdpProtectedConfigAccess ConfigAccess();
 * CATBoolean isLoaded=FALSE;
 * HRESULT rc=ConfigAccess.IsConfigLoaded(<my_instance_ptr>, isLoaded);
 * if ( FAILED(rc) )
 * {
 *   CATIAdpErrorMonitor * pErrorMonitor=0;
 *   ConfigAccess.GetErrorMonitor(pErrorMonitor);
 *   [error treatments]
 *   CATSysReleasePtr(pErrorMonitor);
 * }
 * else
 * {
 *   if ( !isLoaded )
 *   {
 *     CATIAdpProtectedCompletionParameters_var spParams=CATAdpProtectedCompletionParametersConfigFactory::FullDependencies;
 *     CATAdpProtectedOpener opener(spParams);
 *     opener.AddElement(<my_instance_plmid>);
 *     CATPLMComponentData Result;
 *     CATOmbLifeCycleRootsBag Bag;
 *     opener.CompleteAndOpen(Result, Bag);
 *   }
 * }
 * </pre>
 */
class ExportedByCATPLMIntegrationAccess CATAdpProtectedConfigAccess
{

public:
  virtual ~CATAdpProtectedConfigAccess();

/**
 * Class constructor
 * <b>Role</b>: Create an access to dedicated config services.
 * 
 * @param iErrorMonitor [in]
 * Error monitor to populate with errors. You can also use @see CATAdpProtectedConfigAccess#GetErrorMonitor to get it afterwards.
 */
  CATAdpProtectedConfigAccess( CATIAdpErrorMonitor * iErrorMonitor=0 );

/**
 * Search in the Session the Config data associated to a given Instance.
 * <b>Role</b>: enables the user to determine if the Config data associated to an Instance are loaded in the Session.
 *
 * @param iInstance [in]
 * The Instance for which Config data has to be searched.
 * @param oIsLoaded [out]
 * Result.
 *
 * @return
 * <dl>
 * <dt><code>S_OK</code> Operation succeeded<dd>
 * <dt><code>E_FAIL</code> Failure, errors might be available on @CATIAdpErrorMonitor<dd>
 * <dt><code>E_INVALIDARG</code> Invalid input Instance is given (not an Instance, ...)<dd>
 * </dl>
 */
  HRESULT IsConfigLoaded( CATIPLMComponent * iInstance, CATBoolean & oIsLoaded );

/**
 * Search in the Session the Config data associated to a given Instance.
 * <b>Role</b>: enables the user to determine if the Config data associated to an Instance are loaded in the Session.
 *
 * @param iInstance [in]
 * The Instance for which Config data has to be searched.
 * @param iDataspace [in]
 * The Dataspace in which the Config data has to be searched. If <code>NULL</code> or <code>CATProxySpace_Null</code> is given, Authoring dataspace will be used.
 * @param oIsLoaded [out]
 * Result.
 *
 * @return
 * <dl>
 * <dt><code>S_OK</code> Operation succeeded<dd>
 * <dt><code>E_FAIL</code> Failure, errors might be available on @CATIAdpErrorMonitor<dd>
 * <dt><code>E_INVALIDARG</code> Invalid input Instance is given (not an Instance, ...)<dd>
 * </dl>
 */
  HRESULT IsConfigLoaded( CATIAdpPLMIdentificator * iInstance, CATIPLMSpace * iDataspace, CATBoolean & oIsLoaded );
  HRESULT IsConfigLoaded( CATIAdpPLMIdentificator * iInstance, const CATProxySpace & iDataspace, CATBoolean & oIsLoaded );
  HRESULT IsConfigLoaded( const CATPLMID & iInstance, CATIPLMSpace * iDataspace, CATBoolean & oIsLoaded );
  HRESULT IsConfigLoaded( const CATPLMID & iInstance, const CATProxySpace & iDataspace, CATBoolean & oIsLoaded );

/**
 * Search in the given Dataspace the Components pointed by the Config connections.
 * <b>Role</b>: enables the user to search in the given Dataspace the Components pointed through the given Semantic Relation Role by the configuration connections of give PLM Type.
 *
 * @param iDataspace [in]
 * The Dataspace in which the Config data has to be searched. If <code>NULL</code> is given, Authoring dataspace will be used.
 * @param iConfigConnectionType [in]
 * The PLM type of the connections which will be searched in the given Dataspace.
 * @param iSemanticRelationRole [in]
 * The Role of the Semantic Relation hich must be introspected on the found Connections.
 * @param oPointedComponents [out]
 * The Components pointed by the Connections found in the Dataspace.
 *
 * @return
 * <dl>
 * <dt><code>S_OK</code> Operation succeeded<dd>
 * <dt><code>E_FAIL</code> Failure, errors might be available on @CATIAdpErrorMonitor<dd>
 * <dt><code>E_INVALIDARG</code> Invalid input is given<dd>
 * </dl>
 */
  HRESULT FindPointedInSession( CATIPLMSpace * iDataspace, const CATPLMTypeH & iConfigConnectionType, const CATUnicodeString & iSemanticRelationRole, CATLISTP(CATIAdpPLMIdentificator) & oPointedComponents );
  HRESULT FindPointedInSession( CATIPLMSpace * iDataspace, const CATPLMTypeH & iConfigConnectionType, const CATUnicodeString & iSemanticRelationRole, CATLISTV(CATPLMID) & oPointedComponents );
  HRESULT FindPointedInSession( CATIPLMSpace * iDataspace, const CATPLMTypeH & iConfigConnectionType, const CATUnicodeString & iSemanticRelationRole, CATPLMIDSet & oPointedComponents );

/**
 * Get the error monitor.
 * <br><b>Role</b>: enables the user to retrieve the Error Monitor.
 *
 * @param oErrorMonitor [out, CATBaseUnknown#Release]
 * Error monitor giving access to errors.</li>
 *
 * @return
 * <dl>
 * <dt><code>S_OK</code> Operation succeeded </dd>
 * <dt><code>E_FAIL</code> Failure</dd>
 * </dl>
 */
HRESULT GetErrorMonitor( CATIAdpErrorMonitor *& oErrorMonitor );

private:
  CATAdpProtectedConfigAccess( const CATAdpProtectedConfigAccess & );
  CATAdpProtectedConfigAccess & operator=( const CATAdpProtectedConfigAccess & );
  HRESULT IsConfigLoaded( const CATComponentId & iInstance, CATBoolean & oIsLoaded );
  HRESULT FindInDataspace( const CATPLMTypeH & iType, CATIPLMSpace * iSpace, CATLISTV(CATBaseUnknown_var) & oResult );
  HRESULT ExtractPointedComponents( CATOmbRelationSnapshot & iSnapshot, CATPLMIDSet & ioPointedComponents );

private:
  CATIAdpErrorMonitor * _ErrorMonitor;
};

//-----------------------------------------------------------------------

#endif
