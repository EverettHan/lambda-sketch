
// COPYRIGHT Dassault Systemes 2015
#ifndef CATPLMPath_H
#define CATPLMPath_H

#include "CATPLMIdentificationAccess.h"

#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATOmxAny.h"
#include "AttrTypes.h"
#include "CATOmxSR.h"
#include "CATPLMPathDataH.h"
#include "CATLISTV_CATPLMID.h"
#include "CATOmxSharable.h"

class CATComponentId;
class CATPLMTypeH;
class CATUnicodeString;
class CATOmxKeyString;
class CATOmxKeyValueBlock;
class CATPLMPathTypeH;

class ExportedByCATPLMIdentificationAccess CATPLMPath : public CATOmxSharable
{
public:
  CATPLMPath(const CATPLMPathDataH & iPLMPathData);

  ~CATPLMPath();

  CATBoolean IsValid() ;

  HRESULT GetPathTypeH( CATPLMPathTypeH& oPathType ) ;

  const CATOmxAny& GetSynchroStamp() ;

  const CATPLMID GetPointedPlmid() ; 

  const CATOmxKeyValueBlock& GetAttrBlock() ;
  HRESULT GetAttrValue(const CATOmxKeyString& iAttrName,CATOmxAny& oValue,AttrTypes& oType,CATBoolean& oIsMultivaluated);

  CATPLMPath(const CATPLMPath& iSource);
  CATPLMPath& operator = (const CATPLMPath& iSource);

private:

  CATPLMPathDataH _spPathDataH;
};

#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
template <> ExportedByCATPLMIdentificationAccess CATOmxCollecManager & CATOmxDefaultCollecManager <CATPLMPath>::manager();

#endif
