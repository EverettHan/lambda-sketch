/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
 * @level Private
 * @usage U3
 */
#ifndef CATAdpIntegrationRestrictedToolbox_H
#define CATAdpIntegrationRestrictedToolbox_H

#include "CATErrorDef.h"
#include "PLMIntegrationAccessRestrictedUse.h"
#include "CATBooleanDef.h"
//#include "CATCollec.h"
#include "CATPLMID.h"
class CATProxySpace;
class CATIPLMRecordRead;
class CATIAdpErrorMonitorAbstract;

class ExportedByPLMIntegrationAccessRestrictedUse CATAdpIntegrationRestrictedToolbox
{
public:
  CATAdpIntegrationRestrictedToolbox(void);
  virtual ~CATAdpIntegrationRestrictedToolbox(void);

/**
 * @nodoc
 */
  static HRESULT AssociateDataspaceToErrorMonitor( const CATProxySpace & iSpace, CATIAdpErrorMonitorAbstract * iErrorMonitor );
  /*
  * @nodoc
  */
  static HRESULT CompleteWithCnxsAndPorts( const CATLISTV(CATPLMID) & iIds , CATLISTV(CATPLMID) & oIds);

  /*
  * @nodoc
  */
  static HRESULT CompleteWithRepRefs( const CATLISTV(CATPLMID) & iPIDs ,
                                                              const CATListValCATString & iKeyAttrList,
                                                              const CATListValCATUnicodeString & iKeyValueList,
                                                              CATLISTV(CATPLMID) & oPIDs,
                                                              const CATBoolean & iWithPorts=FALSE);

};
#endif

