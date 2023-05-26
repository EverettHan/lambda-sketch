#ifndef CATPLMIDSerializableSet_H
#define CATPLMIDSerializableSet_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2009
/**
* @level Private
* @usage U1
*/
// ----------------------------------------------------------------------------------------------------------------------
#define AuthorizedModule                           999
#define CATPLMIdentifier                           AuthorizedModule
#define PLMQLInEKLDebug                            AuthorizedModule
#define CATOxiPLMIDCollection                  AuthorizedModule
#define CATPLMIntegration                          AuthorizedModule
#define CATPLMIntegrationBase                      AuthorizedModule
#define SimulationBatchExecuterUI                  AuthorizedModule
#define CATSimBatchMonitoring                      AuthorizedModule
#define CATPLMComponentCheckerBatchUI              AuthorizedModule
#define CATPLMComponentChecker                     AuthorizedModule
#if _MK_MODNAME_ == AuthorizedModule
#else
#error Forbidden access to CATPLMIDSerializableSet from a non-infrastructure module
@error

#endif
#undef CATPLMIdentifier
#undef PLMQLInEKLDebug
#undef CATOxiPLMIDCollection
#undef CATPLMIntegration
#undef CATPLMIntegrationBase
#undef SimulationBatchExecuterUI
#undef CATSimBatchMonitoring
#undef CATPLMComponentCheckerBatchUI
#undef CATPLMComponentChecker
// ----------------------------------------------------------------------------------------------------------------------
#include "CATPLMIdentificationAccess.h"
#include "CATBaseUnknown.h"
#include "CATBoolean.h"
#include "CATDataType.h"
#include "CATPLMIDSet.h"

class CATPLMID;
class CATOmXStream;
class CATPLMIDVisitor;
class CATPLMIDSerializableSetImpl;

/**
* Serializable set of PLMID
*/
class ExportedByCATPLMIdentificationAccess CATPLMIDSerializableSet : public CATPLMIDSet
{
public:
  /** useless  */
  HRESULT Init() { return S_OK; }

  /**
  * Serialize the set.
  *
  * @param oStream : the stream where to write the log
  *
  * @return
  *   S_OK if operation succeeded
  *   E_FAIL otherwise
  */
  HRESULT Serialize(CATOmXStream & oStream) const;

  /**
  * Unserialize the set.
  *
  * @param iStream : the log stream to unmarshall
  * @param oDescription : the log description object
  */
  static HRESULT Unserialize(CATOmXStream & iStream, CATPLMIDSerializableSet & oSet);
};
#endif
