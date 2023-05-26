#ifndef CATIOmyTraceWriter_H
#define CATIOmyTraceWriter_H

#include "CATOMYBaseSession.h"
#include "CATUnicodeString.h"
#include "CATOmxArray.h"
#include "CATOmxAny.h"
#include "CATOmxKeyString.h"
#include "CATOmxSR.h"

class OmyTraceWriterTask;

class ExportedByCATOMYBaseSession CATIOmyTraceWriter
{
public:
  virtual ~CATIOmyTraceWriter();
  CATIOmyTraceWriter();
  
  void                 SetFilePath(CATUnicodeString& iPath);
  void                 DoAsyncWrite();  
  
  CATIOmyTraceWriter& operator <<(const CATOmxKeyString&);
  CATIOmyTraceWriter& operator <<(const class CATOmxAny &cur); 
  CATIOmyTraceWriter& operator <<(const class CATUnicodeString &cur); 
    
private:
  CATIOmyTraceWriter(const CATIOmyTraceWriter&); 
  CATIOmyTraceWriter& operator=(const CATIOmyTraceWriter&);
  
  CATOmxSR<OmyTraceWriterTask> _realWriter;
};


#endif
