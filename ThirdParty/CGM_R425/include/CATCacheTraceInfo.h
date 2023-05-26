#ifndef CATCacheTraceInfo_H
#define CATCacheTraceInfo_H

#include "CATAbendInfo.h"
#include "VVSUtils.h"
#include "CATUnicodeString.h"

namespace VVS
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
  
  class ExportedByVVSUtils TraceAbend : public CATAbendInfo
  {
    public:
    
    TraceAbend();
    virtual ~TraceAbend();    
    char * Dump() {return _buf;}  
        
    TraceAbend & operator <<(const char *s);    
    
    TraceAbend & operator <<(const Dir& );
    
    TraceAbend & operator <<(const int v)
      { 
        char buffer[32]; sprintf(buffer,"%d",v); 
        return this->operator << (buffer);
      }
    
    TraceAbend & operator <<(const CATUnicodeString &iMsgToAdd)
      { return this->operator << (iMsgToAdd.ConvertToChar());} 
    
    TraceAbend & operator <<(const Eol& )
      { return this->operator << ("\n");} 
    
    TraceAbend & operator <<(const Res& iRes)
      { 
        return (iRes._isOk) ?
               (this->operator << ("->SUCCEEDED\n")) :
               (this->operator << ("->FAILED (errno:") << strerror(_LastErrno) << (")\n"));
      }         
      
    private:

    char * _buf;
    size_t _bufsize;    
    size_t _FreeSpace;
    int    _LastErrno;
  };
}

typedef VVS::TraceAbend CATCacheTraceInfo;

ExportedByVVSUtils CATCacheTraceInfo& NewCacheTraceInAbendFile();

#endif
