// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMClientTasks.h
// Header definition of CATPLMClientTasks
//
//===================================================================
//
// Usage notes:
// Current class is used to store different client tasks (client tasks containing message and client tasks containing a group of modified objects)
// CATPLMClientTasks respect copy and write pattern
//
//===================================================================
// September 2022  Creation: EPB
//===================================================================
#ifndef CATPLMClientTasks_H
#define CATPLMClientTasks_H

#include "CATPLMServicesItf.h"

#include "CATOmxSR.h"

#include "CATPLMOmxCollections.h"

class CATPLMClientTasksInt;
class CATPLMClientTaskMessage;
class CATPLMClientTaskGroupOfObjects;

class ExportedByCATPLMServicesItf CATPLMClientTasks
{
  friend class CATPLMClientTasksFactory;
public:
  CATPLMClientTasks();
  ~CATPLMClientTasks();

  CATPLMClientTasks(const CATPLMClientTasks&);
  CATPLMClientTasks& operator=(const CATPLMClientTasks&);

  // array of CATPLMClientTaskMessage
  CATPLMArrayClientTaskMessage GetMessages() const;

  // array of CATPLMClientTaskGroupOfObjects
  // Retrieve only objects that are completed
  CATPLMArrayClientTaskGroupOfObjects GetClientTaskGroupOfObjects() const;

  bool IsEmpty() const;
private:
  HRESULT _Append(const CATPLMClientTaskMessage& iMessage);

  HRESULT _Append(const CATPLMClientTaskGroupOfObjects& iObject);

  CATOmxSR<CATPLMClientTasksInt> _spCT;
};

#endif
