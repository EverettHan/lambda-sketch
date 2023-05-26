#ifndef CATCreateMessageExtension_H
#define CATCreateMessageExtension_H


// COPYRIGHT DASSAULT SYSTEMES 2000

#include "TIE_CATICreateInstance.h"       

#define CATMsgCreatingExtension( classname) \
class classname##_CreateExt:public CATBaseUnknown  \
{  \
   CATDeclareClass; \
   public : \
      virtual HRESULT __stdcall CreateInstance(void **ppv); \
};\



#define CATImplementMsgCreatingExtension( classname) \
CATImplementClass(classname##_CreateExt,CodeExtension,CATBaseUnknown,classname); \
TIE_CATICreateInstance(classname##_CreateExt); \
HRESULT __stdcall classname##_CreateExt::CreateInstance(void **ppv)\
{\
   classname *pt = new classname;\
   *ppv = (void *)pt;\
   if (!pt) return(E_UNEXPECTED);\
   return(S_OK);\
}\


#endif
