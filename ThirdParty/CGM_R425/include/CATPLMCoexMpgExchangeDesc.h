#ifndef CATPLMCoexMpgExchangeDesc_H
#define CATPLMCoexMpgExchangeDesc_H

#include "CATPLMServicesItf.h"
#include "CATPLMOmxCollections.h"

#include "CATSysErrorDef.h"

#include "CATOmxSR.h"
#include "CATOmxKeyString.h"
#include "CATOmxArray.h"

#include "CATIAV5Level.h"

// on level >= R421 (2019x), we have two rules to define unicity of each line:
//## UK_CoexMpgExchange_CtxDistantid
//# Enforce(Context, Distant_Identifier, Distant_Repository) unicity
//##################################################################
//unique index name UK_CoexMpgExchange_CtxDistantid column Context, Distant_Identifier, Distant_Repository
//#
//## UK_CoexMpgExchange_CtxLocalid
//# Enforce(Context, Local_Physicalid) unicity
//##################################################################	
//unique index name UK_CoexMpgExchange_CtxLocalid column Context, Local_Physicalid

class ExportedByCATPLMServicesItf CATPLMCoexMpgExchangeDesc
{
public:
  static const CATPLMCoexMpgExchangeDesc &s();

  ~CATPLMCoexMpgExchangeDesc();

  const CATOmxKeyString& GetMpgExchangeName() const;

  const CATOmxArray<CATOmxKeyString>& ListViewAttrName() const;

  const CATOmxKeyString ksrowuuid;
  const CATOmxKeyString kscestampLine;
  const CATOmxKeyString ksLocal_NTType;//deprecated if level >=R421 (2019x)
  const CATOmxKeyString ksLocal_physicalid;//deprecated if level >=R421 (2019x) replaced by ksLocal_Physicalid
  const CATOmxKeyString ksLocal_Repository;//deprecated if level >=R421 (2019x)
  const CATOmxKeyString ksMpgId;//deprecated if level >=R421 (2019x)
  const CATOmxKeyString ksoriginated;
  const CATOmxKeyString ksmodified;
#ifdef CATIAR421
  const CATOmxKeyString ksContext;
  const CATOmxKeyString ksDistant_Identifier;
  const CATOmxKeyString ksDistant_Repository;
  const CATOmxKeyString ksLocal_Physicalid;
#endif

private:
  CATPLMCoexMpgExchangeDesc();

  CATPLMCoexMpgExchangeDesc (CATPLMCoexMpgExchangeDesc &);
  CATPLMCoexMpgExchangeDesc& operator=(CATPLMCoexMpgExchangeDesc&);

  const CATOmxKeyString ksCoexMpgExchange;
  CATOmxArray<CATOmxKeyString> _lViewAttrDesc;
};

#endif
