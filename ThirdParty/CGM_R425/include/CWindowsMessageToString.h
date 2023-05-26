#ifndef MESSAGE_TO_STRING
#define MESSAGE_TO_STRING
#include "DI0PANV2.h"
 
class ExportedByDI0PANV2 CWindowsMessageToString 
{ 
  public: 
    CWindowsMessageToString(); 
    ~CWindowsMessageToString(); 
    // retcode =0 OK
    // retcode =1 frequent message not dumped
    // retcode =2 message not found
    char *GetStringFromMsg( DWORD dwMessage, bool bShowFrequentMessages, int& retCode ); 
};

#endif
