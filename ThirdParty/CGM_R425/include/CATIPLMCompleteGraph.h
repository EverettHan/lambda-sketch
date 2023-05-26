// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMCompleteGraph.h
// Define the CATIPLMCompleteGraph interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Mar 2005  Creation: Code generated by the CAA wizard  son
//===================================================================
/**
* @level Protected
* @usage U3
*/
#ifndef CATIPLMCompleteGraph_H
#define CATIPLMCompleteGraph_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
class CATLISTV(CATPLMID); // Include CATLISTV_CATPLMID to access to that entities.
class CATIAdpErrorMonitor;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMCompleteGraph;
#else
extern "C" const IID IID_CATIPLMCompleteGraph ;
#endif

//------------------------------------------------------------------

/**
* This interface is the unique way to define entry point for the open engine.
* Use @href CATPLMIntegration.CATPLMEngineToolbox#GetCompleteGraph to get a pointer on the complete graph.
* <br><b>Role</b>:
* <br>- Thanks to this interface you can define a coherent set of identifiers to open. In addition, you can choose applicative rules through an CG mode.
* <br>- After building a complete graph set, you can call the OpenEngine's open method on the complete graph, or just ask for a view of the complete graph set ("open simulation view")
*/
class ExportedByCATPLMIntegrationInterfaces CATIPLMCompleteGraph: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

/**
 * Defines a mode of data completion applied to the Complete Graph.
 * <br><b>Role:</b>Description of the available modes defining the type of components which will be retrieved through an expand 
 * request, together with the depth of expand query. Please, refer to @href CATPLMCoreType for semantical explanation on the types.
 * <dt> <code><b>Navigation</b></code>     <dd> Only the components defining the structure on the first level will be retrieved, 
 * i.e. instances (aka. PLMCoreInstance) of the first level with its references (aka. PLMCoreReference).
 * <dt> <code><b>Browse</b></code>     <dd> Only the components defining the usable structure on the first level will be retrieved, 
 * i.e. instances (aka. PLMCoreInstance) of the first level with its references (aka. PLMCoreReference) and rep instances (aka. PLMCoreRepInstance) 
 * of the first level with its references (aka. PLMCoreRepReference).
 * <dt> <code><b>Authoring</b></code>     <dd> All the components defining an authoring structure on the first level will be retrieved, 
 * i.e. instances (aka. PLMCoreInstance) of the first level with its references (aka. PLMCoreReference), rep instances (aka. PLMCoreRepInstance) 
 * of the first level with its references (aka. PLMCoreRepReference), first level connexions (aka. PLMConnection) and first level 
 * ports (aka. PLMPort).
 * <dt> <code><b>Integrity</b></code>     <dd> Only components ensuring the integrity of the opened structure will be retrieved. 
 * Thus, no instance (aka. PLMCoreInstance, PLMCoreRepInstance), port (aka. PLMPort) or connexion (aka. PLMConnection) will be added
 * to the provided set of components.
 * <dt> <code><b>TemporaryExpand</b></code>     <dd> nodoc.
 * <dt> <code><b>FullNavigation</b></code>     <dd> Only the components defining the structure will be retrieved, i.e. references
 * (aka. PLMCoreReference) and instances (aka. PLMCoreInstance). Expand is recursive on all the structure under the roots provided.
 * <dt> <code><b>TemporaryPortOnRep</b></code>     <dd> nodoc.
 * <dt> <code><b>SpecialBrowse</b></code>     <dd> nodoc.
 * <dt> <code><b>Relational</b></code>     <dd> nodoc.
 */
    enum CGMode { Navigation=0, Browse=1, Authoring=2, Integrity=3, TemporaryExpand=4, FullNavigation=5, TemporaryPortOnRep=6, SpecialBrowse=7, Relational=8 };
    
    
    
    /**
    * Completes the provided selection of PLM identifiers according to the applicative rules if required and the mandatory integrity rules.
    * <br>Each call enriches the current set of identifiers.
    * @param const CATLISTV(CATPLMID) & iIds [in]
    *   The ids the client want to open/ simulate open
    * @param const CGMode & iMode [in]
    *   Applicative completion mode
    */
    virtual HRESULT Complete( const CATLISTV(CATPLMID) & iIds , const CGMode & iMode ) = 0 ;
    
    
    /**
    * Retrieves the list of PLM identifiers set managed by the complete graph.
    * @param CATLISTV(CATPLMID) & oIds [out]
    *   All the identifiers collected by the Complete method call (or successive calls)
    */
    virtual HRESULT GetComponents(CATLISTV(CATPLMID) & oIds) =0;


/** 
 * Give access to an error monitor.
 *
 * <br><b>Role</b>: Gets the @href CATIAdpErrorMonitor enabling to introspect the errors occuring during the completion process.
 *
 * @param oErrorMonitor [out, CATBaseUnknown#Release]
 *   The error monitor.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the Error Monitor could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
    virtual HRESULT GetErrorMonitor( CATIAdpErrorMonitor *& oErrorMonitor )=0;
};
CATDeclareHandler(CATIPLMCompleteGraph, CATBaseUnknown);
//------------------------------------------------------------------

#endif