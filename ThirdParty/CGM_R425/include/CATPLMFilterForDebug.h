#ifndef CATPLMFilterForDebug_H
#define CATPLMFilterForDebug_H

#include "CATPLMImplAdapterBase.h"

class CATPLMID;
class CATUnicodeString;

class ExportedByCATPLMImplAdapterBase CATPLMFilterForDebug
{
  friend class CATPLMFilterMinorObjReplacingBSF;
  friend class CATPLMFilterObjectToTreat;
  friend class CATPLMDebugMessages;
  friend class CATPLMQueryFilter;
private:
  static void WritePlmid(const CATPLMID& iPlmid,CATUnicodeString & oComment);

  static void _ExtractMandInfo(const CATPLMID& iPlmid,CATUnicodeString& oStrPhyId,CATUnicodeString& oStrMajId,CATUnicodeString& oStrLogId,CATUnicodeString& oTypeName,CATUnicodeString& oRepo);

  static char*  _MarshallDbBinary(  char  *p,  const  unsigned  char  *data,  short  sz  );
};

#endif
