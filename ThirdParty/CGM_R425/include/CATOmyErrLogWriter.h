
#include "CATUnicodeString.h"
#include "CATOMY.h"
#include "CATSysErrLog.h"

class ExportedByCATOMY CATOmyErrLogWriter
{
  static void AddField(CATStatsEventId iEventId, const char* iFieldName, const CATUnicodeString& iMessage);
public:
  static void Dump(const CATUnicodeString &iMessage);
};

