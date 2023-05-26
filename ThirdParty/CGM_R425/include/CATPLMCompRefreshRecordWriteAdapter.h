// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATPLMCompRefreshRecordWriteAdapter.h
// Define the CATPLMCompRefreshRecordWriteAdapter interface
//
//===================================================================
//
// Usage notes:
//    New interface:
//    During a PLMCOPY, instances and references are explicitely given
//    Completion is called on the server side to get port and connection
//    For each object given (instance or reference), we specify options:
//    KeepOwnership,KeepLock,KeepMaturity,KeepVersioning.
//
//    During a PLMCLONE, completion is called on the server side to retrive
//    all objects.
//
//===================================================================
//
// June 2009  Creation: EPB
//===================================================================

/**
* @level Protected
* @usage U3
*/

#ifndef CATPLMCompRefreshRecordWriteAdapter_H
#define CATPLMCompRefreshRecordWriteAdapter_H

#include "CATPLMImplAdapterClass.h"

#include "CATIPLMCompRefreshRecordWrite.h"

/**
* Interface belonging to the <b>Component services</b>.
* Using this level of abstraction you manipulate only Componet Id without knowing the PDM it belongs to.<br>
*
* Provides methods in order to New Version current object.
* This operation can be done under the control of a transaction of the PDM(s). 
*/
class ExportedByCATPLMImplAdapterClass CATPLMCompRefreshRecordWriteAdapter: public CATIPLMCompRefreshRecordWrite
{
public:
  CATPLMCompRefreshRecordWriteAdapter ();
  virtual ~CATPLMCompRefreshRecordWriteAdapter();

  virtual HRESULT SetBaseObject( const CATPLMID & iBaseId ) ;

  virtual HRESULT GetObjects ( CATPLMID & oTargetId, CATPLMID & oBaseId );

  virtual HRESULT GetAttributeAccess ( CATIPLMAttrWrite** oAttrAccess, const CATPLMTypeId *iExtensionType = NULL);

private:
  CATPLMCompRefreshRecordWriteAdapter (CATPLMCompRefreshRecordWriteAdapter &);
  CATPLMCompRefreshRecordWriteAdapter& operator=(CATPLMCompRefreshRecordWriteAdapter&);

};

#endif
