#ifndef CATIExecLog_h
#define CATIExecLog_h


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "JS0LOGRP.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByJS0LOGRP IID IID_CATIExecLog;
#else
extern "C" const IID IID_CATIExecLog;
#endif
class CATICallTrac2;

class ExportedByJS0LOGRP CATIExecLog : public CATBaseUnknown
{
  CATDeclareInterface;
  public :
    virtual void GiveCurrentItem(CATICallTrac2 * & obj)=0;
};


#endif

