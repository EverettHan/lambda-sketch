#ifndef CATSpaceCmdInfo_H
#define CATSpaceCmdInfo_H

#include "CATString.h"
#include "CATUnicodeString.h"
#include "CATVisFoundation.h"

struct ExportedByCATVisFoundation CATSpaceCmdInfo
{
  CATString headerId;
  CATUnicodeString cmdTitle;
  CATUnicodeString iconPath;
  CATUnicodeString cmdHelp;
  CATSpaceCmdInfo();
  ~CATSpaceCmdInfo();
};
#endif
