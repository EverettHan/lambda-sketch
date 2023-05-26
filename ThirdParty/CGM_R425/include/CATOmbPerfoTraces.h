#ifndef CATOmbPerfoTraces_H_
#define CATOmbPerfoTraces_H_

#include "CATLib.h"
#include "CATUnicodeString.h"
#include "CATSysErrorDef.h"
#include "CATIStatsThematics.h"
#include "CATOMY.h"

class CATListValCATUnicodeString;

class ExportedByCATOMY CATOmbPerfoTraces
{
public:

  static HRESULT Start(int & iCounter, CATUnicodeString & iQEChain, CATTimerId & iologTimer, CATUnicodeString & logId);

  static HRESULT Stop(CATTimerId & ilogTimer, CATUnicodeString & ilogId, CATListValCATUnicodeString & iMsg);
private:
  static CATBoolean _IsActive;
  static CATBoolean _IsVarEvaluated;

};
#endif 
