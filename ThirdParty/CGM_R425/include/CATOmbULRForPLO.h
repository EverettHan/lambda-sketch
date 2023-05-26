// COPYRIGHT Dassault Systemes 2008
/**
* @level Protected
* @usage U1
**/
#ifndef CATOmbULRForPLO_H
#define CATOmbULRForPLO_H

#include "CATObjectModelerBase.h"
#include "CATOmbUniversalLinkResult.h"
#include "CATOmxSR.h"

#include "CATBaseUnknown.h"
#include "CATOmbTimeStamp.h"
#include "CATUnicodeString.h"

//-----------------------------------------------------------------------
class CATILinkableObject_var;
class CATIOmbFunction;
class CATIOmbFunction_var;
class CATLinkStaticSolver;
class CATIOmbFunctionCall;
class CATIOmbDelegateMigration;
class CATIBindParameters;
class CATLinkSolver;
class CATOmxAny;

class ExportedByCATObjectModelerBase CATOmbULRForPLO : public CATOmbUniversalLinkResult
{
  CATDeclareClass;

public:
  static HRESULT CreateULRWithFunctionCall(CATIOmbDelegateMigration * iData, CATOmbULRForPLO *& oULR);

  CATOmbULRForPLO(CATBaseUnknown * iTarget, CATIOmbFunction * doNotUse = NULL);
  virtual ~CATOmbULRForPLO();

  bool IsEmpty() const;

  unsigned int GetULRHashCode() const;

  bool HasProxy() const;
  bool HasProxySpecs() const;
  bool HasFunction() const;

  void Dump(CATUnicodeString & oDump) const;

  HRESULT GetResultTarget(CATBaseUnknown_var & oTarget) const;
  virtual HRESULT GetRealResultTarget(CATBaseUnknown_var & oRealTarget) const;
  HRESULT GetUnfoldResultTarget(CATIBindParameters * iBindParameters, CATBaseUnknown_var & oTarget);
  HRESULT GetStaticTarget(CATILinkableObject_var & oStaticTarget) const;

  HRESULT GetUpdateStamp(CATOmbTimeStamp & oUpdateStamp) const;
  HRESULT GetSynchroStamp(CATOmxAny & ioVersion, CATOmxAny & oStamp) const;

private:
  void GetTarget(CATBaseUnknown_var & oTarget) const;

  CATOmxSR<CATBaseUnknown> m_target;
};

#endif

