// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATPLMClientTaskObject.h
// Header definition of CATPLMClientTaskObject
//
//===================================================================
//
// Usage notes:
// Current class is used to store a client task containing a modified objects
// CATPLMClientTasks respect copy and write pattern
//
//===================================================================
// September 2022  Creation: EPB
//===================================================================
#ifndef CATPLMClientTaskObject_H
#define CATPLMClientTaskObject_H

#include "CATPLMServicesItf.h"

#include "CATPLMTypeIdClassificationEnum.h"

#include "CATOmxSR.h"

class CATPLMClientTaskObjectInt;
class CATPLMID;
class CATOmxKeyValueBlock;
class CATUnicodeString;
class CATPLMRepositoryName;
class CATPLMID_Any;

class ExportedByCATPLMServicesItf CATPLMClientTaskObject
{
  friend class CATPLMClientTasksFactory;
public:
  enum eStatus { Undefined = 1, Created = 2, Updated = 3, Deleted = 4 };

  CATPLMClientTaskObject(const CATUnicodeString& iPhysicalId, CATPLMTypeId_Classification iKind, const CATPLMRepositoryName& iRepo, CATPLMClientTaskObject::eStatus iStatus, const CATOmxKeyValueBlock& iKvb);
  ~CATPLMClientTaskObject();

  CATPLMClientTaskObject(const CATPLMClientTaskObject&);
  CATPLMClientTaskObject& operator=(const CATPLMClientTaskObject&);

  CATPLMID GetPLMID() const;

  CATPLMID_Any GetPhysicalId() const;

  CATPLMTypeId_Classification GetKind() const;

  CATPLMClientTaskObject::eStatus GetStatus() const;

  CATOmxKeyValueBlock GetAttributes() const;

private:
  HRESULT Complete(const CATPLMID_Any& iPhysicalId, const CATPLMID_Any& iLogicalId, const CATPLMID_Any& iMajorId, const CATUnicodeString& iTypeName);

  bool IsComplete() const;

  CATOmxSR<CATPLMClientTaskObjectInt> _spCTObject;
};

#endif
