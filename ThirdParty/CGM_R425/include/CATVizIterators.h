/* COPYRIGHT DASSAULT SYSTEMES 2005 */

#ifdef  __CATVisIterators
#define ExportedByCATVisFoundationIterators DSYExport
#else
#define ExportedByCATVisFoundationIterators DSYImport
#endif
#include "DSYExport.h"


#include <memory.h>
#include "CATErrorDef.h"

#define CATVizDeclareIterator(ClassName)                                   \
public:                                                                    \
   static IID GetIID() { return sIID_##ClassName; }                        \
   virtual HRESULT __stdcall QueryInterface(const IID &iIID, void** oPPV); \
private:                                                                   \
   static IID & sIID_##ClassName                                           \

#define CATVizImplementIterator(ClassName, BaseClass, IIDValue)            \
IID & ClassName::sIID_##ClassName = IIDValue;                              \
HRESULT __stdcall ClassName::QueryInterface(const IID &iIID, void** oPPV)  \
{                                                                          \
   if(memcmp(&sIID_##ClassName, &iIID, sizeof(GUID)) == 0)                 \
   {                                                                       \
      AddRef();                                                            \
      *oPPV = this;                                                        \
      return S_OK;                                                         \
   }                                                                       \
   return BaseClass::QueryInterface(iIID, oPPV);                           \
}                                                                          \

