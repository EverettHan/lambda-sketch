#ifndef CATPLMStrongRelationshipLoader_H
#define CATPLMStrongRelationshipLoader_H

#include "CATPLMServicesItf.h"

#include "CATBoolean.h"
#include "CATSysErrorDef.h"

#include "CATOmxOMap.h"
#include "CATOmxKeyString.h"
#include "CATOmxDefaultCollecManager.h"

class CATPLMType;
class VPMIDicMgr;
class VPMIDicClass;
class VPMIDicRelationClass;
class VPMIDicElement;

typedef  CATOmxOMap<CATOmxKeyString,VPMIDicElement*,CATOmxDefaultCollecManager<CATOmxKeyString>::manager,com_manager> CATPLMKeyStringToDicElementMap;
template <> ExportedByCATPLMServicesItf CATOmxCollecManager&  CATOmxDefaultCollecManager<CATPLMKeyStringToDicElementMap>::manager();
typedef CATOmxOMap<CATString, CATPLMKeyStringToDicElementMap> CATPLMStringToDicElementsMap;

class ExportedByCATPLMServicesItf CATPLMStrongRelationshipLoader
{
public:
  // add strong relationship to relation type (from,to,fromrel,torel) and complex type (V_Owner)
  // CATPLMType::AddRelation(...) is used to do the job
  static HRESULT ComputeStrongRelation(CATPLMType* iopType);

  // STRONG relationship from/to/fromrel/torel...
  static HRESULT GetRelationships( VPMIDicMgr* ipDicMgr,
                                    VPMIDicClass & iClass,
                                    CATBoolean iWithInheritance,
                                    CATPLMStringToDicElementsMap & oMapRelNameWithMapPointedTypeWithDicElem);

  // STRONG relationship from/to/fromrel/torel...
  static HRESULT GetRelationships( VPMIDicMgr* ipDicMgr,
                                    VPMIDicRelationClass & iRelClass,
                                    CATBoolean iWithInheritance,
                                    CATPLMStringToDicElementsMap & oMapRelNameWithMapPointedTypeWithDicElem);
private:
  template <class T>
  static HRESULT _ProcessStrongRelations(T* ipClass,VPMIDicMgr* ipDicMgr,CATPLMType* iopType);
};

#endif
