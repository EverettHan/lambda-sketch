// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATPLMCompWspMngtRecordWriteAdapter.h
// Define the CATPLMCompWspMngtRecordWriteAdapter interface
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

#ifndef CATPLMCompWspMngtRecordWriteAdapter_H
#define CATPLMCompWspMngtRecordWriteAdapter_H

#include "CATPLMImplAdapterClass.h"

#include "CATIPLMCompWspMngtRecordWrite.h"

/**
* Interface belonging to the <b>Component services</b>.
* Using this level of abstraction you manipulate only Component Id without knowing the PDM it belongs to.<br>
*
* Provides methods in order to New Version current object.
* This operation can be done under the control of a transaction of the PDM(s). 
*/
class ExportedByCATPLMImplAdapterClass CATPLMCompWspMngtRecordWriteAdapter: public CATIPLMCompWspMngtRecordWrite
{
public:
  CATPLMCompWspMngtRecordWriteAdapter ();
  virtual ~CATPLMCompWspMngtRecordWriteAdapter();

  virtual HRESULT GetPLMId( CATPLMID & oId );

  virtual HRESULT SynchronizeMap( const CATPLMID &iRefObject);

  virtual HRESULT SynchronizeAttach();

  virtual HRESULT SynchronizeUpdate( const CATPLMID &iRefObject);

  virtual HRESULT SynchronizeDetach ( const CATPLMID &iRefObject);

  virtual HRESULT DeliverCreate();

  virtual HRESULT DeliverUpdate(const CATPLMID &iRefObject);

  virtual HRESULT DeliverDelete(const CATPLMID &iRefObject);

  virtual HRESULT DeliverMap( const CATPLMID &iRefObject);

  virtual HRESULT GetAttributeAccess ( CATIPLMAttrWrite** oAttrAccess, const CATPLMTypeId *iExtensionType = NULL);

private:
  CATPLMCompWspMngtRecordWriteAdapter (CATPLMCompWspMngtRecordWriteAdapter &);
  CATPLMCompWspMngtRecordWriteAdapter& operator=(CATPLMCompWspMngtRecordWriteAdapter&);

};

#endif
