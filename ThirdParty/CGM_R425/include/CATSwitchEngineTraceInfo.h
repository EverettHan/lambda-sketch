#ifndef CATSWETraceInfo_H
#define CATSWETraceInfo_H

#include "CATAbendInfo.h"
#include "CATOmbUtils.h"
#include "CATUnicodeString.h"

class CATPLMID;
class CATOmbStreamDescriptorObjectImpl;

namespace SWE
{
  struct Eol
  {};  
  struct Res
  { 
    Res(CATBoolean isOk) : _isOk(isOk) {}
    CATBoolean _isOk;
  };  
  struct Dir
  { 
    Dir(const CATUnicodeString & iDirPath) : _dirPath(iDirPath) {}
    CATUnicodeString _dirPath;
  };  
  
  class ExportedByCATOmbUtils TraceAbend : public CATAbendInfo
  {
    public:
    
    TraceAbend();
    virtual ~TraceAbend();    
    char * Dump() {return _buf;}  
        
    TraceAbend & operator <<(const char *s);    
    
    TraceAbend & operator <<(const CATOmbStreamDescriptorObjectImpl &);

    TraceAbend & operator <<(const CATPLMID &);
    
    TraceAbend & operator <<(const int v)
      { 
        char buffer[32]; sprintf(buffer,"%d",v); 
        return this->operator << (buffer);
      }
    
    TraceAbend & operator <<(const CATUnicodeString &iMsgToAdd)
      { return this->operator << (iMsgToAdd.ConvertToChar());} 
         
    private:

    char * _buf;
    size_t _bufsize;    
    size_t _FreeSpace;
    int    _LastErrno;
  };
}

typedef SWE::TraceAbend CATSwitchEngineTraceInfo;

ExportedByCATOmbUtils CATSwitchEngineTraceInfo& NewSwitchEngineTraceInAbendFile();

#endif
