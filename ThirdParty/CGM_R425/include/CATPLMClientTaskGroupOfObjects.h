// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMClientTaskGroupOfObjects.h
// Header definition of CATPLMClientTaskGroupOfObjects
//
//===================================================================
//
// Usage notes:
// Current class is used to store a client task containing a group of modified objects
// CATPLMClientTasks respect copy and write pattern
//
//===================================================================
// September 2022  Creation: EPB
//===================================================================
#ifndef CATPLMClientTaskGroupOfObjects_H
#define CATPLMClientTaskGroupOfObjects_H

#include "CATPLMServicesItf.h"

#include "CATPLMOmxCollections.h"

#include "CATOmxSR.h"

class CATPLMClientTaskGroupOfObjectsInt;
class CATUnicodeString;

class ExportedByCATPLMServicesItf CATPLMClientTaskGroupOfObjects
{
  friend class CATPLMClientTasksFactory;
  friend class CATPLMClientTaskFactory;
  friend class CATPLMClientTaskGroupOfObjectsInt;
public:
  CATPLMClientTaskGroupOfObjects();
  ~CATPLMClientTaskGroupOfObjects();

  CATPLMClientTaskGroupOfObjects(const CATPLMClientTaskGroupOfObjects&);
  CATPLMClientTaskGroupOfObjects& operator=(const CATPLMClientTaskGroupOfObjects&);

  bool IsEmpty() const;

  //CATPLMArrayClientTaskObject <=> CATOmxArray of CATPLMClientTaskObject;
  CATPLMArrayClientTaskObject GetClientTaskObjects() const;

  CATUnicodeString GetAdditionalInfo() const;

  CATUnicodeString GetErrorKey() const;

  CATUnicodeString GetCatalogName() const;

  CATUnicodeString GetNLSRequest() const;

private:
  enum eSeverity { Undefined = 1, Error = 2, Notice = 3, UpdateClient = 4};

  eSeverity GetSeverity() const;

  CATPLMClientTaskGroupOfObjects(eSeverity iSeverity, const CATUnicodeString& iAdditionalInfo, const CATPLMArrayClientTaskObject& iCTObject);

  CATPLMArrayClientTaskObject& GetClientTaskObjectsW();

  CATOmxSR<CATPLMClientTaskGroupOfObjectsInt> _spCTObject;
};

#endif
