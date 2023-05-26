

#ifndef CATDLGSTATUSBARPROTECTED_H
#define CATDLGSTATUSBARPROTECTED_H
// TVE6 NOV 2021 
#include "DI0PANV2.h"




class CATDlgStatusBar;
class CATString;
class CATUnicodeString;


typedef void(*FieldUpdateCallbackType)(const  CATUnicodeString &, void* data);
typedef void(*VisibilityPushButtonCallbackType)(int visib, void* data);

class ExportedByDI0PANV2 CATDlgStatusBarProtected
{
public:

   static int         SetPowerInputBoxLink(CATDlgStatusBar* statusBarPowerInput, CATUnicodeString& labelString, CATUnicodeString& fieldDefaultString, FieldUpdateCallbackType fieldFunction, VisibilityPushButtonCallbackType buttonFunction, void* data);
   static void        ResetPowerInputBoxLink(CATDlgStatusBar* statusBarPowerInput, int idReset);  
 

};


#endif


