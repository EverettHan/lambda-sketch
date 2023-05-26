#ifndef CATPLMPathAttributeH_H
#define CATPLMPathAttributeH_H

#include "CATPLMIdentificationAccess.h"

#include "CATSysErrorDef.h"

#include "CATOmxClassManager.h"
#include "CATOmxCollecManager.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxOMap.h"
#include "CATOmxOrderedOSet.h"
#include "CATOmxArray.h"
#include "AttrTypes.h"
#include "CATOmxSR.h"

class CATOmxKeyString;
class CATIPLMPathAttrInt;
class VPMIDicSimple;
class IPLMPathAttrIntFactory;

class ExportedByCATPLMIdentificationAccess CATPLMPathAttributeH
{
public:
  CATPLMPathAttributeH();

  CATPLMPathAttributeH(VPMIDicSimple* ipSimple);

  ~CATPLMPathAttributeH();

  CATPLMPathAttributeH(const CATPLMPathAttributeH&);

  CATPLMPathAttributeH& operator =( const CATPLMPathAttributeH & iSource );

  int operator ==( const CATPLMPathAttributeH & iOther ) const;

  int operator !=( const CATPLMPathAttributeH & iOther ) const;

  HRESULT ComputeHashKey( unsigned int & oKey ) const;

  int Compare( const CATPLMPathAttributeH & iOther ) const;

  const CATOmxKeyString& GetId() const;

  HRESULT GetAttributeType (AttrTypes& oType,CATBoolean& oIsMultivaluated) const;

  HRESULT GetOwnedBy(CATOmxKeyString& oPathTypeName) const;

  CATBoolean IsGlobal() const;
private:
  IPLMPathAttrIntFactory& _Factory() const;

  CATOmxSR<CATIPLMPathAttrInt> _spPathAttrInt;
};

extern const ExportedByCATPLMIdentificationAccess CATPLMPathAttributeH CATPLMPathAttributeH_Null;

template <> ExportedByCATPLMIdentificationAccess CATOmxCollecManager & CATOmxDefaultCollecManager <CATPLMPathAttributeH>::manager();

typedef ExportedByCATPLMIdentificationAccess CATOmxOMap<CATOmxKeyString,CATPLMPathAttributeH,CATOmxDefaultCollecManager<CATOmxKeyString>::manager,CATOmxDefaultCollecManager<CATPLMPathAttributeH>::manager> CATPLMPathAttrNameToPathAttrHMap;

typedef ExportedByCATPLMIdentificationAccess CATOmxArray<CATPLMPathAttributeH,CATOmxDefaultCollecManager<CATPLMPathAttributeH>::manager> CATPLMPathAttrHArray;

#endif
