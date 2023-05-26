/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMEnginesToolbox_H
#define CATPLMEnginesToolbox_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATErrorDef.h"
#include "CATIPLMNewVersionEngine.h"
#include "CATIPLMCloningEngine.h"

class CATIPLMOpenEngine;
class CATIPLMSaveEngine;
class CATIPLMEngineListener;
class CATIPLMSaveScope;
class CATIPLMCompleteGraph;
class CATIPLMReplicationEngine;
class CATIPLMReplicationEnginePlugServices;
// MODIF PA DEB 16/06/2008
class CATIPLMREEditionTokenServices;
// MODIF PA FIN 16/06/2008
class CATIPLMBriefcaseServices;
class CATIPLMMaturityEngine;
class CATIPLMTransferEngine;
class CATIPLMTransferInformation;
class CATIPLMFillEngine;
class CATIPLMLocalSaveEngine;
class CATProxySpace;
class CATUnicodeString;
class CATIPLMGenericListenerAbstract;
class CATIPLMLocalSaveListener;
class CATIPLMLockEngine;
class CATIAdpErrorMonitorAbstract;
class CATIPLMExportEngine;
class CATIPLMCopyEngine;

/**
 * Class to access to the integration engines
 *<br><b>Role</b>: Thanks to its static method, you can access to the open engine, the save engine or to the save scope.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMEnginesToolbox
{
public:

/**
 * @deprecated V6R2011x
 * @use CATPLMSessionManagementBuilder#GetOpenEngine
 */
  static HRESULT GetOpenEngine( CATIPLMOpenEngine *& oOpenEngine , CATIPLMEngineListener * ioListener=0 , CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );

/**
 * @deprecated V6R2011x
 * @use CATPLMSessionManagementBuilder#GetSaveEngine
 */
  static HRESULT GetSaveEngine( CATIPLMSaveEngine *& oSaveEngine , CATIPLMEngineListener * ioListener=0, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );

/**
 * @deprecated V6R2011x
 * @use CATPLMSessionManagementBuilder#GetSaveScope
 */
  static HRESULT GetSaveScope( CATIPLMSaveScope *& oSaveScope);

/**
 * @deprecated V6R2011x
 * @use CATPLMSessionManagementBuilder#GetCompleteGraph
 */
  static HRESULT GetCompleteGraph( CATIPLMCompleteGraph *& oCGraph, CATIPLMEngineListener * ioListener=0, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );

/** 
 * @deprecated V6R2011x
 * @use CATPLMComponentManagementBuilder#GetMaturityEngine
 */
  static HRESULT GetMaturityEngine( CATIPLMMaturityEngine *& oEngine, 
                                    CATIPLMEngineListener * iListener, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );

  /**
  * Get a replication engine.
  *
  * <br><b>Role</b>: Creation of a replication engine
  *
  * @param opReplicationEngine [out, CATBaseUnknown#Release]
  *   A pointer on the replication engine. Release the pointer when useless.
  * @param ioListener [inout]
  *   The error listener to use during export/import process.
 * @param ioErrorMonitor [inout]
 *   The ErrorMonitor that collects all eventual errors happening during export/import process 
  * @return
  * <dl>
  * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the replication engine to retrieve a pointer on the @href CATIPLMReplicationEngine interface.</tt>
  * </dl>
  *
  */

  static HRESULT GetReplicationEngine( CATIPLMReplicationEngine *& opReplicationEngine, CATIPLMEngineListener * ioListener = 0, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );
 
	/**
  * Get a replication engine.
  *
  * <br><b>Role</b>: Creation of a replication engine
  *
  * @param opReplicationEngine [out, CATBaseUnknown#Release]
  *   A pointer on the replication engine. Release the pointer when useless.
  * @param ioListener [inout]
  *   The error listener to use during export/import process.
	* @param iProxySpace [in]
  *	  The workspace for the replication engine to work in. 
 * @param ioErrorMonitor [inout]
 *   The ErrorMonitor that collects all eventual errors happening during export/import process 
  * @return
  * <dl>
  * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the replication engine to retrieve a pointer on the @href CATIPLMReplicationEngine interface.</tt>
  * </dl>
  *
  */
  static HRESULT GetReplicationEngine( CATIPLMReplicationEngine *& opReplicationEngine, CATIPLMEngineListener * ioListener , const CATProxySpace & iProxySpace, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );

  /**
  * Get the services dedicated to briefcase management.
  *
  * <br><b>Role</b>: Returns a service component dedicated to briefcase management.
  *
  * @param opBriefcaseServices [out, CATBaseUnknown#Release]
  *   A pointer on the briefcase service component. Release the pointer when useless.
  * @return
  * <dl>
  * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the service component to retrieve a pointer on the @href CATIPLMBriefcaseServices interface.</tt>
  * </dl>
  *
  */
  static HRESULT GetBriefcaseServices( CATIPLMBriefcaseServices *& opBriefcaseServices );

  /**
  * Get the services dedicated to plug management.
  *
  * <br><b>Role</b>: Returns an interface exposing services dedicated to PLM channel management. 
  *
  * @param opPlugServices [out, CATBaseUnknown#Release]
  *   A pointer on the plug service component. Release the pointer when useless.
  * @return
  * <dl>
  * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the service component to retrieve a pointer on the @href CATIPLMBriefcaseServices interface.</tt>
  * </dl>
  *
  */
  static HRESULT GetPlugServices( CATIPLMReplicationEnginePlugServices *& opPlugServices );

// MODIF PA DEB 16/06/2008
/**
  * Get the services dedicated to the edition tokens.
  *
  * <br><b>Role</b>: Returns an interface exposing services dedicated to edition tokens management. 
  *
  * @param opEditionTokenServices [out, CATBaseUnknown#Release]
  *   A pointer on the edition tokens service component. Release the pointer when useless.
  * @return
  * <dl>
  * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the service component to retrieve a pointer on the @href CATIPLMREEditionTokenServices interface.</tt>
  * </dl>
  *
  */
  static HRESULT GetEditionTokenServices( CATIPLMREEditionTokenServices *& opEditionTokenServices );
// MODIF PA FIN 16/06/2008


 /**
 * Gets a pointer on CATIPLMTransferEngine and CATIPLMTransferInformation.
 *
 * @param oTransferEngine [out, CATBaseUnknown#Release]
 * The retrieved transfer engine. Release is to be called on the provided pointer when useless.
 *
 * @param oTransferInfo [out, CATBaseUnknown#Release]
 * The retrieved transfer information. Release is to be called on the provided pointer when useless.
 *
 * @param iListener [in]
 * The listener to attach to the transfer process.
 *
 * @return
 * <tt>HRESULT</tt>
 * <dl>
 * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the transfer engine to retrieve a pointer on the @href CATIPLMTransferEngine interface.</tt>
 * </dl>
 */
  static HRESULT GetTransferEngine( CATIPLMTransferEngine *& oTransferEngine, 
									CATIPLMTransferInformation *& oTransferInfo,
									CATIPLMEngineListener * iListener=0);

 
/** 
 * @deprecated V6R2011x
 * @use CATPLMSessionManagementBuilder#GetFillEngine
 */
  static HRESULT GetFillEngine( CATIPLMFillEngine *& oEngine, 
                                const CATProxySpace & iSpace, CATIPLMEngineListener * iListener, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );

/**
 * @deprecated V6R2010
 * @use CATPLMSessionManagementBuilder#GetFillEngine
 */
  static HRESULT GetFillEngine( CATIPLMFillEngine *& oEngine, 
                                const CATUnicodeString & iSpaceId, CATIPLMEngineListener * iListener );

/**
 * @deprecated V6R2011x
 * @use CATPLMComponentManagementBuilder#GetLockEngine
 */
  static HRESULT GetLockEngine(CATIPLMLockEngine *& oEngine, CATIPLMEngineListener * ioListener = 0, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0);


/**
 * @deprecated V6R2011x
 * @use CATPLMSessionManagementBuilder#GetLocalSaveEngine
 */
  static HRESULT GetLocalSaveEngine( CATIPLMLocalSaveEngine *& oEngine, CATIPLMLocalSaveListener * ioListener = 0, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );

/**
 * @deprecated V6R2011x
 * @use CATPLMComponentManagementBuilder#GetVersioningEngine
 */
  static HRESULT GetNewVersionEngine( CATIPLMNewVersionEngine::VersioningMode iVersioningMode,
                                      CATIPLMNewVersionEngine *& oEngine, CATIPLMEngineListener * iListener, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );

/**
 * @deprecated V6R2011x
 * @use CATPLMComponentManagementBuilder#GetCloningEngine
 */
  static HRESULT GetCloningEngine( CATPLMCloningMode::CloningMode iCloningMode,
                                   CATIPLMCloningEngine *& oEngine, CATIPLMEngineListener * iListener, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );

/**
 * @deprecated V6R2011x
 * @use CATPLMComponentManagementBuilder#GetCopyEngine
 */
  static HRESULT GetCopyEngine(    CATPLMCloningMode::CloningMode iCloningMode,
                                   CATIPLMCopyEngine *& oEngine, CATIPLMEngineListener * iListener, CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );


  /**
  * Get an export engine.
  *
  * <br><b>Role</b>: Creation of an export engine
  *
  * @param oExportEngine [out, CATBaseUnknown#Release]
  *   A pointer on the replication engine. Release the pointer when useless.
  * @param ioListener [inout]
  *   The error listener to use during export completion process.
 * @param ioErrorMonitor [inout]
 *   The ErrorMonitor that collects all eventual errors happening during export completion process 
  * @return
  * <dl>
  * <dt> <tt>The result of the @href CATBaseUnknown#QueryInterface on the export engine to retrieve a pointer on the @href CATIPLMExportEngine interface.</tt>
  * </dl>
  *
  */
  static HRESULT GetExportEngine( CATIPLMExportEngine *& oExportEngine, CATIPLMEngineListener * ioListener=0 , CATIAdpErrorMonitorAbstract * ioErrorMonitor=0 );

};
#endif
