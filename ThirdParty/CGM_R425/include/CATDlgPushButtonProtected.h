#ifndef CATDLGPUSHBUTTONPROTECTED_H
#define CATDLGPUSHBUTTONPROTECTED_H
#include "DI0PANV2.h"
#include "CATBoolean.h"
class CATDlgPushButton;
class CATUnicodeString;

class ExportedByDI0PANV2 CATDlgPushButtonProtected
{
  public :
      // effective on Windows only
      // When set, this attribute leads to contextual menu activation through left mouse button INSTEAD of right mouse button 
      static void SetContextualMenuActiveUnderLeftButton(CATDlgPushButton* push, CATBoolean b);
};
#endif


